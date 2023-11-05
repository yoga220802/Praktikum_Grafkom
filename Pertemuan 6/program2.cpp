#include <GL/glut.h>

GLfloat light_diffuse[] = {1.0, 0.0, 0.0, 1.0};
GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};

void gambar3D(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 1);

    glPushMatrix();
    glTranslatef(-3.0, 1.0, -8.0);
    glutWireTetrahedron();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.0, 1.0, -8.0);
    glutWireOctahedron();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.5f, -2.5f, -8.0);
    glutWireDodecahedron();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.0, -2.5f, -8.0);
    glutWireIcosahedron();
    glPopMatrix();

    glFlush();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    gambar3D();
    glutSwapBuffers();
}

void init(void) {
    int w=800, h=600;
    glShadeModel(GL_FLAT);
    glClearColor(1, 1, 1, 0);
    glClearAccum(0, 0, 0, 0);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Grafika Komputer 3 dimensi");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}