
#include "soar/sml_Client.h"

#include <iostream>
#include <string>

int main(int, char**)
{
   const int kernelPort(12121);
   sml::Kernel* kernel = sml::Kernel::CreateKernelInNewThread(kernelPort);
   if (kernel->HadError()) {
      std::cout << "There was an error after creating the Kernel instance\n";
      std::cout << kernel->GetLastErrorDescription() << std::endl;
      return EXIT_SUCCESS;
   }
   std::cout << "Kernel created\n";
   system("pause");

   kernel->Shutdown();
   delete kernel;
   return EXIT_SUCCESS;
}
