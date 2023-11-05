#include <GL/glut.h>

GLfloat light_diffuse[] = {1.0, 0.0, 0.0, 1.0};
GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};

void pentagonPrism(void)
{
    glRotatef(45.0, 0.5, 1.0, 0.0);

    glBegin(GL_POLYGON);
    glNormal3f(0.0f, 0.0f, 1.0f);  // Normal menghadap ke depan
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0f, 6.0f, 2.0f);
    glVertex3f(5.0f, 2.0f, 2.0f);
    glVertex3f(3.0f, -4.0f, 2.0f);
    glVertex3f(-3.0f, -4.0f, 2.0f);
    glVertex3f(-5.0f, 2.0f, 2.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0f, 0.0f, -1.0f);  // Normal menghadap ke belakang
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0f, 6.0f, -2.0f);
    glVertex3f(5.0f, 2.0f, -2.0f);
    glVertex3f(3.0f, -4.0f, -2.0f);
    glVertex3f(-3.0f, -4.0f, -2.0f);
    glVertex3f(-5.0f, 2.0f, -2.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0f, 1.0f, 0.0f);  // Normal menghadap ke atas
    glColor3f(0, 0, 1);
    glVertex3f(0.0f, 6.0f, -2.0f);
    glVertex3f(5.0f, 2.0f, -2.0f);
    glVertex3f(5.0f, 2.0f, 2.0f);
    glVertex3f(0.0f, 6.0f, 2.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(-1.0f, 0.0f, 0.0f);  // Normal menghadap ke kiri
    glColor3f(0, 0, 1);
    glVertex3f(5.0f, 2.0f, -2.0f);
    glVertex3f(3.0f, -4.0f, -2.0f);
    glVertex3f(3.0f, -4.0f, 2.0f);
    glVertex3f(5.0f, 2.0f, 2.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(1.0f, 0.0f, 0.0f);  // Normal menghadap ke kanan
    glColor3f(0, 0, 1);
    glVertex3f(3.0f, -4.0f, -2.0f);
    glVertex3f(-3.0f, -4.0f, -2.0f);
    glVertex3f(-3.0f, -4.0f, 2.0f);
    glVertex3f(3.0f, -4.0f, 2.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0f, 0.0f, -1.0f);  // Normal menghadap ke belakang
    glColor3f(0, 0, 1);
    glVertex3f(-3.0f, -4.0f, -2.0f);
    glVertex3f(-5.0f, 2.0f, -2.0f);
    glVertex3f(-5.0f, 2.0f, 2.0f);
    glVertex3f(-3.0f, -4.0f, 2.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(0.0f, 1.0f, 0.0f);  // Normal menghadap ke atas
    glColor3f(0, 0, 1);
    glVertex3f(0.0f, 6.0f, -2.0f);
    glVertex3f(-5.0f, 2.0f, -2.0f);
    glVertex3f(-5.0f, 2.0f, 2.0f);
    glVertex3f(0.0f, 6.0f, 2.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(-1.0f, 0.0f, 0.0f);  // Normal menghadap ke kiri
    glColor3f(0, 0, 1);
    glVertex3f(-5.0f, 2.0f, -2.0f);
    glVertex3f(-3.0f, -4.0f, -2.0f);
    glVertex3f(-3.0f, -4.0f, 2.0f);
    glVertex3f(-5.0f, 2.0f, 2.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glNormal3f(1.0f, 0.0f, 0.0f);  // Normal menghadap ke kanan
    glColor3f(0, 0, 1);
    glVertex3f(0.0f, 6.0f, -2.0f);
    glVertex3f(-5.0f, 2.0f, -2.0f);
    glVertex3f(-5.0f, 2.0f, 2.0f);
    glVertex3f(0.0f, 6.0f, 2.0f);
    glEnd();

}

void pentagonAntiPrism(void)
{
    glRotatef(30.0, 1.0, 1.0, 1.0);

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
    glColor3f(1, 0, 1);
    glVertex3f(0.0f, -4.0f, -2.0f);
    glVertex3f(-5.0f, 0.0f, -2.0f);
    glVertex3f(-3.0f, -4.0f, 2.0f);
    glEnd();

    glutPostRedisplay();
}

void gambar3D(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat intensitasCahaya[] = {0.9f, 0.9f, 0.9f, 1.0f};
    GLfloat posisiCahaya[] = {2.0f, 2.0f, 2.0f, 0.0f};

    glLightfv(GL_LIGHT0, GL_POSITION, posisiCahaya);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, intensitasCahaya);

    GLfloat bahan_ambient[][6] = {
    {0.784f, 0.215f, 0.392f, 1.0f},
    {0.784f, 0.576f, 0.215f, 1.0f},
    {0.905f, 0.145f, 0.094f, 1.0f},
    {0.384f, 0.717f, 0.988f, 1.0f},
    {0.215f, 0.423f, 0.784f, 1.0f},
    {0.215f, 0.784f, 0.294f, 1.0f}
    };
    GLfloat bahan_diffuse[][4] = {
    {0.784f, 0.215f, 0.392f, 1},
    {0.784f, 0.576f, 0.215f, 1},
    {0.905f, 0.145f, 0.094f, 1},
    {0.384f, 0.717f, 0.988f, 1},
    {0.215f, 0.423f, 0.784f, 1},
    {0.215f, 0.784f, 0.294f, 1}
};

    GLfloat bahan_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat bahan_shininess[] = {90.0f};

    glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient[0]);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse[0]);
    glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess);

    glPushMatrix();
    glTranslatef(-3.0, 1.0, -8.0);
    glutSolidTetrahedron();
    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient[1]);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse[1]);
    glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess);
    glPushMatrix();
    glTranslatef(2.0, 1.0, -8.0);
    glutSolidOctahedron();
    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient[2]);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse[2]);
    glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess);
    glPushMatrix();
    glTranslatef(2.5f, -2.5f, -8.0);
    glutSolidDodecahedron();
    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient[3]);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse[3]);
    glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess);
    glPushMatrix();
    glTranslatef(-4.0, -2.5f, -8.0);
    glutSolidIcosahedron();
    glPopMatrix();


    glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient[4]);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse[4]);
    glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess);
    glPushMatrix();
    glTranslatef(-2.0, 3.0f, -8.0);
    glScalef(0.2f, 0.2f, 0.2f);
    pentagonPrism();
    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient[5]);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse[5]);
    glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess);
    glPushMatrix();
    glTranslatef(2.0, 3.0f, -8.0);
    glScalef(0.2f, 0.2f, 0.2f);
    pentagonAntiPrism();
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
