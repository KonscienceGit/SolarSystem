#include "solarsystem.h"

using namespace std;

  //Constant variables:
  //Lightning configuration
  static const GLfloat light_position[] =    {    0.0f,    0.0f,    0.0f,    0.01f   };
  static const GLfloat light_no_specular[] = {    0.0f,    0.0f,    0.0f,    1.0f    };
  static const GLfloat light_diffuse[]  =    {    1.0f,    1.0f,    1.0f,    1.0f    };
  static const GLfloat light_no_ambient[]  = {    0.0f,    0.0f,    0.0f,    1.0f    };
  static const GLfloat light_ambient[]  =    {    1.0f,    1.0f,    1.0f,    1.0f    };

  //Various constants
  static const float _BodyScaleDiv = 6.0f*pow(10, 5); //Also affect the scale of orbits since each orbit is calculated from the radius of each body
  static const float _SunScaleDiv = 6.0f*pow(10, 6);
  static const int  _NB_TEX = 12;

  //Data arrays for the system to be rendered. Sidereal mean relative to the background stars, as opposed to Synodic wich mean relative from earth's POV. Here Sidereal is the norm choosen.
  static const int _iBodyNumber[] =      {0                    ,1                     ,2                    ,3                    ,4                    ,5                    ,6                     ,7                     ,8                     ,9                     ,10                   ,11}; //number of the body, in hierarchical order (generally Stars>Planets>Moons)
  static char const* const _ceBodyName[]={"Skybox"             ,"Sun"                 ,"Mercury"            ,"Venus"              ,"Earth"              ,"Mars"               ,"Jupiter"             ,"Saturn"              ,"Uranus"              ,"Neptune"             ,"Moon"               ,"SaturnRings"}; //Name of the body
  static const float _fBodyRadius[] =    {3.45f                ,695700.0f/_SunScaleDiv,2439.7f/_BodyScaleDiv,6051.8f/_BodyScaleDiv,6371.0f/_BodyScaleDiv,3389.5f/_BodyScaleDiv,69911.0f/_BodyScaleDiv,58232.0f/_BodyScaleDiv,25362.0f/_BodyScaleDiv,24622.0f/_BodyScaleDiv,1737.1f/_BodyScaleDiv,62117.0f/_BodyScaleDiv}; //Body radius in km
  static const float _fRingInnerRadius[]={0.0f                 ,0.0f                  ,0.0f                 ,0.0f                 ,0.0f                 ,0.0f                 ,0.0f                  ,0.0f                  ,0.0f                  ,0.0f                  ,0.0f                 ,74658.0f/_BodyScaleDiv}; //Body inner radius in km (for belts)
  static const float _fAscendingNode[] = {0.0f                 ,0.0f                  ,48.331f              ,76.680f              ,-11.26064f           ,49.558f              ,100.464f              ,113.665f              ,74.006f               ,131.784f              ,0.0f                 ,0.0f}; // Longitude of the ascending node of the orbit in degree
	static const float _fOrbitalIncli[] =  {0.0f                 ,0.0f                  ,6.34f                ,2.19f                ,1.57f                ,1.67f                ,0.32f                 ,0.93f                 ,1.02f                 ,0.72f                 ,5.145f               ,0.0f}; //Orbital Inclinaison, relative to the invariable plane (the system barycenter), excepted for satellites where it's relative to the parent's ecliptic
	static const float _fArgumPeriapsis[]= {0.0f                 ,0.0f                  ,29.124f              ,54.884f              ,114.20783f           ,286.502f             ,273.867f              ,339.392f              ,96.998857f            ,276.336f              ,0.0f                 ,0.0f}; //Argument of Periapsis
  static const float _fOrbitalPeriod[] = {1.0f                 ,1.0f                  ,87.9691f             ,224.701f             ,365.256363004f       ,686.971f             ,4332.59f              ,10759.22f             ,30688.5f              ,60182.0f              ,27.321661f           ,1.0f}; //Sidereal Orbital period in days
  static const float _eccentricity[] =   {0.0f                 ,0.0f                  ,0.205630f            ,0.006772f            ,0.0167086f           ,0.0934f              ,0.0489f               ,0.0565f               ,0.046381f             ,0.009456f             ,0.0549f              ,0.0f}; //eccentricity of the elliptical orbits
	static const float _fAxialTilt[] =     {0.0f                 ,7.25f                 ,0.034f               ,177.36f              ,23.4392811f          ,25.15f               ,3.13f                 ,26.73f                ,97.77f                ,28.32f                ,6.687f               ,26.73f}; //Axial tilt of the body in degree, relative to its orbit plane
  static const float _fRotationPeriod[]= {1.0f                 ,25.05f                ,58.646f              ,243.025f             ,0.99726968f          ,1.025957f            ,0.4135416667f         ,0.439583f             ,0.71833f              ,0.6713f               ,27.321661f           ,0.439583f}; //Sidereal Rotation period
  static const GLfloat _glfColor[][3] =  {{0.0f,0.0f,0.0f}     ,{1.0f,1.0f,0.1f}      ,{0.6f,0.6f,0.6f}     ,{0.95f,0.81f,0.44f}  ,{0.0f,0.3f,1.0f}     ,{1.0f,0.51f,0.33f}   ,{1.0f,0.7f,0.4f}      ,{1.0f,0.88f,0.53f}    ,{0.8f,1.0f,1.0f}      ,{0.28f,0.4f,1.0f}     ,{0.5f,0.5f,0.5f}    ,{1.0f,0.88f,0.53f}}; // RGB color properties for the GLwire sphere
  static const int _iNbSatellite[] =     {1                    ,8                     ,0                    ,0                    ,1                    ,0                    ,0                     ,1                     ,0                     ,0                     ,0                    ,0}; // The count of sattelite of this body
  static const int _iFirstSatellite[] =  {1                    ,2                     ,0                    ,0                    ,10                   ,0                    ,0                     ,11                    ,0                     ,0                     ,0                    ,0}; //The number of the first satellite of this body. 0 is null (first body can't be a satellite anyway)
	static const int _iBodyType[] =        {0                    ,1                     ,2                    ,2                    ,2                    ,2                    ,2                     ,2                     ,2                     ,2                     ,2                    ,3}; //The type of celestial object, 0 is the skybox, 1 is a star, 2 is a planet, 3 is an asteroid belt
	static const bool _bOrbital[] =        {false                ,false                 ,true                 ,true                 ,true                 ,true                 ,true                  ,true                  ,true                  ,true                  ,true                 ,false}; //whether the body is orbiting or not (in this case we consider asteroid belt "not orbiting" for simplification)
  static char const* const _ceText[] =   {"res/8k_milkyway.jpg","res/2k_sun.jpg"      ,"res/2k_mercury.jpg" ,"res/2k_venus.jpg"   ,"res/2k_earth.jpg"   ,"res/2k_mars.jpg"    ,"res/2k_jupiter.jpg"  ,"res/2k_saturn.jpg"   ,"res/2k_uranus.jpg"   ,"res/2k_neptune.jpg"  ,"res/2k_moon.jpg"    ,"res/saturn_rings.png"}; //Name of the body 

  //Static variables:
  static float fSemiMajorAxis;

  //Setting up sphere for texture mapping
  static GLUquadricObj *sphere = NULL;
  static GLUquadricObj *skybox = NULL;
  static GLUquadricObj *ringbeltTop = NULL;
  static GLUquadricObj *ringbeltBot = NULL;

