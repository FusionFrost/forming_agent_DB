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
	char buffer[1000];
	GetCurrentDirectory(sizeof(buffer),buffer);
	createINI( AnsiString(buffer) );

	EditShow();

}
__fastcall TSetting::~TSetting()
{

}

//---------------------------------------------------------------------------
void __fastcall TSetting::Pdf2TxtButtonClick(TObject *Sender)
{
	if(OpenTextFileDialog1->Execute())
	{
		PathToPdfToTxtConvector = OpenTextFileDialog1->FileName;
		if(PathToWinrar != NULL)
		{
			addToIni("SETTINGS","PDFTOTXT",PathToPdfToTxtConvector);
			PDF2TXTEdit->Text = PathToPdfToTxtConvector;
		}
	}

}
//---------------------------------------------------------------------------
void __fastcall TSetting::Button2Click(TObject *Sender)
{

	if(PathToPdfToTxtConvector == "")
	{
		ShowMessage("Ошибка: Укажите путь до Pdfconvertor");
	}else
	if(PathTo7Zip == "")
	{
		ShowMessage("Ошибка: Укажите путь до 7zip");
	}else
    if(PathToWinrar == "")
	{
		ShowMessage("Ошибка: Укажите путь до Winrar");
	}else
	{
    	Setting->Close();
	}

}
//---------------------------------------------------------------------------

void __fastcall TSetting::SevenZipButtonClick(TObject *Sender)
{
	if(OpenTextFileDialog1->Execute())
	{
		PathTo7Zip = OpenTextFileDialog1->FileName;
		if(PathToWinrar != NULL)
		{
			addToIni("SETTINGS","7ZIP",PathTo7Zip);
			SEVENZIPEdit->Text = PathTo7Zip;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TSetting::WinrarButtonClick(TObject *Sender)
{
	if(OpenTextFileDialog1->Execute())
	{
		PathToWinrar = OpenTextFileDialog1->FileName;
		if(PathToWinrar != NULL)
		{
			addToIni("SETTINGS","WINRAR",PathToWinrar);
			WINRAREdit->Text = PathToWinrar;
		}
	}
}

void TSetting::createINI(AnsiString dir)
{
	AnsiString s = dir + "\\options.ini";	//! Путь до options.ini
	Ini = new TIniFile(s);                  //! Создает новый ini или подключается к существующему
	readIni(); 								//! Считываем значения из настроек
}
void TSetting::addToIni(AnsiString Unit,AnsiString Object, AnsiString value)
{
	Ini->WriteString(Unit,Object,value);
}
void TSetting::readIni()
{
	PathToPdfToTxtConvector = Ini->ReadString("SETTINGS","PDFTOTXT","");
	PathTo7Zip = Ini->ReadString("SETTINGS","7ZIP","");
	PathToWinrar = Ini->ReadString("SETTINGS","WINRAR","");

	if(PathToPdfToTxtConvector == "" | PathTo7Zip == "" | PathToWinrar == "")
	{
		Setting->Show();
	}
}

void TSetting::EditShow()
{
	//! Отображение Edit
	PDF2TXTEdit->Text = PathToPdfToTxtConvector;
	SEVENZIPEdit->Text = PathTo7Zip;
	WINRAREdit->Text = PathToWinrar;
}

//---------------------------------------------------------------------------
