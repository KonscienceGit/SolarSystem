TEMPLATE = app
TARGET   = SolarSystem
CONFIG  += qt opengl warn_on release thread
QT -= gui
QT += xml opengl

FORMS       = my_gui_form.ui
HEADERS     = my_qglviewer.h my_main_window.h my_scene.h solarsystem.h
SOURCES     = my_qglviewer.cpp my_main_window.cpp my_scene.cpp main.cpp solarsystem.cpp

INCLUDEPATH += ./glm-0.4.1

#unix:LIBS *= -lQGLViewer -lglut to use with glut, not freeglut
LIBS += -lglu32

# Intermediate files are created in a separate folder
MOC_DIR = .moc
OBJECTS_DIR = .obj

#path are relative to the project folder

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Libraries/freeglut/lib/ -lfreeglut -lopengl32
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Libraries/freeglut/lib/ -lfreeglutd -lopengl32
else:unix: LIBS += -L$$PWD/../Libraries/freeglut/lib/ -lfreeglut -lopengl32

INCLUDEPATH += $$PWD/../Libraries/freeglut/include
DEPENDPATH += $$PWD/../Libraries/freeglut/include

unix|win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Libraries/libQGLViewer-2.7.1/QGLViewer/ -lQGLViewer2
unix|win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Libraries/libQGLViewer-2.7.1/QGLViewer/ -lQGLViewerd2

INCLUDEPATH += $$PWD/../Libraries/libQGLViewer-2.7.1/QGLViewer
DEPENDPATH += $$PWD/../Libraries/libQGLViewer-2.7.1/QGLViewer

#TODO:
#
#Make .pro file move dependencies in the build folder
#Remove unneeded comments
