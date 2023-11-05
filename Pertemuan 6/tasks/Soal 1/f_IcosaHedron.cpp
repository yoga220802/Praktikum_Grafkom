#include <GL/glut.h>

GLfloat light_diffuse[] = {1.0, 0.0, 0.0, 1.0};
GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};

void Gambar3D(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat intensitasCahaya[] = {0.9f, 0.9f, 0.9f, 1.0f};
    GLfloat posisiCahaya[] = {2.0f, 2.0f, 2.0f, 0.0f};

    glLightfv(GL_LIGHT0, GL_POSITION, posisiCahaya);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, intensitasCahaya);

    // Objek Tetrahedron
    GLfloat bahan_ambient_cyan[] = {0.0f, 0.850f, 1.0f, 1.0f}; // Warna RGBA
    GLfloat bahan_diffuse_cyan[] = {0.0f, 0.850f, 1.0f, 1.0f}; // Warna RGBA
    GLfloat bahan_specular_cyan[] = {0.2f, 0.6f, 0.2f, 1.0f};
    GLfloat bahan_shininess_cyan[] = {90.0f};

    glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient_cyan);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse_cyan);
    glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular_cyan);
    glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess_cyan);
    glTranslatef(0, 0.0, -5.0);
    glScaled(2, 2, 2);
    glRotated(45, 1, 1, 0);
    glutSolidIcosahedron();

    glFlush();
    // glutPostRedisplay();
}

void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Gambar3D();
    glutSwapBuffers();
}

void Inisial(void)
{
    int w = 800, h = 600;
    glShadeModel(GL_FLAT);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClearAccum(0.0, 0.0, 0.0, 0.0);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("2206050 - Yoga Agustiansyah");
    glutDisplayFunc(Display);
    Inisial();
    glutMainLoop();
    return 0;
}
