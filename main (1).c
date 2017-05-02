#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/gl.h>
//#include <windows.h>
#include <GL/glu.h>
#include <math.h>
#ifdef __unix__
# include <unistd.h>
#elif defined _WIN32
# include <windows.h>
#define sleep(x) Sleep(1000 * x)
#endif
// angle of rotation for the camera direction
float angle=0.0;
// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f;
// XZ position of the camera
float x=0.0f,z=5.0f;
int i;
void displaysolid();
void myReshape ( int w, int h );
void spinCube ( );
void createHourGlass();
void mouse ( int btn, int state, int x, int y );
void curvedraw(GLfloat [4][3]);
GLfloat ctrlpoints1[4][3] = {
        { 255.0, 260.0, 0.0}, { 280.0, 300.0, 0.0},
        {290.0, 350.0, 0.0}, {300.0, 400.0, 0.0}};
GLfloat ctrlpoints2[4][3] = {
        { 245.0, 260.0, 0.0}, { 220.0, 300.0, 0.0},
        {210.0, 350.0, 0.0}, {200.0, 400.0, 0.0}};
GLfloat ctrlpoints3[4][3] = {
        { 245.0, 240.0, 0.0}, { 220.0, 200.0, 0.0},
        {210.0, 150.0, 0.0}, {200.0, 100.0, 0.0}};
GLfloat ctrlpoints4[4][3] = {
        { 255.0, 240.0, 0.0}, { 280.0, 200.0, 0.0},
        {290.0, 150.0, 0.0}, {300.0, 100.0, 0.0}};

