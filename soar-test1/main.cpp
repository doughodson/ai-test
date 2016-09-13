
#include "soar/sml_Client.h"
#include "windows.h"

#include <iostream>
#include <string>

int main()
{
   sml::Kernel* kernel = sml::Kernel::CreateKernelInNewThread();
   if (kernel->HadError()) {
      std::cout << "There was an error after creating the Kernel instance\n";
      std::cout << kernel->GetLastErrorDescription() << std::endl;
      return EXIT_SUCCESS;
   }
   std::cout << "Kernel created\n";

   // create an agent named "agent"
   sml::Agent* agent = kernel->CreateAgent("agent");
   // load productions
   agent->LoadProductions("agent.soar");
   if (agent->HadError()) {
      std::cout << "There was an error loading the production" << std::endl;
      std::cout << agent->GetLastErrorDescription() << std::endl;
      return EXIT_SUCCESS;
   }
   std::cout << "Agent, productions loaded\n";

   // open soar debugger - make sure the path to debugger is in system path
   static int kernelPort(12121);
   agent->SpawnDebugger(kernelPort, "C:/book-code/ai-test/3rdparty/bin/SoarJavaDebugger.jar");

   std::cout << "Hit return when debugger has opened\n";
   system("pause");

   // this is how agents should be run in a production environment
   // kernel->RunAllAgentsForever();

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
         std::cout << "Sending information on the input link" << std::endl;
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
