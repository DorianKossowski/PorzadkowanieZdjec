#include "gui_interface.h"
namespace fs = std::experimental::filesystem;


void gui_interface::SelectDirectoryToImport(wxCommandEvent& event)
{
	if (dirDialog->ShowModal() == wxID_OK)
	{
		baseFolder = dirDialog->GetPath();
		photosAmount = numberOfPhotos();
		statusCounter = 0;
		percentageProgress->SetLabel("0 %");
		showProgress->SetValue(0);

		wxClientDC dc(this);
		dc.Clear();
		dc.DrawText(baseFolder, 100, 40);
	}
}

// ustawia flage
void gui_interface::ModeSelect(wxCommandEvent& event)
{
	if (modeChoice->GetSelection() == 0)
	{
		automaticMode = true;
		leftRotation->Enable(false);
		rightRotation->Enable(false);
		nextPhoto->Enable(false);
	}
	else
	{
		automaticMode = false;
		leftRotation->Enable(true);
		rightRotation->Enable(true);
		nextPhoto->Enable(true);
	}
}

// aktualizuje wpisane wartosci
void gui_interface::UpdateThumbnailSize(wxCommandEvent& event)
{
	folder_hierarchy::max_height = wxAtoi(height->GetValue());
	folder_hierarchy::max_width = wxAtoi(width->GetValue());
}

// ustawia poziom kompresji
void gui_interface::SetCompressionLevel(wxScrollEvent& event) {
	compressionLevelValue = compressionLevel->GetValue();
	compression->SetLabel("poziom kompresji (" + std::to_string(100 - compressionLevelValue) + " %)");
}

// glowny punkt programu
void gui_interface::StartOrganizing(wxCommandEvent& event)
{
	if (dirDialog->ShowModal() == wxID_OK)
	{
		if (width->GetValue() == "" && height->GetValue() == "") 
		{
			wxMessageDialog(NULL, "Wprowad\u017A przynajmniej jeden wymiar!", "Uwaga!", wxOK).ShowModal();
		}
		else 
		{
			// blokowanie przyciskow
			dirImport->Enable(false);
			modeChoice->Enable(false);
			height->Enable(false);
			width->Enable(false);
			compressionLevel->Enable(false);
			organizePhotos->Enable(false);
			contactSheet->Enable(false);

			newFolder = dirDialog->GetPath();
			copyHierarchy();
			percentageProgress->SetLabel("DONE");
			showProgress->SetValue(100);

			// odblokowanie przyciskow
			dirImport->Enable(true);
			modeChoice->Enable(true);
			height->Enable(true);
			width->Enable(true);
			compressionLevel->Enable(true);
			organizePhotos->Enable(true);
			contactSheet->Enable(true);
		}
		Repaint_done();
	}
}

// ustawia flage
void gui_interface::AddContactSheet(wxCommandEvent& event)
{
	if (contactSheet->IsChecked())
		contactSheetFlag = true;
	else
		contactSheetFlag = false;
}

// dziala to tak ze ustawia flage, bo wewnatrz imageHandler jest petla ktora
// odswieza ekran dopoki sie nie wcisnie next
// a rotate to tez flagi ktore po prostu obracaja wewnatrz tej petli
void gui_interface::RotateLeft(wxCommandEvent& event) {
	left = true;
}
// koment wyzej
void gui_interface::RotateRight(wxCommandEvent& event) {
	right = true;
}
// koment wyzej
void gui_interface::GoToNextPhoto(wxCommandEvent& event) {
	next = true;
}

void gui_interface::Repaint(wxImage Img) {
	wxClientDC dc(this);
	wxBitmap bitmap(Img);
	dc.Clear();
	dc.DrawText(baseFolder, 100, 40);
	dc.DrawBitmap(bitmap, 450, 50);
	Repaint();
}

void gui_interface::Repaint() {
	showProgress->SetValue(statusCounter * 100 / photosAmount);
	percentageProgress->SetLabel(std::to_string(statusCounter) + " / " + std::to_string(photosAmount)
		+ " (" + std::to_string(statusCounter * 100 / photosAmount) + " %)");
	wxYield();
}

