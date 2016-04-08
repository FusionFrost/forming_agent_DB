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
}

__fastcall TfrmMain::~TfrmMain()
{
	delete arv;
}


void TfrmMain::call()
{
	arv->clearPutDir();
	arv->ExtractFiles(arv->getCurDir(),arv->getPutDir());

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

