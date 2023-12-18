#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<bool> keyStatus(256, false); // Untuk menampung status tombol (256 tombol keyboard)

GLfloat light_diffuse1[] = {1, 1, 1, 0.5};
GLfloat light_position[] = {0.0f, 50.0f, -75.0f, 1.0f};

float scaleValue = 1.0, translateValue = 0.0, rotateValue = 0.0, cloudRotation = 0.0, eyePositionX = 0.0, eyePositionY = 20.0, eyePositionZ = 50.0;

void keyboard(unsigned char key, int x, int y)
{
    keyStatus[key] = true;
}

void keyboardUp(unsigned char key, int x, int y)
{
    keyStatus[key] = false;
}

bool isKeyPressed(char key)
{
    return keyStatus[key];
}

void objectManipulation()
{
    const float scaleSpeed = 0.001;
    const float translateSpeed = 0.01;
    const float rotateSpeed = 0.5;
    if (isKeyPressed('w'))
    {
        scaleValue += scaleSpeed; // perbesar
    }
    else if (isKeyPressed('m') && scaleValue > 0.001)
    {
        scaleValue -= scaleSpeed; // perkecil
    }

    if (isKeyPressed('d') && translateValue > -10)
    {
        translateValue -= translateSpeed;
    }
    else if (isKeyPressed('u') && translateValue < 0)
    {
        translateValue += translateSpeed;
    }

    if (isKeyPressed('l'))
    {
        rotateValue += rotateSpeed;
    }
    else if (isKeyPressed('n'))
    {
        rotateValue -= rotateSpeed;
    }

    if (isKeyPressed('r'))
    {
        scaleValue = 1.0;
        translateValue = 0.0;
        rotateValue = 0.0;
    }

    cloudRotation += 0.1;
    if (cloudRotation > 360.0)
    {
        cloudRotation -= 360.0;
    }

    glutPostRedisplay();
}

struct vec3
{
    float x, y, z;
};

class dots
{
private:
    int numOfPoint[3] = {5, 10, 20};
    struct Tiang
    {
        GLfloat part1[5][3];
        GLfloat part2[5][3];
        GLfloat part3[5][3];
    };

    struct Pohon
    {
        GLfloat part1[5][3];
        GLfloat part2[5][3];
    };

    struct Bendera
    {
        GLfloat part1[9][3];
        GLfloat part2[9][3];
        GLfloat part3[9][3];
    };

public:
    // tiang Bendera
    Tiang tiang = {{{}, {-0.5, 20}, {0.5, 20}, {0.5, 0.5}, {-0.5, 0.5}},
                   {{}, {-2.5, 0.5}, {2.5, 0.5}, {2.5, -0.5}, {-2.5, -0.5}},
                   {{}, {-4, -0.5}, {4, -0.5}, {4, -1.5}, {-4, -1.5}}};

    Pohon pohon = {{{}, {-12, 1.5}, {-10, 1.5}, {-10, -1.5}, {-12, -1.5}},
                   {{}, {-12, 9}, {-10, 9}, {-8.5, 1.5}, {-13.5, 1.5}}};

    Bendera bendera = {
        {{}, {0.5, 20.0}, {1.5, 20.0}, {2.0, 20.0}, {3.0, 20.0}, {3.5, 20.0}, {4.5, 20.0}, {5.0, 20.0}, {6.0, 20.0}},
        {{}, {0.5, 18.0}, {1.5, 18.0}, {2.0, 18.0}, {3.0, 18.0}, {3.5, 18.0}, {4.5, 18.0}, {5.0, 18.0}, {6.0, 18.0}},
        {{}, {0.5, 16.0}, {1.5, 16.0}, {2.0, 16.0}, {3.0, 16.0}, {3.5, 16.0}, {4.5, 16.0}, {5.0, 16.0}, {6.0, 16.0}}};

