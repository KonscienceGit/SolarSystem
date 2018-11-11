# SolarSystem
A light C++/OpenGL visualizer, able to render a stellar system based on its properties.
![A quick animation featuring the solar system in motion](https://github.com/KonscienceGit/SolarSystem/blob/master/Screenshoots/SolarSystemGif.gif)

## How to use

### For windows
You can either :
-clone/download this repo and open the source_files folder as a project into Qt creator 5
-download the compiled version [on this branch](https://github.com/KonscienceGit/SolarSystem/tree/Windows_compiled_release), it should run right out of the box.

### For Debian
You may grab the source code in the [Old_Ubuntu_source_code_from Jan_2018.tgz](https://github.com/KonscienceGit/SolarSystem/blob/master/Old_Ubuntu_source_code_from%20Jan_2018.tgz) tarball in this repo, it's an older code sir, but it checks out.


## Origin

This program was first a computer-science college project, that somehow evolved into something more concrete, both substantially and emotionally. To make it short, I took so much pleasure making this program, it revealed in me my passion for graphics programming.

## What it is

This is, as of now, a light weight C++ OpenGL 3D visualizer, able to project a rendering of the solar system.
All bodies sizes except the sun are on scale.
While orbit radiuses are simplified, rotations axes, rotation period, orbit period, orbit tilt and so forth are parameters the visualizer take into account and represent accurately. While the orbit period is correct, it's not fully using Kepler's law and then bodies speed is simply a linear angular speed from the orbit plane pov.

## Present functions

Forward time in hours, days, weeks and months by press of keys "h, j, s, m" (and backward with the CAPS equivalent) and make bodies orbit adequately.
Switch between wireframe, solid, and smooth lightning polygon rendering with the "f" key.
Toggle textures on or off with the "t" key.
Toggle orbit lines on or off with the "o" key.
Toggle rotation indicator on or off with the "i" key.

## Future functions

* I'd like to be able to render any possible star system, with the loading of any kind of text file exchange format (json, csv...)
To do so I need a pool of textures, categorize bodies to represent each "major" types of stars, planets, etc
* A mean of exctracting bodies astronomical properties autonomously (xslt parsing?) from sources.
* I will also try to make my very own visualizer, as this one use some legacy code from my teacher Bruno Jobard, at the university of Pau, France. In doing so I will try and use a recent OpenGL standard (library GLFW for example).
* Correctly implement Kepler's law for the bodies motion, or even N-body simulation in a separate option.

## Technologies used

* Language:
>   C++
* Framework:
>   Qt4 (Qt5 for current build)
* Graphic Standard and API:
>   OpenGL
* Graphic library:
>   Glut/freeglut

## Credits to

* Bruno Jobard for building the ground of the visualizer with isiviewer, http://bjobard.perso.univ-pau.fr/
* Solar System Scope team for nearly all of the textures used https://www.solarsystemscope.com/
* Alpha-Element for the saturn rings texture https://alpha-element.deviantart.com/art/Stock-Image-Saturn-Rings-393767006
