#include <GL/glut.h>

GLfloat light_diffuse[] = {1.0, 0.0, 0.0, 1.0};
GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};

void GambarPrisma(void) {
	
    //Membuat Objek Prisma
    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(-2.0, 1.0, -8.0);
    glScalef (2.0, 2.0, 2.0);
    glutSolidCube(0.5);
    
    glPopMatrix();
}

void GambarAntiprisma(void) {
	
    //Membuat Objek Antiprisma
    glColor3f(0.0, 0.0, 1.0);
    glPushMatrix();
    glTranslatef(-2.0, -3.0, -8.0);
    glScalef (2.0, 2.0, 2.0);
    glutSolidCone(0.25, 0.5, 16, 8);
    
    glPopMatrix();
}

void Gambar3D(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    GLfloat intensitasCahaya[] = {0.9f, 0.9f, 0.9f, 1.0f};
    GLfloat posisiCahaya[] = {2.0f, 2.0f, 2.0f, 0.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, posisiCahaya);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, intensitasCahaya);
    
	//Objek Tetrahedron
    GLfloat bahan_ambient_hijau[] = {0.0f, 0.6f, 0.0f, 1.0f}; //Untuk Mengatur Warna Objek
    GLfloat bahan_diffuse_hijau[] = {0.0f, 0.8f, 0.0f, 1.0f};
    GLfloat bahan_specular_hijau[] = {0.2f, 0.6f, 0.2f, 1.0f};
    GLfloat bahan_shininess_hijau[] = {90.0f};
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient_hijau);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse_hijau);
    glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular_hijau);
    glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess_hijau);
    
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient_hijau);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse_hijau);
    
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(0.0, 1.0, -8.0);
    glutSolidTetrahedron(); //Membuat Objek
    glPopMatrix();
    
    //Objek Octahedron
    GLfloat bahan_ambient_kuning[] = {0.5f, 0.5f, 0.0f, 1.0f}; //Untuk Mengatur Warna Objek
    GLfloat bahan_diffuse_kuning[] = {0.6f, 0.6f, 0.0f, 1.0f};
    GLfloat bahan_specular_kuning[] = {0.6f, 0.6f, 0.0f, 1.0f};
    GLfloat bahan_shininess_kuning[] = {90.0f};

    glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient_kuning);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse_kuning);
    glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular_kuning);
    glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess_kuning);

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient_kuning);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse_kuning);
    
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(2.0, 1.0, -8.0);
    glutSolidOctahedron(); //Membuat Objek
    glPopMatrix();

    //Objek Dodecahedron
    GLfloat bahan_ambient_ungu[] = {0.5f, 0.0f, 0.5f, 1.0f}; //Untuk Mengatur Warna Objek
    GLfloat bahan_diffuse_ungu[] = {0.6f, 0.0f, 0.6f, 1.0f};
    GLfloat bahan_specular_ungu[] = {0.6f, 0.0f, 0.6f, 1.0f};
    GLfloat bahan_shininess_ungu[] = {90.0f};

    glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient_ungu);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse_ungu);
    glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular_ungu);
    glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess_ungu);

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient_ungu);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse_ungu);
    
    glColor3f(0.5, 0.0, 0.5);
    glTranslatef(2.5f, -2.5f, -8.0);
    glutSolidDodecahedron(); //Membuat Objek
    glPopMatrix();

    //Objek Icosahedron
    GLfloat bahan_ambient_oranye[] = {1.0f, 0.5f, 0.0f, 1.0f}; //Untuk Mengatur Warna Objek
    GLfloat bahan_diffuse_oranye[] = {1.0f, 0.5f, 0.0f, 1.0f};
    GLfloat bahan_specular_oranye[] = {1.0f, 0.5f, 0.0f, 1.0f};
    GLfloat bahan_shininess_oranye[] = {90.0f};

    glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient_oranye);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse_oranye);
    glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular_oranye);
    glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess_oranye);

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient_oranye);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse_oranye);
    
    glColor3f(1.0, 0.5, 0.0);
    glTranslatef(-4, -2.5f, -8.0);
    glutSolidIcosahedron(); //Membuat Objek
    glPopMatrix();
    
    //Objek Prisma
    GLfloat bahan_ambient_merah[] = {0.6f, 0.0f, 0.0f, 1.0f}; //Untuk Mengatur Warna Objek
    GLfloat bahan_diffuse_merah[] = {0.8f, 0.0f, 0.0f, 1.0f};
    GLfloat bahan_specular_merah[] = {0.8f, 0.0f, 0.0f, 1.0f};
    GLfloat bahan_shininess_merah[] = {90.0f};

    glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient_merah);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse_merah);
    glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular_merah);
    glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess_merah);

    glColor3f(1.0, 0.0, 0.0); 
    GambarPrisma(); //Pemanggilan Fungsi Prisma
    
    //Objek Antiprisma
    GLfloat bahan_ambient_biru[] = {0.0f, 0.0f, 0.6f, 1.0f}; //Untuk Mengatur Warna Objek
    GLfloat bahan_diffuse_biru[] = {0.0f, 0.0f, 0.8f, 1.0f};
    GLfloat bahan_specular_biru[] = {0.0f, 0.0f, 0.8f, 1.0f};
    GLfloat bahan_shininess_biru[] = {90.0f};

    glMaterialfv(GL_FRONT, GL_AMBIENT, bahan_ambient_biru);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse_biru);
    glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular_biru);
    glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess_biru);

    glColor3f(0.0, 0.0, 1.0); 
    GambarAntiprisma(); //Pemanggilan Fungsi Antiprisma
    
    glFlush();
}

void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Gambar3D();
    glutSwapBuffers();
}

void Inisial(void) {
    int w = 800, h = 600;
    glShadeModel(GL_FLAT);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClearAccum(0.0, 0.0, 0.0, 0.0);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("AGUS");
    glutDisplayFunc(Display);
    Inisial();
    glutMainLoop();
    return 0;
}