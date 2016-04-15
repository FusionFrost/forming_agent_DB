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
#include "Word2pdf.h"
#include "archiv.h"
#include "settings.h"

#include <dos.h>
#include <dir.h>

#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.ImgList.hpp>

//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
	TOpenDialog *OpenDialog1;
	TButton *MainButton;
	TMainMenu *MainMenu;
	TMenuItem *Settings2;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TImageList *ImageList1;
	TToolButton *ToolButton4;
	TToolButton *ToolButton5;
	void __fastcall MainButtonClick(TObject *Sender);
	void __fastcall ToolButton5Click(TObject *Sender);
	void __fastcall ToolButton1Click(TObject *Sender);
	void __fastcall ToolButton2Click(TObject *Sender);

private:	// User declarations
    struct ffblk f;					//! ���������� � �����
	int done;

	void call();
	void callConvertPdfToTxt();
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
