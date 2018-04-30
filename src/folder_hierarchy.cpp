#include "folder_hierarchy.h"

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
	*/
	try
	{
		if(automaticMode) // || strzalka do gory???
		{
			fs::copy_file(source, destination);
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
	std::cout << "STYKOWKA" << std::endl;
	for (int i = 0; i < photosInFolder.size(); i++)
		std::cout << photosInFolder[i] << std::endl; // wypisuje sciezki do kolejnych zdjec
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
