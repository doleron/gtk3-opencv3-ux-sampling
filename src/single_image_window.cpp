#include "single_image_window.h"

#include <iostream>

SingleImageWindow::SingleImageWindow(std::string imagePath)
{
	this->set_border_width(10);

	image.set(imagePath);

	Glib::RefPtr< const Gdk::Pixbuf > pixbuf = image.get_pixbuf();

	if(!pixbuf) {
		image.set("../images/image_not_found.png");
	}

	mainGrid.attach(image, 0, 0, 1, 1);

	buttonClose.add_label("Close");
	buttonClose.signal_pressed().connect(sigc::mem_fun(*this, &SingleImageWindow::close));
	mainGrid.attach(buttonClose, 0, 2, 1, 1);

	mainGrid.show_all();

	add(mainGrid);
}

SingleImageWindow::~SingleImageWindow()
{

}
