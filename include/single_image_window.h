#ifndef SINGLEIMAGEWINDOW_H_
#define SINGLEIMAGEWINDOW_H_

#include <gtkmm.h>
#include <string>

class SingleImageWindow : public Gtk::Window
{

public:    

	SingleImageWindow(std::string imagePath);
	virtual ~SingleImageWindow();

private:

	Gtk::Image image;
	Gtk::Button buttonClose;
	Gtk::Grid mainGrid;

};


#endif // SINGLEIMAGEWINDOW_H_
