#ifndef CAMERAIMAGEWINDOW_H_
#define CAMERAIMAGEWINDOW_H_

#include <gtkmm.h>
#include <opencv2/opencv.hpp>
#include <mutex>
#include <thread>

void cameraLoop();
bool initializeCamera(int cameraIndex);

class CameraGrabberWindow : public Gtk::Window
{

public:    

	CameraGrabberWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);
	virtual ~CameraGrabberWindow();
	void stopCamera();
	void pauseResumeCamera();
	void updateImage(cv::Mat & frame);

	bool isPaused() {
		return this->paused;
	}

private:

	Glib::RefPtr<Gtk::Builder> builder;
	Gtk::Image *drawingImage;
	Gtk::Button *closeButton;
	Gtk::ToggleButton *resumePauseButton;

	bool paused;

};

extern std::mutex imageMutex;
extern Glib::Dispatcher dispatcher;
extern volatile bool captureVideoFromCamera;
extern cv::VideoCapture camera;
extern cv::Mat frameBGR, frame;
extern CameraGrabberWindow *cameraGrabberWindow; 

#endif // CAMERAIMAGEWINDOW_H_
