#ifndef __LAZER_H
#define __LAZER_H

#include <GL/glui.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>

using namespace std;

GLUquadricObj *cylinder;

GLfloat emeraldAmbient [] = {.0215, .1745, .0215};
GLfloat emeraldDiffuse [] = {.07568, .61424, .07568};
GLfloat emeraldSpecular [] = {.633, .727811, .633};
GLfloat emeraldShininess = .6 * 128;

void drawCylinder()
{ 
  GLfloat pos[] = {0, 1, 0, 1};
  glLightfv(GL_LIGHT0, GL_POSITION, pos);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  cylinder = gluNewQuadric();
  gluQuadricNormals(cylinder, GLU_FLAT);
  gluQuadricDrawStyle(cylinder, GLU_FILL);

  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, emeraldDiffuse);
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, emeraldAmbient);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, emeraldSpecular);
  glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, emeraldShininess);

  gluCylinder(cylinder, .03, .03, .3, 30, 30);
  gluDeleteQuadric(cylinder);
}

#endif