SolarSystem::SolarSystem()
{
  sphere = gluNewQuadric();
  skybox = gluNewQuadric();
  ringbeltTop = gluNewQuadric(); //Top side of a ringbelt
  ringbeltBot = gluNewQuadric(); //Bottom side of a ringbelt
  texNames = new GLuint[_NB_TEX];
	cerr << "SolarSystem constructor called" << endl;
}

SolarSystem::~SolarSystem()
{
  gluDeleteQuadric(sphere);
  gluDeleteQuadric(skybox);
  gluDeleteQuadric(ringbeltTop);
  gluDeleteQuadric(ringbeltBot);  
  delete[] texNames;
	cerr << "~SolarSystem" << endl;
}


void SolarSystem::init_system()
{
  _timeDay = 0;     //Default time of the day
  _textured = 1;    //Planet are textured by default
  _indicators = 0;  //Rotation arrows and rotation axis are not drawn by default
  _orbitlines = 1;  //Orbit lines are drawn by default
  glMatrixMode(GL_MODELVIEW);
  //Light0 Setting up principal light source (here the star light)
  glLightfv(GL_LIGHT0,    GL_POSITION,    light_position);
  glLightfv(GL_LIGHT0,    GL_SPECULAR,    light_no_specular);
  glLightfv(GL_LIGHT0,    GL_AMBIENT,    light_no_ambient); 
  //Light1 for the sun to be illuminated realistically, it need ambient lightning
  glLightfv(GL_LIGHT1,    GL_DIFFUSE,    light_diffuse);
  glLightfv(GL_LIGHT1,    GL_AMBIENT,    light_ambient); 
  
  //load textures
  std::vector<QImage*> img;
  glGenTextures(_NB_TEX, texNames);
  for (int i = 0; i < _NB_TEX ; i++ )
    {
    img.push_back(this->loadImage(_ceText[i]));
    if (img[i] != NULL) 
      {
      glBindTexture(GL_TEXTURE_2D, texNames[i]);
      glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
      glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
      glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA, img[i]->width(), img[i]->height() ,0, GL_RGBA,GL_UNSIGNED_BYTE, img[i]->bits());
      }
    }

  //Setting up quadratic parameters  
  //Sphere for planets and stars
  gluQuadricDrawStyle(sphere, GLU_FILL);
  gluQuadricTexture(sphere, GL_TRUE);
  gluQuadricNormals(sphere, GLU_SMOOTH);
  //sphere with inverted normals for the skybox
  gluQuadricDrawStyle(skybox, GLU_FILL);
  gluQuadricTexture(skybox, GL_TRUE);
  gluQuadricNormals(skybox, GLU_SMOOTH);
  gluQuadricOrientation(skybox, GLU_INSIDE); //setting normals to point inside
  //Disk for the top of ringbelts
  gluQuadricDrawStyle(ringbeltTop, GLU_FILL);
  gluQuadricTexture(ringbeltTop, GL_TRUE);
  gluQuadricNormals(ringbeltTop, GLU_FLAT); // ringbelt is flat, so no smooth needed
  //Disk with inverted normals for the bottom of ringbelts
  gluQuadricDrawStyle(ringbeltBot, GLU_FILL);
  gluQuadricTexture(ringbeltBot, GL_TRUE);
  gluQuadricOrientation(ringbeltBot, GLU_INSIDE); //setting normals to point on the other side
  gluQuadricNormals(ringbeltBot, GLU_FLAT); // ringbelt is flat, so no smooth needed
  
  //backface culling for the skybox, and to reduce by half the vertices to compute.
  glEnable(GL_CULL_FACE);
  //Enable alpha blending
  glEnable(GL_BLEND);
  
  cerr << "SolarSystem initialised" << endl;
  cout << endl << "Non-required features include:" << endl << "-Displaying axis with the 'i' key." << endl << "-Hiding orbit lines with the 'o' key." << endl << endl << "For more information please refer to the Read_Me.txt in the source folder." <<endl;
}


