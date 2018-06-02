#pragma once

#include <experimental/filesystem>
#include <iostream>

// for handling image
// for yeld()
#include <wx/wx.h>

class folder_hierarchy
{
public:
	// zwraca ilosc wszystkich zdjec o odpowiednim formacie znajdujacych sie w glab folderu bazowego
	int numberOfPhotos();
	// sprawdza czy zdjecie jest odpowiedniego rozszerzenia
	bool in_array(const std::string &extension);

protected:
	// sciezka do folderu bazowego
	std::string baseFolder;
	// sciezka folderu docelowego
	std::string newFolder;
	// dopuszczalne formaty zdjec
	std::vector<std::string> validExtensions{ ".jpg", ".jpeg", ".jpe", ".jfif", ".bmp", ".JPG", ".JPEG" };
	// ilosc wszyskich zdjec, ilosc juz obrobionych zdjec
	int photosAmount, statusCounter;
	// sciezki do zdjec w aktualnym folderze, potrzebne do stykowek
	std::vector<std::string> photosInFolder;
	// rozmiary
	static int max_width;
	static int max_height;
	// poziom kompresji
	static int compressionLevelValue;

	bool contactSheetFlag = false;
	bool automaticMode = true;
};
