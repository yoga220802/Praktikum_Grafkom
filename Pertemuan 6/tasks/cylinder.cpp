#include <GL/glut.h>
#include <cmath>

float radius = 0.5f; // Radius silinder
float halfLength = 1.0f; // Setengah tinggi silinder
int slices = 30; // Jumlah segmen pada silinder

void display() {
    glOrtho(-10, 10, -10, 10, -10, 10);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1, 1, 1, 1);
    glColor3f(0.5f, 0.5f, 1.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);

    for (int i = 0; i < slices; i++) {
        float theta = static_cast<float>(i) * 2.0f * M_PI;
        float nextTheta = static_cast<float>(i + 1) * 2.0f * M_PI;

        glBegin(GL_TRIANGLE_STRIP);
        glVertex3f(0.0f, halfLength, 0.0f);
        glVertex3f(radius * cos(theta), halfLength, radius * sin(theta));
        glVertex3f(radius * cos(nextTheta), halfLength, radius * sin(nextTheta));
        glVertex3f(radius * cos(nextTheta), -halfLength, radius * sin(nextTheta));
        glVertex3f(radius * cos(theta), -halfLength, radius * sin(theta));
        glVertex3f(0.0f, -halfLength, 0.0f);
        glEnd();
    }

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("OpenGL Cylinder");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
