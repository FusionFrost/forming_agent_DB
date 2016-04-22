//---------------------------------------------------------------------------

#pragma hdrstop

#include "doc2txt.h"

//! Конвектор преобразует файлы Microsoft Word в pdf
void doc2txt::convert(AnsiString WordFile,AnsiString PathPutTxt)
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
		AnsiString str = AnsiString(s +" /cs 3000 /i \"" + WordFile + "\" /o \"" + PathPutTxt + "\" /pto 0");

		if(CreateProcess(NULL, str.c_str(),NULL,NULL,false,CREATE_NEW_CONSOLE|HIGH_PRIORITY_CLASS,NULL,NULL, &StartInfo, &ProcInfo) == true)
		{
			if (WaitForSingleObject(ProcInfo.hProcess,10000)== WAIT_TIMEOUT)
			{
				CloseHandle(ProcInfo.hProcess);
			}
			TerminateProcess(ProcInfo.hProcess, 0);
		}else
		{ShowMessage("Ошибка: Не может конвертировать из WORD в PDF");}
		}
}

void doc2txt::convertPro(AnsiString WordFile,AnsiString PathPutTxt)
{
	TStringList* word=new TStringList;
	String filename = WordFile;
	Variant  vVarApp,vVarDoc,vVarParagraphs,vVarParagraph;
	AnsiString resolution = ExtractFileExt(filename);
	AnsiString str = StringReplace( ExtractFileName(filename),resolution,"",TReplaceFlags()<< rfReplaceAll << rfIgnoreCase);

	try
	{
		vVarApp=CreateOleObject("Word.Application");
	}
	catch(...)
	{
		MessageBox(0, "Не удачно получилось открыть Word", "Внимание", MB_OK);
		return;
	}

	vVarApp.OlePropertySet("Visible",false);
	vVarDoc = vVarApp.OlePropertyGet("Documents");
	vVarDoc.OleProcedure("Open", StringToOleStr(filename));
	vVarDoc = vVarDoc.OleFunction("Item",1);
	vVarDoc.OleProcedure("Activate");
	String s = vVarDoc.OlePropertyGet("Content").OlePropertyGet("Text");
	word->Add(s);
	word->SaveToFile( PathPutTxt + str +".txt" );
	vVarApp.OleProcedure("Quit");
	delete word;
}

//---------------------------------------------------------------------------
#pragma package(smart_init)