void gui_interface::Repaint_done() {
	wxClientDC dc(this);
	dc.Clear();
	dc.DrawText(baseFolder, 100, 40);
	dc.DrawText("� 2018 credits:", 550, 100);
	dc.DrawText("Gabriela Miedlar", 500, 200);
	dc.DrawText("Dorian Kossowski", 500, 225);
	dc.DrawText("Piotr Kolecki", 500, 250);
}

void gui_interface::copyHierarchy()
{
	// handlery
	wxInitAllImageHandlers();
	statusCounter = 0;

	for (auto& p : fs::directory_iterator(baseFolder))
	{
		if (!fs::is_directory(p) && in_array(p.path().filename().extension().string()))
		{
			imageHandler(p.path().string(), newFolder + "\\" + p.path().filename().string());
			photosInFolder.push_back(p.path().string());
			Repaint();
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
					Repaint();
				}
			}
			if (photosInFolder.size() && contactSheetFlag)
				createContactSheet(tempLocation);
		}
	}
}

void gui_interface::imageHandler(const std::string& source, const std::string& destination)
{
	std::cout << "FROM: " << source << std::endl;
	std::cout << "TO: " << destination << std::endl;

	// obraz
	wxImage image;
	wxImage baseImage;

	// rozmiar wyswietlanego podgladu
	int preview_size = 450;
	
	// jakosc
	wxImageResizeQuality quality;
	if (compressionLevelValue <= 33)
		quality = wxIMAGE_QUALITY_NEAREST;
	else if (compressionLevelValue > 33 && compressionLevelValue < 66)
		quality = wxIMAGE_QUALITY_BILINEAR;
	else if (compressionLevelValue >= 66)
		quality = wxIMAGE_QUALITY_BICUBIC;

	// stosunek
	double ratio = 1;

	if (baseImage.LoadFile(source)) {
		image = baseImage.Copy();
		// obraz musi miec wymiary
		if (image.GetWidth() > 0 && image.GetHeight() > 0) {
			// obraz jest wertykalny (wyzszy niz szerszy)
			if (image.GetHeight() > image.GetWidth()) {
				// wspolczynnik 
				ratio = static_cast<double> (image.GetWidth()) / static_cast<double> (image.GetHeight());
				// rysuje sobie
				Repaint(baseImage.Scale(preview_size * ratio, preview_size));
				// najpierw sprawdzam czy mam wgl wymiary
				if (max_width > 0 && max_height > 0) {
					// nie wiem jak to opisac XD
					// jak mam oba to skaluje do mniejszego
					if (max_width > max_height * ratio)
						image.Rescale(ratio * max_height, max_height, quality);
					else
						image.Rescale(max_width, max_width / ratio, quality);
				}
				// inaczej znaczy ze czegos nie mam
				else if (max_width > 0)
					image.Rescale(max_width, max_width / ratio, quality);
				else if (max_height > 0)
					image.Rescale(max_height * ratio, max_height, quality);
			}
			// obraz jest horyzontalny
			else {
				// wspolczynnik
				ratio = static_cast<double> (image.GetHeight()) / static_cast<double> (image.GetWidth());
				// rysuje sobie
				Repaint(image.Scale(preview_size, preview_size * ratio));
				// najpierw sprawdzam czy mam wgl wymiary
				if (max_width > 0 && max_height > 0) {
					// nie wiem jak to opisac XD
					// jak mam oba to skaluje do mniejszego
					if (max_height > max_width * ratio)
						image.Rescale(max_width, max_width * ratio, quality);
					else
						image.Rescale(max_height / ratio, max_height, quality);
				}
				// inaczej znaczy ze czegos nie mam
				else if (max_width > 0)
					image.Rescale(max_width, max_width * ratio, quality);
				else if (max_height > 0)
					image.Rescale(max_height / ratio, max_height, quality);
			}
		}
	}
	try {
		if (automaticMode) { // || strzalka do gory
			// stare
			// fs::copy_file(source, destination);

			// obraz musi miec wymiary
			if (image.GetWidth() > 0 && image.GetHeight() > 0) {
				// zapis do pliku
				image.SaveFile(destination);
				std::cout << "NUMBER: " << ++statusCounter << std::endl;
			}
		}
		else {
			while (!next) {
				if (right) {
					baseImage = baseImage.Rotate90();
					image = image.Rotate90();
					// odswiez ekran
					if (baseImage.GetWidth() > baseImage.GetHeight())
						Repaint(baseImage.Scale(preview_size, preview_size * ratio));
					else
						Repaint(baseImage.Scale(preview_size * ratio, preview_size));
				}
				else if (left) {
					baseImage = baseImage.Rotate90(false);
					image = image.Rotate90(false);
					// odswiez ekran
					if (baseImage.GetWidth() > baseImage.GetHeight())
						Repaint(baseImage.Scale(preview_size, preview_size * ratio));
					else
						Repaint(baseImage.Scale(preview_size * ratio, preview_size));
				}
				right = false;
				left = false;
				wxYield();
			}
			next = false;
			// obraz musi miec wymiary
			if (image.GetWidth() > 0 && image.GetHeight() > 0) {
				// zapis do pliku
				image.SaveFile(destination);
				std::cout << "NUMBER: " << ++statusCounter << std::endl;
			}
		}
	}
	catch (fs::filesystem_error& e) {
		std::cout << "Can't copy photo - " << e.what() << std::endl;
	}
}

