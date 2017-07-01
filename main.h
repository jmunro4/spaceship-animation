#ifndef MAIN_H
#define MAIN_H

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <jpeglib.h>
#include <jerror.h>
#include "lazer.h"
#include "ship.h"
#include "asteroid.h"

GLuint laserList;
GLuint shipList;
GLuint cockpitList;
GLuint asteroidList;

static const int FPS = 60;
static float curAngle = 0.0;
bool wobble = false;
bool flip = false;
static float vertmove = 0.0;
static float horizmove = 0.0;
bool moveUp = true;
bool moveLeft = true;
static float lasermove = 0.0;
static float astmove = 0.0;
static float astscale = 1.0;
static float explmove = 0.0;

static float astmove1 = 0.0;
static float astmove2 = 0.0;
static float astmove3 = 0.0;
static float astmove4 = 0.0;

// GLUT window
int glutWin;
int width = 800;
int height = 800;

//Texture Variables

// Star Textures
#define starWidth 1920
#define starHeight 1080

unsigned char starImg[3 * starWidth * starHeight];

GLuint starTex;

//Steel Texture
GLuint steelTex;

#define steelWidth 500
#define steelHeight 400

unsigned char steelImg[3 * steelWidth * steelHeight];

//Glass Texture
GLuint glassTex;

#define glassWidth 432
#define glassHeight 432

unsigned char glassImg[3 * glassWidth * glassHeight];

//Asteroid Texture
GLuint asteroidTex;

#define asteroidWidth 300
#define asteroidHeight 300

unsigned char asteroidImg[3* asteroidWidth * asteroidHeight];






int load_texture (const char * filename,
		  unsigned char * dest,
		  const int format,
		  const unsigned int width,
		  const unsigned int height)
{
  FILE *fd;
  struct jpeg_decompress_struct cinfo;
  struct jpeg_error_mgr jerr;
  unsigned char * line;

  cinfo.err = jpeg_std_error (&jerr);
  jpeg_create_decompress (&cinfo);

  if (0 == (fd = fopen(filename, "rb")))
    return 1;

  jpeg_stdio_src (&cinfo, fd);
  jpeg_read_header (&cinfo, TRUE);
  if ((cinfo.image_width != width) || (cinfo.image_height != height))
    return 1;

  if (GL_RGB == format)
  {
    if (cinfo.out_color_space == JCS_GRAYSCALE)
      return 1;
  }
  else
    if (cinfo.out_color_space != JCS_GRAYSCALE)
      return 1;

  jpeg_start_decompress (&cinfo);

  while (cinfo.output_scanline < cinfo.output_height)
  {
    line = dest +
      (GL_RGB == format ? 3 * width : width) * cinfo.output_scanline;
    jpeg_read_scanlines (&cinfo, &line, 1);
  }

  jpeg_finish_decompress (&cinfo);
  jpeg_destroy_decompress (&cinfo);
  return 0;
}

float randomFloat(float a, float b) 
{
  float random = ((float) rand()) / (float) RAND_MAX;
  float diff = b - a;
  float r = random * diff;
  
  return a + r;
}

float rand1 = randomFloat(5,15);
float rand2 = randomFloat(5,15);
float rand3 = randomFloat(5,15);
float randx1 = randomFloat(-7, 7);
float randy1 = randomFloat(1, 7);
float randx2 = randomFloat(-7, 7);
float randy2 = randomFloat(1, 7);
float randx3 = randomFloat(-7, 7);
float randy3 = randomFloat(-2.5, -4);
float randx4 = randomFloat(-7, 7);
float randy4 = randomFloat(-2.5, -4);

#endif
