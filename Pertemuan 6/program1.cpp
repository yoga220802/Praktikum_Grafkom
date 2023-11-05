#include <GL/glut.h>

GLfloat light_diffuse[] = {0.0, 0.850, 1.0, 1.0};
// GLfloat light_diffuse[] = {0.9f, 0.9f, 0.9f, 1.0f};
GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};
// GLfloat light_position[] = {2.0f, 2.0f, 2.0f, 0.0};


void gambar3D(void) {
    glRotated(1, 1, 1, 1);

    glBegin(GL_QUADS);
    // depan
    glNormal3f(0.0f, 0.0f, 1.0f); //normal menuju Kita
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);

    // belakang
    glNormal3f(0.0f, 0.0f, -1.0f); //normal menjauh Kita
    glVertex3f(-1.0f, -1.0f, -1.0f);

    //atas
    glNormal3f(0.0f, 1.0f, 1.0f); // normal berarah kita
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    // glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    //bawah
    glNormal3f(0.0f, -1.0f, 0.0f); // normal berarah bawah
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    //kanan
    glNormal3f(1.0f, 0.0f, 0.0f); // normal berarah kekanan
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    //kiri
    glNormal3f(-1.0f, 0.0f, 0.0f); // normal berarah kekanan
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glEnd();
    glutPostRedisplay();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    gambar3D();
    glutSwapBuffers();
}


void init(void) {
    glClearColor(1, 1, 1, 1);
    // PENCAJAYAAN
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHT0);

    glEnable(GL_LIGHTING);

    // BUFFER
    glEnable(GL_DEPTH_TEST);

    // SETUP CUBE
    glMatrixMode(GL_PROJECTION);
    // gluPerspective(45.0, 1, 1.0, 10.0);
    glOrtho(-5, 5, -5, 5, -5, 5);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0.0, 0.0, 5.0,
    0.0, 0.0, 0.0,
    0.0, 1.0, 0.0);

    // glTranslatef(0.0, 0.0, -1.0);
    glRotatef(30.0, 0.0, 1.0, 1.0);
    glRotatef(15.0, 1.0, 1.0, 0.0);
}

void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Memanggil fuction display saatu klik kiri mouse
        display(); 
        // Meminta glut untuk merender ulang tampilan
        glutPostRedisplay();
    }
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    // glutInitWindowSize(400, 400);
    glutCreateWindow("GRAFIKA KOMPUTER 3D");
    glutDisplayFunc(display);
    init();
    // glutMouseFunc(mouseClick);
    glutMainLoop();
    return 0;
}