void SolarSystem::draw_system()
{
	fSemiMajorAxis = 0.0f;
  glLightfv(GL_LIGHT0,    GL_POSITION,    light_position); //Reset light0 position
  glDisable(GL_LIGHT0);
  glEnable(GL_LIGHT1); 
  glDisable(GL_TEXTURE_2D);
  draw_body(0, fSemiMajorAxis); //first, draw the skybox, which will then call to draw the sun, which will call its satellites  etc etc..
}


void SolarSystem::draw_body(int iBody, float &fThisSemiMajorAxis)
{
  float fDegree, fMySatelliteSemiMajorAxis;
  glPushMatrix();  
  
  if (iBody != 0) //If this is not the skybox,
    {
    fThisSemiMajorAxis += 1.5f*_fBodyRadius[iBody];  //Orbital radius is function of the radius of the bodies, to keep them equally separated
    fDegree = fmod(_timeDay*15/_fRotationPeriod[iBody], 360);//Rotation position in degree, long version:	fDegree = fmod(_timeDay*360/(24*_fRotationPeriod[iBody]), 360);    
    glColor3f(0.15f,0.15f,0.15f);
    
  	if (_bOrbital[iBody]) //If this body need to be drawn in an orbital fashion (IE not the skybox, the sun or asteroid belts...)
		  {
		  float x, y, fRadian;
		  glRotatef(_fAscendingNode[iBody],0,0,1); // Longitude of ascending node
		  glRotatef(_fOrbitalIncli[iBody],1,0,0); // Orbital inclinaison
		  glRotatef(_fArgumPeriapsis[iBody],0,0,1); // Argument of Periapsis
	    
	    if (_orbitlines)  //Draw Orbit line
	      {
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 100; i++)
          {
          fRadian = fmod(i*2*M_PI/100, 2*M_PI);//fRadian = fmod(_timeDay*2*M_PI/(24*_fOrbitalPeriod[iBody]), 2*M_PI);
          orbit_calculus(fThisSemiMajorAxis , _eccentricity[iBody], fRadian, x, y);
          glVertex2f( x , y );
          }
        glEnd();
	      }
	    fRadian = fmod(_timeDay*M_PI/(12*_fOrbitalPeriod[iBody]), 2*M_PI);//Orbital position in radian, long version: fRadian = fmod(_timeDay*2*M_PI/(24*_fOrbitalPeriod[iBody]), 2*M_PI);
      orbit_calculus(fThisSemiMajorAxis , _eccentricity[iBody], fRadian, x, y);
		  glTranslatef( x , y , 0 ); //Placing the body on its elliptic orbit
		  }
   	glPushMatrix();
    glRotatef(_fAxialTilt[iBody],1,0,0); // Axial tilt
    glRotatef(fDegree,0,0,1); // Body's rotation
    
    if (_indicators) //draw rotation axis and rotation indicators
    	{
      glColor3f(0.4f,0.4f,0.4f);
      glBegin(GL_LINES);
      glVertex3f( _fBodyRadius[iBody] , 0 , 0 );   glVertex3f( 2*_fBodyRadius[iBody] , 0 , 0 ); 
      glVertex3f(0 , 0 , -2*_fBodyRadius[iBody] ); glVertex3f( 0 , 0 , 2*_fBodyRadius[iBody] ); 
      glEnd();
    	}
    }

  glColor3f(1.0f,1.0f,1.0f);  //default color for proper texture blending
  
	switch (_iBodyType[iBody])
		{
		case 0: //Draw the skybox
      if (_textured)
        {
        glBindTexture(GL_TEXTURE_2D, texNames[iBody]);
        glEnable(GL_TEXTURE_2D);
        gluSphere(skybox, _fBodyRadius[iBody], 50,50);
        glDisable(GL_TEXTURE_2D);
        }
      else
        {
        glColor3f(_glfColor[iBody][0],_glfColor[iBody][1],_glfColor[iBody][2]);  
      	glutWireSphere(_fBodyRadius[iBody], 35,20);
        }
      fMySatelliteSemiMajorAxis = 0.0f;
		break;
		
		case 1: //Draw a Star

      if (_textured)
        {
        glBindTexture(GL_TEXTURE_2D, texNames[iBody]);
        glEnable(GL_TEXTURE_2D);
        gluSphere(sphere, _fBodyRadius[iBody], 100,50);
        glDisable(GL_TEXTURE_2D);
        }
      else
        {
        glColor3f(_glfColor[iBody][0],_glfColor[iBody][1],_glfColor[iBody][2]);  
      	glutWireSphere(_fBodyRadius[iBody], 30,20);
        }
			fMySatelliteSemiMajorAxis = 2.0f*_fBodyRadius[iBody];
		  fThisSemiMajorAxis += 1.5f*_fBodyRadius[iBody]  + 80000.0f/_BodyScaleDiv;
		break;
		
		case 2: //Draw a Planet
      glDisable(GL_LIGHT1);
      glEnable(GL_LIGHT0);
      if (_textured)
        {
        glBindTexture(GL_TEXTURE_2D, texNames[iBody]);
        glEnable(GL_TEXTURE_2D);
        gluSphere(sphere, _fBodyRadius[iBody], 100,50);
        glDisable(GL_TEXTURE_2D);
        }
      else
        {
        glColor3f(_glfColor[iBody][0],_glfColor[iBody][1],_glfColor[iBody][2]);  
      	glutWireSphere(_fBodyRadius[iBody], 30,20);
        }

      glDisable(GL_LIGHT0);
      glEnable(GL_LIGHT1);
			fMySatelliteSemiMajorAxis = 1.5f*_fBodyRadius[iBody];
		  fThisSemiMajorAxis += 1.5f*_fBodyRadius[iBody]  + 80000.0f/_BodyScaleDiv;
 		break;
 		
		case 3: //Draw an Asteroid belt
      glDisable(GL_LIGHT1);
      glEnable(GL_LIGHT0);
      if (_textured)
        {
        glBindTexture(GL_TEXTURE_2D, texNames[iBody]);
        glEnable(GL_TEXTURE_2D);
        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
        gluDisk(ringbeltTop, _fRingInnerRadius[iBody],  _fBodyRadius[iBody]+_fRingInnerRadius[iBody],  50,  1);
        gluDisk(ringbeltBot, _fRingInnerRadius[iBody],  _fBodyRadius[iBody]+_fRingInnerRadius[iBody],  50,  1);
        glDisable(GL_TEXTURE_2D);        
        }
      else
        {
        glColor3f(_glfColor[iBody][0],_glfColor[iBody][1],_glfColor[iBody][2]);  
        glutWireTorus(_fBodyRadius[iBody]/2 , _fRingInnerRadius[iBody]+_fBodyRadius[iBody]/2 , 2, 50);
        }

      glDisable(GL_LIGHT0);
      glEnable(GL_LIGHT1);
		break;
		}
		
  glPopMatrix();

  for (int i = _iFirstSatellite[iBody]; i < _iNbSatellite[iBody]+_iFirstSatellite[iBody]; i++)
  	{  //Draw Satellite(s)
    draw_body(i, fMySatelliteSemiMajorAxis);
  	}
  	
  glPopMatrix();
  
}

