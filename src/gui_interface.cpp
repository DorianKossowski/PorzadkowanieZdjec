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
	}
}

// ustawia flage
void gui_interface::ModeSelect(wxCommandEvent& event)
{
	if (modeChoice->GetSelection() == 0)
		automaticMode = true;
	else
		automaticMode = false;
}

// aktualizuje wpisane wartosci
void gui_interface::UpdateThumbnailSize(wxCommandEvent& event)
{
	folder_hierarchy::max_height = wxAtoi(height->GetValue());
	folder_hierarchy::max_width = wxAtoi(width->GetValue());
}

void gui_interface::SetCompressionLevel(wxScrollEvent& event)
{

}

// glowny punkt programu
void gui_interface::StartOrganizing(wxCommandEvent& event)
{
	if (dirDialog->ShowModal() == wxID_OK)
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
		percentageProgress->SetLabel("100 %");
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

	// Sprawdzam tylko czy kontrolka jest pusta, trzeba bedzie dopisac warunek zeby wprowadzona wartosc byla liczba.
	if (width->GetValue() == "" && height->GetValue() == "")
	{
		wxMessageDialog(NULL, "Wprowad\u017A stopie\u0144 kompresji!", "Uwaga!", wxOK ).ShowModal();
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


void gui_interface::RotateLeft(wxCommandEvent& event)
{
	//sprawdzam czy jestem w trybie polautomatycznym
	if (modeChoice->GetSelection() == 1)
	{

	}
}

void gui_interface::RotateRight(wxCommandEvent& event)
{
	//sprawdzam czy jestem w trybie polautomatycznym
	if (modeChoice->GetSelection() == 1)
	{

	}
}