
#include "soar/sml_Client.h"
#include "windows.h"

#include <iostream>
#include <string>

void forwardEventHandler(void* userData, sml::Agent* agent, char const* commandName, sml::WMElement* outputWme)
{
   std::cout << "Foward event handler was called\n";
}

void stopEventHandler(void* userData, sml::Agent* agent, char const* commandName, sml::WMElement* outputWme)
{
   std::cout << "Stop event handler was called\n";
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
   if (kernel->HadError()) {
      std::cout << kernel->GetLastErrorDescription() << std::endl;
      return EXIT_SUCCESS;
   }

   agent->LoadProductions("agent.soar");
   if (agent->HadError()) {
      std::cout << "There was an error loading productions\n";
      std::cout << agent->GetLastErrorDescription() << std::endl;
      return EXIT_SUCCESS;
   }
//   agent->SetBlinkIfNoChange(TRUE);

   agent->AddOutputHandler("forward", forwardEventHandler, agent, NULL);
   agent->AddOutputHandler("stop", stopEventHandler, agent, NULL);

   // open debugger
// const std::string debugger("C:/book-code/ai-test/3rdparty/bin/SoarJavaDebugger.jar");
// pAgent->SpawnDebugger(kernelPort, debugger.c_str());

   Sleep(5000);

   //Running Agents
   //UpdateEventHandler handler = 
//   int callBackId = kernel->RegisterForUpdateEvent(sml::smlEVENT_AFTER_ALL_OUTPUT_PHASES, MyUpdateEventHandler, FALSE);
//   kernel->RunAllAgentsForever();

   sml::Identifier* agentInputLink = agent->GetInputLink();

   std::string* s = new std::string("empty");
   sml::StringElement* wmeFront = agent->CreateStringWME(agentInputLink, "front", s->c_str());

   const int steps = 15;
   for (int x=0; x < steps; x++) {
      if (agent->GetRunState() != sml::sml_RUNSTATE_HALTED) {

         std::cout << "Run agent until it produces output " << "step: " << x << std::endl;
         agent->RunSelfTilOutput();

         // read and process commands from agent
         const int numCommands = agent->GetNumberCommands();
         for (int i=0; i < numCommands; i++) {
            sml::Identifier* command = agent->GetCommand(i);

            // this was command returned by agent (update environment)
            std::cout << "Agent command result : " << command->GetCommandName() << std::endl;

            // mark command as complete
            command->AddStatusComplete();
         }

         // defines a simple world
         if (x < steps-5) {
            *s = "empty";
         } else {
            *s = "wall";
         }
         agent->Update(wmeFront, s->c_str());
         std::cout << "Updated information on input link" << std::endl;
      }
      if (agent->GetRunState() == sml::sml_RUNSTATE_HALTED) {
         std::cout << "Agent HALTED\n";
      }
   }

   system("pause");

   kernel->Shutdown();
   delete kernel;

   std::cout << "Program finished\n";
   return EXIT_SUCCESS;
}
