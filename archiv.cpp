//---------------------------------------------------------------------------

#pragma hdrstop

#include "archiv.h"
//---------------------------------------------------------------------------


Archiv::Archiv()
{
	//! Получаем текущую директорию (в которой выполняется exe)
	char buffer[1000];
	GetCurrentDirectory(sizeof(buffer),buffer);
	setDefaultDir(buffer);
}

/*!

	en: funcktion extracting filse(recursion) in current directory ru: Функция распаковки файлов(рекурсивной) в указанном каталоге.
	en: first argument: Path to current files 					   ru: первый аргумент: Путь до файлов(Папка, где лежат все файлы)
	en: Second argument: Path where to put the file                ru: второй аргумент: Путь куда положить распакованные файлы
*/
void Archiv::ExtractFiles(AnsiString CurDir,AnsiString putDir)
{
	AnsiString cDir = CurDir; //! Запоминаем указанную директорию
	AnsiString CmdLine_7z, CmdLine_zip, CmdLine_rar;

	STARTUPINFO StartInfo = {sizeof(TStartupInfo)};
	PROCESS_INFORMATION ProcInfo;
	LPCSTR t;
	StartInfo.cb= sizeof(StartInfo);
	StartInfo.dwFlags = STARTF_USESHOWWINDOW;
	StartInfo.wShowWindow= SW_HIDE;

	CmdLine_7z = DefaultDir + "\\7z\\7za.exe x " + cDir +"\\*.7z -r -o" + putDir;
	CmdLine_zip = DefaultDir + "\\7z\\7za.exe x " + cDir +"\\*.zip -r -o" + putDir;
	CmdLine_rar = DefaultDir + "\\WinRar\\Rar.exe x " + cDir +"\\*.rar -r " + putDir;

	//! Для .7z
	if(CreateProcess(NULL, CmdLine_7z.c_str(),NULL,NULL,false,CREATE_NEW_CONSOLE|HIGH_PRIORITY_CLASS,NULL,NULL, &StartInfo, &ProcInfo) == true)
	{
		if (WaitForSingleObject(ProcInfo.hProcess,10000)== WAIT_TIMEOUT)
		{
			CloseHandle(ProcInfo.hProcess);
		}
		TerminateProcess(ProcInfo.hProcess, 0);
	}else
	{ShowMessage("Ошибка");}


	//! Для .zip
	if(CreateProcess(NULL, CmdLine_zip.c_str(),NULL,NULL,false,CREATE_NEW_CONSOLE|HIGH_PRIORITY_CLASS,NULL,NULL, &StartInfo, &ProcInfo) == true)
	{
		if (WaitForSingleObject(ProcInfo.hProcess,10000)== WAIT_TIMEOUT)
		{
			CloseHandle(ProcInfo.hProcess);
		}
		TerminateProcess(ProcInfo.hProcess, 0);
	}else
	{ShowMessage("Ошибка");}

	//! Для .rar
	if(CreateProcess(NULL, CmdLine_rar.c_str(),NULL,NULL,false,CREATE_NEW_CONSOLE|HIGH_PRIORITY_CLASS,NULL,NULL, &StartInfo, &ProcInfo) == true)
	{
		if (WaitForSingleObject(ProcInfo.hProcess,10000)== WAIT_TIMEOUT)
		{
			CloseHandle(ProcInfo.hProcess);
		}
		TerminateProcess(ProcInfo.hProcess, 0);
	}else
	{ShowMessage("Ошибка");}


	TStringDynArray list = TDirectory::GetDirectories(putDir);
	if( list.Length != 0)
	{
		for(int i = 0; i < list.Length; i++)
		{
			ExtractFilesLite(list[i],putDir);
			Dir.Delete(list[i],true);
		}
	}

	 ExtractFilesLite(putDir,putDir);


}

