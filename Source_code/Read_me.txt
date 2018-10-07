//////////////////
Star system viewer
//////////////////

Made by: Poinsignon Nicolas
Version: Jan 6 2018
Using isiviewer, all credits goes to Bruno Jobard   http://bjobard.perso.univ-pau.fr/
saturn rings texture is from https://alpha-element.deviantart.com/art/Stock-Image-Saturn-Rings-393767006  rights of use are granted.

___________
Decription:
This program allow the visualisation of star systems in 3D.

___________
How to use:
-Unix version:
  Need:
    -OS Ubuntu 14.04
    -packages  cmake cmake-qt-gui cmake-curses-gui libglew-dev libqglviewer-dev qt4-dev-tools qt4-qtconfig libtclap-dev qtcreator geomview doxygen-gui

  In a terminal command prompt, enter this folder repertory and enter the following,
    To install:
      -mkdir ../build
      -cd ../build
      -cmake ../isiviewer_glut/
      -make
      
    To execute the program:
      -./isiviewer
      
_________
Controls:
  -Naviguation controls:
    -Pan and rotate the view with mouse
    -Zoom with mousewheel
    -Detach camera with the space key
  -Keymapping:
    -h increase simulation time by 1 hour
    -H decrease simulation time by 1 hour
    -j increase simulation time by 1 day
    -J decrease simulation time by 1 day
    -s increase simulation time by 1 week
    -S decrease simulation time by 1 week
    -m increase simulation time by 1 month
    -M decrease simulation time by 1 month
    -i toggle rotation axis and rotation indicators on or off
    -o toggle orbit lines on or off
    -f switch between  smooth rendering, flat rendering and wireframe mode
    
