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
	arv->clearDir(); //! ������ ����������

	if(arv->getCurDir() == "") //! ���� �� ������� ����������
	{
		arv->putCurDir(arv->getDefaultDir() + "\\Input\\" );
	}
	if(arv->getPutDir() == "")
	{
		arv->putPutDir(arv->getDefaultDir() + "\\Output\\" );
	}

	arv->deleteAllFiles();									//! ������� ��� ����� � ��������� �����
	arv->ExtractFiles(arv->getCurDir(),arv->getPutDir()); 	//! ���������� ������ �� ������

	callConvertPdfToTxt(); 									//! �������������� ��� ����� pdf � txt
	arv->deleteFiles(); 									//! ������� ������ �����( ������� pdf,������)
}

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



//---------------------------------------------------------------------------

void __fastcall TfrmMain::MainButtonClick(TObject *Sender)
{
	call();
}
//---------------------------------------------------------------------------



void __fastcall TfrmMain::ToolButton5Click(TObject *Sender)
{
	Setting->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ToolButton1Click(TObject *Sender)
{
	String dir;
	SelectDirectory("����� ��������","", dir ); 	//! �������� �����
	arv->putCurDir(dir);                            //! ������ ���������� � curDir
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ToolButton2Click(TObject *Sender)
{
	String dir;
	SelectDirectory("����� ��������","", dir );   	//! �������� �����
	arv->putPutDir(dir);
}
//---------------------------------------------------------------------------

