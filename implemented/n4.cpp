#include <GL/freeglut.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
using namespace std;

float xd1, yd1, xd2, yd2;
int xmax = 100;
int ymax = 100;
int xmin = -100;
int ymin = -100;
void disp();

void Init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-320, 320, -240, 240);
    glMatrixMode(GL_PROJECTION);
    glColor3f(1.0, 1.0, 1.0);
}
void dda(float x1, float y1, float x2, float y2)
{
    float dx, dy, steps, x, y, xinc, yinc;
    dx = x2 - x1;
    dy = y2 - y1;
    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    xinc = dx / steps;
    yinc = dy / steps;

    x = x1, y = y1;
    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2d(x, y);
    for (int i = 0; i < steps; i++)
    {
        x = x + xinc;
        y = y + yinc;
        glVertex2d(x, y);
    }
    glEnd();
    glFlush();
}

void disp()
{
    dda(xmin, ymin, xmax, ymin);
    dda(xmax, ymin, xmax, ymax);
    dda(xmax, ymax, xmin, ymax);
    dda(xmin, ymax, xmin, ymin);
    glFlush();

    glColor3f(0.0, 0.0, 1.0);
    dda(xd1, yd1, xd2, yd2);
}

int code(int x, int y)
{
    int c = 0;
    if (y > ymax)
        c = 8;
    if (y < ymin)
        c = 4;
    if (x > xmax)
        c = c | 2;
    if (x < xmin)
        c = c | 1;
    return c;
}

void cohen(float x1, float y1, float x2, float y2)
{
    int c1 = code(x1, y1);
    int c2 = code(x2, y2);
    float m = (y2 - y1) / (x2 - x1);

    while ((c1 | c2) > 0)
    {
        if ((c1 & c2) > 0)
        {
            disp();
            return;
        }

        int c;
        int xi = x1;
        int yi = y1;
        c = c1;
        float x, y;

        if (c == 0)
        {
            c = c2;
            xi = x2;
            yi = y2;
        }
        if ((c & 8) > 0)
        {
            y = ymax;
            x = xi + (1.0 / m) * (ymax - yi);
        }
    }
}

void mykey(unsigned char ch, int x, int y)
{
    if (ch == 'c')
    {
    }
}

int main(int argc, char **argv)
{
    cout << "enter co ordinates of first point \n";
    cout << "X1: ";
    cin >> xd1;
    cout << "\nY1: ";
    cin >> yd1;
    cout << "\nX2: ";
    cin >> xd2;
    cout << "\nY2: ";
    cin >> yd2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Line Clipping");
    Init();
    glutDisplayFunc(disp);
    glutKeyboardFunc(mykey);
    glutMainLoop();
}
