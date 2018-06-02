#include "folder_hierarchy.h"

int folder_hierarchy::max_width = 64;
int folder_hierarchy::max_height = 64;

int folder_hierarchy::compressionLevelValue = 0;

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
