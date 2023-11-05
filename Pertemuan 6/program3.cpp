#include <GL/glut.h>

GLfloat light_diffuse[] = {1.0, 0.0, 0.0, 1.0};
GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};

void gambar3D(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat intensitasCahaya[] = {0.9f, 0.9f, 0.9f, 1.0f};
    GLfloat posisiCahaya[] = {2.0f, 2.0f, 2.0f, 0.0f};

    glLightfv(GL_LIGHT0, GL_POSITION, posisiCahaya);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, intensitasCahaya);

    GLfloat bahan_ambient[] = {0.0f, 0.5f, 0.6f, 1.0f};
    GLfloat bahan_diffuse[] = {0.6f, 0.6f, 0.6f, 1.0f};
    GLfloat bahan_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat bahan_shininess[] = {90.0f};

    glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess);

    glPushMatrix();
    glTranslatef(-3.0, 1.0, -8.0);
    glutSolidTetrahedron();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.0, 1.0, -8.0);
    glutSolidOctahedron();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.5f, -2.5f, -8.0);
    glutSolidDodecahedron();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.0, -2.5f, -8.0);
    glutSolidIcosahedron();
    glPopMatrix();

    glFlush();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    gambar3D();
    glutSwapBuffers();
}

void inisialisasi(void) {
    int w = 800, h = 600;
    glShadeModel(GL_FLAT);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClearAccum(0.0, 0.0, 0.0, 0.0);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Grafika Komputer 3 Dimensi");
    glutDisplayFunc(display);
    inisialisasi();
    glutMainLoop();
    return 0;
}
