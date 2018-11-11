/**
 * @file   main.cpp
 * @author Bruno Jobard
 * @author Nicolas Poinsignon
 * @date   Dec 2017
 * 
 * @brief  Declares an application, a main window and a 3D scene
 * 
 * 
 */
#include <QApplication>
#include <GL/glut.h>
#include "my_main_window.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  
  // initialize the GLUT API (for geometric objects)
  glutInit(&argc, argv);

  // initialize my custom 3D scene
  float objectRadius = 1.;

  MyScene scene(objectRadius); //is now static so memory can be set free by the program
  QPointer<MyScene> myScene = &scene;

  // initialize my custom main window
  MyMainWindow window(myScene);//is now static so memory can be set free by the program
  QPointer<MyMainWindow> myMainWindow = &window;
  
  // display the window
  myMainWindow->show();
  
  // enter in the main loop
  return app.exec();
}

