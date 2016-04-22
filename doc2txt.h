//---------------------------------------------------------------------------

#ifndef doc2txtH
#define doc2txtH

#include <stdio.h>
#include <windows.h>
#include <ComObj.hpp>

#include "settings.h"

class doc2txt
{
private:

public:
	void convert( AnsiString WordFile,AnsiString PathPutTxt);
	void convertPro(AnsiString WordFile,AnsiString PathPutTxt);
};
//---------------------------------------------------------------------------
#endif