float p1[60],q1[60],p2[60],q2[60],p3[60],q3[60],p4[60],q4[60];
int k;
void values1()
{
    int i;
    p1[0]=200.0;
    q1[0]=400.0;
    for(i=0;i<60;i++)
    {
        p1[i+1] = p1[i]+0.75;
    }

    for(i=0;i<61;i++)
    {
        q1[i] = (9200.0-28.0*p1[i])/9.0;
    }
}
void values2()
{
    int i;
    p2[0]=300.0;
    q2[0]=400.0;
    for(i=0;i<60;i++)
    {
        p2[i+1]=p2[i]-0.75;
    }
    for(i=0;i<61;i++)
    {
        q2[i] = (28*p2[i]-4800)/9;
    }
}
void values3()
{
    int i;
    p3[0]=200.0;
    q3[0]=100.0;
    for(i=0;i<60;i++)
    {
        p3[i+1]=p3[i]+0.75;
    }
    for(i=0;i<61;i++)
    {
        q3[i] = (28*p3[i]-4700)/9;
    }
}
void values4()
{
    int i;
    p4[0]=300.0;
    q4[0]=100.0;
    for(i=0;i<60;i++)
    {
        p4[i+1]=p4[i]-0.75;
    }

    for(i=0;i<61;i++)
    {
        q4[i] = (9300-28*p4[i])/9;
    }
}
void drawHollowCircle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * M_PI;
	glBegin(GL_LINE_LOOP);
		for(i = lineAmount; i >= 0;i--) {
			glVertex2f(
			   x + (radius * cos(i *  twicePi / lineAmount)),
			   y + (radius* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
}
void wall(double thickness)
{
	glPushMatrix();
	glTranslated(0.5,0.5*thickness,0.5);
	glScaled(1.0,thickness,1.0);
	glutSolidCube(1.0);
	glPopMatrix();
}
void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3i(1,0,0);
    glPointSize(5.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glLineWidth(2.0);
    gluOrtho2D(0.0,499.0,0.0,499.0);
    glShadeModel(GL_FLAT);
}
void draw(float p1[],float q1[],float p2[],float q2[])
{
        glBegin(GL_LINES);
        glVertex2f(p1[k],q1[k]);
        glVertex2f(p2[k],q2[k]);
        glEnd();
        glFlush();
}

void sleep1()
{
    for(i=0;i<160;i++)
    {
        glColor3f(1.0,1.0,0.0);
        glBegin(GL_POINTS);
       // drawHollowCircle(247.0,260.0-i,1.0);
        drawHollowCircle(250.0,260.0-i,1.0);
      //  drawHollowCircle(253.0,260.0-i,1.0);
        glEnd();
        glFlush();
        usleep(6250);
    }

}

/*void drawRightHalfCircle(float x,float y,float r)  // the empty one
{
    float i;
    //glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    float radius = r;
    float twoPI = 2 * M_PI;
    glMatrixMode(GL_MODELVIEW); //operate in model view
    glLoadIdentity();//after every matrixmode, loadidentity is used.
    glTranslatef(x,y, 0.0f);
    glRotatef(-90,0.0,0.0,1.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
    for (i = 0.0; i <= twoPI / 2; i += 0.001)
        glVertex2f((sin(i)*radius), (cos(i)*radius));

    glEnd();
    glFlush();
}*/


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    displaysolid();
    float i,j,r;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
    drawHollowCircle(250.0,400.0,50.0);
    drawHollowCircle(250.0,100.0,50.0);
    glFlush();
    curvedraw(ctrlpoints1);
    curvedraw(ctrlpoints2);
    curvedraw(ctrlpoints3);
    curvedraw(ctrlpoints4);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(255.0,260.0);
    glVertex2f(255.0,240.0);
    glVertex2f(245.0,240.0);
    glVertex2f(245.0,260.0);
    glEnd();
    glFlush();
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(255.0,260.0);
    glVertex2f(255.0,240.0);
    glVertex2f(245.0,240.0);
    glVertex2f(245.0,260.0);
    glVertex2f(200.0,400.0);
    glVertex2f(245.0,260.0);
    glVertex2f(300.0,400.0);
    glVertex2f(255.0,260.0);
    glVertex2f(200.0,100.0);
    glVertex2f(245.0,240.0);
    glVertex2f(300.0,100.0);
    glVertex2f(255.0,240.0);
    glEnd();
    //createHourGlass();
    glColor3f(1.0,1.0,0.0);
    for(k=0;k<60;k++)
    {
        draw(p1,q1,p2,q2);
    }
    for(k=0;k<60;k++)
    {
        glColor3f(1.0,1.0,0.0);
        draw(p3,q3,p4,q4);

       r = 49-k;
    /*    if(r>0)
        drawRightHalfCircle(250.0,100.0,r); */
        drawHollowCircle(250.0,100.0,r);
        glFlush();
        glColor3f(0.1,0.1,0.1);
        draw(p1,q1,p2,q2);
  //      r = 49-k;
 //       if(r>0)
//        drawRightHalfCircle(250.0,100.0,r);
        sleep1();
    }
    glFlush();
    glColor3f(1.0, 0.0, 0.0);
    drawHollowCircle(250.0,400.0,50.0);
    glFlush();
    //glutSwapBuffers();
}
void displayrev()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    displaysolid();
    float i,j;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
    drawHollowCircle(250.0,400.0,50.0);
    drawHollowCircle(250.0,100.0,50.0);
    glFlush();
    curvedraw(ctrlpoints1);
    curvedraw(ctrlpoints2);
    curvedraw(ctrlpoints3);
    curvedraw(ctrlpoints4);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(255.0,260.0);
    glVertex2f(255.0,240.0);
    glVertex2f(245.0,240.0);
    glVertex2f(245.0,260.0);
    glEnd();
    glFlush();
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(255.0,260.0);
    glVertex2f(255.0,240.0);
    glVertex2f(245.0,240.0);
    glVertex2f(245.0,260.0);
    glVertex2f(200.0,400.0);
    glVertex2f(245.0,260.0);
    glVertex2f(300.0,400.0);
    glVertex2f(255.0,260.0);
    glVertex2f(200.0,100.0);
    glVertex2f(245.0,240.0);
    glVertex2f(300.0,100.0);
    glVertex2f(255.0,240.0);
    //createHourGlass();
    glColor3f(1.0,1.0,0.0);
    for(k=0;k<60;k++)
    {
        draw(p3,q3,p4,q4);
    }
    for(k=0;k<60;k++)
    {
        glColor3f(1.0,1.0,0.0);
        draw(p1,q1,p2,q2);
        glColor3f(0.1,0.1,0.1);
        draw(p3,q3,p4,q4);
        sleep1();
    }
    glEnd();
    glFlush();
    glColor3f(1.0, 0.0, 0.0);
    drawHollowCircle(250.0,400.0,50.0);
    glFlush();
    sleep(2);
}
void display1()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    displaysolid();
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
    drawHollowCircle(250.0,400.0,50.0);
    drawHollowCircle(250.0,100.0,50.0);
    glFlush();
    curvedraw(ctrlpoints1);
    curvedraw(ctrlpoints2);
    curvedraw(ctrlpoints3);
    curvedraw(ctrlpoints4);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(255.0,260.0);
    glVertex2f(255.0,240.0);
    glVertex2f(245.0,240.0);
    glVertex2f(245.0,260.0);
    glEnd();
    glFlush();
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(255.0,260.0);
    glVertex2f(255.0,240.0);
    glVertex2f(245.0,240.0);
    glVertex2f(245.0,260.0);
    glVertex2f(200.0,400.0);
    glVertex2f(245.0,260.0);
    glVertex2f(300.0,400.0);
    glVertex2f(255.0,260.0);
    glVertex2f(200.0,100.0);
    glVertex2f(245.0,240.0);
    glVertex2f(300.0,100.0);
    glVertex2f(255.0,240.0);
    for(k=0;k<60;k++)
    {
        glColor3f(1.0,1.0,0.0);
        draw(p3,q3,p4,q4);
        glColor3f(0.1,0.1,0.1);
        draw(p1,q1,p2,q2);
    }
    glEnd();
    glFlush();
    sleep(1);
}
void displaysolid()
{
    GLfloat mat_ambient[]={0.7f,0.7f,0.7f,1.0f};
	GLfloat mat_diffuse[]={0.5f,0.5f,0.5f,1.0f};
	GLfloat mat_specular[]={1.0f,1.0f,1.0f,1.0f};
	GLfloat mat_shininess[]={50.0f};

	//The glMaterialfv function specifies material parameters for the lighting model.
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	GLfloat lightIntensity[]={0.7f,0.7f,0.7f,0.7f};
	GLfloat light_position[]={2.0f,6.0f,3.0f,0.0f};

	//The glLightfv function returns light source parameter values.
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);
}
void mouse ( int btn, int state, int x, int y )
{
     int a,b;
     if ( btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
    {
        glTranslatef(250,250,0.0);
        glRotatef(-45,0.0,0.0,1.0);
        glTranslatef(-250,-250,0.0);
        display1();
        glTranslatef(250,250,0.0);
        glRotatef(-45,0.0,0.0,1.0);
        glTranslatef(-250,-250,0.0);
        display1();
        glTranslatef(250,250,0.0);
        glRotatef(-45,0.0,0.0,1.0);
        glTranslatef(-250,-250,0.0);
        display1();
        glTranslatef(250,250,0.0);
        glRotatef(-45,0.0,0.0,1.0);
        glTranslatef(-250,-250,0.0);
        displayrev();
        exit(0);
    }
}
void curvedraw(GLfloat ctr[4][3])
{
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctr[0][0]);
    glEnable(GL_MAP1_VERTEX_3);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    for (i = 0; i <= 30; i++)
         glEvalCoord1f((GLfloat) i/30.0);
    glEnd();
    /* The following code displays the control points as dots.
    glPointSize(5.0);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    for (i = 0; i < 4; i++)
         glVertex3fv(&ctr[i][0]);
    glEnd();*/
    glFlush();
}
void createHourGlass()
{
	/*glColor3f(1.0, 0.0, 0.0);
    drawHollowCircle(250.0,400.0,50.0);
    drawHollowCircle(250.0,100.0,50.0);
    glFlush();
    curvedraw(ctrlpoints1);
    curvedraw(ctrlpoints2);
    curvedraw(ctrlpoints3);
    curvedraw(ctrlpoints4);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(255.0,260.0);
    glVertex2f(255.0,240.0);
    glVertex2f(245.0,240.0);
    glVertex2f(245.0,260.0);
    glEnd();
    glFlush();*/
    glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
    drawHollowCircle(250.0,400.0,50.0);
    drawHollowCircle(250.0,100.0,50.0);
    glFlush();
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(255.0,260.0);
    glVertex2f(255.0,240.0);
    glVertex2f(245.0,240.0);
    glVertex2f(245.0,260.0);
    glVertex2f(200.0,400.0);
    glVertex2f(245.0,260.0);
    glVertex2f(300.0,400.0);
    glVertex2f(255.0,260.0);
    glVertex2f(200.0,100.0);
    glVertex2f(245.0,240.0);
    glVertex2f(300.0,100.0);
    glVertex2f(255.0,240.0);
    glEnd();
    glFlush();
}
void myReshape ( int w, int h )
{
    glViewport ( 0, 0, w, h );
    glMatrixMode ( GL_PROJECTION );
    glLoadIdentity ( );

  if ( w <= h )
  {
    glOrtho (
      -2.0, 2.0,
      -2.0 * ( GLfloat ) h / ( GLfloat ) w, 2.0 * ( GLfloat ) h / ( GLfloat ) w,
      -10.0, 10.0 );
  }
  else
  {
    glOrtho (
      -2.0 * ( GLfloat ) h / ( GLfloat ) w, 2.0 * ( GLfloat ) h / ( GLfloat ) w,
      -2.0, 2.0,
      -10.0, 10.0 );
  }

  glMatrixMode ( GL_MODELVIEW );
}
void processSpecialKeys(int key, int xx, int yy) {

	float fraction = 0.1f;

	switch (key) {
		case GLUT_KEY_LEFT :
			angle -= 0.01f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_RIGHT :
			angle += 0.01f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_UP :
			x += lx * fraction;
			z += lz * fraction;
			break;
		case GLUT_KEY_DOWN :
			x -= lx * fraction;
			z -= lz * fraction;
			break;
	}
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    values1();
    values2();
    values3();
    values4();
    glutCreateWindow("Hour Glass");
    init();
    glutDisplayFunc(display);
    glutMouseFunc ( mouse );
    //glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	//glShadeModel(GL_SMOOTH);//Specifies a symbolic value representing a shading technique. Accepted values are GL_FLAT and GL_SMOOTH.
	//glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glClearColor(0.1,0.1,0.1,0.0);
	glViewport(0,0,640,480);
	//glutKeyboardFunc(processSpecialKeys);
	//glutSpecialFunc(processSpecialKeys);
	// OpenGL init
	//glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
