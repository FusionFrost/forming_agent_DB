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
	AnsiString CmdLine_7z, CmdLine_zip, CmdLine_rar;

	STARTUPINFO StartInfo = {sizeof(TStartupInfo)};
	PROCESS_INFORMATION ProcInfo;
	LPCSTR t;
	StartInfo.cb= sizeof(StartInfo);
	StartInfo.dwFlags = STARTF_USESHOWWINDOW;
	StartInfo.wShowWindow= SW_HIDE;

	char buffer[1000];
	GetCurrentDirectory(sizeof(buffer),buffer);
	AnsiString DefaultDir = buffer;

	if(putDir == "")
	{
		putDir = DefaultDir + "\\res";
	}

	if(cDir == "")        //! ���� ������ - ���������� �� ���������
	{
		CmdLine_7z = DefaultDir + "\\7z\\7za.exe x " + DefaultDir +"\\Archivs\\*.7z -r -o" + DefaultDir + "\\res";
		CmdLine_zip = DefaultDir + "\\7z\\7za.exe x " + DefaultDir +"\\Archivs\\*.zip -r -o" + DefaultDir + "\\res";
		CmdLine_rar = DefaultDir + "\\WinRar\\Rar.exe x " + DefaultDir +"\\Archivs\\*.rar -r " + DefaultDir + "\\res";
	}else
	{
		CmdLine_7z = DefaultDir + "\\7z\\7za.exe x " + cDir +"\\*.7z -r -o" + putDir;
		CmdLine_zip = DefaultDir + "\\7z\\7za.exe x " + cDir +"\\*.zip -r -o" + putDir;
		CmdLine_rar = DefaultDir + "\\WinRar\\Rar.exe x " + cDir +"\\*.rar -r " + putDir;
	}

	//! ��� .7z
	if(CreateProcess(NULL, CmdLine_7z.c_str(),NULL,NULL,false,CREATE_NEW_CONSOLE|HIGH_PRIORITY_CLASS,NULL,NULL, &StartInfo, &ProcInfo) == true)
	{
		if (WaitForSingleObject(ProcInfo.hProcess,1000)== WAIT_TIMEOUT)
		{
			CloseHandle(ProcInfo.hProcess);
		}
		TerminateProcess(ProcInfo.hProcess, 0);
	}else
	{ShowMessage("������");}


	//! ��� .zip
	if(CreateProcess(NULL, CmdLine_zip.c_str(),NULL,NULL,false,CREATE_NEW_CONSOLE|HIGH_PRIORITY_CLASS,NULL,NULL, &StartInfo, &ProcInfo) == true)
	{
		if (WaitForSingleObject(ProcInfo.hProcess,1000)== WAIT_TIMEOUT)
		{
			CloseHandle(ProcInfo.hProcess);
		}
		TerminateProcess(ProcInfo.hProcess, 0);
	}else
	{ShowMessage("������");}

	//! ��� .rar
	if(CreateProcess(NULL, CmdLine_rar.c_str(),NULL,NULL,false,CREATE_NEW_CONSOLE|HIGH_PRIORITY_CLASS,NULL,NULL, &StartInfo, &ProcInfo) == true)
	{
		if (WaitForSingleObject(ProcInfo.hProcess,1000)== WAIT_TIMEOUT)
		{
			CloseHandle(ProcInfo.hProcess);
		}
		TerminateProcess(ProcInfo.hProcess, 0);
	}else
	{ShowMessage("������");}


	TStringDynArray list = TDirectory::GetDirectories(DefaultDir + "\\res");
	if( list.Length != 0)
	{
		for(int i = 0; i < list.Length; i++)
		{
			ExtractFilesLite(list[i],DefaultDir + "\\res");
			Dir.Delete(list[i],true);
		}
	}

	 ExtractFilesLite(putDir,putDir);
	 DeleteFile("*.rar");

}

