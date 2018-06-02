///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUI_H__
#define __GUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/choice.h>
#include <wx/gauge.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/dirdlg.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/msgdlg.h>
#include <wx/checkbox.h>
#include <wx/slider.h>



///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame
///////////////////////////////////////////////////////////////////////////////
class MyFrame : public wxFrame
{
private:

protected:
	wxButton* dirImport;
	wxChoice* modeChoice;
	wxStaticText* maxHeight;
	wxTextCtrl* height;
	wxStaticText* maxWidth;
	wxTextCtrl* width;
	wxSlider* compressionLevel;
	wxStaticText* compression;
	wxButton* organizePhotos;
	wxGauge* showProgress;
	wxStaticText* percentageProgress;
	wxCheckBox* contactSheet;
	wxPanel* photosPanel;
	wxButton* leftRotation;
	wxButton* rightRotation;
	wxDirDialog* dirDialog;
	double thumbnailHeight;
	double thumbnailWidth;


	// Virtual event handlers, overide them in your derived class
	virtual void SelectDirectoryToImport(wxCommandEvent& event) { event.Skip(); }
	virtual void ModeSelect(wxCommandEvent& event) { event.Skip(); }
	virtual void UpdateThumbnailSize(wxCommandEvent& event) { event.Skip(); }
	virtual void SetCompressionLevel(wxScrollEvent& event) { event.Skip(); }
	virtual void StartOrganizing(wxCommandEvent& event) { event.Skip(); }
	virtual void AddContactSheet(wxCommandEvent& event) { event.Skip(); }
	virtual void RotateLeft(wxCommandEvent& event) { event.Skip(); }
	virtual void RotateRight(wxCommandEvent& event) { event.Skip(); }


public:

	MyFrame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(953, 567), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	~MyFrame();

};

#endif //__GUI_H__

