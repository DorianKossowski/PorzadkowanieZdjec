#include "gui_interface.h"

void gui_interface::refresh()
{
	wxClientDC clientDC(this->m_panel2);
	wxBufferedDC bufferDC(&clientDC);
	PrepareDC(bufferDC);

	bufferDC.Clear();

	wxSize size = m_panel2->GetVirtualSize();
	int x = size.GetX() / 2;
	int y = size.GetY() / 2;

	bufferDC.DrawRotatedText(m_textBox->GetValue(), x - 120, y + 120, 0);
	bufferDC.SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_NORMAL, false, "Harlow Solid"));
	bufferDC.DrawRotatedText(m_textBox->GetValue(), x + 80, y + 80, 90);

	if (slonce)
	{
		wxPoint centre(x - 100, y - 110);
		bufferDC.SetPen(*wxYELLOW_PEN);
		bufferDC.SetBrush(*wxYELLOW_BRUSH);
		bufferDC.DrawCircle(centre, 35);
	}
	else if (gwiazda)
	{
		wxPoint gwiazdaPoints[5];
		gwiazdaPoints[0] = wxPoint(x - 100, y - 150);
		gwiazdaPoints[1] = wxPoint(x - 130, y - 70);
		gwiazdaPoints[2] = wxPoint(x - 60, y - 120);
		gwiazdaPoints[3] = wxPoint(x - 140, y - 120);
		gwiazdaPoints[4] = wxPoint(x - 70, y - 70);

		bufferDC.SetPen(m_starColor.GetColour());
		bufferDC.SetBrush(wxBrush(m_starColor.GetColour()));
		bufferDC.DrawPolygon(WXSIZEOF(gwiazdaPoints), gwiazdaPoints, 0, 0);
	}
	else if (ksiezyc)
	{
		wxPoint A(x - 100, y - 110);
		wxPoint B(x - 118, y - 128);
		bufferDC.SetPen(*wxLIGHT_GREY);
		bufferDC.SetBrush(*wxLIGHT_GREY);
		bufferDC.DrawCircle(A, 35);

		bufferDC.SetPen(*wxWHITE);
		bufferDC.SetBrush(*wxWHITE);
		bufferDC.DrawCircle(B, 35);
	}
	bufferDC.SetPen(*wxBLACK_PEN);
	bufferDC.SetBrush(*wxTRANSPARENT_BRUSH);

	wxPoint points[5];
	if (banan)
	{
		points[0] = wxPoint(x - 25, y - 45);
		points[1] = wxPoint(x - 12, y - 40);
		points[2] = wxPoint(x, y - 35);
		points[3] = wxPoint(x + 12, y - 40);
		points[4] = wxPoint(x + 22, y - 45);

		bufferDC.DrawEllipse(x - 25, y - 63, 20, 15);
		bufferDC.DrawEllipse(x + 3, y - 63, 20, 15);
		bufferDC.DrawSpline(5, points);

		wxInitAllImageHandlers();
		banan_png.LoadFile("banan.png", wxBITMAP_TYPE_PNG);
		banan_bitmap = wxBitmap(banan_png);
		bufferDC.DrawBitmap(banan_bitmap, x - 100, y + 25 - m_scrollBar->GetThumbPosition());
	}
	else
	{
		points[0] = wxPoint(x - 25, y - 35);
		points[1] = wxPoint(x - 12, y - 40);
		points[2] = wxPoint(x, y - 45);
		points[3] = wxPoint(x + 12, y - 40);
		points[4] = wxPoint(x + 22, y - 35);

		bufferDC.DrawEllipse(x - 25, y - 63, 20, 15);
		bufferDC.DrawEllipse(x + 3, y - 63, 10, 15);
		bufferDC.DrawSpline(5, points);
	}
	wxPoint ludzikPoints[7];
	ludzikPoints[0] = wxPoint(x, y);
	ludzikPoints[1] = wxPoint(x + 70, y + 45);
	ludzikPoints[2] = wxPoint(x - 70, y + 45 - m_scrollBar->GetThumbPosition());
	ludzikPoints[3] = wxPoint(x, y - 50);
	ludzikPoints[4] = wxPoint(x, y + 80);
	ludzikPoints[5] = wxPoint(x - 60, y + 140);
	ludzikPoints[6] = wxPoint(x + 60, y + 140);
	bufferDC.DrawCircle(ludzikPoints[3], 30);
	bufferDC.DrawLine(x, y - 20, x, y + 80);
	bufferDC.DrawLine(ludzikPoints[0], ludzikPoints[1]);
	bufferDC.DrawLine(ludzikPoints[0], ludzikPoints[2]);
	bufferDC.DrawLine(ludzikPoints[4], ludzikPoints[5]);
	bufferDC.DrawLine(ludzikPoints[4], ludzikPoints[6]);

}



void gui_interface::textChanging(wxCommandEvent & event)
{
	refresh();
}

void gui_interface::colorClick(wxCommandEvent & event)
{
	m_colorDialog->ShowModal();
	m_starColor = m_colorDialog->GetColourData();
	refresh();
}

void gui_interface::choiceClick(wxCommandEvent& event)
{
	if (m_choice->GetSelection() == 0)
	{
		gwiazda = true; ksiezyc = false; slonce = false;
		refresh();
	}
	else if (m_choice->GetSelection() == 1)
	{
		gwiazda = false; ksiezyc = true; slonce = false;
		refresh();
	}
	else if (m_choice->GetSelection() == 2)
	{
		gwiazda = false; ksiezyc = false; slonce = true;
		refresh();
	}
}
void gui_interface::bananCheck(wxCommandEvent& event)
{
	if (m_bananBox->IsChecked())
	{
		m_scrollBar->Enable(true);
		banan = true;
		refresh();
	}
	else
	{
		m_scrollBar->Enable(false);
		banan = false;
		refresh();
	}
}
void gui_interface::trackSlider(wxScrollEvent& event)
{
	m_sliderRate->SetValue(m_scrollBar->GetThumbPosition());
	refresh();
}
void gui_interface::saveOnClick(wxCommandEvent& event)
{
	wxClientDC clientDC(this->m_panel2);
	wxBufferedDC bufferDC(&clientDC);
	PrepareDC(bufferDC);

	wxInitAllImageHandlers();

	wxString name;

	if (m_saveDialog->ShowModal() == wxID_OK)
	{
		name = m_saveDialog->GetPath();

		wxSize size = m_panel2->GetVirtualSize();
		save_bitmap = new wxBitmap(size);

		wxMemoryDC memory;
		memory.SelectObject(*save_bitmap);
		memory.Blit(0, 0, size.GetX(), size.GetY(), &bufferDC, 0, 0, wxCOPY, true);

		wxImage result = save_bitmap->ConvertToImage();
		result.SaveFile(name, wxBITMAP_TYPE_BMP);
	}
}