void Archiv::ExtractFilesLite(AnsiString CurDir,AnsiString putDir)
{
	AnsiString cDir = CurDir; //! ���������� ��������� ����������
	AnsiString CmdLine_7z, CmdLine_zip, CmdLine_rar;

	STARTUPINFO StartInfo = {sizeof(TStartupInfo)};
	PROCESS_INFORMATION ProcInfo;
	LPCSTR t;
	StartInfo.cb= sizeof(StartInfo);
	StartInfo.dwFlags = STARTF_USESHOWWINDOW;
	StartInfo.wShowWindow= SW_HIDE;

	char buffer[1000];
	GetCurrentDirectory(sizeof(buffer),buffer);
	AnsiString DefaultDir = buffer;

	if(putDir == "")
	{
		putDir = DefaultDir;
	}

	if(cDir == "")        //! ���� ������ - ���������� �� ���������
	{
		CmdLine_7z = DefaultDir + "\\7z\\7za.exe x " + DefaultDir +"\\Archivs\\*.7z -r -o" + DefaultDir + "\\res";
		CmdLine_zip = DefaultDir + "\\7z\\7za.exe x " + DefaultDir +"\\Archivs\\*.zip -r -o" + DefaultDir + "\\res";
		CmdLine_rar = DefaultDir + "\\WinRar\\Rar.exe x " + DefaultDir +"\\Archivs\\*.rar -r " + DefaultDir + "\\res";
	}else
	{
		CmdLine_7z = DefaultDir + "\\7z\\7za.exe x " + cDir +"\\*.7z -r -o" + putDir;
		CmdLine_zip = DefaultDir + "\\7z\\7za.exe x " + cDir +"\\*.zip -r -o" + putDir;
		CmdLine_rar = DefaultDir + "\\WinRar\\Rar.exe x " + cDir +"\\*.rar -r " + putDir;
	}

	//! ��� .7z
	if(CreateProcess(NULL, CmdLine_7z.c_str(),NULL,NULL,false,CREATE_NEW_CONSOLE|HIGH_PRIORITY_CLASS,NULL,NULL, &StartInfo, &ProcInfo) == true)
	{
		if (WaitForSingleObject(ProcInfo.hProcess,1000)== WAIT_TIMEOUT)
		{
			CloseHandle(ProcInfo.hProcess);
		}
		TerminateProcess(ProcInfo.hProcess, 0);
	}else
	{ShowMessage("������");}


	//! ��� .zip
	if(CreateProcess(NULL, CmdLine_zip.c_str(),NULL,NULL,false,CREATE_NEW_CONSOLE|HIGH_PRIORITY_CLASS,NULL,NULL, &StartInfo, &ProcInfo) == true)
	{
		if (WaitForSingleObject(ProcInfo.hProcess,1000)== WAIT_TIMEOUT)
		{
			CloseHandle(ProcInfo.hProcess);
		}
		TerminateProcess(ProcInfo.hProcess, 0);
	}else
	{ShowMessage("������");}

	//! ��� .rar
	if(CreateProcess(NULL, CmdLine_rar.c_str(),NULL,NULL,false,CREATE_NEW_CONSOLE|HIGH_PRIORITY_CLASS,NULL,NULL, &StartInfo, &ProcInfo) == true)
	{
		if (WaitForSingleObject(ProcInfo.hProcess,1000)== WAIT_TIMEOUT)
		{
			CloseHandle(ProcInfo.hProcess);
		}
		TerminateProcess(ProcInfo.hProcess, 0);
	}else
	{ShowMessage("������");}


}

void Archiv::clearPutDir()
{
	if(putDir == "")
	{
		char buffer[1000];
		GetCurrentDirectory(sizeof(buffer),buffer);
		AnsiString DefaultDir = buffer;
		DefaultDir = DefaultDir+"\\res";
		Dir.Delete(DefaultDir,true);
	}else
	{
		Dir.Delete(putDir,true);
	}
}
#pragma package(smart_init)
