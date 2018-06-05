///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gui.h"

///////////////////////////////////////////////////////////////////////////

MyFrame::MyFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->SetBackgroundColour(wxColour(147, 147, 147));

	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* leftSizer;
	leftSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* importSizer;
	importSizer = new wxBoxSizer(wxVERTICAL);

	importSizer->SetMinSize(wxSize(200, 70));
	dirImport = new wxButton(this, wxID_ANY, wxT("Importuj katalog"), wxDefaultPosition, wxDefaultSize, 0);
	importSizer->Add(dirImport, 0, wxALIGN_CENTER | wxALL | wxSHAPED, 5);


	leftSizer->Add(importSizer, 0, wxALIGN_CENTER | wxEXPAND | wxSHAPED, 5);

	wxBoxSizer* choiceSizer;
	choiceSizer = new wxBoxSizer(wxVERTICAL);

	choiceSizer->SetMinSize(wxSize(200, 70));
	wxString modeChoiceChoices[] = { wxT("tryb automatyczny"), wxT("tryb p\u00F3\u0142automatyczny") };
	int modeChoiceNChoices = sizeof(modeChoiceChoices) / sizeof(wxString);
	modeChoice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, modeChoiceNChoices, modeChoiceChoices, 0);
	modeChoice->SetSelection(0);
	choiceSizer->Add(modeChoice, 0, wxALIGN_CENTER | wxALL, 5);


	leftSizer->Add(choiceSizer, 0, wxALIGN_CENTER | wxEXPAND | wxSHAPED, 5);

	wxBoxSizer* dimensionsSizer;
	dimensionsSizer = new wxBoxSizer(wxHORIZONTAL);

	dimensionsSizer->SetMinSize(wxSize(250, 100));
	wxBoxSizer* heightSizer;
	heightSizer = new wxBoxSizer(wxVERTICAL);

	maxHeight = new wxStaticText(this, wxID_ANY, wxT("Max. wysoko\u015B\u0107 miniaturki"), wxDefaultPosition, wxDefaultSize, 0);
	maxHeight->Wrap(-1);
	heightSizer->Add(maxHeight, 0, wxALL, 5);

	wxFloatingPointValidator<int> _val(0, nullptr, wxNUM_VAL_ZERO_AS_BLANK);
	_val.SetRange(0, 1920);

	height = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _val);
	heightSizer->Add(height, 0, wxALL, 5);


	dimensionsSizer->Add(heightSizer, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer(wxVERTICAL);

	maxWidth = new wxStaticText(this, wxID_ANY, wxT("Max. szeroko\u015B\u0107 miniaturki"), wxDefaultPosition, wxDefaultSize, 0);
	maxWidth->Wrap(-1);
	bSizer12->Add(maxWidth, 0, wxALL, 5);

	width = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _val);
	bSizer12->Add(width, 0, wxALL, 5);


	dimensionsSizer->Add(bSizer12, 1, wxEXPAND, 5);


	leftSizer->Add(dimensionsSizer, 0, wxALIGN_CENTER | wxEXPAND | wxSHAPED, 5);

	wxBoxSizer* compressionSizer;
	compressionSizer = new wxBoxSizer(wxVERTICAL);

	compressionSizer->SetMinSize(wxSize(350, 100));
	compressionLevel = new wxSlider(this, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxSize(300, 40), wxSL_HORIZONTAL);
	compressionSizer->Add(compressionLevel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL | wxSHAPED, 5);

	compression = new wxStaticText(this, wxID_ANY, wxT("poziom kompresji (100 %)"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);
	compression->Wrap(-1);
	compressionSizer->Add(compression, 0, wxALIGN_CENTER_HORIZONTAL | wxALL | wxSHAPED, 5);


	leftSizer->Add(compressionSizer, 1, wxALIGN_CENTER | wxEXPAND | wxSHAPED, 5);

	wxBoxSizer* organizeSizer;
	organizeSizer = new wxBoxSizer(wxVERTICAL);

	organizeSizer->SetMinSize(wxSize(350, 70));
	organizePhotos = new wxButton(this, wxID_ANY, wxT("Porz\u0105dkuj zdj\u0119cia"), wxDefaultPosition, wxDefaultSize, 0);
	organizeSizer->Add(organizePhotos, 0, wxALIGN_CENTER | wxALL | wxSHAPED, 5);


	leftSizer->Add(organizeSizer, 0, wxALIGN_CENTER | wxEXPAND | wxSHAPED, 5);

	wxBoxSizer* progressSizer;
	progressSizer = new wxBoxSizer(wxVERTICAL);

	progressSizer->SetMinSize(wxSize(350, 100));
	showProgress = new wxGauge(this, wxID_ANY, 100, wxPoint(-1, -1), wxSize(300, 30), wxGA_HORIZONTAL | wxSIMPLE_BORDER);
	showProgress->SetValue(0);
	progressSizer->Add(showProgress, 0, wxALIGN_CENTER | wxALL | wxSHAPED, 5);

	percentageProgress = new wxStaticText(this, wxID_ANY, wxT("0 %"), wxDefaultPosition, wxSize(-1, -1), 0);
	percentageProgress->Wrap(-1);
	progressSizer->Add(percentageProgress, 0, wxALIGN_CENTER | wxALL, 5);


	leftSizer->Add(progressSizer, 0, wxALIGN_CENTER | wxEXPAND | wxSHAPED, 5);

	wxBoxSizer* contactSheetSizer;
	contactSheetSizer = new wxBoxSizer(wxVERTICAL);

	contactSheet = new wxCheckBox(this, wxID_ANY, wxT("dodaj styk\u00F3wki"), wxDefaultPosition, wxDefaultSize, 0);
	contactSheetSizer->Add(contactSheet, 0, wxALIGN_CENTER | wxALL, 5);


	leftSizer->Add(contactSheetSizer, 0, wxEXPAND, 5);

	mainSizer->Add(leftSizer, 0, wxEXPAND, 5);

	wxBoxSizer* rightSizer;
	rightSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* rotationSizer;
	rotationSizer = new wxBoxSizer(wxHORIZONTAL);

	leftRotation = new wxButton(this, wxID_ANY, wxT("Obr\u00F3t w lewo o 90\u2070"), wxDefaultPosition, wxDefaultSize, 0);
	leftRotation->Enable(false);
	rotationSizer->Add(leftRotation, 0, wxALIGN_CENTER | wxALL, 5);

	rightRotation = new wxButton(this, wxID_ANY, wxT("Obr\u00F3t w prawo o 90\u2070"), wxDefaultPosition, wxDefaultSize, 0);
	rightRotation->Enable(false);
	rotationSizer->Add(rightRotation, 0, wxALIGN_CENTER | wxALL, 5);

	nextPhoto = new wxButton(this, wxID_ANY, wxT("-->"), wxDefaultPosition, wxDefaultSize, 0);
	nextPhoto->Enable(false);
	nextPhoto->SetMinSize(wxSize(50, -1));

	rotationSizer->Add(nextPhoto, 0, wxALIGN_CENTER | wxALL, 5);

	rightSizer->Add(rotationSizer, 0, wxALIGN_CENTER | wxEXPAND | wxSHAPED, 5);

	mainSizer->Add(rightSizer, 1, wxEXPAND, 5);


	this->SetSizer(mainSizer);
	this->Layout();

	this->Centre(wxBOTH);

	// Connect Events
	dirImport->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::SelectDirectoryToImport), NULL, this);
	modeChoice->Connect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(MyFrame::ModeSelect), NULL, this);
	height->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MyFrame::UpdateThumbnailSize), NULL, this);
	width->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MyFrame::UpdateThumbnailSize), NULL, this);
	compressionLevel->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame::SetCompressionLevel), NULL, this);
	compressionLevel->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame::SetCompressionLevel), NULL, this);
	compressionLevel->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame::SetCompressionLevel), NULL, this);
	compressionLevel->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame::SetCompressionLevel), NULL, this);
	compressionLevel->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame::SetCompressionLevel), NULL, this);
	compressionLevel->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame::SetCompressionLevel), NULL, this);
	compressionLevel->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame::SetCompressionLevel), NULL, this);
	compressionLevel->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame::SetCompressionLevel), NULL, this);
	compressionLevel->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame::SetCompressionLevel), NULL, this);
	organizePhotos->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::StartOrganizing), NULL, this);
	contactSheet->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrame::AddContactSheet), NULL, this);
	leftRotation->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::RotateLeft), NULL, this);
	rightRotation->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::RotateRight), NULL, this);
	nextPhoto->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::GoToNextPhoto), NULL, this);

	dirDialog = new wxDirDialog(this, wxT("Wybierz katalog"), wxT(""));
}

