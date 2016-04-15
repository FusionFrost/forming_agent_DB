//---------------------------------------------------------------------------

#pragma hdrstop

#include "pdf2txt.h"

void pdf2txt::convert(AnsiString PdfFile,AnsiString PathPutTxt)
{
	STARTUPINFO StartInfo = {sizeof(TStartupInfo)};
	PROCESS_INFORMATION ProcInfo;
	LPCSTR t;
	StartInfo.cb= sizeof(StartInfo);
	StartInfo.dwFlags = STARTF_USESHOWWINDOW;
	StartInfo.wShowWindow= SW_HIDE;

	AnsiString s = Setting->getPathToPdfToTxtConvector();	//! Получаем путь до конектора
	if(s != NULL)
	{
		AnsiString str = AnsiString(s +" /cs 9000 /i \"" + PdfFile + "\" /o \"" + PathPutTxt + "\" /pto 0");

		if(CreateProcess(NULL, str.c_str(),NULL,NULL,false,CREATE_NEW_CONSOLE|HIGH_PRIORITY_CLASS,NULL,NULL, &StartInfo, &ProcInfo) == true)
		{
			if (WaitForSingleObject(ProcInfo.hProcess,10000)== WAIT_TIMEOUT)
			{
				CloseHandle(ProcInfo.hProcess);
			}
			TerminateProcess(ProcInfo.hProcess, 0);
		}else
		{ShowMessage("Ошибка: Не может конвертировать из PDF в TXT");}
	}
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
