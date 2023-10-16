#include <GL/glut.h>
void Garis ();
int main (int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(300, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow ("Latihan III - Membuat Objek Sebuah Garis");
    glClearColor(0.2, 0.2, 0.2, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-150, 150, -200, 200);
    glutIdleFunc(Garis);
    glutDisplayFunc(Garis);
    glutMainLoop();
}

void Garis () {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3f(0.0, 0.51, 0.85);
    glVertex2d(0,-100);
    glColor3f(1, 1, 1);
    glVertex2d(0, 0);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3f(0.0, 0.51, 0.85);
    glVertex2d(0,50);
    glColor3f(1, 1, 1);
    glVertex2d(0, 150);
    glEnd();
    glFinish();
}