void gui_interface::createContactSheet(const std::string& place)
{
	wxInitAllImageHandlers();

	// rozmiar komorki
	int cell_size = 128;
	// numer stykowki
	int contact_sheet_number = 1;

	wxImage image(5 * cell_size, 8 * cell_size);
	unsigned char* image_data = image.GetData();
	wxImage image_tmp;
	int i;
	
	int step = 0;

	std::cout << "STYKOWKA" << std::endl;
	for (int j = 0; j < photosInFolder.size(); j++) {
		// wypisanie ladne ze sie robi
		if (step == 0) {
			percentageProgress->SetLabel(
				"(" + std::to_string(j) + " / " +
				std::to_string(photosInFolder.size()) + ") " +
				"creating contact sheet");
			step++;
		}
		else if (step == 1) {
			percentageProgress->SetLabel(
				"(" + std::to_string(j) + " / " +
				std::to_string(photosInFolder.size()) + ") " +
				"creating contact sheet.");
			step++;
		}
		else if (step == 2) {
			percentageProgress->SetLabel(
				"(" + std::to_string(j) + " / " +
				std::to_string(photosInFolder.size()) + ") " +
				"creating contact sheet..");
			step++;
		}
		else if (step == 3) {
			percentageProgress->SetLabel(
				"(" + std::to_string(j) + " / " +
				std::to_string(photosInFolder.size()) + ") " +
				"creating contact sheet...");
			step = 0;
		}
		// zeby odswiezyc obraz
		wxYield();

		// sluzy do obliczania pozycji nastepnego obrazka
		i = j % 40;

		// wypisuje sciezki do kolejnych zdjec
		//std::cout << photosInFolder[i] << std::endl;

		// wczytuje po kolei zdjecia
		image_tmp.LoadFile(photosInFolder[j]);

		// sprawdzam wymiary
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

		// jesli przetworzyl juz 40 obrazow to zapisze i jak cos to zapisze nastepne w inne miejsce
		if (i == 39) {
			image.SaveFile(place + "_stykowka" + std::to_string(contact_sheet_number) + ".jpg");
			contact_sheet_number++;
			image.Clear();
		}
	}
	// jesli ma pelne stykowki zeby nie zapisal 2 razy
	if (i != 39)
		image.SaveFile(place + "_stykowka" + std::to_string(contact_sheet_number) + ".jpg");
}
