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
	arv = new Archiv;
}
void TfrmMain::call()
{
	arv->ExtractFiles(arv->getCurDir(),arv->getPutDir());

}
void __fastcall TfrmMain::Button1Click(TObject *Sender)
{
	String dir;
	SelectDirectory("����� ��������","", dir );
	arv->putCurDir(dir);
}


//---------------------------------------------------------------------------

void __fastcall TfrmMain::Button2Click(TObject *Sender)
{
	String dir;
	SelectDirectory("����� ��������","", dir );
	arv->putPutDir(dir);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Button3Click(TObject *Sender)
{
	call();
}
//---------------------------------------------------------------------------
