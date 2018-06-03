#pragma once
#include "gui.h"
#include "folder_hierarchy.h"

class gui_interface : public MyFrame, public folder_hierarchy
{
public:
	gui_interface(wxWindow* parent) : MyFrame(parent) {}
	
	// Po wcisnieciu buttona dirImport pojawia sie okno do wyboru katalogu ze zdjeciami ktory bedziemy porzadkowac.
	virtual void SelectDirectoryToImport(wxCommandEvent& event);

	// Tutaj wybieramy w jakim trybie bedziemy pracowac (dostepne opcje: "tryb automatyczny" lub "tryb polautomatyczny")
	virtual void ModeSelect(wxCommandEvent& event);

	// Zapisujemy do zmiennych thumbnailHeight i thumbnailWidth wprowadzona przed uzytkownika wysokosc i szerokosc miniaturek.
	virtual void UpdateThumbnailSize(wxCommandEvent& event);

	virtual void SetCompressionLevel(wxScrollEvent& event);

	// Po wcisnieciu buttona organizePhotos pokawia sie okno do wyboru katalogu do ktorego bedziemy zapisywac katalog
	// z uporzadkowanymi zdjeciami. Pozniej startujemy z porzadkowaniem zdjec. Jesli uzytkownik nie ustawil stopnia kompesji
	// pojawia sie ostrzezenie. Na panelu photosPanel bedzie mozna zobaczyc porzadkowane zdjecia. 
	// Caly czas aktualizowana bedzie wartosc wxGauge* showProgress gdzie bedzie pokazane jaki procent
	// jaki procent zdjec uporzadkowalismy a zmienna tekstowa percentageProgress bedzie wypisywac ta wartosc 
	// (percentageProgress->SetLabel("x %")). 
	virtual void StartOrganizing(wxCommandEvent& event);

	// Po zaznaczeniu CheckBoxa dodajemy stykówki do nowo utworzonego folderu z miniaturkami.
	virtual void AddContactSheet(wxCommandEvent& event);

	// W trybie polautomatycznym po nacisnieciu buttona leftRotation mozemy obrocic zdjecie o 90 stopni w lewo.
	virtual void RotateLeft(wxCommandEvent& event);

	// W trybie polautomatycznym po nacisnieciu buttona rightRotation mozemy obrocic zdjecie o 90 stopni w prawo.
	virtual void RotateRight(wxCommandEvent& event);

	// W trybie polautomatycznym po nacisnieciu buttona --> przechodzi do nastepnego zdjecia.
	virtual void GoToNextPhoto(wxCommandEvent& event);

	// odswieza obraz z rysowaniem zdjecia
	void Repaint(wxImage Img);

	// odswieza obraz
	void Repaint();
	
	// taki bajer ;)
	void Repaint_done();

	// dokonuje operacji na zdjeciu, kopiuje do lokalizacji docelowej
	void imageHandler(const std::string& source, const std::string& destination);

	// tworzy kopie hierarchii folderow w lokalizacji docelowej
	void copyHierarchy();

	// tworzy stykowki ze zdjec w danym folderze
	void createContactSheet(const std::string& place);
};