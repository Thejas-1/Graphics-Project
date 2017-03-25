#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//#include "vec.h"
//typedef vec3 point3
//#define point3 int

/*GLfloat xRotated, yRotated, zRotated;
GLdouble radius=1;
point3 quad_data[342];*/
//int strip_data[40];


void display(void);
//void reshape(int x, int y);

void myinit()
{
    /*attributes*/
    glClearColor(1.0,1.0,1.0,1.0);
    /*White Background*/
    glColor3f(1.0,0.0,0.0);
    /*Draw in red*/
    /*setup viewing*/
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0,2.0,-2.0,2.0,-2.0,2.0);
    glMatrixMode(GL_MODELVIEW);

}



/*void horizontal()
{
float M_PI = 3.14159;
const float DegreesToRadians = M_PI / 180.0; // M_PI = 3.14159...
//point3

// 8 rows of 18 quads
int k = 0;
float phi,theta;
for(phi = -80.0; phi <= 80.0; phi += 20.0)
{
float phir
= phi*DegreesToRadians;
float phir20 = (phi + 20.0)*DegreesToRadians;
for(theta = -180.0; theta <= 180.0; theta += 20.0)
{
float thetar = theta*DegreesToRadians;
quad_data[k] = (int)(sin(thetar)*cos(phir),cos(thetar)*cos(phir), sin(phir));
k++;
quad_data[k] = (int)(sin(thetar)*cos(phir20),cos(thetar)*cos(phir20), sin(phir20));
k++;
}
}
}*/

/*void vertical()
{
float M_PI = 3.14159;
const float DegreesToRadians = M_PI / 180.0; // M_PI = 3.14159...
int k = 0;
//point3
strip_data[k] = (int)(0.0, 0.0, 1.0);
k++;
float sin80 = sin(80.0*DegreesToRadians);
float cos80 = cos(80.0*DegreesToRadians);
float theta;
for(theta = -180.0; theta <= 180.0; theta += 20.0)
{
float thetar = theta*DegreesToRadians;
strip_data[k] = (int)(sin(thetar)*cos80,cos(thetar)*cos80, sin80);
k++;
}
strip_data[k] = (int)(0.0, 0.0, -1.0);
k++;
for(theta = -180.0; theta <= 180.0; theta += 20.0)
{
float thetar = theta;
strip_data[k] = (int)(sin(thetar)*cos80,cos(thetar)*cos80, sin80);
k++;
}
}*/
int X,Y,Z;
void display()
{
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glColor3f(0.0,0.0,1.0);
  glLoadIdentity();
  float phir,phi,phir20,theta,thetar;
  const float c=(3.14/180);
  for(phi=-80.0;phi<=80.0;phi+=20.0)
  {
    phir = phi*c;
    phir20 = (phi+20.0)*c;
    thetar = theta*c;
    glBegin(GL_QUAD_STRIP);
    glColor3f(1.0,0.0,0.0);
    for(theta=-180.0;theta<=180.0;theta+=20.0)
    {
        thetar = theta*c;
        X = sin(thetar)*cos(phir);
        Y = cos(thetar)*sin(phir);
        Z = sin(phir);
        glVertex3d(X,Y,Z);
        X=sin(thetar)*cos(phir20);
        Y=cos(thetar)*sin(phir20);
        Z=sin(phir);
        glVertex3d(X,Y,Z);
    }
    glEnd();
    glFlush();
  }



}

void myReshape(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h)
    glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
    else
    glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();


}


int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutCreateWindow("Solid Sphere");
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);


    glutDisplayFunc(display);
    myinit();
   glutReshapeFunc(myReshape);
    glutMainLoop();
    return 0;
}

