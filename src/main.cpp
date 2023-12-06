#include <coreinit/thread.h>
#include <coreinit/time.h>
#include <coreinit/systeminfo.h>
#include <nn/ac.h>

#include <whb/proc.h>
#include <whb/log.h>
#include <whb/log_console.h>

int main(int argc, char **argv)
{
   nn::ac::ConfigIdNum configId;

   nn::ac::Initialize();
   nn::ac::GetStartupId(&configId);
   nn::ac::Connect(configId);

   WHBProcInit();
   WHBLogConsoleInit();

   while(true) {  
           WHBLogPrintf("This is a demo");
           WHBLogConsoleDraw();
   }

   WHBLogConsoleFree();
   WHBProcShutdown();

   nn::ac::Finalize();
   return 0;
}
