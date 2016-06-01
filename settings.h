//---------------------------------------------------------------------------

#ifndef settingsH
#define settingsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>

#include "IniFiles.hpp"
#include "archiv.h"
#include <iostream>
//---------------------------------------------------------------------------
class TSetting : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TButton *Pdf2TxtButton;
	TLabel *Label1;
	TOpenTextFileDialog *OpenTextFileDialog1;
	TButton *Button2;
	TGroupBox *GroupBox2;
	TGroupBox *GroupBox3;
	TLabel *Label2;
	TLabel *Label3;
	TButton *SevenZipButton;
	TButton *WinrarButton;
	TEdit *PDF2TXTEdit;
	TEdit *WINRAREdit;
	TEdit *SEVENZIPEdit;
	TLabel *Label4;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *Edit3;
	void __fastcall Pdf2TxtButtonClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall SevenZipButtonClick(TObject *Sender);
	void __fastcall WinrarButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TSetting(TComponent* Owner);
	__fastcall ~TSetting();
	AnsiString PathToPdfToTxtConvector;
	AnsiString PathTo7Zip;
	AnsiString PathToWinrar;
	TIniFile *Ini;

	AnsiString getPathToPdfToTxtConvector(){ return PathToPdfToTxtConvector; }
	AnsiString getPathTo7Zip(){ return PathTo7Zip; }
	AnsiString getPathToWinrar(){ return PathToWinrar; }

    void EditShow();
    void addToIni(AnsiString Unit,AnsiString Object, AnsiString value);
	void createINI(AnsiString dir);
	void readIni();
};
//---------------------------------------------------------------------------
extern PACKAGE TSetting *Setting;
//---------------------------------------------------------------------------
#endif
