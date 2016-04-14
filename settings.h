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


//---------------------------------------------------------------------------
class TSetting : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TButton *Button1;
	TLabel *Label1;
	TOpenTextFileDialog *OpenTextFileDialog1;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	AnsiString PathToPdfToTxtConvector;

	AnsiString getPathToPdfToTxtConvector(){ return PathToPdfToTxtConvector; }
	__fastcall TSetting(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSetting *Setting;
//---------------------------------------------------------------------------
#endif
