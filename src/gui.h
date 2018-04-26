///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Mar 23 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUI_H__
#define __GUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/scrolbar.h>
#include <wx/gauge.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/frame.h>
#include <wx/colordlg.h>
#include <wx/dcbuffer.h>
#include <wx/gdicmn.h>
#include <wx/statbmp.h>
#include <wx/filedlg.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame
///////////////////////////////////////////////////////////////////////////////
class MyFrame : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_panel2;
		wxButton* m_save;
		wxCheckBox* m_bananBox;
		wxScrollBar* m_scrollBar;
		wxButton* m_color;
		wxGauge* m_sliderRate;
		wxTextCtrl* m_textBox;
		wxChoice* m_choice;
		wxColourDialog* m_colorDialog;
		wxColourData m_starColor;
		wxImage banan_png;
		wxBitmap banan_bitmap;
		wxFileDialog* m_saveDialog;
		wxBitmap* save_bitmap;

		bool gwiazda, ksiezyc, slonce;
		bool banan;

		virtual void refresh() {}
		// Virtual event handlers, overide them in your derived class
		virtual void saveOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void bananCheck( wxCommandEvent& event ) { event.Skip(); }
		virtual void colorClick(wxCommandEvent& event) { event.Skip(); }
		virtual void textChanging( wxCommandEvent& event ) { event.Skip(); }
		virtual void choiceClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void trackSlider(wxScrollEvent& event) { event.Skip(); }
	
	public:
		
		MyFrame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT(" GFK Lab 03"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(567, 360), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);
		~MyFrame();
		
};

#endif //__GUI_H__
