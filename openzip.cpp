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
	//arv->clearPutDir();
	arv->ExtractFiles(arv->getCurDir(),arv->getPutDir()); 	//! ���������� ������ �� ������
	callConvertPdfToTxt(); 									//! �������������� ��� ����� pdf � txt
	arv->deleteFiles(); 									//! ������� ������ �����( ������� pdf,������)
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
	SelectDirectory("����� ��������","", dir ); 	//! �������� �����
	arv->putCurDir(dir);                            //! ������ ���������� � curDir
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::Button2Click(TObject *Sender)
{
	String dir;
	SelectDirectory("����� ��������","", dir );   	//! �������� �����
	arv->putPutDir(dir);                          	//! ������ ���������� � putDir
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

