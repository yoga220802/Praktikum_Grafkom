#include <GL/glut.h>
#include <pthread.h>
// #include <windows.h>

// Variabel untuk menyimpan sudut rotasi
double rotationAngle = 0.0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.850, 1);
    
    // Objek pertama
    glPushMatrix();
    glRotated(rotationAngle, 0, 0, 1);
    glRecti(-10, 0, 10, 5);
    
    // Objek kedua dengan rotasi
    glRecti(20, 20, 40, 25);
    glPopMatrix();
    
    glFlush();
}

void myInit() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(50, 50, 50, 50);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.078, 0.178, 0.294, 1.0);
    glColor3f(0, 0, 0);
}

void idle() {
    // Fungsi ini akan dipanggil ketika tidak ada peristiwa lain yang terjadi
    // Di sini, kita meningkatkan sudut rotasi dan meminta glut untuk merender ulang tampilan
    rotationAngle += 1.0;
    if (rotationAngle >= 360.0) {
        rotationAngle -= 360.0;
    }
    glutPostRedisplay();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rotation");
    glutDisplayFunc(display);
    myInit();
    
    // Atur fungsi idle
    glutIdleFunc(idle);
    
    glutMainLoop();
    return 0;
}
