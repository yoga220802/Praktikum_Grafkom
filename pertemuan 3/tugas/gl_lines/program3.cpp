#include <GL/glut.h>
#include <math.h>

void myInit() {
    glClearColor(0.078, 0.178, 0.294, 1.0);
    glColor3f(1, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 10.5, -2.0, 2.0);
    glMatrixMode(GL_MODELVIEW);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.850, 1);

    float x = 0.0;
    // glPointSize(2);
    glBegin(GL_LINES);
    for(x = 0.0; x <= 1.5*6.28; x+=0.01){
        glVertex2f(x, sin(x));
    }

    glEnd();

    glColor3f(0.0, 1.0, 0.45);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex3f(-10.0, 0.0, 0.0);
    glVertex3f(10.0, 0.0, 0.0);
    glVertex3f(0.0, -10.0, 0.0);
    glVertex3f(0.0, 10.0, 0.0);
    glVertex3f(0.0, 0.0, 10.0);
    glVertex3f(0.0, 0.0, -10.0);

    glEnd();
    glFlush();
}

void kunci (unsigned char key, int x, int y){
    switch(key){
        case 27:
        case 'q':
        exit(0);
        break;
    }

    glutPostRedisplay();
}

int main(int argc, char* argv[]) {
    glutInit (&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Yoga Agustiansyah - 2206050 (Program 3)");
    glutDisplayFunc(display);
    glutKeyboardFunc(kunci);
    myInit();
    glutMainLoop();
    return 0;
}