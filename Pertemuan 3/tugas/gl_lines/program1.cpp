#include <GL/glut.h>

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.078, 0.178, 0.294, 1.0);

    float t = 0.0;
    glColor3f(0.0, 0.850, 1);

    glBegin(GL_LINES);
    for (t = -1.0; t <= 1.0; t += 0.01) {
        glVertex3f(t, -0.5 + t * t, 0.0);
    }
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
    glutCreateWindow("Yoga Agustiansyah - 2206050 (Program 1)");
    glutDisplayFunc(display);
    glutKeyboardFunc(kunci);
    glutMainLoop();
    return 0;
}
