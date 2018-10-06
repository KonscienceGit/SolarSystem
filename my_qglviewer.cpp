#include "my_qglviewer.h"
#include <QGLWidget>


MyQGLViewer::MyQGLViewer(QWidget *parent)
  : QGLViewer(parent), _myScene(NULL)
{
    //QGLWidget *qglwidget = qobject_cast<QGLWidget>(qApp);
}

void MyQGLViewer::setMyScene(MyScene* myScene)
{
  _myScene = myScene;
}

void MyQGLViewer::init()
{
  // call the scene init method
  _myScene->init();

}


void MyQGLViewer::draw()
{
  // call the scene draw method
  _myScene->draw();

}

void MyQGLViewer::keyPressEvent(QKeyEvent *e)
{
  bool handled = false;

  handled = _myScene->keyPressEvent(e);
  
  if (!handled)
    QGLViewer::keyPressEvent(e);

  // update the window
  //QGLWidget::updateGL();
  MyQGLViewer::update();

}
