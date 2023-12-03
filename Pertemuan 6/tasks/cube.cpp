#include <GL/glut.h>
#include <iostream>
#include <math.h>
using namespace std;
struct vec3{
	float x, y, z;
};
GLfloat light_diffuse[]={1,0,0,1};
GLfloat light_diffuse2[] = {0, 0, 1, 1};
//GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};
GLfloat light_position[] = {2.0f, 2.0f, 2.0f, 1.0f};
GLfloat light_position2[] = {-2.0f, -2.0f, -2.0f, 1.0f};

vec3 kalkulasi_glNormal(vec3 titik1, vec3 titik2, vec3 titik3){
	vec3 U = {titik2.x - titik1.x, titik2.y-titik1.y, titik2.z-titik1.z}; //titik2-titik1
	vec3 V = {titik3.x - titik1.x, titik3.y-titik1.y, titik3.z-titik1.z}; //titik3-titik1
	vec3 normal = {
		U.y*V.z - U.z*V.y, //titik glNormal X
		U.z*V.x - U.x*V.z, //titik glNormal Y
		U.x*V.y - U.y*V.x //titik glNormal Z
	};
	return normal;
}

vec3 normalisasi(vec3 koordinat){
	float pembagi = sqrt(pow(koordinat.x, 2) + pow(koordinat.y, 2) + pow(koordinat.z, 2));
	vec3 newKoordinat = {
		koordinat.x/pembagi,
		koordinat.y/pembagi,
		koordinat.z/pembagi
	};
	return newKoordinat;
}

void gambar3D(void){
	glBegin(GL_QUADS);
	// muka depan
	//glNormal3f(0.0f, 0.0f, 1.0f);
	vec3 NDepan = normalisasi(kalkulasi_glNormal({-1, -1, 1},{1, -1, 1}, {1,1,1})); //ND = Normal Depan, 
	//cout << ND.x << " " << ND.y << " " << ND.z << " ";
	glNormal3f(NDepan.x, NDepan.y, NDepan.z); //Normal menuju Kita
	glVertex3f(-1, -1, 1); //titik 1 (depan)
	glVertex3f( 1.0f, -1.0f, 1.0f); //Titik 2 (depan)
	glVertex3f( 1.0f, 1.0f, 1.0f); //Titik 3 (depan)
	glVertex3f(-1.0f, 1.0f, 1.0f); //Titik 4 (depan)
	// muka belakang
	vec3 NBelakang = normalisasi(kalkulasi_glNormal({-1, -1, -1},{1, -1, -1},{1,1,-1}));
	//glNormal3f(0.0f, 0.0f, -1.0f);
	glNormal3f(NBelakang.x, NBelakang.y, -NBelakang.z); //Normal menjauh Kita
	glVertex3f(-1, -1, -1); //titik 1 (Belakang)
	glVertex3f( 1.0f, -1.0f, -1.0f); //Titik 2 (Belakang)
	glVertex3f( 1.0f, 1.0f, -1.0f); //Titik 3 (Belakang)
	glVertex3f(-1.0f, 1.0f, -1.0f); //Titik 4 (Belakang)
	//muka atas
	vec3 NAtas = normalisasi(kalkulasi_glNormal({-1, 1, -1},{-1, 1, 1},{1,1,1}));
	//glNormal3f( 0.0f, 1.0f, 1.0f); //Normal berarah atas
	glNormal3f(NAtas.x, NAtas.y, NAtas.z);
	glVertex3f(-1,1,-1); //titik 1 (atas)
	glVertex3f(-1, 1, 1); //titik 2 (atas)
	glVertex3f(1, 1, 1); //titik 3 (atas)
	glVertex3f(1, 1, -1); //titik 4 (atas)
	//muka bawah
	vec3 NBawah = normalisasi(kalkulasi_glNormal({-1, -1, -1},{1, -1, -1},{1,-1,1}));
	//glNormal3f(0, -1, 0); //Normal berarah bawah
	//cout << NBawah.x << " " << NBawah.y << " " << NBawah.z << " ";
	glNormal3f(NBawah.x, -NBawah.y, NBawah.z);
	glVertex3f(-1, -1, -1); //titik 1 bawah
	glVertex3f(1, -1, -1); //titik 2 bawah
	glVertex3f(1, -1, 1); //titik 3 bawah
	glVertex3f(-1, -1, 1); // titik 4 bawah
	//muka kanan
	vec3 NKanan = normalisasi(kalkulasi_glNormal({1, -1, -1},{1, 1, -1},{1,1,1}));
	//glNormal3f(1, 0, 0); //normal arah kanan
	glNormal3f(NKanan.x, NKanan.y, NKanan.z);
	glVertex3f(1, -1, -1); //titik 1 kanan
	glVertex3f(1, 1, -1); //titik 2 kanan
	glVertex3f(1, 1, 1); //titik 3 kanan
	glVertex3f(1, -1, 1); //titik 4 kanan
	//muka kiri
	vec3 NKiri = normalisasi(kalkulasi_glNormal({-1, -1, -1},{-1, 1, -1},{-1,1,1}));
	glNormal3f(-NKiri.x, NKiri.y, NKiri.z);
	//glNormal3f(-1, 0, 0); //normal arah kiri
	glVertex3f(-1, -1, -1); //titik 1 kiri
	glVertex3f(-1, 1, -1); //titik 2 kiri
	glVertex3f(-1, 1, 1); //titik 3 kiri
	glVertex3f(-1, -1, 1); //titik 4 kiei
 	glEnd();
}

void display(){
	//glRotatef(0.03,0,1,1);
	glRotatef(0.3, 1, 1, 0);
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gambar3D();
	glutSwapBuffers();
	glutPostRedisplay();
}

void inisialisasi(){
	//pencahayaan
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0); //Konfigurasi Cahaya ke-1
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHT1); //Konfigurasi Cahaya ke-2
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse2);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position2);
	//Buffer
	glEnable(GL_DEPTH_TEST);
	//setup kubus
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40,1,1,10);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0); //melihat pada (0,0,5), center pada (0,0,0) dan arah y (0,1,0)
	//Mengatur Posisi sudut
	//glTranslatef(0,0,-1);
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Renaldy Azhari | 2106020");
	glutDisplayFunc(display);
	inisialisasi();
	glutMainLoop();
	return 0;
}