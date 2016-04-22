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
	DocToTxt = new doc2txt;
	EpubToTxt = new epub2txt;
	HtmlToTxt = new html2txt;
}

__fastcall TfrmMain::~TfrmMain()
{
	delete arv;
	delete PdfToTxt;
	delete DocToTxt;
	delete EpubToTxt;
	delete HtmlToTxt;
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

	arv->deleteAllFiles();									//! Удаляем все файлы в корневой(putdir) папке
	arv->ExtractFiles(arv->getCurDir(),arv->getPutDir()); 	//! Распаковка файлов из архива(папок и файлов)

	callConvertHtmlToTxt();                                 //! Конвертирует все файлы html в pdf (не в txt)
	callConvertEpubToTxt();                                 //! Конвертирует все файлы epub в pdf (не в txt)
	callConvertWordToTxt();                                 //! Конвертирует все файлы word в pdf (не в txt)
	callConvertPdfToTxt(); 									//! Конвертировать все файлы pdf в txt (вызывать всегда в конце)

	//! Удаляем файлы
	arv->deletePdf();
	arv->deleteDocx();
	arv->deleteDoc();
	arv->deleteRar();
	arv->deleteZip();
	arv->delete7z();
}

//! Конвертирует PDF в TXT
void TfrmMain::callConvertPdfToTxt()
{
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

//! Ковертирует EPUB в PDF
void TfrmMain::callConvertEpubToTxt()
{
	AnsiString s = arv->getPutDir()+"\*.epub";
	done = findfirst( s.c_str(), &f, 0);
	while(!done)
	{
		s = arv->getPutDir() + AnsiString(f.ff_name);
		AnsiString sl = arv->getPutDir();
		EpubToTxt->convert(s,sl);
		done = findnext(&f);
	}
}

//! Конвертирует docx/doc в PDF
void TfrmMain::callConvertWordToTxt()
{

	AnsiString s = arv->getCurDir()+"\*.docx";
	done = findfirst( s.c_str(), &f, 0);
	while(!done)
	{
		s = arv->getPutDir() + AnsiString(f.ff_name);
		AnsiString sl = arv->getPutDir();
		DocToTxt->convert(s,sl);
		done = findnext(&f);
	}

	s = arv->getPutDir()+"\*.doc";
	done = findfirst( s.c_str(), &f, 0);
	while(!done)
	{
		s = arv->getPutDir() + AnsiString(f.ff_name);
		AnsiString sl = arv->getPutDir();
		DocToTxt->convert(s,sl);
		done = findnext(&f);
	}

}

//! Конвертирует html в PDF
void TfrmMain::callConvertHtmlToTxt()
{
	AnsiString s = arv->getPutDir()+"\*.html";
	done = findfirst( s.c_str(), &f, 0);
	while(!done)
	{
		s = arv->getPutDir() + AnsiString(f.ff_name);
		AnsiString sl = arv->getPutDir();
		HtmlToTxt->convert(s,sl);
		done = findnext(&f);
	}
}

void __fastcall TfrmMain::MainButtonClick(TObject *Sender)
{
	call();
}

void __fastcall TfrmMain::ToolButton5Click(TObject *Sender)
{
	Setting->Show();
}

void __fastcall TfrmMain::ToolButton1Click(TObject *Sender)
{
	String dir;
	SelectDirectory("Выбор каталога","", dir ); 	//! Выбираем папку
	arv->putCurDir(dir);                            //! Кладем директорию в curDir
}

void __fastcall TfrmMain::ToolButton2Click(TObject *Sender)
{
	String dir;
	SelectDirectory("Выбор каталога","", dir );   	//! Выбираем папку
	arv->putPutDir(dir);
}

