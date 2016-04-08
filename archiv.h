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
	bool ck;
public:
	Archiv() { ck = true;}
	~Archiv() {}
	void ExtractFiles(AnsiString CDir,AnsiString pDir); //! ���������� ������ � ��������� �����
	void putCurDir(AnsiString cDir){ curDir = cDir; }
	void putPutDir(AnsiString cDir){ putDir = cDir; }
	AnsiString getCurDir() { return curDir; }
	AnsiString getPutDir() { return putDir; }

	void setCK(bool k) { ck = k; } 						//! ���������� �������� ck
	void clearPutDir();									//! �������� putDir
};
#endif
