#include <iostream>
#include <gtkmm.h>

#include "single_image_window.h"
#include "camera_image_grabber.h"

using namespace std;

std::mutex imageMutex;
Glib::Dispatcher dispatcher;
volatile bool captureVideoFromCamera = false;
cv::VideoCapture camera;
cv::Mat frameBGR, frame;
CameraGrabberWindow *cameraGrabberWindow = nullptr; 

int main(int argc, char** argv) {

	if( argc != 3)
    {
    	cout << "Usage:" << endl;
    	cout << "option 1: gtk3_opencv3_ux single-image <path-to-image>" << endl;
    	cout << "option 2: gtk3_opencv3_ux cam-grabber <camera-index>" << endl;
    	return -1;
    }

	string mode = string{argv[1]};

	if(mode.compare("single-image") == 0) {

		Gtk::Main app(argc, argv);

		string imagePath = string{argv[2]};

		SingleImageWindow singleImageWindow(imagePath);

		Gtk::Main::run(singleImageWindow);

	} else if(mode.compare("cam-grabber") == 0) {

		Gtk::Main app(argc, argv);

		Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("../main_window.glade"); 

		builder->get_widget_derived("MainWindow", cameraGrabberWindow); 
		if(cameraGrabberWindow) {

			dispatcher.connect([&]() {
				imageMutex.lock();
				cameraGrabberWindow->updateImage(frame);
				imageMutex.unlock();
			});

			int cameraIndex = atoi(argv[2]);

			bool cameraInitialized = initializeCamera(cameraIndex);

			if(cameraInitialized) {
				captureVideoFromCamera = true;
				cout << "Everything sounds fine lets rock!" << endl;
				std::thread cameraThread = std::thread(&cameraLoop);
				Gtk::Main::run(*cameraGrabberWindow);

				captureVideoFromCamera = false;
				cameraThread.join();
			} else {
				cout << "Failed to initialize the camera" << endl;
			}

		} else {
			cout << "Failed to initialize the GUI" << endl;
		}

	} else {
		cout << "mode not recognized: " << mode << endl;
		return -1;
	}

	if(camera.isOpened()) {
		camera.release();
		cout << "Camera released success!" << endl;
	}

}