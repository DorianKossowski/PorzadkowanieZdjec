#include "gui_interface.h"


void gui_interface::SelectDirectoryToImport(wxCommandEvent& event)
{
	if (dirDialog->ShowModal() == wxID_OK)
	{}
}

void gui_interface::ModeSelect(wxCommandEvent& event)
{

}

void gui_interface::UpdateThumbnailSize(wxCommandEvent& event)
{
	
}

void gui_interface::StartOrganizing(wxCommandEvent& event)
{
	if (dirDialog->ShowModal() == wxID_OK)
	{}

	// Sprawdzam tylko czy kontrolka jest pusta, trzeba bedzie dopisac warunek zeby wprowadzona wartosc byla liczba.
	if (width->GetValue() == "" && height->GetValue() == "")
	{
		wxMessageDialog(NULL, "Wprowad\u017A stopie\u0144 kompresji!", "Uwaga!", wxOK ).ShowModal();
	}
}

void gui_interface::AddContactSheet(wxCommandEvent& event)
{

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