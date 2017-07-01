#include "main.h"
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <jpeglib.h>
#include <jerror.h>

void init()
{
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glEnable(GL_DEPTH_TEST);

  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

  //Background Texture
  glGenTextures(1, &starTex);
  load_texture("stars.jpg", starImg, GL_RGB, starWidth, starHeight);
  glBindTexture(GL_TEXTURE_2D, starTex);

  gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, starWidth, starHeight, GL_RGB, GL_UNSIGNED_BYTE, starImg);
  
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

  glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
  glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);

  //Spaceship Texture
  glGenTextures(2, &steelTex);
  load_texture("steel.jpg", steelImg, GL_RGB, steelWidth, steelHeight);
  glBindTexture(GL_TEXTURE_2D, steelTex);

  gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, steelWidth, steelHeight, GL_RGB, GL_UNSIGNED_BYTE, steelImg);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
  glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);

  //Glass Textures
  glGenTextures(3, &glassTex);
  load_texture("glass.jpg", glassImg, GL_RGB, glassWidth, glassHeight);
  glBindTexture(GL_TEXTURE_2D, glassTex);

  gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, glassWidth, glassHeight, GL_RGB, GL_UNSIGNED_BYTE, glassImg);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

  //Asteroid Texture
  glGenTextures(4, &asteroidTex);
  load_texture("rock1.jpg", asteroidImg, GL_RGB, asteroidWidth, asteroidHeight);
  glBindTexture(GL_TEXTURE_2D, asteroidTex);

  gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, asteroidWidth, asteroidHeight, GL_RGB, GL_UNSIGNED_BYTE, asteroidImg);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
  glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
  
  //laser list
  laserList = glGenLists(1);
  glNewList(laserList, GL_COMPILE);
  drawCylinder();
  glEndList();

  //ship list
  shipList = glGenLists(1);
  glNewList(shipList, GL_COMPILE);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, steelTex);
  drawShip();
  glDisable(GL_TEXTURE_2D);
  glEndList();
  
  //cockpit list
  cockpitList = glGenLists(1);
  glNewList(cockpitList, GL_COMPILE);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, glassTex);
  drawCockpit();
  glDisable(GL_TEXTURE_2D);
  glEndList();
  
  //asteroid list
  asteroidList = glGenLists(1);
  glNewList(asteroidList, GL_COMPILE);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, asteroidTex);
  drawIcos();
  glDisable(GL_TEXTURE_2D);
  glEndList();



  glMatrixMode(GL_PROJECTION);

}


void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0, (GLfloat) width / (GLfloat) height, 1.0, 225);  
  
  // Draw the background in orthographic view
  glPushMatrix();
  glLoadIdentity();
  gluOrtho2D(0.0, 1.0, 0.0, 1.0);

  // Draw the texture map to the background
  glMatrixMode(GL_MODELVIEW);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, starTex);

  // Disable auto texture coordinates for background
  glDisable(GL_TEXTURE_GEN_S);
  glDisable(GL_TEXTURE_GEN_T);

  // No depth info needed for orthographic view
  glDepthMask(GL_FALSE);
  // Draw a background wall
  glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex2f(0.0, 0.0);
    glTexCoord2f(1.0, 0.0);
    glVertex2f(1.0, 0.0);
    glTexCoord2f(1.0, 1.0);
    glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0);
    glVertex2f(0.0, 1.0);
  glEnd();

  // Switch back to 3D
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);

  // Now we do need depth info
  glDepthMask(GL_TRUE);
  
  //Disable texture mapping
  glDisable(GL_TEXTURE_2D);

  glPushMatrix();
  glTranslatef(0.0, -1.0, -7.0);
  glRotatef(-80, 1.0, 0.0, 0.0);
  glRotatef(90, 0.0, 0.0, 1.0);
  glRotatef(curAngle, 1.0, 0.0, 0.0);
  glTranslatef(0.0, horizmove, vertmove);
  glScalef(0.5, 0.5, 0.5);
  glCallList(shipList);
  glPushMatrix();
  glScalef(1.0, 3.0, 1.0);
  glCallList(cockpitList);
  glPopMatrix();

  // Laser
  glPushMatrix();
  glTranslatef(1, 2.96, 0);
  glRotatef(90, 0, 1, 0);
  glTranslatef(-lasermove/10, lasermove/7, -lasermove);
  glScalef(5.0, 5.0, 5.0);
  glCallList(laserList);
  glPopMatrix();

  // Laser
  glPushMatrix();
  glTranslatef(1, -2.96, 0);
  glRotatef(90, 0, 1, 0);
  glTranslatef(-lasermove/10, -lasermove/7, -lasermove);
  glScalef(5.0, 5.0, 5.0);
  glCallList(laserList);
  glPopMatrix();
  glPopMatrix();

  // Head-on Astroid
  glPushMatrix();
  glTranslatef(rand2*explmove, rand1* explmove, -255 + astmove);
  glScalef(astscale, astscale, astscale);
  glCallList(asteroidList);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(-rand2*explmove, rand3*explmove, -255 + astmove);
  glScalef(astscale, astscale, astscale);
  glCallList(asteroidList);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(rand1*explmove, -rand3*explmove, -255 + astmove);
  glScalef(astscale, astscale, astscale);
  glCallList(asteroidList);
  glPopMatrix();

  // Astroids
  glPushMatrix();
  glTranslatef(randx1, randy1, -300 + astmove1);
  glCallList(asteroidList);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(randx2, randy2, -350 + astmove2);
  glCallList(asteroidList);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(randx3, randy3, -275 + astmove3);
  glCallList(asteroidList);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(randx4, randy4, -325 + astmove4);
  glCallList(asteroidList);
  glPopMatrix();
  
  glutSwapBuffers();
  glFlush();
}

