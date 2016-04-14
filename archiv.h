//---------------------------------------------------------------------------

#ifndef archivH
#define archivH
#include <vcl.h>

#include <System.IOUtils.hpp> //! ������ � ������������

#include <dos.h>
#include <dir.h>
//---------------------------------------------------------------------------
class Archiv
{
private:
	AnsiString curDir;											//! ������� ����������, ��� ����� �����(������� ������ ������������)
	AnsiString putDir;      									//! ����������, ���� �������� ������������� �����
	AnsiString DefaultDir;
	TDirectory Dir;
public:
	Archiv();
	~Archiv() {}
	void ExtractFiles(AnsiString CDir,AnsiString pDir); //! ���������� ������ � ��������� �����
	void ExtractFilesLite(AnsiString CDir,AnsiString pDir); //! ���������� ������ � ��������� �����
	void putCurDir(AnsiString cDir){ curDir = cDir; }
	void putPutDir(AnsiString cDir){ putDir = cDir; }
	AnsiString getCurDir() { return curDir; }
	AnsiString getPutDir() { return putDir; }
	AnsiString getDefaultDir() { return DefaultDir; }
	void setDefaultDir(AnsiString D) { DefaultDir = D; }
	void clearDir(){ curDir = ""; putDir = ""; }
	void deleteFiles();

	void clearPutDir();									//! �������� putDir
};
#endif
