
#include "soar/sml_Client.h"
#include "windows.h"

#include "AgentData.hpp"

#include <iostream>
#include <string>

//
// kernel events
//

//typedef void(* sml::UpdateEventHandler) (smlUpdateEventId id, void *pUserData, Kernel *pKernel, smlRunFlags runFlags)
void updateEventHandler(sml::smlUpdateEventId id, void* userData, sml::Kernel* kernel, sml::smlRunFlags runFlags)
{
   // check for output (handled by callbacks), update world state, send new input

   // delay
   std::cout << "\nKernel update event triggered - Sleeping for 3 seconds\n";
   Sleep(3000);

   // send new input
   AgentData* agentData = static_cast<AgentData*>(userData);

   static int steps(0);
   if (steps < 5) {
      agentData->agent->Update(agentData->wmeFront, "empty");
   } else {
      agentData->agent->Update(agentData->wmeFront, "wall");
   }
   steps++;
   std::cout << "Updated information on input link" << std::endl;

   agentData->agent->ClearOutputLinkChanges();
}

//
// agent events
//

void forwardEventHandler(void* userData, sml::Agent* agent, char const* cmdName, sml::WMElement* outputWme)
{
   std::cout << "Agent: Foward event handler was called for " << agent->GetAgentName() << "\n";
}

void stopEventHandler(void* userData, sml::Agent* agent, char const* cmdName, sml::WMElement* outputWme)
{
   std::cout << "Agent: Stop event handler was called for " << agent->GetAgentName() << "\n";
}

int main(int, char**)
{
   std::cout << "sizeof char        : " << sizeof(char)        << " bytes\n";
   std::cout << "sizeof sml::Kernel : " << sizeof(sml::Kernel) << " bytes\n";
   std::cout << "sizeof sml::Agent  : " << sizeof(sml::Agent)  << " bytes\n";

   const int kernelPort = 12121;
   sml::Kernel* kernel = sml::Kernel::CreateKernelInNewThread(kernelPort);
   if (kernel->HadError()) {
      std::cout << "There was an error after creating the Kernel instance\n";
      std::cout << kernel->GetLastErrorDescription() << std::endl;
      return EXIT_SUCCESS;
   }

   sml::Agent* agent1 = kernel->CreateAgent("agent1");
   if (kernel->HadError()) {
      std::cout << kernel->GetLastErrorDescription() << std::endl;
      return EXIT_SUCCESS;
   }

   agent1->LoadProductions("agent.soar");
   if (agent1->HadError()) {
      std::cout << "There was an error loading productions\n";
      std::cout << agent1->GetLastErrorDescription() << std::endl;
      return EXIT_SUCCESS;
   }

//   agent->SetBlinkIfNoChange(TRUE);

   // open debugger
   const std::string debugger("C:/book-code/ai-test/3rdparty/bin/SoarJavaDebugger.jar");
   agent1->SpawnDebugger(kernelPort, debugger.c_str());

   std::cout << "Hit return after debugger opens\n";
   system("pause");

	AgentData* agentData1 = new AgentData(agent1);

   // int Kernel::RegisterForUpdateEvent(smlUpdateEventId id, UpdateEventHandler handler, void* pUserData, bool addToBack = true)
   kernel->RegisterForUpdateEvent(sml::smlEVENT_AFTER_ALL_OUTPUT_PHASES, updateEventHandler, agentData1);

   //
   // AddOutputHandler (char const *pAttributeName, OutputEventHandler handler, void *pUserData, bool addToBack=true)
   // Register an "Output event handler". This is one way to be notified when output occurs on the output link. You
   // register for a specific attribute name (e.g. "move") and when that attribute is added to the output link the
   // handler you have registered for that name is called.
   //
   agent1->AddOutputHandler("forward", forwardEventHandler, agentData1);
   agent1->AddOutputHandler("stop", stopEventHandler, agentData1);

   kernel->RunAllAgentsForever();
   std::cout << "Kernel running forever\n";
   system("pause");

   kernel->Shutdown();
   delete kernel;

   std::cout << "Program finished\n";
   system("pause");

   return EXIT_SUCCESS;
}
