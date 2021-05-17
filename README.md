# gtk3-opencv3-ux-sampling

## Description

Cmake/make, C++11, OpenCV 3.3, GTK3.0/gtkmm3 and Glade to write a basic Webcam GUI viewer.

## GTK 3.0

GTK is a multi-platform library to create graphical user interfaces. Different of Qt, GTK is fully free [GNU LGPL](https://www.gnu.org/licenses/old-licenses/lgpl-2.1.html) so yes you can use GTK in your commercial projects without trouble.

See more about GTK at https://www.gtk.org/

## gtkmm 3.0

I forgot to say that GTK is written in plain C. No problem at all but maybe you would like to use powerful features of C++. But no panic (yet) because we have gtkmm. gtkmm is a gtk C++ wrapper and luckly we can use all the C++ expressively features to create our beautiful and also object oriented graphical user interface projects.

To learn more about gtkmm, check out here: https://developer.gnome.org/gtkmm-tutorial/stable/sec-gtkmm.html.en

## Glade

gtkmm does an awesome work by helping us to avoid writing low level C code. However, GUI code is always boilerplate and writing these things by hand is often tedious and sometimes error prone. Luckly, we can get rid this sort of problems with Glade. Glade is a GUI Generation tool. With Glade you can write the same interface for differents languages (Java, Python and C++ just to cite some).

In this example, all we need to know about Glade is that you can generate a .glade file with Glade and load it in GTK/gtkmm. If you want to learn more about how to use Glade to create your own interface, I recommend this pretty basic but actually good tutorial: http://milindapro.blogspot.com.br/2012/10/create-gui-with-gtkmm-glade-with-gtkmm.html

## OpenCV 3

OpenCV is a mature and large set of image processing algorithms. In despite of this, in this example I just use OpenCV to grab images from the camera. However, always amazes me what people can do with OpenCV, in particular the last version (currently 3.4). OpenCV is a huge world. I work with for it the last 4 years but everyday I learn something new about it.

A great start point with OpenCV is the Display Image example: https://docs.opencv.org/2.4/doc/tutorials/introduction/linux_gcc_cmake/linux_gcc_cmake.html

## CMake for the build generation

Here I use gcc 5.4 which is a C++11 compatible compiler. But it is hard to write the whole command and it is easy to forgot something like a linker flag or something like. Call g++ to compile something directly is used just in the introdutory C++ courses. In practice it is used Makefiles to build (compile/link) all the artifacts. Again, it is hard to use make directly so we use CMake to generate the Makefiles and than we can call make to finally do the job and generate all our executables and libraries.

Although cmake is changing in a daily basis, this tutorial can be stil useful as an kickoff: https://www.jetbrains.com/help/clion/2016.1/quick-cmake-tutorial.html

If you are an old cmake guy, do not wait to give a look in the cmake antipatterns guide: http://voices.canonical.com/jussi.pakkanen/2013/03/26/a-list-of-common-cmake-antipatterns/

## build instructions

Clone and build the project:

```
git clone https://github.com/doleron/gtk3-opencv3-ux-sampling.git
cd gtk3-opencv3-ux-sampling
mkdir build
cd build
cmake ..
make
```

## running the application

The application has two modes: single image and webcam

### option 1: single image

Just type in the terminal:

$ ./gtk3_opencv3_ux single-image my-picture.png

Change my-picture.png to you preferrable image:

$ ./gtk3_opencv3_ux single-image ../images/Lenna.png

![single mode](https://raw.githubusercontent.com/doleron/gtk3-opencv3-ux-sampling/master/repo_imgs/single-image.png)

### option 2: webcam grabbing

Just type in the terminal:

$ ./gtk3_opencv3_ux cam-grabber 0

The "0" is the camera index. If you have an onboard webcam or an usb webcam, try to play with the numbers such as 0, 1 or 2. 

![webcam mode](https://raw.githubusercontent.com/doleron/gtk3-opencv3-ux-sampling/master/repo_imgs/webcam-mode.png)

## Requirements

Make sure you have GTKmm, GTK 3 and OpenCV (3 at least) installed. The way you do to install this packages varies by operational system. Here (https://www.gtkmm.org/en/download.html) you can find instructions how to install GTKmm into your machine. Here (https://www.gtk.org/download/index.php) you can find the same steps for GTK3 and in the [Glade's website] (https://glade.gnome.org/) there are instructions to install Glade from sources or from binaries.

GTk3 asnd GTk2 don't live together peaceful. If you try to run the examples and got this error message:

```Gtk-ERROR **: GTK+ 2.x symbols detected. Using GTK+ 2.x and GTK+ 3 in the same proc```

It is mostly you have OpenCV build with GTk2 support. The only way to fix it is rebuild OpenCV without GTk2:

opencv_dir/release$cmake [other options] -D WITH_GTK_2_X=OFF ..

in order to disable GTk2 from OpenCV.

I ran this example on an Ubuntu 16.04 virtual machine and also on Raspbian Stretch. Make sure that you have a c++11 compliant compiler. My current compiler/version is  gcc 5.4. I didn't tried to run this code on Windows.

