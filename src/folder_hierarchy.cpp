#include "folder_hierarchy.h"
// for handling image
#include <wx/image.h>

namespace fs = std::experimental::filesystem;

int folder_hierarchy::numberOfPhotos()
{
	int counter = 0;
	for (fs::recursive_directory_iterator end, dir(baseFolder); dir != end; ++dir)
	{
		fs::path pathObj(*dir);
		if (in_array(pathObj.extension().string()))
			counter++;
	}
	return counter;
}

bool folder_hierarchy::in_array(const std::string &extension)
{
	return std::find(validExtensions.begin(), validExtensions.end(), extension) != validExtensions.end();
}

void folder_hierarchy::imageHandler(const std::string& source, const std::string& destination)
{
	std::cout << "FROM: " << source << std::endl;
	std::cout << "TO: " << destination << std::endl;
	/*
		DZIALANIA NA OBRAZIE
		narazie skaluje do max 64 px
	*/
	// handlery
	wxInitAllImageHandlers();

	// obraz
	wxImage image;
	if (image.LoadFile(source)) {
		// obraz jest wertykalny (wyzszy niz szerszy)
		if (image.GetHeight() > image.GetWidth()) {
			// wspolczynnik 
			double ratio = static_cast<double> (image.GetWidth()) / static_cast<double> (image.GetHeight());
			image.Rescale(ratio * 64, 64);
		}
		// obraz jest horyzontalny
		else {
			// wspolczynnik
			double ratio = static_cast<double> (image.GetHeight()) / static_cast<double> (image.GetWidth());
			image.Rescale(64, ratio * 64);
		}
	}
	try
	{
		if(automaticMode) // || strzalka do gory???
		{
			/* stare
			fs::copy_file(source, destination);
			*/

			// zapis do pliku
			image.SaveFile(destination);
			std::cout << "NUMBER: " << ++statusCounter << std::endl;
		}
	}
	catch (fs::filesystem_error& e)
	{
		std::cout << "Can't copy photo - " <<  e.what() << std::endl;
	}
}

void folder_hierarchy::createContactSheet(const std::string& place)
{
	wxInitAllImageHandlers();

	// rozmiar komorki
	int cell_size = 128;

	wxImage image(5 * cell_size, 8 * cell_size);
	unsigned char* image_data = image.GetData();
	wxImage image_tmp;

	std::cout << "STYKOWKA" << std::endl;
	for (int i = 0; i < photosInFolder.size(); i++) {
		// i >= 40 bo jest 5 x 8
		// jakby bylo wiecej zdjec to bedzie tylko jedna stykowka z 40 zdjeciami
		if (i >= 40)
			break;

		std::cout << photosInFolder[i] << std::endl; // wypisuje sciezki do kolejnych zdjec
		image_tmp.LoadFile(photosInFolder[i]);

		if (image_tmp.GetHeight() > image_tmp.GetWidth()) {
			double ratio = static_cast<double> (image_tmp.GetWidth()) / static_cast<double> (image_tmp.GetHeight());
			image_tmp.Rescale(ratio * cell_size, cell_size);
		}
		else {
			double ratio = static_cast<double> (image_tmp.GetHeight()) / static_cast<double> (image_tmp.GetWidth());
			image_tmp.Rescale(cell_size, ratio * cell_size);
		}
		// dodaje padding zeby bylo latwiej - resize dodaje obramowanie jesli obrazek jest mniejszy
		image_tmp.Resize(wxSize(cell_size, cell_size), wxPoint(0, 0), 0, 0, 0);

		unsigned char* image_data_tmp = image_tmp.GetData();

		int row = static_cast<int> (i / 5);
		for (int y = 0; y < image_tmp.GetHeight(); y++)
			for (int x = 0; x < image_tmp.GetWidth(); x++) {
				// przesuniecie o rzad (5 obrazkow) +
				// przesuniecie o obrazek (do nastepnej komorki w rzedzie) +
				// przesuniecie na konkretne piksele

				// R
				image_data[row * cell_size * cell_size * 5 * 3 + (i % 5) * cell_size * 3 + y * cell_size * 3 * 5 + x * 3 + 0] = image_data_tmp[cell_size * y * 3 + x * 3 + 0];
				// G
				image_data[row * cell_size * cell_size * 5 * 3 + (i % 5) * cell_size * 3 + y * cell_size * 3 * 5 + x * 3 + 1] = image_data_tmp[cell_size * y * 3 + x * 3 + 1];
				// B
				image_data[row * cell_size * cell_size * 5 * 3 + (i % 5) * cell_size * 3 + y * cell_size * 3 * 5 + x * 3 + 2] = image_data_tmp[cell_size * y * 3 + x * 3 + 2];
			}
	}
	image.SaveFile(place + "_stykowka.jpg");
}

void folder_hierarchy::copyHierarchy()
{
	for (auto& p : fs::directory_iterator(baseFolder))
	{
		if (!fs::is_directory(p) && in_array(p.path().filename().extension().string()))
		{
			imageHandler(p.path().string(), newFolder + "\\" + p.path().filename().string());
			photosInFolder.push_back(p.path().string());
		}
	}
	if (photosInFolder.size() && contactSheetFlag)
		createContactSheet(newFolder);

	for (fs::recursive_directory_iterator end, dir(baseFolder); dir != end; ++dir)
	{
		fs::path pathObj(*dir);
		std::string tempLocation = newFolder + "\\" + dir->path().string().substr(baseFolder.length() + 1);
		if (fs::is_directory(pathObj))
		{
			photosInFolder.clear();
			for (auto& p : fs::directory_iterator(*dir))
			{
				if (!fs::is_directory(p) && in_array(p.path().filename().extension().string()))
				{
					fs::create_directories(tempLocation);
					imageHandler(p.path().string(), tempLocation + "\\" + p.path().filename().string());
					photosInFolder.push_back(p.path().string());
				}
			}
			if (photosInFolder.size() && contactSheetFlag)
				createContactSheet(tempLocation);
		}
	}
}
