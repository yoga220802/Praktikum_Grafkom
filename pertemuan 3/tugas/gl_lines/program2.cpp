#include <GL/glut.h>

void myinit() {
    glClearColor(0.078, 0.178, 0.294, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50.0, 50.0, -5.0, 700.0);
    glMatrixMode(GL_MODELVIEW);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.850, 1);
    float t = 0.0;
    //f(x)=1/14(x+4)(x+1)(x-1)(x-3)+0.5
    glPointSize(2);
    glBegin(GL_LINES);
    for (t = -10.0; t <= 10.0; t += 0.1) {
        glVertex3f(t, (t + 4) * (t + 1) * (t - 1) * (t - 3) / 14 + 0.5, 0.0);
    }
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-10.0, 0.0, 0.0);
    glVertex3f(10.0, 0.0, 0.0);
    glVertex3f(0.0, -10.0, 0.0);
    glVertex3f(0.0, 10.0, 0.0);
    glEnd();

    glFlush();
}

void kunci(unsigned char key, int x, int y) {
    switch (key) {
    case 27:
    case 'q':
        exit(0);
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Yoga Agustiansyah - 2206050 (Program 2)");
    glutDisplayFunc(display);
    myinit();
    glutKeyboardFunc(kunci);
    glutMainLoop();
    return 0;
}
