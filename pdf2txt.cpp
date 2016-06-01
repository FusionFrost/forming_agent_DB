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
	ZeroMemory( &StartInfo, sizeof(StartInfo) );
	StartInfo.cb = sizeof(StartInfo);

	AnsiString s = Setting->getPathToPdfToTxtConvector();	//! Получаем путь до конектора
	if(s != NULL)
	{
		AnsiString str = AnsiString(s + " " +PdfFile + " /to " + PathPutTxt);

		if(CreateProcess(NULL, str.c_str(),NULL,NULL,false,CREATE_NEW_CONSOLE|REALTIME_PRIORITY_CLASS,NULL,NULL, &StartInfo, &ProcInfo) == true)
		{
//			if (WaitForSingleObject(ProcInfo.hProcess,1000)== WAIT_TIMEOUT)
//			{
//				CloseHandle(ProcInfo.hProcess);
//			}
//			TerminateProcess(ProcInfo.hProcess, 0);
		}else
		{ShowMessage("Ошибка: Не может конвертировать из PDF в TXT");}
	}
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
