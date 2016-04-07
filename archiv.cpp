//---------------------------------------------------------------------------

#pragma hdrstop

#include "archiv.h"
//---------------------------------------------------------------------------

/*!

	en: funcktion extracting filse(recursion) in current directory ru: ������� ���������� ������(�����������) � ��������� ��������.
	en: first argument: Path to current files 					   ru: ������ ��������: ���� �� ������(�����, ��� ����� ��� �����)
	en: Second argument: Path where to put the file                ru: ������ ��������: ���� ���� �������� ������������� �����
*/
void Archiv::ExtractFiles(AnsiString CurDir,AnsiString putDir)
{
	AnsiString cDir = CurDir; //! ���������� ��������� ����������
	AnsiString CmdLine;
	STARTUPINFO StartInfo = {sizeof(TStartupInfo)};
	PROCESS_INFORMATION ProcInfo;
	LPCSTR t;
	StartInfo.cb= sizeof(StartInfo);
	StartInfo.dwFlags = STARTF_USESHOWWINDOW;
	StartInfo.wShowWindow= SW_HIDE;

    char buffer[1000];
	GetCurrentDirectory(sizeof(buffer),buffer);
	AnsiString DefaultDir = buffer;

	if(cDir == NULL)        //! ���� ������ - ���������� �� ���������
	{
		CmdLine= DefaultDir + "\\7z\\7za.exe x " + DefaultDir +"\\Archivs\\*.7z -r -o" + DefaultDir + "\\res\\";
	}else
	{
		CmdLine= DefaultDir + "\\7z\\7za.exe x " + cDir +"\\*.7z -r -o" + putDir + "\\";
	}

	if(!CreateProcess(NULL, CmdLine.c_str(),
			NULL,NULL,false,
			CREATE_NEW_CONSOLE|HIGH_PRIORITY_CLASS,
			NULL,NULL, &StartInfo, &ProcInfo))
	ShowMessage("������");
	else
	{
	if (WaitForSingleObject(ProcInfo.hProcess,1000)== WAIT_TIMEOUT)
	CloseHandle(ProcInfo.hProcess);
	}
}
#pragma package(smart_init)
