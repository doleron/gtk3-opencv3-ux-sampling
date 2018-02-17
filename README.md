# basic-googletest-example

## Description

Cmake/make, C++11, OpenCV 3.3, GTK3.0/gtkmm3 and Glade to write a basic Webcam powered Graphical User Interface.

## GTK 3.0

GTK is a multi-platform library to create graphical user interfaces. Different of Qt, GTK is fully free [GNU LGPL](https://www.gnu.org/licenses/old-licenses/lgpl-2.1.html) so yes you can use GTK in yours commercial projects without trouble.

See more about GTK at https://www.gtk.org/

## gtkmm 3.0

I forgot to say that GTK is written in C. No problem at all but if you like to use the powerful features from C++ like <3 <3 ihneritance or functional programming <3 <3 you having in hell. But don' t panic (yet) gtkmm is a C++ wrapper and luckly we can use all the C++ expressively features to create beautifull object oriented graphical interface projects.

To learn more about gtkmm: https://developer.gnome.org/gtkmm-tutorial/stable/sec-gtkmm.html.en

## Glade

gtkmm does an awesome work helping us to avoid to write low level C code. However, write GUI code is always boilerplate and write these THINGS by hand is often tedious and sometimes error prone. Luckly, we can avoid this kinda of problems with Glade. Glade is a GUI Generation tool and with Glade you can write useful interfaces for several differents languages (Java, Python and C++ just to cite some).

In this example all we need to know about Glade is that you can generate a .glade file in Glade and load it in GTK/gtkmm. If you want to learn more how to use Glade to create your own interface I recommend this pretty basic but good tutorial: http://milindapro.blogspot.com.br/2012/10/create-gui-with-gtkmm-glade-with-gtkmm.html

## OpenCV 3

OpenCV is a mature set of image processing algorithms. In this example I just used OpenCV to grab images from the camera but it is amazes what people can do with OpenCV, mainly the last version (currently 3.4). OpenCV is a huge world. I work with for the last 4 years but everyday I learn something new about it.

I great start point with OpenCV is the Display Image example: https://docs.opencv.org/2.4/doc/tutorials/introduction/linux_gcc_cmake/linux_gcc_cmake.html

## CMake for the build generation

I used g++ 5.4 C++11 compatible compiler in this demo. But it is hard to write the whole command and it is easy to forgot something like a linker flag or something like. Call g++ to compile something directly is used just in the introdutory C++ courses. In practice it is used Makefiles to build (compile/link) all the artifacts. Again, it is hard to use make directly so we use CMake to generate the Makefiles and than we can call make to finally do the job and generate all our executables and libraries.

Cmake is chance everyday but this tutorial can be useful to start: https://www.jetbrains.com/help/clion/2016.1/quick-cmake-tutorial.html

If you are a old cmake guy give a look in the Cmake antipatterns guide: http://voices.canonical.com/jussi.pakkanen/2013/03/26/a-list-of-common-cmake-antipatterns/

## build instructions

A classical CMake call is enough to build all the project:

```
git clone https://github.com/doleron/gtk3-opencv3-ux-sampling.git
cd gtk3-opencv3-ux-sampling
mkdir build
cd build
cmake ..
make
```

## running test and other stuff

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

The "0" is the camera index. If you have an onboard webcam or an usb webcam, try to play with the numbers 0, 1 or 2. 

![webcam mode](https://raw.githubusercontent.com/doleron/gtk3-opencv3-ux-sampling/master/repo_imgs/webcam-mode.png)

## Requirements

I ran this example into an Ubuntu 16.04 virtual machine. Make sure that you have a c++11 compliant compiler. My current compiler/version is the g++/5.4. This code not runs on Windows. Do not expect that I will waste my time porting it for Windows.

