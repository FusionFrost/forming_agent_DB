//---------------------------------------------------------------------------

#ifndef archivH
#define archivH
#include <vcl.h>

//---------------------------------------------------------------------------
class Archiv
{
private:
	AnsiString curDir;											//! Текущая директория, где лежат файлы(Которую укажет пользователь)
	AnsiString putDir;      									//! Директория, куда кладутся распакованные файлы
public:
	void ExtractFiles(AnsiString CDir,AnsiString pDir); //! Распаковка файлов в указанной папке
	void putCurDir(AnsiString cDir){ curDir = cDir; }
	void putPutDir(AnsiString cDir){ putDir = cDir; }
	AnsiString getCurDir() { return curDir; }
	AnsiString getPutDir() { return putDir; }
};
#endif
