#pragma once
#include "gui.h"

class gui_interface : public MyFrame
{
public:
	gui_interface(wxWindow* parent) : MyFrame(parent) {}
	
	virtual void refresh();

	virtual void textChanging(wxCommandEvent& event);
	virtual void colorClick(wxCommandEvent& event);
	virtual void choiceClick(wxCommandEvent& event);
	virtual void bananCheck(wxCommandEvent& event);
	virtual void trackSlider(wxScrollEvent& event);
	virtual void saveOnClick(wxCommandEvent& event);

private:

};