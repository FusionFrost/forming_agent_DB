//---------------------------------------------------------------------------

#ifndef archivH
#define archivH
#include <vcl.h>

#include <System.IOUtils.hpp> //! ������ � ������������

#include <dos.h>
#include <dir.h>
//!
//! ����� ��� ���������� �������, ���������� ����� � ������
//!
class Archiv
{
private:
	AnsiString curDir;											//! ������� ����������, ��� ����� �����(������� ������ ������������)
	AnsiString putDir;      									//! ����������, ���� �������� ������������� �����
	AnsiString DefaultDir;
	TDirectory Dir;

	struct ffblk f;
	int done;

public:
	Archiv();
	~Archiv() {}

	void ExtractFiles(AnsiString CDir,AnsiString pDir); 				//!
	void ExtractFilesAll(AnsiString CDir,AnsiString pDir); 				//!
	void ExtractFilesArchiv(AnsiString CurDir,AnsiString putDir); 		//!
	void ExtractFilesTxt(AnsiString cDir, AnsiString pDir);             //!
	void ExtractFolderAndArchiv(AnsiString CurDir,AnsiString putDir);   //!
	void ExtractFolder(AnsiString cDir,AnsiString pDir);                //!
	void ExtractFolderAll(AnsiString CurDir,AnsiString putDir);         //!

	void putCurDir(AnsiString cDir){ curDir = cDir; }
	void putPutDir(AnsiString cDir){ putDir = cDir; }
    void setDefaultDir(AnsiString D) { DefaultDir = D; }
	void clearDir(){ curDir = ""; putDir = ""; }
	void copy(AnsiString FileSource, AnsiString FileDestan);

	AnsiString getCurDir() { return curDir; }
	AnsiString getPutDir() { return putDir; }
	AnsiString getDefaultDir() { return DefaultDir; }

	void deleteAllFiles();                                      //! ������� ��� �����
    void deleteDocx();											//! ������� ��� ����� .docx
	void deleteDoc();											//! ������� ��� ����� .doc
	void deletePdf();                                           //! ������� ��� ����� .pdf
	void deleteRar();                                           //! ������� ��� ����� .rar
	void deleteZip();                                           //! ������� ��� ����� .zip
	void delete7z();                                            //! ������� ��� ����� .7z
};
#endif