MyFrame::~MyFrame()
{
	// Disconnect Events
	dirImport->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::SelectDirectoryToImport), NULL, this);
	modeChoice->Disconnect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(MyFrame::ModeSelect), NULL, this);
	height->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MyFrame::UpdateThumbnailSize), NULL, this);
	width->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MyFrame::UpdateThumbnailSize), NULL, this);
	compressionLevel->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame::SetCompressionLevel), NULL, this);
	compressionLevel->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame::SetCompressionLevel), NULL, this);
	compressionLevel->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame::SetCompressionLevel), NULL, this);
	compressionLevel->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame::SetCompressionLevel), NULL, this);
	compressionLevel->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame::SetCompressionLevel), NULL, this);
	compressionLevel->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame::SetCompressionLevel), NULL, this);
	compressionLevel->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame::SetCompressionLevel), NULL, this);
	compressionLevel->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame::SetCompressionLevel), NULL, this);
	compressionLevel->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame::SetCompressionLevel), NULL, this);
	organizePhotos->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::StartOrganizing), NULL, this);
	contactSheet->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrame::AddContactSheet), NULL, this);
	leftRotation->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::RotateLeft), NULL, this);
	rightRotation->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::RotateRight), NULL, this);
	nextPhoto->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::GoToNextPhoto), NULL, this);
}

