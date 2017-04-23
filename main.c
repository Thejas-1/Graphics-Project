#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/gl.h>
//#include <windows.h>
#include <GL/glu.h>
#include <math.h>
//#include <conio.h>
int i;
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
	glFlush();
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

void display1(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
    drawHollowCircle(250.0,400.0,50.0);
    drawHollowCircle(250.0,100.0,50.0);
    //glFlush();
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

}

void display(void)
{
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
    //display1();
    display1();
    float max=350;
    glColor3f(1.0,0.0,0.0);
    for(i=210.0;i<=290.0;i+=2)
    {
        for(j=350.0;j>=max;j-=2)
           drawHollowCircle(i,j,1.0);
    if(i<=250.0)
    max-=2;
    else
    max+=2;
    }
    max =300.0;
    for(i=225.0;i<=275.0;i+=2)
    {
        for(j=305.0;j>=max;j-=2)
            drawHollowCircle(i,j,1.0);
        if(i<=250.0)
        max-=2;
        else
        max+=2;

    }
float min=210;
max=210;
        for(j=348.0;j>=305.0;j-=2)
        {
            for(i=min;i<=max;i+=2)
            drawHollowCircle(i,j,1.0);
            min+=1;
            max+=2;
        }
   //s if(kbhit())
   int k;
  for(i=0,k=275;i<100,k>225;i+=3,k-=2)
    {
        display1();
        glColor3f(1.0,0.0,0.0);
        drawHollowCircle(225.0,350.0-i,1.0);
        drawHollowCircle(250.0,350.0-i,1.0);
        drawHollowCircle(k,350.0-i,1.0);
        drawHollowCircle(235.0,350.0-i,1.0);
        drawHollowCircle(245.0,350.0-i,1.0);
        drawHollowCircle(260.0,350.0-i,1.0);
        drawHollowCircle(230.0,350.0-i,1.0);
        drawHollowCircle(229.0,335.0-i,1.0);
         drawHollowCircle(225.0,345.0-i,1.0);
        drawHollowCircle(227.0,347.0-i,1.0);
        drawHollowCircle(229.0,349.0-i,1.0);
        drawHollowCircle(250.0,275.0-i,1.0);
        drawHollowCircle(250.0,250.0-i,1.0);
        drawHollowCircle(275.0,350.0-i,1.0);
        drawHollowCircle(235.0,350.0-i,1.0);
        drawHollowCircle(245.0,350.0-i,1.0);
        drawHollowCircle(260.0,350.0-i,1.0);
        drawHollowCircle(230.0,350.0-i,1.0);
        drawHollowCircle(229.0,335.0-i,1.0);
         drawHollowCircle(225.0,345.0-i,1.0);
        drawHollowCircle(227.0,347.0-i,1.0);
        drawHollowCircle(229.0,349.0-i,1.0);
        drawHollowCircle(250.0,305.0-i,1.0);

        //drawHollowCircle()
        //glColor3f(1.0,1.0,1.0);


           usleep(39999);
//        for(i=0;i)

        glClear(GL_COLOR_BUFFER_BIT);
        //drawHollowCircle(250.0+i,200.0+i,2.0);

    }
    //float max=275.0;
    /*for(i=225.0;i<275.0;i++)
    {
     for(j=250;j>=200.0;j--)
       {
        display1();
        glColor3f(1.0,0.0,0.0);
        if(i=j)
        drawHollowCircle(i,j,1.0);

        usleep(39999);


       }
    max--;*/
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
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Circle");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