void SolarSystem::set_timeDay(int time)
{
	_timeDay += time;
	cout << "solarsystem date: "<< _timeDay%24 << " hours,  "<< (_timeDay/24)%30 << " days,  "<< (_timeDay/720)%12 << " months,  "<< _timeDay/8640 << " years."<< endl; //not yet accurate.
}

void SolarSystem::toggle_texture()
{
	_textured = (_textured + 1)%2 ;
	cout << "Toggle textures"<< endl;
}

void SolarSystem::toggle_orbitlines()
{
	_orbitlines = (_orbitlines + 1)%2 ;
	cout << "Toggle orbit lines"<< endl;
}

void SolarSystem::toggle_indicators()
{
	_indicators = (_indicators + 1)%2 ;
	cout << "Toggle rotation and rotation axis indicators"<< endl;
}

void SolarSystem::orbit_calculus(float a, float e, float angle, float & x, float & y)
{
	x = a*(cos(angle)-e);
	y = a*sqrt(1-e*e)*sin(angle);
}

QImage* SolarSystem::loadImage(std::string filename)
{
  // load image
  QImage img(filename.c_str());

  if (img.isNull())
    {
    cerr << "Unable to load " << filename << endl;
    return NULL;
    }

  cout << "Loading " << filename << ", "  << img.width() << "x" << img.height() << " pixels" << endl;
  // For a more secure and general texture loading procedure, have a
  // look at:
  // http://artis.imag.fr/~Gilles.Debunne/QGLViewer/examples/textureViewer.html

  // convert it to suitable OpenGL 
  QImage* glImg = new QImage(QGLWidget::convertToGLFormat(img));

  return glImg;
}
