#include "my_scene.h"


using namespace std;

/** 
 * Constructor
 * 
 * @param radius 
 */
MyScene::MyScene(float radius)
{
  std::cout << "constructing :  MyScene" << std::endl;

  _currentObject = MyScene::SOLARSYSTEM;
  _numberOfObjects = 1;	         // increment it when you add a new 3D object!

  _radius = radius;

  _radiusMin = 0.1;
  _radiusMax = 2.0;
  _radiusIncr = 0.1;
}

/** 
 * Destructor
 * 
 */
MyScene::~MyScene()
{
  std::cout<<"~MyScene"<<std::endl;
}

/** 
 * Init the scene and OpenGL state
 * 
 */
void MyScene::init()
{
  cerr << "MyScene::init called" << endl;
  glColor3f(0.5, 0., 0.);

  // set antialiased lines
  glEnable(GL_LINE_SMOOTH);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
  glLineWidth(1.5);
  glEnable(GL_NORMALIZE); // normalize normal vectors when objects are scaled
  //set scene lightning
  _solarsystem.init_system();
}

/** 
 * Draw the scene
 * 
 */
void MyScene::draw()
{
  cerr << "Myscene::draw called" << endl;
  glPushMatrix();
  glScalef(_radius/2, _radius/2, _radius/2);

  //Performance evaluation /*  clock_t start, end;  start = clock();  */  //comment out this section
  _solarsystem.draw_system();

  //Performance evaluation /*  end = clock();  cout << "Time required for execution: " << (double)(end-start)/CLOCKS_PER_SEC << " seconds." << "\n\n"; */  //comment out this section

  glPopMatrix();
}

/** 
 * Slot set current object
 * 
 * @param currentObject
 */
void MyScene::slotSetCurrentObject(int currentObject)
{
  std::cout << "slotSetCurrentObject "<< currentObject << std::endl;
  _currentObject = currentObject;
  emit sigCurrentObjectChanged(currentObject);
  
}

/** 
 * Slot set display mode
 * 
 * @param currentObject
 */
/*void MyScene::slotSetDisplayMode(int displayMode)
{

  std::cout << "slotSetDisplayMode "<< displayMode%3 << std::endl;
  _displayMode = displayMode;

  switch (displayMode%3) {
  case MyScene::WIREFRAME:
      cerr << "Wireframe mode activated"<< endl;
    glDisable(GL_LIGHTING);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    break;
  case MyScene::FLATSHADED: 
      cerr << "FlatShaded mode activated"<< endl;
    glEnable(GL_LIGHTING);
    glShadeModel(GL_FLAT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    break;
  case MyScene::SMOOTHSHADED:
      cerr << "SmoothShaded mode activated"<< endl;
    glEnable(GL_LIGHTING);
    glShadeModel(GL_SMOOTH);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    break;
  }

  emit sigDisplayModeChanged(displayMode);
}*/


/** 
 * Slot set radius
 * 
 * @param radius 
 */
void MyScene::slotSetRadius(double radius)
{
  if (fabs(_radius - float(radius))>1e-6) {
    //std::cout << "slotSetRadius "<< radius << std::endl;
    _radius = radius;
    emit sigRadiusChanged(radius);
  }
}

/** 
 * Process keyboard events for QGLViewer widget
 * 
 * @param e a keyboard event from QGLViewer 
 * 
 * @return true if the event has been handled
 */
bool MyScene::keyPressEvent(QKeyEvent *e)
{
  const Qt::KeyboardModifiers modifiers = e->modifiers();

  // A simple switch on e->key() is not sufficient if we want to take
  // state key into account.  With a switch, it would have been
  // impossible to separate 'F' from 'CTRL+F'.  That's why we use
  // imbricated if...else and a "handled" boolean.

  bool handled = false;

  float epsilon = 1e-5;  // for float comparison
  
  // Increase radius with 'r'
  if ((e->key()==Qt::Key_R) && (modifiers==Qt::NoButton)) {
    if (_radius+_radiusIncr <= _radiusMax + epsilon)
      this->slotSetRadius(_radius+_radiusIncr);
    handled = true;
  } 
  // Decrease radius with 'R'
  else if ((e->key()==Qt::Key_R) && (modifiers==Qt::SHIFT)) {
    if (_radius-_radiusIncr >= _radiusMin - epsilon)
      this->slotSetRadius(_radius-_radiusIncr);
    handled = true;
  }
      
  // Decrease current displayed object with 'O'
  else if ((e->key()==Qt::Key_O) && (modifiers==Qt::SHIFT)) {
    this->slotSetCurrentObject(_currentObject-1);
    handled = true;
  }
      
  // change display mode with 'f'
  else if ((e->key()==Qt::Key_F) && (modifiers==Qt::NoButton)) {
    _solarsystem.nextDisplayMode();
    handled = true;
  }
  

  // increment time by 1 month with 'm'
  else if ((e->key()==Qt::Key_M) && (modifiers==Qt::NoButton)) {
    _solarsystem.set_timeDay(720);
    handled = true;
  }

  // decrement time by 1 month with 'M'
  else if ((e->key()==Qt::Key_M) && (modifiers==Qt::SHIFT)) {
    _solarsystem.set_timeDay(-720);
    handled = true;
  }

  // increment time by 1 week with 's'
  else if ((e->key()==Qt::Key_S) && (modifiers==Qt::NoButton)) {
    _solarsystem.set_timeDay(175);
    handled = true;
  }

  // decrement time by 1 week with 'S'
  else if ((e->key()==Qt::Key_S) && (modifiers==Qt::SHIFT)) {
    _solarsystem.set_timeDay(-175);
    handled = true;
  }
  // increment time by 1 day with 'j'
  else if ((e->key()==Qt::Key_J) && (modifiers==Qt::NoButton)) {
    _solarsystem.set_timeDay(24);
    handled = true;
  }

  // decrement time by 1 day with 'J'
  else if ((e->key()==Qt::Key_J) && (modifiers==Qt::SHIFT)) {
    _solarsystem.set_timeDay(-24);
    handled = true;
  }
  // increment time by 1 hour with 'h'
  else if ((e->key()==Qt::Key_H) && (modifiers==Qt::NoButton)) {
    _solarsystem.set_timeDay(1);
    handled = true;
  }
  
  // decrement time by 1 hour with 'H'
  else if ((e->key()==Qt::Key_H) && (modifiers==Qt::SHIFT)) {
    _solarsystem.set_timeDay(-1);
    handled = true;
  }
  
  // Toggle draw texture
  else if ((e->key()==Qt::Key_T) && (modifiers==Qt::NoButton)) {
    _solarsystem.toggle_texture();
    handled = true;
  }
  
    // Toggle orbit lines
  else if ((e->key()==Qt::Key_O) && (modifiers==Qt::NoButton)) {
    _solarsystem.toggle_orbitlines();
    handled = true;
  }
  
    // Toggle axis and rotation indicators
  else if ((e->key()==Qt::Key_I) && (modifiers==Qt::NoButton)) {
    _solarsystem.toggle_indicators();
    handled = true;
  }
      // ... and so on with other else/if blocks.

  return handled;
}
