#include <GL/glut.h>

GLfloat light_diffuse[] = {0.0, 0.850, 1.0, 1.0};
GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};

void pentagonAntiPrism(void)
{
    glRotatef(1.0, 0.5, 1.0, 0.0);

    // Sisi atas
    glBegin(GL_POLYGON);
    glNormal3f(0.0f, 0.0f, 1.0f);  // Normal menghadap ke depan
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0f, 6.0f, 2.0f);
    glVertex3f(5.0f, 2.0f, 2.0f);
    glVertex3f(3.0f, -4.0f, 2.0f);
    glVertex3f(-3.0f, -4.0f, 2.0f);
    glVertex3f(-5.0f, 2.0f, 2.0f);
    glEnd();

    // Sisi bawah
    glBegin(GL_POLYGON);
    glNormal3f(0.0f, 0.0f, -1.0f);  // Normal menghadap ke belakang
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0f, -4.0f, -2.0f);
    glVertex3f(-5.0f, 0.0f, -2.0f);
    glVertex3f(-3.0f, 6.0f, -2.0f);
    glVertex3f(3.0f, 6.0f, -2.0f);
    glVertex3f(5.0f, 0.0f, -2.0f);
    glEnd();

    // Sisi depan
    glBegin(GL_POLYGON);
    glNormal3f(0.0f, 1.0f, 0.0f);
    glColor3f(0, 1, 0);
    glVertex3f(0.0f, 6.0f, 2.0f);
    glVertex3f(5.0f, 2.0f, 2.0f);
    glVertex3f(3.0f, 6.0f, -2.0f);
    glEnd();

    // Sisi kiri depan
    glBegin(GL_POLYGON);
    glNormal3f(-1.0f, 0.5f, 0.0f);
    glVertex3f(-3.0f, 6.0f, -2.0f);
    glVertex3f(3.0f, 6.0f, -2.0f);
    glVertex3f(0.0f, 6.0f, 2.0f);
    glEnd();

    // Sisi kanan depan
    glBegin(GL_POLYGON);
    glNormal3f(1.0f, 0.5f, 0.0f);
    glVertex3f(3.0f, 6.0f, -2.0f);
    glVertex3f(5.0f, 0.0f, -2.0f);
    glVertex3f(5.0f, 2.0f, 2.0f);
    glEnd();

    // Sisi kiri agak depan
    glBegin(GL_POLYGON);
    glNormal3f(-1.0f, 0.0f, 0.5f);
    glVertex3f(0.0f, 6.0f, 2.0f);
    glVertex3f(-5.0f, 2.0f, 2.0f);
    glVertex3f(-3.0f, 6.0f, -2.0f);
    glEnd();

    // Sisi kanan agak depan
    glBegin(GL_POLYGON);
    glNormal3f(1.0f, 0.0f, 0.5f);
    glVertex3f(5.0f, 2.0f, 2.0f);
    glVertex3f(3.0f, -4.0f, 2.0f);
    glVertex3f(5.0f, 0.0f, -2.0f);
    glEnd();

    // Sisi kiri
    glBegin(GL_POLYGON);
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-5.0f, 0.0f, -2.0f);
    glVertex3f(-3.0f, 6.0f, -2.0f);
    glVertex3f(-5.0f, 2.0f, 2.0f);
    glEnd();

    // Sisi kanan
    glBegin(GL_POLYGON);
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, -4.0f, -2.0f);
    glVertex3f(5.0f, 0.0f, -2.0f);
    glVertex3f(3.0f, -4.0f, 2.0f);
    glEnd();

    // Sisi kiri agak belakang
    glBegin(GL_POLYGON);
    glNormal3f(-1.0f, -0.5f, -0.5f);
    glVertex3f(-3.0f, -4.0f, 2.0f);
    glVertex3f(-5.0f, 2.0f, 2.0f);
    glVertex3f(-5.0f, 0.0f, -2.0f);
    glEnd();

    // Sisi kanan agak belakang
    glBegin(GL_POLYGON);
    glNormal3f(1.0f, -0.5f, -0.5f);
    glVertex3f(3.0f, -4.0f, 2.0f);
    glVertex3f(-3.0f, -4.0f, 2.0f);
    glVertex3f(0.0f, -4.0f, -2.0f);
    glEnd();

    // Sisi belakang
    glBegin(GL_POLYGON);
    glNormal3f(0.0f, -1.0f, 0.0f);
    // glNormal3f(0.0f, 0.0f, -1.0f);
    glColor3f(1, 0, 1);
    glVertex3f(0.0f, -4.0f, -2.0f);
    glVertex3f(-5.0f, 0.0f, -2.0f);
    glVertex3f(-3.0f, -4.0f, 2.0f);
    glEnd();

    glutPostRedisplay();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    pentagonAntiPrism();
    glutSwapBuffers();
}

void init(void)
{
    glClearColor(0, 0, 0, 1);
    // PENCAHAYAAN
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHT0);

    glEnable(GL_LIGHTING);

    // BUFFER
    glEnable(GL_DEPTH_TEST);

    // SETUP CUBE
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // gluPerspective(120.0, 1.0, 1.0, 100.0); // 45 derajat FOV, rasio aspek 1.0, jarak dekat 1.0, jarak jauh 100.0
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10, 10);

    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0.0, 0.0, 10.0, // Posisi kamera
              0.0, 0.0, 0.0,  // Titik pandang
              0.0, 1.0, 0.0); // Vektor arah atas

    // glRotatef(30.0, 0.0, 1.0, 1.0);
    // glRotatef(15.0, 1.0, 1.0, 0.0);
}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("2206050 - Yoga Agustiansyah");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
