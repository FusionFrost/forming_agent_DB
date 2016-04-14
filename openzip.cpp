//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "openzip.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ZipForge"
#pragma resource "*.dfm"
TfrmMain *frmMain;
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
    : TForm(Owner)
{
	arv = new Archiv();
	PdfToTxt = new pdf2txt;

}

__fastcall TfrmMain::~TfrmMain()
{
	delete arv;
	delete PdfToTxt;
}


void TfrmMain::call()
{
	arv->clearDir(); //! Чистим директории

	if(arv->getCurDir() == "") //! Если не указали директорию
	{
		arv->putCurDir(arv->getDefaultDir() + "\\Input\\" );
	}
	if(arv->getPutDir() == "")
	{
		arv->putPutDir(arv->getDefaultDir() + "\\Output\\" );
	}
	//arv->clearPutDir();
	arv->ExtractFiles(arv->getCurDir(),arv->getPutDir()); 	//! Распаковка файлов из архива
	callConvertPdfToTxt(); 									//! Конвертировать все файлы pdf в txt
	arv->deleteFiles(); 									//! Удалить лишние файлы( Формата pdf,архивы)
}

void TfrmMain::callConvertPdfToTxt()
{
	struct ffblk f;
	register int done;
	AnsiString s = arv->getPutDir()+"\*.pdf";
	done = findfirst( s.c_str(), &f, 0);
	while(!done)
	{
		s = arv->getPutDir() + AnsiString(f.ff_name);
		AnsiString sl = arv->getPutDir();
		PdfToTxt->convert(s,sl);
		done = findnext(&f);
	}

}
void __fastcall TfrmMain::Button1Click(TObject *Sender)
{
	String dir;
	SelectDirectory("Выбор каталога","", dir ); 	//! Выбираем папку
	arv->putCurDir(dir);                            //! Кладем директорию в curDir
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::Button2Click(TObject *Sender)
{
	String dir;
	SelectDirectory("Выбор каталога","", dir );   	//! Выбираем папку
	arv->putPutDir(dir);                          	//! Кладем директорию в putDir
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Button3Click(TObject *Sender)
{
	call();
}
//---------------------------------------------------------------------------



void __fastcall TfrmMain::ToolButton5Click(TObject *Sender)
{
	Setting->Show();
}
//---------------------------------------------------------------------------

