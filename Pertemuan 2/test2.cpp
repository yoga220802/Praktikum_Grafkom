#include <GL/glut.h>
#include <math.h>
void display (void)
{
glClearColor (1, 1, 1, 0);
glClear (GL_COLOR_BUFFER_BIT);
glColor3f(1, 0, 0);
// glLineWidth(10.0);
glLineWidth(10.0);
glBegin (GL_LINE_LOOP);
glVertex2f(-0.5,-0.5);
glVertex2f(-0.5,0.01);
glVertex2f(-0.3,0.01);
glVertex2f(-0.3,-0.5);
glVertex2f(-0.3,0.07);
glVertex2f(-0.1,0.07);
glVertex2f(-0.1,-0.5);
glVertex2f(-0.1,0.6);
glVertex2f(0.1,0.6);
glVertex2f(0.1,-0.5);
glVertex2f(0.1,0.14);
glVertex2f(0.3,0.13);
glVertex2f(0.3,-0.5);
glVertex2f(0.3,0.1);
glVertex2f(0.5,0.1);
glVertex2f(0.5,-0.7);
glVertex2f(0.2,-0.8);
// glVertex2f(-0.5,0.5);
// glVertex2f(0.5,-0.5);
glEnd ();
glFlush ();
}

int main (int argc, char **argv){
glutInit(&argc, argv);
glutCreateWindow("Yoga Agustiansyah - 2206050");
glutDisplayFunc (display);
glutMainLoop();
// return 0;
}