    // methods
    void
    setZTiang(GLfloat z1, GLfloat z2, GLfloat z3)
    {
        for (int i = 0; i < 5; i++)
        {
            tiang.part1[i][2] = z1;
            tiang.part2[i][2] = z2;
            tiang.part3[i][2] = z3;
        }
    }

    void setZPohon(GLfloat z1, GLfloat z2)
    {
        for (int i = 0; i < 5; i++)
        {
            pohon.part1[i][2] = z1;

            i <= 2 ? pohon.part2[i][2] = z1 : pohon.part2[i][2] = z2;
        }
    }

    void setZBendera(GLfloat z1, GLfloat z2, GLfloat z3)
    {
        for (int i = 0; i < 9; i++)
        {
            if (i > 2 && i < 4)
            {
                bendera.part1[i][2] = z2;
                bendera.part2[i][2] = z2;
                bendera.part3[i][2] = z2;
            }
            else if (1 > 4 && 1 < 6)
            {
                bendera.part1[i][2] = z3;
                bendera.part2[i][2] = z3;
                bendera.part3[i][2] = z3;
            }
            else
            {
                bendera.part1[i][2] = z1;
                bendera.part2[i][2] = z1;
                bendera.part3[i][2] = z1;
            }
        }
    }
};
dots front;
dots rear;

vec3 normalCalculate(GLfloat dots1[3], GLfloat dots2[3], GLfloat dots3[3])
{
    vec3 U = {dots2[0] - dots1[0], dots2[1] - dots1[1], dots2[3] - dots1[3]};
    vec3 V = {dots3[0] - dots1[0], dots3[1] - dots1[1], dots3[3] - dots1[3]};
    vec3 normal = {
        U.y * V.z - U.z * V.y,
        U.z * V.x - U.x * V.z,
        U.x * V.y - U.y * V.x};
    return normal;
}

vec3 normalize(const vec3 coordinate)
{
    float divider = sqrt(pow(coordinate.x, 2) + pow(coordinate.y, 2) + pow(coordinate.z, 2));
    vec3 newCoordinate = {
        coordinate.x / divider,
        coordinate.y / divider,
        coordinate.z / divider};
    return newCoordinate;
}

void setNormalizedNormal(GLfloat dots1[3], GLfloat dots2[3], GLfloat dots3[3])
{
    vec3 normal = normalCalculate(dots1, dots2, dots3);
    vec3 normalized_normal = normalize(normal);
    glNormal3f(normalized_normal.x, normalized_normal.y, normalized_normal.z);
}

void objectSides(GLfloat p1[3], GLfloat p2[3], GLfloat p3[3], GLfloat p4[3])
{
    setNormalizedNormal(p1, p2, p3);
    glVertex3fv(p1);
    glVertex3fv(p2);
    glVertex3fv(p3);
    glVertex3fv(p4);
}

void frontAndRear_quads(GLfloat points[5][3])
{
    setNormalizedNormal(points[1], points[2], points[3]);
    for (int i = 1; i <= 4; i++)
    {
        glVertex3fv(points[i]);
    }
}

void sidesDrawer(int endPoint, GLfloat front_points[][3], GLfloat rear_points[][3], bool backToFirst = true)
{
    for (int i = 1; i < endPoint; i++)
    {
        objectSides(front_points[i], front_points[i + 1], rear_points[i + 1], rear_points[i]);
    }
    if (backToFirst)
    {
        objectSides(front_points[endPoint], front_points[1], rear_points[1], rear_points[endPoint]);
    }
}

void extras()
{
    glColor3f(0.0 / 255.0, 145.0 / 255.0, 23.0 / 255.0); // rgb(0, 154, 23)

    glBegin(GL_QUADS);
    glVertex3f(-100, -1.5, 100);
    glVertex3f(100, -1.5, 100);
    glVertex3f(100, -1.5, -100);
    glVertex3f(-100, -1.5, -100);
    glEnd();
}

