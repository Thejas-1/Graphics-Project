#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <windows.h>
#include <GL/glu.h>
#include <math.h>
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
void display(void)
{
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
