//---------------------------------------------------------------------------

#pragma hdrstop

#include "archiv.h"
//---------------------------------------------------------------------------


Archiv::Archiv()
{
	//! Получаем текущую директорию (в которой выполняется exe)
	char buffer[1000];
	GetCurrentDirectory(sizeof(buffer),buffer);
	setDefaultDir(buffer); // Устанавливаем дефолтную директорию
}

/*!

	en: funcktion extracting filse(recursion) in current directory ru: Функция распаковки файлов(рекурсивной) в указанном каталоге.
	en: first argument: Path to current files 					   ru: первый аргумент: Путь до файлов(Папка, где лежат все файлы)
	en: Second argument: Path where to put the file                ru: второй аргумент: Путь куда положить распакованные файлы
*/
void Archiv::ExtractFiles(AnsiString CurDir,AnsiString putDir)
{
	ExtractFilesAll(CurDir,putDir);                             //! распаковка архивов,папок, файлов в указанный каталог
	ExtractFolderAndArchiv(putDir,putDir);                      //! Распаковка всех вложенностей папок и архивов
	ExtractFilesTxt(CurDir,putDir); 							//! Копирует все файлы txt из cDir в pDir
}

void Archiv::ExtractFolderAndArchiv(AnsiString CurDir,AnsiString putDir)
{
	ExtractFolder(putDir,putDir);                               //! Распаковываем содержимое папки в указанный каталог
	ExtractFilesArchiv(putDir,putDir);                          //! Распаковываем файлы в указанном каталоге

	//Если после распаковки архивов остались папки
	TStringDynArray list = TDirectory::GetDirectories(CurDir);
	if( list.Length != 0)
	{
    	ExtractFolderAndArchiv(CurDir,putDir);
	}
}

/*!
	Распаковка архивов, перенос папок и файлов(нужного расширения) в putDir
*/
void Archiv::ExtractFilesAll(AnsiString CurDir,AnsiString putDir)
{
	AnsiString cDir = CurDir; //! Запоминаем указанную директорию
	AnsiString CmdLine_7z, CmdLine_zip, CmdLine_rar;

	STARTUPINFO StartInfo = {sizeof(TStartupInfo)};
	PROCESS_INFORMATION ProcInfo;
	LPCSTR t;
	StartInfo.cb= sizeof(StartInfo);
	StartInfo.dwFlags = STARTF_USESHOWWINDOW;
	StartInfo.wShowWindow= SW_HIDE;

	CmdLine_7z = DefaultDir + "\\7z\\7za.exe x " + cDir +"\\*.7z -o" + putDir;
	CmdLine_zip = DefaultDir + "\\7z\\7za.exe x " + cDir +"\\*.zip -o" + putDir;
	CmdLine_rar = DefaultDir + "\\WinRar\\Rar.exe x " + cDir +"\\*.rar " + putDir;

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
		ShowMessage("Ошибка");

	//! Для .rar
	if(CreateProcess(NULL, CmdLine_rar.c_str(),NULL,NULL,false,CREATE_NEW_CONSOLE|HIGH_PRIORITY_CLASS,NULL,NULL, &StartInfo, &ProcInfo) == true)
	{
		if (WaitForSingleObject(ProcInfo.hProcess,10000)== WAIT_TIMEOUT)
		{
			CloseHandle(ProcInfo.hProcess);
		}
		TerminateProcess(ProcInfo.hProcess, 0);
	}else
		ShowMessage("Ошибка");

	ExtractFolderAll(CurDir,putDir); //! Экспорт папок из файла

}

void Archiv::ExtractFilesArchiv(AnsiString CurDir,AnsiString putDir)
{

	AnsiString cDir = CurDir; //! Запоминаем указанную директорию
	AnsiString CmdLine_7z, CmdLine_zip, CmdLine_rar;

	STARTUPINFO StartInfo = {sizeof(TStartupInfo)};
	PROCESS_INFORMATION ProcInfo;
	LPCSTR t;
	StartInfo.cb = sizeof(StartInfo);
	StartInfo.dwFlags = STARTF_USESHOWWINDOW;
	StartInfo.wShowWindow = SW_HIDE;

	bool check = false;

	AnsiString zip = CurDir+"\*.zip";
	done = findfirst( zip.c_str(), &f, 0);
	while(!done)
	{
		zip =  CurDir + AnsiString(f.ff_name);
		CmdLine_zip = DefaultDir + "\\7z\\7za.exe x " + zip +" -r -o" + putDir;

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

		DeleteFile(zip);

		check = true;
		done = findnext(&f);
	}

	AnsiString SevenZ = CurDir+"\*.7z";
	done = findfirst( SevenZ.c_str(), &f, 0);
	while(!done)
	{
		SevenZ =  CurDir + AnsiString(f.ff_name);
		CmdLine_7z = DefaultDir + "\\7z\\7za.exe x " + SevenZ +" -r -o" + putDir;

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

		DeleteFile(SevenZ);

		check = true;
		done = findnext(&f);
	}

	AnsiString rar = CurDir+"\*.rar";
	done = findfirst( rar.c_str(), &f, 0);
	while(!done)
	{
		rar =  CurDir + AnsiString(f.ff_name);
		CmdLine_rar = DefaultDir + "\\WinRar\\Rar.exe x " + rar +" -r " + putDir;

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

		DeleteFile(rar);

		check = true;
		done = findnext(&f);
	}

	if(check == true)
	{
		ExtractFilesArchiv(putDir,putDir);
	}


}

