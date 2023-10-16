    #include <GL/glut.h>

    void garis () {
        glClear (GL_COLOR_BUFFER_BIT);
        glLineWidth (10);

        glBegin(GL_LINES);

        glColor3f(0.0, 0.51, 0.85);
        glVertex2f(100,100);
        glColor3f(1, 0, 0.701);
        glVertex2f(-100,100);
        
        glColor3f(1, 0, 0.701);
        glVertex2f(100,50);
        glVertex2f(-100,50);

        glColor3f(0.0, 0.51, 0.85);
        glVertex2f(100,0);
        glVertex2f(-100,0);

        glEnd ();

        glFlush();
        glFinish ();
    }

    int main(int argc, char**argv) {
        glutInit (&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
        glutInitWindowSize(400, 400);
        glutInitWindowPosition(100,100);
        glutCreateWindow ("2206050 - Yoga Agustiansyah");
        glClearColor(0.2, 0.2, 0.2, 1.0);
        glMatrixMode(GL_PROJECTION);
        gluOrtho2D(-200, 200, -200, 200);
        glutDisplayFunc (garis);
        glutMainLoop();
        return 0;
    }