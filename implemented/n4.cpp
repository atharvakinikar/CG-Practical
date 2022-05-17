#include <iostream>
#include <GL/freeglut.h>
#include <GL/glut.h>
using namespace std;

int xmax = 100;
int xmin = -100;
int ymax = 100;
int ymin = -100;
int xd1, yd1, xd2, yd2;
void Init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    gluOrtho2D(-250, 250, -250, 250);
}

void dda(float x1, float y1, float x2, float y2)
{
    float steps, xinc, yinc, dx, dy, x, y;
    dx = x2 - x1;
    dy = y2 - y1;
    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    xinc = dx / steps;
    yinc = dy / steps;
    x = x1;
    y = y1;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POINTS);
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

int code(int x, int y)
{
    // TBRL
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
            draw();
            return;
        }

        int c = 0;
    }
}

void mykey(unsigned char ch, int x1, int y1)
{
    if (ch == 'c')
    {
        cohen(xd1, yd1, xd2, yd2);
        glFlush();
    }
}

void draw()
{
    dda(xmin, ymin, xmax, ymin); // creating window using dda algorithm to draw lines
    dda(xmax, ymin, xmax, ymax);
    dda(xmax, ymax, xmin, ymax);
    dda(xmin, ymax, xmin, ymin);
    dda(10, 10, 150, 150);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("line clipping");
    Init();
    glutDisplayFunc(draw);
    glutKeyboardFunc(mykey);
    glutMainLoop();
}