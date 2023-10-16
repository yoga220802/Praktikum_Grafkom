#include <GL/glut.h>

void garis () {
	glClear (GL_COLOR_BUFFER_BIT);
	// Mengatur Ketebalan Garis
    glLineWidth (10);

	// Membuat glut bertipe garis
	glBegin(GL_LINES);

	// Garis Pertama Dengan Warna Gradien Cyan-Magenta
	glColor3f(0.0, 0.51, 0.85);
	glVertex2f(100,100);
	glColor3f(1, 0, 0.701);
	glVertex2f(-100,100);
	
	// Garis Pertama Dengan Warna Magenta
	glColor3f(1, 0, 0.701);
	glVertex2f(100,50);
	glVertex2f(-100,50);

	// Garis Pertama Dengan Warna Cyan
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

	// Mengatur ukuran window program menjadi 400px X p00px
	glutInitWindowSize(400, 400);

	// Mangatur posisi windows agar berada di koordinat yang ditentukan
	glutInitWindowPosition(100,100);

	// Mengatur nama window sesuai menjadi "2206050 - Yoga Agustiansyah"
	glutCreateWindow ("2206050 - Yoga Agustiansyah");

	// Mengatur warna background window menjadi abu abu
	glClearColor(0.2, 0.2, 0.2, 1.0);
	
	glMatrixMode(GL_PROJECTION);

	// Mengatur maksX, maksY, minX, dan minY
	gluOrtho2D(-200, 200, -200, 200);

	// Memanggil function garis dengan fungsi glut display
	glutDisplayFunc (garis);

	// Membuat program terus diulang agar output terus dimunculkan
	glutMainLoop();
    return 0;
}