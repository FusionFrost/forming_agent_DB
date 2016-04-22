//---------------------------------------------------------------------------

#ifndef archivH
#define archivH
#include <vcl.h>

#include <System.IOUtils.hpp> //! Работа с директориями

#include <dos.h>
#include <dir.h>
//!
//! Класс для распаковки архивов, распаковки папок и файлов
//!
class Archiv
{
private:
	AnsiString curDir;											//! Текущая директория, где лежат файлы(Которую укажет пользователь)
	AnsiString putDir;      									//! Директория, куда кладутся распакованные файлы
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

	void deleteAllFiles();                                      //! Удаляет все файлы
    void deleteDocx();											//! Удаляет все файлы .docx
	void deleteDoc();											//! Удаляет все файлы .doc
	void deletePdf();                                           //! Удаляет все файлы .pdf
	void deleteRar();                                           //! Удаляет все файлы .rar
	void deleteZip();                                           //! Удаляет все файлы .zip
	void delete7z();                                            //! Удаляет все файлы .7z
};
#endif
