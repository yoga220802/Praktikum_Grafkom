#include <GL/glut.h> 
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.5);
    glRecti(0, 0, 10, 10);
    glTranslated(20.0, 20.0, 0);
    glRecti(0, 0, 10, 10);
    glFlush();
}

void myInit() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 50, 0, 50);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1, 1, 1, 1);
    glColor3f(0, 0, 0);
}

int main(int argc, char*argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Transform");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
    return 0;
}