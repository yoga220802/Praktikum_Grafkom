#include <GL/glut.h> 
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.850, 1);
    glRecti(0, 0, 20, 5);
    glTranslated(10.0, 10.0, 0);
    glRecti(0, 0, 20, 5);
    glFlush();
}

void myInit() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 50, 0, 50);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.078, 0.178, 0.294, 1.0);
    glColor3f(0, 0, 0);
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
    glutCreateWindow("Yoga Agustiansyah - 2206050 (translasi)");
    glutDisplayFunc(display);
    myInit();
    glutMouseFunc(mouseClick);
    glutMainLoop();
    return 0;
}