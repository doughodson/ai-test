

#include <iostream>
#include <string>
#include "soar/sml_Client.h"

int main(int, char**)
{
   sml::Kernel* kernel = sml::Kernel::CreateKernelInNewThread();
   sml::Agent* agent = kernel->CreateAgent("soar");

   std::cout << agent->ExecuteCommandLine("echo Hello World");

   std::string dummy;
   std::cin >> dummy;
   return 0;
}
