# SolarSystem
A light C++/OpenGL visualizer, able to render a stellar system based on its properties.


## Origin

This program was first a computer-science college project, that somehow evolved into something more concrete, both substantially and emotionally. To make it short, I took so much pleasure making this program, it revealed in me my passion for computer graphics.

## What it is

This is, as of now, a light weight C++ OpenGL visualizer, able to project 3D rendering of the solar system.
All bodies sizes except the sun are on scale.
While orbit radiuses are simplified, rotations axes, rotation period, orbit period, orbit tilt and so forth are parameters the visualizer take into account and represent accurately.

## Present functions

Forward time in hours, days, weeks and months by press of keys "h, j, s, m" (and backward with the CAPS equivalent) and make bodies orbit adequately.
Switch between wireframe, solid, and smooth lightning polygon rendering with the "f" key.
Toggle textures on or off with the "t" key.
Toggle orbit lines on or off with the "o" key.
Toggle rotation indicator on or off with the "i" key.

## Future functions

I'd like to be able to render any possible star system, with the loading of any kind of text file exchange format (json, csv...)
To do so I need a pool of textures, categorize bodies to represent each "major" types of stars, planets, etc
And maybe a mean of exctracting bodies astronomical properties autonomously (xslt parsing?) from sources.
I will also try to make my very own visualizer, as this one use some legacy code from my teacher Bruno Jobard, at the university of Pau, France. In doing so I will try and use a recent OpenGL standard (library GLFW for example).

## Technologies used

* Language:
  C++
* Framework:
  Qt4 (Qt5 for current build)
* Graphic Standard and API:
  OpenGL
* Graphic library:
  Glut
