/**
 * @file   solarsystem.h
 * @author Nicolas Poinsignon
 * @date   Dec 2017
 *
 * @brief  Contain the data of the solar system celestial bodies.
 *
 *
 */
#ifndef _SOLARSYSTEM_H_
#define _SOLARSYSTEM_H_

#include <algorithm>
#include <glm/glm.h>
#include <GL/gl.h>  // OpenGL include file
#include <GL/glut.h>
#include <iostream>
#include <iterator>
#include <math.h>
#include <QGLWidget>
#include <QImage>
#include <QKeyEvent>
#include <QObject>
#include <vector>     // STL Vector type

/**
 * SolarSystem class
 *
 */
class SolarSystem {
    private:
    int _timeDay; //Time of simulation in hours.
    int _textured; //Whether to texture bodies or not
    int _orbitlines; //Whether to draw orbit lines or not
    int _indicators; //Whether to draw bodies rotation axis and arrows or not
    int _displayMode; //Current display mode
	float fSemiMajorAxis; //The procedurally increasing radius of each body orbit
	void orbit_calculus(float a, float e, float angle, float & x, float & y);
    enum displayModeType {WIREFRAME, FLATSHADED, SMOOTHSHADED};
    // Textures
    GLuint *texNames;
    QImage* loadImage(std::string filename);


    public:
    SolarSystem();
    ~SolarSystem();
    void init_system();
    void draw_system();
    void draw_body(int iBody, float &fThisSemiMajorAxis);
    void set_timeDay(int time);
    void nextDisplayMode();
    void toggle_texture();
    void toggle_orbitlines();
    void toggle_indicators();
};

#endif
