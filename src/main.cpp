#include "gui_interface.h"
#include "wx/wxprec.h"
	
class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};
IMPLEMENT_APP(MyApp)
bool MyApp::OnInit()
{
	MyFrame *frame = new gui_interface(NULL);
	frame->Show(true);
	return true;
}

