//---------------------------------------------------------------------------

#ifndef archivH
#define archivH
#include <vcl.h>

#include <System.IOUtils.hpp> //! Работа с директориями

#include <dos.h>
#include <dir.h>
//---------------------------------------------------------------------------
class Archiv
{
private:
	AnsiString curDir;											//! Текущая директория, где лежат файлы(Которую укажет пользователь)
	AnsiString putDir;      									//! Директория, куда кладутся распакованные файлы
	AnsiString DefaultDir;
	TDirectory Dir;
public:
	Archiv();
	~Archiv() {}
	void ExtractFiles(AnsiString CDir,AnsiString pDir); //! Распаковка файлов в указанной папке
	void ExtractFilesLite(AnsiString CDir,AnsiString pDir); //! Распаковка файлов в указанной папке
	void putCurDir(AnsiString cDir){ curDir = cDir; }
	void putPutDir(AnsiString cDir){ putDir = cDir; }
	AnsiString getCurDir() { return curDir; }
	AnsiString getPutDir() { return putDir; }
	AnsiString getDefaultDir() { return DefaultDir; }
	void setDefaultDir(AnsiString D) { DefaultDir = D; }
	void clearDir(){ curDir = ""; putDir = ""; }
	void deleteFiles();

	void clearPutDir();									//! Очистить putDir
};
#endif
