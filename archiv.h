//---------------------------------------------------------------------------

#ifndef archivH
#define archivH
#include <vcl.h>

#include <System.IOUtils.hpp> //! ������ � ������������
//---------------------------------------------------------------------------
class Archiv
{
private:
	AnsiString curDir;											//! ������� ����������, ��� ����� �����(������� ������ ������������)
	AnsiString putDir;      									//! ����������, ���� �������� ������������� �����
	TDirectory Dir;
public:
	Archiv() {}
	~Archiv() {}
	void ExtractFiles(AnsiString CDir,AnsiString pDir); //! ���������� ������ � ��������� �����
	void ExtractFilesLite(AnsiString CDir,AnsiString pDir); //! ���������� ������ � ��������� �����
	void putCurDir(AnsiString cDir){ curDir = cDir; }
	void putPutDir(AnsiString cDir){ putDir = cDir; }
	AnsiString getCurDir() { return curDir; }
	AnsiString getPutDir() { return putDir; }

	void clearPutDir();									//! �������� putDir
};
#endif
