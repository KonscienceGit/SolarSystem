/**
 * @file   my_scene.h
 * @author Bruno Jobard
 * @author Nicolas Poinsignon
 * @date   Dec 2017
 *
 * @brief  Defines a custom 3D scene
 *
 *
 */
#ifndef _ISI_MY_SCENE_H_
#define _ISI_MY_SCENE_H_

#include <QObject>
#include <QKeyEvent>
#include "solarsystem.h"
#include <iostream>
#include <time.h>
#include <math.h>
#include <GL/gl.h>  // OpenGL include file
#include <GL/freeglut.h>

class MyScene : public QObject{
    Q_OBJECT

    enum displayModeType {WIREFRAME, FLATSHADED, SMOOTHSHADED};
    enum objectName {SOLARSYSTEM, FOOBAR};

protected:
// 3D Objects
//  Foobar    _foobar;			/**< the generic placeholder name*/
    SolarSystem    _solarsystem;			/**< the Sol system v propre*/


// Parameters
    int   _currentObject;	        /**< id of the current displayed 3D object */
    int   _numberOfObjects;	/**< number of 3D objets available */
    float _radius;		/**< radius of the object from the graphical interface */

// Info for GUI
    double _radiusMin;
    double _radiusMax;
    double _radiusIncr;
public:
    MyScene(float radius=1.);
    ~MyScene();

    inline void setCurrentObject(int co){_currentObject=co;}
    inline int currentObject(){return _currentObject;}

    inline void setRadius(float radius){_radius=radius;}
    inline float radius(){return _radius;}
    inline double radiusMin (){return _radiusMin;}
    inline double radiusMax (){return _radiusMax;}
    inline double radiusIncr(){return _radiusIncr;}

    void init();
    void draw();

signals:
    void sigCurrentObjectChanged(int co);
    void sigRadiusChanged(double radius);

public slots:
    void slotSetCurrentObject(int co);
    void slotSetRadius(double radius);

public:
    bool keyPressEvent(QKeyEvent *e);
};

#endif