void reshape(int w, int h)
{
  width = w;
  height = h;

  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0, (GLfloat) w / (GLfloat) h, 1.0, 225);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void timer(int v)
{
  if(wobble)
    {
      // wobble
      if(curAngle > 15.0)
	  flip = true;
      else if(curAngle < -15.0)
	  flip = false;
      
      if(flip == false)
      	  curAngle += .5;
      else
      	  curAngle -= .5;

      // oscillate
      if(vertmove > 0.40)
	  moveUp = false;
      else if(vertmove < -0.35)
	  moveUp = true;

      if(moveUp == false)
      	  vertmove -= 0.01;
      else
      	  vertmove += 0.01;

      if(horizmove > 0.45)
	  moveLeft = false;
      else if(horizmove < -0.45)
	  moveLeft = true;
      
      if(moveLeft == false)
      	  horizmove -= 0.01;
      else
      	  horizmove += 0.01;
      // lasers
      if(lasermove <= -20)
	  lasermove = 0;
      else
	lasermove -= 0.7;
      // astroid
      if(astmove < 200) // expl point
	{
	  astmove++;
	}
      else if(astmove < 255) 
	{
	  astscale = 0.33;
	  explmove += 0.005;
	  astmove++;
	}
      else
	{
	  astmove = 0.0;
	  astscale = 1.0;
	  explmove = 0.0;
	  rand1 = randomFloat(6,15);
	  rand2 = randomFloat(6,15);
	  rand3 = randomFloat(6,15);
	}

      if(astmove1 < 300)
	{
	  astmove1+=2 ;
	}
      else
	{
	  astmove1 = 0.0;
	  randx1 = randomFloat(-7, 7);
	  randy1 = randomFloat(1, 7);
	}

      if(astmove2 < 350)
	{
	  astmove2+=1.5;
	}
      else
	{
	  astmove2 = 0.0;
	  randx2 = randomFloat(-7, 7);
	  randy2 = randomFloat(1, 7);
	}

      if(astmove3 < 275)
	{
	  astmove3+=1.2;
	}
      else
	{
	  astmove3 = 0.0;
	  randx3 = randomFloat(-7, 7);
	  randy3 = randomFloat(-2.5, -4);
	}

      if(astmove4 < 325)
	{
	  astmove4+=1.7;
	}
      else
	{
	  astmove4 = 0.0;
	  randx4 = randomFloat(-7, 7);
	  randy4 = randomFloat(-2.5, -4);
	}


      glutPostRedisplay();
    }
  glutTimerFunc(1000/FPS, timer, v);
  
}

void mouse(int button, int state, int x, int y)
{
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
      if(wobble == true)
	wobble = false;
      else
	wobble = true;
    }
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(width, height);

  glEnable(GL_DEPTH_TEST);

  glutWin = glutCreateWindow("Movie");
  init();
  glutDisplayFunc(display);
  glutMouseFunc(mouse);
  glutTimerFunc(100, timer, 0);

  glutMainLoop();
}