void drawCloud(float cloudRotation, float cloudPositionX, float cloudPositionY, float cloudPositionZ = -50)
{
    glPushMatrix();
    glRotatef(cloudRotation, 0, 1, 0);
    glTranslatef(cloudPositionX, cloudPositionY, -50); // Mengubah posisi awan sesuai kebutuhan
    glColor3f(1, 1, 1);
    glBegin(GL_TRIANGLES);
    // Bagian atas awan
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(-2.0f, 1.0f, 0.0f);
    glVertex3f(2.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 4.0f, 0.0f);

    // Bagian bawah awan
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3f(-3.0f, -1.0f, 0.0f);
    glVertex3f(3.0f, -1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);

    // Bagian sisi awan
    glNormal3f(1.0, 1.0, 0.0);
    glVertex3f(-3.0f, -1.0f, 0.0f);
    glVertex3f(-2.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);

    glNormal3f(-1.0, 1.0, 0.0);
    glVertex3f(-2.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(2.0f, 1.0f, 0.0f);

    glVertex3f(2.0f, 1.0f, 0.0f);
    glVertex3f(3.0f, -1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);

    glVertex3f(3.0f, -1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-3.0f, -1.0f, 0.0f);
    glEnd();

    glPopMatrix();
}

void renderText(float x, float y, void *font, const char *string)
{
    glRasterPos2f(x, y);
    while (*string)
    {
        glutBitmapCharacter(font, *string);
        string++;
    }
}

// DRAW OBJECT
void drawTiangBendera()
{
    front.setZTiang(0.5, 2.5, 4);
    rear.setZTiang(-0.5, -2.5, -4);

    glColor3f(136.0 / 255.0, 141.0 / 255.0, 143.0 / 255.0); // rgb(62, 63, 63)

    glBegin(GL_QUADS);
    setNormalizedNormal(front.tiang.part1[1], front.tiang.part1[2], front.tiang.part1[3]);
    frontAndRear_quads(front.tiang.part1);
    frontAndRear_quads(rear.tiang.part1);
    sidesDrawer(4, front.tiang.part1, rear.tiang.part1);

    setNormalizedNormal(front.tiang.part2[1], front.tiang.part2[2], front.tiang.part2[3]);
    frontAndRear_quads(front.tiang.part2);
    frontAndRear_quads(rear.tiang.part2);
    sidesDrawer(4, front.tiang.part2, rear.tiang.part2);

    setNormalizedNormal(front.tiang.part3[1], front.tiang.part3[2], front.tiang.part3[3]);
    frontAndRear_quads(front.tiang.part3);
    frontAndRear_quads(rear.tiang.part3);
    sidesDrawer(4, front.tiang.part3, rear.tiang.part3);
    glEnd();
}

void drawBendera()
{
    front.setZBendera(0.25, 0.0, 0.5);
    rear.setZBendera(-0.25, 0.5, 0.0);

    glPushMatrix();

    glTranslatef(0, translateValue, 0);
    glRotatef(rotateValue, 0, 1, 0);

    glBegin(GL_QUADS);

    // TOP
    glColor3f(1, 0, 0); // rgb(255, 0, 0)
    sidesDrawer(7, front.bendera.part1, rear.bendera.part1, false);
    sidesDrawer(7, front.bendera.part2, rear.bendera.part2, false);
    sidesDrawer(7, front.bendera.part1, front.bendera.part2, false);
    sidesDrawer(7, rear.bendera.part1, rear.bendera.part2, false);

    // BOTTOM
    glColor3f(1, 1, 1); // rgb(255, 255, 255)
    sidesDrawer(7, front.bendera.part2, rear.bendera.part2, false);
    sidesDrawer(7, front.bendera.part3, rear.bendera.part3, false);
    sidesDrawer(7, front.bendera.part2, front.bendera.part3, false);
    sidesDrawer(7, rear.bendera.part2, rear.bendera.part3, false);
    glEnd();

    glPopMatrix();
}

void drawPohon(GLfloat positionX, GLfloat positionZ, GLfloat height)
{
    front.setZPohon(12, 13.5);
    rear.setZPohon(10, 8.5);

    glPushMatrix();
    glScalef(scaleValue, height + scaleValue, scaleValue);
    glTranslatef(positionX, 0, positionZ);

    glBegin(GL_QUADS);
    glColor3f(97.0 / 255, 70.0 / 255, 38.0 / 255); // rgb(97, 70, 38))
    frontAndRear_quads(front.pohon.part1);
    frontAndRear_quads(rear.pohon.part1);
    sidesDrawer(4, front.pohon.part1, rear.pohon.part1);

    glColor3f(92.0 / 255.0, 168.0 / 255.0, 4.0 / 255.0); // rgb(92, 169, 4)
    frontAndRear_quads(front.pohon.part2);
    frontAndRear_quads(rear.pohon.part2);
    sidesDrawer(4, front.pohon.part2, rear.pohon.part2);
    glEnd();

    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(135.0 / 255.0, 206.0 / 255.0, 235.0 / 255.0, 1.0); // rgb(135, 207, 235)

    GLfloat ambient[] = {0.2f, 0.2f, 0.2f, 1.0f};
    GLfloat diffuse[] = {0.8f, 0.8f, 0.8f, 1.0f};
    GLfloat specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat shininess[] = {100.0f};

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

    const char *text1 = "Translation : u (up) / d (down)";
    const char *text2 = "Rotation : l (left) / n (not left a.k.a right)";
    const char *text3 = "Scaling : m (mini) / w (wumbo)";
    const char *text4 = "r for reset all condition";

    renderText(-18.0f, 20.0f, GLUT_BITMAP_HELVETICA_12, text1);
    renderText(-18.0f, 18.0f, GLUT_BITMAP_HELVETICA_12, text2);
    renderText(-18.0f, 16.0f, GLUT_BITMAP_HELVETICA_12, text3);
    renderText(-18.0f, 14.0f, GLUT_BITMAP_HELVETICA_12, text4);

    extras();
    drawCloud(cloudRotation + 100, -10, 15);
    drawCloud(-cloudRotation - 50, 0, 20, -45);
    drawCloud(-cloudRotation - 100, -5, 10, 70);
    drawCloud(cloudRotation + 50, 10, 17, 50);
    drawCloud(cloudRotation + 50, -7, 10, 10);

    drawTiangBendera();

    drawBendera();
    glPushMatrix();
    objectManipulation(); // Memanggil fungsi untuk perubahan skala objek
    drawPohon(0, 0, 0.5);
    drawPohon(20, 0, 0.0);
    drawPohon(20, -30, 0.7);
    drawPohon(15, -60, 0.3);
    drawPohon(-10, -60, 0.3);
    // glTranslatef(-10, 0, 10);
    glutSwapBuffers();
    // glutPostRedisplay();
}

void init()
{
    // pencahayaan
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0); // Konfigurasi Cahaya ke-1
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse1);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_DEPTH_TEST);
    // setup projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 500.0); // sudut pandang vertikal, lebar/tinggi layar, jarak terdepan kamera, jarak terjauh kamera
    // glOrtho(-20, 20, -10, 30, -20, 20);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyePositionX, eyePositionY, eyePositionZ, // eyeX, eyeY, eyeZ (Posisi Kamera)
              0.0, 5.0, 0.0,                            // centerX, centerY, CenterZ (Titik Pusat Yang Dilihat Kamera)
              0.0, 1.0, 0.0);                           // Vektor Atas

    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    cout << "\t\tTB KELOMPOK 8" << endl
         << "\tTeknik Informatika B" << endl
         << endl
         << "Yoga Agustiansyah\t(2206050)" << endl
         << "Azki Fadilah\t\t(2206048)" << endl
         << "Ikbal Amiludin\t\t(2206051)" << endl
         << endl
         << "Tema : Bendera";

    glutInit(&argc, argv);  
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 350);
    glutCreateWindow("TB KELOMPOK 8 - Bendera");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);
    glutIdleFunc(objectManipulation);
    init();
    glutMainLoop();

    return 0;
}