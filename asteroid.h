#define X .525731112119133606
#define Z .850650808352039932

/* Set up the vertex info for an Icosahedron */
static GLfloat IcosahedronVertices[12][3] = 
{
  {-X, 0.0, Z}, {X, 0.0, Z}, {-X, 0.0, -Z}, {X, 0.0, -Z},
  {0.0, Z, X}, {0.0, Z, -X}, {0.0, -Z, X}, {0.0, -Z, -X},
  {Z, X, 0.0}, {-Z, X, 0.0}, {Z, -X, 0.0}, {-Z, -X, 0.0}
};

/* Set up how the vertices go together for an Icosahedron*/
static GLuint IcoIndices[20][3] =
{

  {1, 4, 0}, {4, 9, 0}, {4, 5, 9}, {8, 5, 4},
  {1, 8, 4}, {1, 10, 8}, {10, 3, 8}, {8, 3, 5},
  {3, 2, 5}, {3, 7, 2}, {3, 10, 7}, {10, 6, 7},
  {6, 11, 7}, {6, 0, 11}, {6, 1, 0}, {10, 1, 6},
  {11, 0, 9}, {2, 11, 9}, {5, 2, 9}, {11, 2, 7}
};

void triangleSubDivide(GLfloat* v1, GLfloat* v2, GLfloat* v3, int num)
{
  if(num == 0)
    {
    
      glBegin(GL_TRIANGLES);
      glTexCoord2f(0.0,0.0);
      glNormal3fv(v1);
      glVertex3fv(v1);
      glTexCoord2f(1.0, 0.0);
      glNormal3fv(v2);
      glVertex3fv(v2);
      glTexCoord2f(0.0, 1.0);
      glNormal3fv(v3);
      glVertex3fv(v3);
      glEnd();
    }
  else
    {
      GLfloat mid1[3] = {(v1[0]+v2[0])/2, (v1[1]+v2[1])/2, (v1[2]+v2[2])/2};
      GLfloat mid2[3] = {(v1[0]+v3[0])/2, (v1[1]+v3[1])/2, (v1[2]+v3[2])/2};
      GLfloat mid3[3] = {(v3[0]+v2[0])/2, (v3[1]+v2[1])/2, (v3[2]+v2[2])/2};

      GLfloat dm1 = sqrt(pow(mid1[0], 2)+pow(mid1[1], 2)+pow(mid1[2], 2));
      GLfloat dm2 = sqrt(pow(mid2[0], 2)+pow(mid2[1], 2)+pow(mid2[2], 2));
      GLfloat dm3 = sqrt(pow(mid3[0], 2)+pow(mid3[1], 2)+pow(mid3[2], 2));

      GLfloat mid1Norm[3] = {mid1[0]/dm1, mid1[1]/dm1, mid1[2]/dm1};
      GLfloat mid2Norm[3] = {mid2[0]/dm2, mid2[1]/dm2, mid2[2]/dm2};
      GLfloat mid3Norm[3] = {mid3[0]/dm3, mid3[1]/dm3, mid3[2]/dm3};
 
      triangleSubDivide(v1, mid1Norm, mid2Norm, num-1);
      triangleSubDivide(mid1Norm, v2, mid3Norm, num-1);
      triangleSubDivide(mid2Norm, mid3Norm, v3, num-1);
      triangleSubDivide(mid1Norm, mid3Norm, mid2Norm, num-1);
   }
}

void drawIcos()
{
  glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, IcosahedronVertices);
  
  for(int i = 0; i < 20; i++)
    {
      GLfloat v1[3] = {IcosahedronVertices[IcoIndices[i][0]][0], IcosahedronVertices[IcoIndices[i][0]][1], IcosahedronVertices[IcoIndices[i][0]][2]}; 
      GLfloat v2[3] = {IcosahedronVertices[IcoIndices[i][1]][0], IcosahedronVertices[IcoIndices[i][1]][1], IcosahedronVertices[IcoIndices[i][1]][2]};
      GLfloat v3[3] = {IcosahedronVertices[IcoIndices[i][2]][0], IcosahedronVertices[IcoIndices[i][2]][1], IcosahedronVertices[IcoIndices[i][2]][2]};
      triangleSubDivide(v1, v2, v3, 1);
    }
  glDisableClientState(GL_VERTEX_ARRAY);
}

void drawSphere()
{
  GLUquadricObj *sphere1;
  sphere1 = gluNewQuadric();
  gluQuadricDrawStyle(sphere1,GLU_FILL);
  gluSphere(sphere1,1,20,20);
}
