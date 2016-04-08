//---------------------------------------------------------------------------

#ifndef archivH
#define archivH
#include <vcl.h>

#include <System.IOUtils.hpp> //! Работа с директориями
//---------------------------------------------------------------------------
class Archiv
{
private:
	AnsiString curDir;											//! Текущая директория, где лежат файлы(Которую укажет пользователь)
	AnsiString putDir;      									//! Директория, куда кладутся распакованные файлы
	TDirectory Dir;
public:
	Archiv() {}
	~Archiv() {}
	void ExtractFiles(AnsiString CDir,AnsiString pDir); //! Распаковка файлов в указанной папке
	void ExtractFilesLite(AnsiString CDir,AnsiString pDir); //! Распаковка файлов в указанной папке
	void putCurDir(AnsiString cDir){ curDir = cDir; }
	void putPutDir(AnsiString cDir){ putDir = cDir; }
	AnsiString getCurDir() { return curDir; }
	AnsiString getPutDir() { return putDir; }

	void clearPutDir();									//! Очистить putDir
};
#endif
