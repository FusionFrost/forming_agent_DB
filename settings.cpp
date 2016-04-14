//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "settings.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSetting *Setting;
//---------------------------------------------------------------------------
__fastcall TSetting::TSetting(TComponent* Owner)
	: TForm(Owner)
{
	OpenTextFileDialog1->Filter = "Text files (*.exe)|*.EXE";


}
//---------------------------------------------------------------------------
void __fastcall TSetting::Button1Click(TObject *Sender)
{
	if(OpenTextFileDialog1->Execute())
    {
		PathToPdfToTxtConvector = OpenTextFileDialog1->FileName;
	}
}
//---------------------------------------------------------------------------
