
#include "soar/sml_Client.h"
#include "windows.h"

#include <iostream>

int main()
{
   sml::Kernel* kernel = sml::Kernel::CreateKernelInNewThread();

   // Check that nothing went wrong.  We will always get back a kernel object
   // even if something went wrong and we have to abort.
   if (kernel->HadError()) {
      std::cout << "There was an error after creating the Kernel instance" << std::endl;
      std::cout << kernel->GetLastErrorDescription() << std::endl;
      return 0;
   }

   std::cout << "Kernel created\n";

   std::cout << "Creating agent and loading productions\n";
   sml::Agent* agent = kernel->CreateAgent("agent");
   agent->LoadProductions("agent.soar");
   if (kernel->HadError()) {
      std::cout << "There was an error loading the production" << std::endl;
      std::cout << kernel->GetLastErrorDescription() << std::endl;
      return 0;
   }

   //sml::Agent* agent1 = kernel->CreateAgent("agent1");
   //agent1->LoadProductions("agent.soar");
   //sml::Agent* agent2 = kernel->CreateAgent("agent2");
   //agent2->LoadProductions("agent.soar");

   // open soar debugger, make sure the path to debugger is in system path
   static int kernelPort(12121);
   agent->SpawnDebugger(kernelPort, "C:/book-code/soar-test/3rdparty/bin/SoarJavaDebugger.jar");

   std::cout << "Please connect debugger\n";
   system("pause");

   static int initialX = 3;
   static int initialY = 4;
   int time = 0;

   std::string World[5][5] = {
      { "wall", "wall", "wall", "wall", "wall" },
      { "wall", "empty", "empty", "empty", "wall" },
      { "wall", "empty", "empty", "empty", "wall" },
      { "wall", "empty", "empty", "empty", "wall" },
      { "wall", "wall", "wall", "wall", "wall" }
   };

   //The documentation mentions this is how agents should be
   //run in a production environment
   //pKernel->RunAllAgentsForever();

   sml::Identifier* pInputLink = agent->GetInputLink();

   //Here I am creating a WME on the input link, it is based on the eaters example

   sml::StringElement* pWME1 = agent->CreateStringWME(pInputLink, "front", "empty");
   sml::StringElement* pWME2 = agent->CreateStringWME(pInputLink, "orientation", "north");
   sml::IntElement* pWME3 = agent->CreateIntWME(pInputLink, "time", time);
   sml::IntElement* pWME4 = agent->CreateIntWME(pInputLink, "x", initialX);
   sml::IntElement* pWME5 = agent->CreateIntWME(pInputLink, "y", initialY);

   int x = initialX;
   int y = initialY;

   while (agent->GetRunState() != 3) {

      std::cout << "Run agent until it produces output" << std::endl;
      agent->RunSelfTilOutput();
      time++;

      int numberCommands = agent->GetNumberCommands();
      for (int i = 0; i < numberCommands; i++) {
         sml::Identifier* pCommand = agent->GetCommand(i);

         std::string name = pCommand->GetCommandName();

         std::cout << name << std::endl;
         //updateWorld(string[][], int x, int y);
         if (y != 0) {
            y--;
            agent->DestroyWME(pWME1);
            agent->DestroyWME(pWME5);
            char* pFrontWorld = &World[x][y][0];
            pWME1 = agent->CreateStringWME(pInputLink, "front", pFrontWorld);
            pWME5 = agent->CreateIntWME(pInputLink, "y", y);
         }
         std::cout << "Sending information on the input link" << std::endl;

         agent->DestroyWME(pWME3);
         pWME3 = agent->CreateIntWME(pInputLink, "time", time);

         // Then mark the command as completed
         pCommand->AddStatusComplete();
      }

      std::cout << "Waiting 5 seconds\n";
      Sleep(6000);
      std::cout << "Done with wait\n";

   }

   std::cout << "Program finished\n";
   return 0;
}