void Archiv::ExtractFolder(AnsiString cDir,AnsiString pDir)
{
	AnsiString inStr,outStr;
	TStringDynArray list = TDirectory::GetDirectories(cDir);
	if( list.Length != 0)
	{
		for(int i = 0; i < list.Length; i++)
		{
			TStringDynArray list_f = TDirectory::GetDirectories(list[i]);
			if( list.Length != 0)
			{
				ExtractFolder(list[i],pDir);
			}
			AnsiString s = list[i]+"\\*.*";
			done = findfirst( s .c_str(), &f, 0);
			while(!done)
			{
				inStr =  list[i]+ "\\" + AnsiString(f.ff_name);
				outStr = pDir + AnsiString(f.ff_name);
				MoveFile(inStr.c_str(),outStr.c_str());
				done = findnext(&f);
			}
			Dir.Delete(list[i],true);
		}
	}
}

//! Копирует все папки из директории CurDir в
void Archiv::ExtractFolderAll(AnsiString CurDir,AnsiString putDir)
{
	TStringDynArray list = TDirectory::GetDirectories(CurDir);
	if( list.Length != 0)
	{
		for(int i = 0; i < list.Length; i++)
		{
			copy(list[i],putDir);
		}
	}
}

//! Копирует все файлы txt из cDir в pDir
void Archiv::ExtractFilesTxt(AnsiString cDir, AnsiString pDir)
{
	AnsiString inStr = cDir+"\\*.txt";
	AnsiString outStr;
	done = findfirst( inStr.c_str(), &f, 0);
	while(!done)
	{
		outStr = pDir+ "\\" + AnsiString(f.ff_name);
		MoveFile(inStr.c_str(),outStr.c_str());
		done = findnext(&f);
	}
}

//Копирует из одной диретории в другую
void Archiv::copy(AnsiString FileSource, AnsiString FileDestan)
{
	char cFrom[MAX_PATH]={0};
	strcpy(cFrom,FileSource.c_str());

	SHFILEOPSTRUCT fos;
	memset(&fos,0,sizeof(SHFILEOPSTRUCT));
	fos.hwnd = Application->Handle;
	fos.wFunc = FO_COPY;
	fos.pFrom = cFrom;
	fos.pTo = FileDestan.c_str();
	fos.fFlags = FOF_ALLOWUNDO | FOF_NOCONFIRMMKDIR;
	SHFileOperation(&fos);
}

//! Удаляет все файлы .docx
void Archiv::deleteDocx()
{
	//! Удаляем все doc
	AnsiString s = putDir+"\*.docx";
	done = findfirst( s.c_str(), &f, 0);
	while(!done)
	{
		s =  putDir + AnsiString(f.ff_name);
		DeleteFile(s);
		done = findnext(&f);
	}
}

//! Удаляет все файлы .doc
void Archiv::deleteDoc()
{
	AnsiString s = putDir+"\*.doc";
	done = findfirst( s.c_str(), &f, 0);
	while(!done)
	{
		s =  putDir + AnsiString(f.ff_name);
		DeleteFile(s);
		done = findnext(&f);
	}
}

//! Удаляет все файлы .pdf
void Archiv::deletePdf()
{
	AnsiString s = putDir+"\*.pdf";
	done = findfirst( s.c_str(), &f, 0);
	while(!done)
	{
		s =  putDir + AnsiString(f.ff_name);
		DeleteFile(s);
		done = findnext(&f);
	}
}

//! Удаляем все файлы .rar
void Archiv::deleteRar()
{
	//! Удаляем все rar
	AnsiString s = putDir+"\*.rar";
	done = findfirst( s.c_str(), &f, 0);
	while(!done)
	{
		s =  putDir + AnsiString(f.ff_name);
		DeleteFile(s);
		done = findnext(&f);
	}
}

//! Удаляем все файлы .zip
void Archiv::deleteZip()
{
	//! Удаляем все zip
	AnsiString s = putDir+"\*.zip";
	done = findfirst( s.c_str(), &f, 0);
	while(!done)
	{
		s =  putDir + AnsiString(f.ff_name);
		DeleteFile(s);
		done = findnext(&f);
	}
}

//! Удаляем все файлы .7z
void Archiv::delete7z()
{
	//! Удаляем все rar
	AnsiString s = putDir+"\*.7z";
	done = findfirst( s.c_str(), &f, 0);
	while(!done)
	{
		s =  putDir + AnsiString(f.ff_name);
		DeleteFile(s);
		done = findnext(&f);
	}
}


/*!
	Удаляет все файлы из putDir
*/
void Archiv::deleteAllFiles()
{
	struct ffblk f;
	register int done;

	//! Удаляем все PDF
	AnsiString s = putDir+"\*.*";
	done = findfirst( s.c_str(), &f, 0);
	while(!done)
	{
		s =  putDir + AnsiString(f.ff_name);
		DeleteFile(s);
		done = findnext(&f);
	}
}

#pragma package(smart_init)
