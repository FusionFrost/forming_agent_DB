//---------------------------------------------------------------------------

#ifndef openzipH
#define openzipH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.FileCtrl.hpp>

#include "pdf2txt.h"
#include "archiv.h"

//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components

	TButton *Button1;
	TOpenDialog *OpenDialog1;
	TButton *Button2;
	TButton *Button3;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);

private:	// User declarations
	void call();

public:		// User declarations
	pdf2txt *PdfToTxt;
    Archiv *arv;
	__fastcall TfrmMain(TComponent* Owner);
	__fastcall ~TfrmMain();

};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
