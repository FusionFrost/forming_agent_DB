//---------------------------------------------------------------------------

#ifndef pdf2txtH
#define pdf2txtH


#include <stdio.h>
#include <windows.h>
#include "zlib.h"

class pdf2txt
{
private:

public:
	int Convert(char *pathPdf,char *pathTxt);
	size_t FindStringInBuffer(char* buffer, char* search, size_t buffersize);
	float ExtractNumber(const char* search, int lastcharoffset);
	bool seen2(const char* search, char* recent);
	void ProcessOutput(FILE* file, char* output, size_t len);
};
//---------------------------------------------------------------------------
#endif
