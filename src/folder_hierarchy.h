#pragma once

#include <experimental/filesystem>
#include <iostream>

class folder_hierarchy
{
public:
	// zwraca ilosc wszystkich zdjec o odpowiednim formacie znajdujacych sie w glab folderu bazowego
	int numberOfPhotos();
	// sprawdza czy zdjecie jest odpowiedniego rozszerzenia
	bool in_array(const std::string &extension);
	// dokonuje operacji na zdjeciu, kopiuje do lokalizacji docelowej
	void imageHandler(const std::string& source, const std::string& destination);
	// tworzy stykowke ze zdjec w danym folderze
	void createContactSheet(const std::string& place);
	// tworzy kopie hierarchii folderow w lokalizacji docelowej
	void copyHierarchy();

protected:
	// sciezka do folderu bazowego
	std::string baseFolder;
	// sciezka folderu docelowego
	std::string newFolder;
	// dopuszczalne formaty zdjec
	std::vector<std::string> validExtensions{ ".jpg", ".jpeg", ".jpe", "jfif", ".bmp" };
	// ilosc wszyskich zdjec, ilosc juz obrobionych zdjec
	int photosAmount, statusCounter;
	// sciezki do zdjec w aktualnym folderze, potrzebne do stykowek
	std::vector<std::string> photosInFolder;

	bool contactSheetFlag, automaticMode;
};
