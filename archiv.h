//---------------------------------------------------------------------------

#ifndef archivH
#define archivH
#include <vcl.h>

//---------------------------------------------------------------------------
class Archiv
{
private:
	AnsiString curDir;											//! ������� ����������, ��� ����� �����(������� ������ ������������)
	AnsiString putDir;      									//! ����������, ���� �������� ������������� �����
public:
	void ExtractFiles(AnsiString CDir,AnsiString pDir); //! ���������� ������ � ��������� �����
	void putCurDir(AnsiString cDir){ curDir = cDir; }
	void putPutDir(AnsiString cDir){ putDir = cDir; }
	AnsiString getCurDir() { return curDir; }
	AnsiString getPutDir() { return putDir; }
};
#endif
