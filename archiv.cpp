//---------------------------------------------------------------------------

#pragma hdrstop

#include "archiv.h"
//---------------------------------------------------------------------------


Archiv::Archiv()
{
	//! �������� ������� ���������� (� ������� ����������� exe)
	char buffer[1000];
	GetCurrentDirectory(sizeof(buffer),buffer);
	setDefaultDir(buffer); // ������������� ��������� ����������
}

/*!

	en: funcktion extracting filse(recursion) in current directory ru: ������� ���������� ������(�����������) � ��������� ��������.
	en: first argument: Path to current files 					   ru: ������ ��������: ���� �� ������(�����, ��� ����� ��� �����)
	en: Second argument: Path where to put the file                ru: ������ ��������: ���� ���� �������� ������������� �����
*/
void Archiv::ExtractFiles(AnsiString CurDir,AnsiString putDir)
{
	ExtractFilesAll(CurDir,putDir);                             //! ���������� �������,�����, ������ � ��������� �������
	ExtractFolderAndArchiv(putDir,putDir);                      //! ���������� ���� ������������ ����� � �������
	ExtractFilesTxt(CurDir,putDir); 							//! �������� ��� ����� txt �� cDir � pDir
}

void Archiv::ExtractFolderAndArchiv(AnsiString CurDir,AnsiString putDir)
{
	ExtractFolder(putDir,putDir);                               //! ������������� ���������� ����� � ��������� �������
	ExtractFilesArchiv(putDir,putDir);                          //! ������������� ����� � ��������� ��������

	//���� ����� ���������� ������� �������� �����
	TStringDynArray list = TDirectory::GetDirectories(CurDir);
	if( list.Length != 0)
	{
    	ExtractFolderAndArchiv(CurDir,putDir);
	}
}

/*!
	���������� �������, ������� ����� � ������(������� ����������) � putDir
*/
void Archiv::ExtractFilesAll(AnsiString CurDir,AnsiString putDir)
{
	AnsiString cDir = CurDir; //! ���������� ��������� ����������
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

	//! ��� .7z
	if(CreateProcess(NULL, CmdLine_7z.c_str(),NULL,NULL,false,CREATE_NEW_CONSOLE|HIGH_PRIORITY_CLASS,NULL,NULL, &StartInfo, &ProcInfo) == true)
	{
		if (WaitForSingleObject(ProcInfo.hProcess,10000)== WAIT_TIMEOUT)
		{
			CloseHandle(ProcInfo.hProcess);
		}
		TerminateProcess(ProcInfo.hProcess, 0);
	}else
	{ShowMessage("������");}


	//! ��� .zip
	if(CreateProcess(NULL, CmdLine_zip.c_str(),NULL,NULL,false,CREATE_NEW_CONSOLE|HIGH_PRIORITY_CLASS,NULL,NULL, &StartInfo, &ProcInfo) == true)
	{
		if (WaitForSingleObject(ProcInfo.hProcess,10000)== WAIT_TIMEOUT)
		{
			CloseHandle(ProcInfo.hProcess);
		}
		TerminateProcess(ProcInfo.hProcess, 0);
	}else
		ShowMessage("������");

	//! ��� .rar
	if(CreateProcess(NULL, CmdLine_rar.c_str(),NULL,NULL,false,CREATE_NEW_CONSOLE|HIGH_PRIORITY_CLASS,NULL,NULL, &StartInfo, &ProcInfo) == true)
	{
		if (WaitForSingleObject(ProcInfo.hProcess,10000)== WAIT_TIMEOUT)
		{
			CloseHandle(ProcInfo.hProcess);
		}
		TerminateProcess(ProcInfo.hProcess, 0);
	}else
		ShowMessage("������");

	ExtractFolderAll(CurDir,putDir); //! ������� ����� �� �����

}

void Archiv::ExtractFilesArchiv(AnsiString CurDir,AnsiString putDir)
{

	AnsiString cDir = CurDir; //! ���������� ��������� ����������
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

		//! ��� .zip
		if(CreateProcess(NULL, CmdLine_zip.c_str(),NULL,NULL,false,CREATE_NEW_CONSOLE|HIGH_PRIORITY_CLASS,NULL,NULL, &StartInfo, &ProcInfo) == true)
		{
			if (WaitForSingleObject(ProcInfo.hProcess,10000)== WAIT_TIMEOUT)
			{
				CloseHandle(ProcInfo.hProcess);
			}
			TerminateProcess(ProcInfo.hProcess, 0);
		}else
		{ShowMessage("������");}

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

		//! ��� .7z
		if(CreateProcess(NULL, CmdLine_7z.c_str(),NULL,NULL,false,CREATE_NEW_CONSOLE|HIGH_PRIORITY_CLASS,NULL,NULL, &StartInfo, &ProcInfo) == true)
		{
			if (WaitForSingleObject(ProcInfo.hProcess,10000)== WAIT_TIMEOUT)
			{
				CloseHandle(ProcInfo.hProcess);
			}
			TerminateProcess(ProcInfo.hProcess, 0);
		}else
		{ShowMessage("������");}

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

		//! ��� .rar
		if(CreateProcess(NULL, CmdLine_rar.c_str(),NULL,NULL,false,CREATE_NEW_CONSOLE|HIGH_PRIORITY_CLASS,NULL,NULL, &StartInfo, &ProcInfo) == true)
		{
			if (WaitForSingleObject(ProcInfo.hProcess,10000)== WAIT_TIMEOUT)
			{
				CloseHandle(ProcInfo.hProcess);
			}
			TerminateProcess(ProcInfo.hProcess, 0);
		}else
		{ShowMessage("������");}

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

//! �������� ��� ����� �� ���������� CurDir �
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

//! �������� ��� ����� txt �� cDir � pDir
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

//�������� �� ����� ��������� � ������
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

//! ������� ��� ����� .docx
void Archiv::deleteDocx()
{
	//! ������� ��� doc
	AnsiString s = putDir+"\*.docx";
	done = findfirst( s.c_str(), &f, 0);
	while(!done)
	{
		s =  putDir + AnsiString(f.ff_name);
		DeleteFile(s);
		done = findnext(&f);
	}
}

//! ������� ��� ����� .doc
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

//! ������� ��� ����� .pdf
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

//! ������� ��� ����� .rar
void Archiv::deleteRar()
{
	//! ������� ��� rar
	AnsiString s = putDir+"\*.rar";
	done = findfirst( s.c_str(), &f, 0);
	while(!done)
	{
		s =  putDir + AnsiString(f.ff_name);
		DeleteFile(s);
		done = findnext(&f);
	}
}

//! ������� ��� ����� .zip
void Archiv::deleteZip()
{
	//! ������� ��� zip
	AnsiString s = putDir+"\*.zip";
	done = findfirst( s.c_str(), &f, 0);
	while(!done)
	{
		s =  putDir + AnsiString(f.ff_name);
		DeleteFile(s);
		done = findnext(&f);
	}
}

//! ������� ��� ����� .7z
void Archiv::delete7z()
{
	//! ������� ��� rar
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
	������� ��� ����� �� putDir
*/
void Archiv::deleteAllFiles()
{
	struct ffblk f;
	register int done;

	//! ������� ��� PDF
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
