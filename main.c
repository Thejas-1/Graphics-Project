
#include <math.h>
//#include <iostream>
#include <GL/glut.h>

#define PI 3.14159265

//using namespace std;

// Globals.
static float R = 5.0; // Radius of hemisphere.
static int p = 12; // Number of longitudinal slices.
static int q = 10; // Number of latitudinal slices.
static float Xangle = 0.0, Yangle = 0.0, Zangle = 0.0; // Angles to rotate hemisphere.

// Drawing routine.
void display(void)
{
   int  i, j;

   glClear (GL_COLOR_BUFFER_BIT);

   glLoadIdentity(); //Always used before glTranslate or any other matrix transformation so that the present matrix is converted into identity matrix to start from fresh


   glTranslatef(0.0, 0.0, -10.0); // Command to push the hemisphere, which is drawn centered at the origin,
   // into the viewing frustum.

   // Commands to turn the hemisphere.
   glRotatef(Zangle, 0.0, 0.0, 1.0);
   glRotatef(Yangle, 0.0, 1.0, 0.0);
   glRotatef(Xangle, 1.0, 0.0, 0.0);

   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
   glColor3f(0.0, 0.0, 0.0);

   // Array of latitudinal quadrilateral strips, each parallel to the equator, stacked one
   // above the other from the equator to the north pole.
   for(j = 0; j < q; j++)
   {
      // One latitudinal triangle strip.
      glBegin(GL_QUAD_STRIP);
         for(i = 0; i <= p; i++)
		 {
            glVertex3f( R * cos( (float)(j+1)/q * PI/2.0 ) * cos( 2.0 * (float)i/p * PI ),
                        R * sin( (float)(j+1)/q * PI/2.0 ),
					    R * cos( (float)(j+1)/q * PI/2.0 ) * sin( 2.0 * (float)i/p * PI ) );
            glVertex3f( R * cos( (float)j/q * PI/2.0 ) * cos( 2.0 * (float)i/p * PI ),
                        R * sin( (float)j/q * PI/2.0 ),
					    R * cos( (float)j/q * PI/2.0 ) * sin( 2.0 * (float)i/p * PI ) );
		 }
      glEnd();
   }

   glFlush();
}

// Initialization routine.
void setup(void)
{
   glClearColor(1.0, 1.0, 1.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
   glViewport(0, 0, (GLsizei)w, (GLsizei)h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
   // gluPerspective(90.0, 1.0, 5.0, 100.0);
   // gluPerspective(90.0, (float)w/(float)h, 5.0, 100.0);

   glMatrixMode(GL_MODELVIEW);
}

// Keyboard input processing routine.
/*void keyInput(unsigned char key, int x, int y)
{
   switch(key)
   {
      case 27:
         exit(0);
         break;
      case 'P':
         p += 1;
         glutPostRedisplay();
         break;
      case 'p':
         if (p > 3) p -= 1;
         glutPostRedisplay();
         break;
      case 'Q':
         q += 1;
         glutPostRedisplay();
         break;
      case 'q':
         if (q > 3) q -= 1;
         glutPostRedisplay();
         break;
      case 'x':
         Xangle += 5.0;
		 if (Xangle > 360.0) Xangle -= 360.0;
         glutPostRedisplay();
         break;
      case 'X':
         Xangle -= 5.0;
		 if (Xangle < 0.0) Xangle += 360.0;
         glutPostRedisplay();
         break;
      case 'y':
         Yangle += 5.0;
		 if (Yangle > 360.0) Yangle -= 360.0;
         glutPostRedisplay();
         break;
      case 'Y':
         Yangle -= 5.0;
		 if (Yangle < 0.0) Yangle += 360.0;
         glutPostRedisplay();
         break;
      case 'z':
         Zangle += 5.0;
		 if (Zangle > 360.0) Zangle -= 360.0;
         glutPostRedisplay();
         break;
      case 'Z':
         Zangle -= 5.0;
		 if (Zangle < 0.0) Zangle += 360.0;
         glutPostRedisplay();
         break;
      default:
         break;
   }
}*/

// Routine to output interaction instructions to the C++ window.
/*void printInteraction(void)
{
   cout << "Interaction:" << endl;
   cout << "Press P/p to increase/decrease the number of longitudinal slices." << endl
        << "Press Q/q to increase/decrease the number of latitudinal slices." << endl
        << "Press x, X, y, Y, z, Z to turn the hemisphere." << endl;
}*/

// Main routine.
int main(int argc, char **argv)
{
   //printInteraction();
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("hemisphere.cpp");
   setup();
   glutDisplayFunc(display);
   glutReshapeFunc(resize);
  // glutKeyboardFunc(keyInput);
   glutMainLoop();

   return 0;
}
