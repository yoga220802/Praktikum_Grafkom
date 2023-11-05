#include <GL/glut.h>
#include <math.h>

void display (void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0, 0.850, 1);
    glRotated(50, 1, 1, 1);
    glutWireCube(2);
    glFlush();
}

void init (void) {
    glClearColor(0.078, 0.178, 0.294, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5, 5, -5, 5, -5, 5);
    glMatrixMode(GL_MODELVIEW);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
}
void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Memanggil fuction display saatu klik kiri mouse
        display();
        // Meminta glut untuk merender ulang tampilan
        glutPostRedisplay();
    }
}

int main(int argc, char*argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Yoga Agustiansyah - 2206050");
    glutDisplayFunc(display);
    init();
    glutMouseFunc(mouseClick);
    glutMainLoop();
    return 0;
}