#include <Windows.h>

BOOL IsRunAsAdministrator();
void ElevateNow()
{
  BOOL bAlreadyRunningAsAdministrator = FALSE;
  try
  {
  bAlreadyRunningAsAdministrator = IsRunAsAdministrator();
  }
  catch(...)
  {
    _asm nop
  }
  if(!bAlreadyRunningAsAdministrator)
  {
    char szPath[MAZ_PATH];
    if (GetModuleFileName(NULL, szPath, ARRAYSIZE(szPath)))
    {
      SHELLEXECUTEINFO sei = { sizeof(sei) };

      sei.lpVerb = "runas";
      sei.lpFile = szPath;
      sei.hwnd = NULL;
      sei.nShow = SW_NORMAL;

      if(!ShellExecuteEx(&sei))
      {
        DWORD dwError = GetLastError();
        if (dwError == ERROR_CANCELLED)
        CreateThread(0,0,(LPTHREAD_START_ROUTINE)ElevateNow,0,0,0);
      }
    }
  }
  else
  {
  }
}