void Archiv::ExtractFilesLite(AnsiString CurDir,AnsiString putDir)
{
	AnsiString cDir = CurDir; //! Запоминаем указанную директорию
	AnsiString CmdLine_7z, CmdLine_zip, CmdLine_rar;

	STARTUPINFO StartInfo = {sizeof(TStartupInfo)};
	PROCESS_INFORMATION ProcInfo;
	LPCSTR t;
	StartInfo.cb= sizeof(StartInfo);
	StartInfo.dwFlags = STARTF_USESHOWWINDOW;
	StartInfo.wShowWindow= SW_HIDE;

	CmdLine_7z = DefaultDir + "\\7z\\7za.exe x " + cDir +"\\*.7z -r -o" + putDir;
	CmdLine_zip = DefaultDir + "\\7z\\7za.exe x " + cDir +"\\*.zip -r -o" + putDir;
	CmdLine_rar = DefaultDir + "\\WinRar\\Rar.exe x " + cDir +"\\*.rar -r " + putDir;

	//! Для .7z
	if(CreateProcess(NULL, CmdLine_7z.c_str(),NULL,NULL,false,CREATE_NEW_CONSOLE|HIGH_PRIORITY_CLASS,NULL,NULL, &StartInfo, &ProcInfo) == true)
	{
		if (WaitForSingleObject(ProcInfo.hProcess,10000)== WAIT_TIMEOUT)
		{
			CloseHandle(ProcInfo.hProcess);
		}
		TerminateProcess(ProcInfo.hProcess, 0);
	}else
	{ShowMessage("Ошибка");}


	//! Для .zip
	if(CreateProcess(NULL, CmdLine_zip.c_str(),NULL,NULL,false,CREATE_NEW_CONSOLE|HIGH_PRIORITY_CLASS,NULL,NULL, &StartInfo, &ProcInfo) == true)
	{
		if (WaitForSingleObject(ProcInfo.hProcess,10000)== WAIT_TIMEOUT)
		{
			CloseHandle(ProcInfo.hProcess);
		}
		TerminateProcess(ProcInfo.hProcess, 0);
	}else
	{ShowMessage("Ошибка");}

	//! Для .rar
	if(CreateProcess(NULL, CmdLine_rar.c_str(),NULL,NULL,false,CREATE_NEW_CONSOLE|HIGH_PRIORITY_CLASS,NULL,NULL, &StartInfo, &ProcInfo) == true)
	{
		if (WaitForSingleObject(ProcInfo.hProcess,10000)== WAIT_TIMEOUT)
		{
			CloseHandle(ProcInfo.hProcess);
		}
		TerminateProcess(ProcInfo.hProcess, 0);
	}else
	{ShowMessage("Ошибка");}

}

void Archiv::clearPutDir()
{
	if(putDir == "")
	{
		Dir.Delete(DefaultDir,true);
	}else
	{
		Dir.Delete(putDir,true);
	}
}

void Archiv::deleteFiles()
{
	struct ffblk f;
	register int done;

	//! Удаляем все PDF
	AnsiString s = putDir+"\*.pdf";
	done = findfirst( s.c_str(), &f, 0);
	while(!done)
	{
		s =  putDir + AnsiString(f.ff_name);
		DeleteFile(s);
		done = findnext(&f);
	}

	//! Удаляем все rar
	s = putDir+"\*.rar";
	done = findfirst( s.c_str(), &f, 0);
	while(!done)
	{
		s =  putDir + AnsiString(f.ff_name);
		DeleteFile(s);
		done = findnext(&f);
	}

	//! Удаляем все zip
	s = putDir+"\*.zip";
	done = findfirst( s.c_str(), &f, 0);
	while(!done)
	{
		s =  putDir + AnsiString(f.ff_name);
		DeleteFile(s);
		done = findnext(&f);
	}

	//! Удаляем все rar
	s = putDir+"\*.7z";
	done = findfirst( s.c_str(), &f, 0);
	while(!done)
	{
		s =  putDir + AnsiString(f.ff_name);
		DeleteFile(s);
		done = findnext(&f);
	}
}
#pragma package(smart_init)
