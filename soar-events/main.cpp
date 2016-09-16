
#include "soar/sml_Client.h"
#include "windows.h"

#include <iostream>
#include <string>

void MyUpdateEventHandler(sml::smlSystemEventId id, void* pUserData, sml::Kernel* kernel, sml::smlRunFlags runFlags)
{
   std::cout << "The output handler was called\n";
}

int main(int, char**)
{
   const int kernelPort = 12121;
   sml::Kernel* kernel = sml::Kernel::CreateKernelInNewThread(kernelPort);
   if (kernel->HadError()) {
      std::cout << "There was an error after creating the Kernel instance\n";
      std::cout << kernel->GetLastErrorDescription() << std::endl;
      return EXIT_SUCCESS;
   }

   sml::Agent* agent = kernel->CreateAgent("agent");
   agent->LoadProductions("agent.soar");
   agent->SetBlinkIfNoChange(TRUE);
   if (agent->HadError()) {
      std::cout << "There was an error loading the production\n";
      std::cout << agent->GetLastErrorDescription() << std::endl;
      return EXIT_SUCCESS;
   }

   //This is the command to open a Debugger window
   const std::string debugger("C:/book-code/ai-test/3rdparty/bin/SoarJavaDebugger.jar");
   //pAgent->SpawnDebugger(kernelPort, debugger.c_str());
   static int initialX = 0;

   std::string World[20] = { "empty", "empty", "empty", "empty", "empty", "empty",
      "empty", "empty", "empty", "empty", "empty", "empty", "empty", "empty",
      "empty", "empty", "empty", "empty", "empty", "wall" };

   Sleep(5000);
   //Running Agents
   //UpdateEventHandler handler = 
   int callBackId = kernel->RegisterForUpdateEvent(sml::smlEVENT_AFTER_ALL_OUTPUT_PHASES, MyUpdateEventHandler, FALSE);
   kernel->RunAllAgentsForever();

   sml::Identifier* pInputLink = agent->GetInputLink();

   //Here I am creating a WME on the input link, it is based on the eaters example

   sml::StringElement* pWME1 = agent->CreateStringWME(pInputLink, "front", "empty");

   int x = initialX;

   while (agent->GetRunState() != sml::sml_RUNSTATE_HALTED) {
      
      std::cout << "\nRunning agent until output\n";
      agent->RunSelfTilOutput();

      const int numberCommands = agent->GetNumberCommands();
      std::cout << "Number if commands in output link: " << numberCommands << std::endl;

      for (int i = 0; i < numberCommands; i++) {
         sml::Identifier* pCommand = agent->GetCommand(i);

         std::string name = pCommand->GetCommandName();

         std::cout << "Received from Soar: " << name << std::endl;

         if (name == "forward"){
            x++;
            char* pFrontWorld = &World[x][0];
            std::cout << "Sending information on the input link" << std::endl;
            std::cout << "Sending front " << pFrontWorld << std::endl;
            agent->Update(pWME1, pFrontWorld);

         }
         else if (name == "stop") {

            char* pFrontWorld = &World[x][0];
            std::cout << "Sending information on the input link\n";
            std::cout << "Sending front " << pFrontWorld << std::endl;
            agent->Update(pWME1, pFrontWorld);
         }

         // Then mark the command as completed
         pCommand->AddStatusComplete();

      }
   }
   std::cout << "Enter to exit\n";
   while (std::cin.get() != '\n');
   kernel->Shutdown();
   delete kernel;

   return EXIT_SUCCESS;
}
