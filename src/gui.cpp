///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Mar 23 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gui.h"

///////////////////////////////////////////////////////////////////////////

MyFrame::MyFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* sizerLeft;
	sizerLeft = new wxBoxSizer( wxVERTICAL );
	
	m_panel2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel2->SetBackgroundColour( wxColour( 255, 255, 255 ) );
	
	sizerLeft->Add( m_panel2, 1, wxEXPAND | wxALL, 5 );
	
	
	mainSizer->Add( sizerLeft, 3, wxEXPAND, 5 );
	
	wxBoxSizer* sizerRight;
	sizerRight = new wxBoxSizer( wxVERTICAL );
	
	m_save = new wxButton( this, wxID_ANY, wxT("Zapis do pliku"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerRight->Add( m_save, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_bananBox = new wxCheckBox( this, wxID_ANY, wxT("banan"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerRight->Add( m_bananBox, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_scrollBar = new wxScrollBar( this, wxID_ANY, wxDefaultPosition, wxSize( 160,-1 ), wxSB_HORIZONTAL );
	sizerRight->Add( m_scrollBar, 0, wxALIGN_CENTER|wxALL, 5 );
	m_scrollBar->SetRange(101);
	m_scrollBar->Enable(false);


	m_color = new wxButton( this, wxID_ANY, wxT("kolor gwiazdki"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerRight->Add( m_color, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_sliderRate = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	m_sliderRate->SetValue( 0 );
	sizerRight->Add( m_sliderRate, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_textBox = new wxTextCtrl( this, wxID_ANY, wxT("tekst"), wxDefaultPosition, wxDefaultSize, 0 );
	sizerRight->Add( m_textBox, 0, wxALIGN_CENTER|wxALL, 5 );
	
	wxString m_choiceChoices[] = { wxT("gwiazdka"), wxT("ksiezyc"), wxT("slonko") };
	int m_choiceNChoices = sizeof( m_choiceChoices ) / sizeof( wxString );
	m_choice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceNChoices, m_choiceChoices, 0 );
	m_choice->SetSelection( -1 );
	sizerRight->Add( m_choice, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	mainSizer->Add( sizerRight, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( mainSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	m_colorDialog = new wxColourDialog(this);
	m_saveDialog = new wxFileDialog(this, _("Wybierz plik:"), _(""), _(""), _("*.*"), wxFD_SAVE);
	// Connect Events
	m_save->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::saveOnClick ), NULL, this );
	m_bananBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame::bananCheck ), NULL, this );
	m_color->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::colorClick ), NULL, this );
	m_textBox->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame::textChanging ), NULL, this );
	m_choice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame::choiceClick ), NULL, this );
	m_scrollBar->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame::trackSlider), NULL, this);
}

MyFrame::~MyFrame()
{
	// Disconnect Events
	m_save->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::saveOnClick ), NULL, this );
	m_bananBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame::bananCheck ), NULL, this );
	m_color->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::colorClick ), NULL, this );
	m_textBox->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame::textChanging ), NULL, this );
	m_choice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame::choiceClick ), NULL, this );
	m_scrollBar->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame::trackSlider), NULL, this);
}
