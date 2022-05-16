#include <iostream>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <math.h>
using namespace std;

void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 500, 0, 500);
    glMatrixMode(GL_PROJECTION);
    glColor3f(0.2, 0.5, 1);
}

void dda(float x1, float y1, float x2, float y2)
{
    float dy, dx, steps, xi, yi, k;
    dx = x2 - x1;
    dy = y2 - y1;
    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    xi = dx / steps;
    yi = dy / steps;

    glBegin(GL_POINTS);
    glColor3f(0.2, 0.5, 1);
    glVertex2d(x1, y1);

    for (k = 0; k < steps; k++)
    {
        x1 += xi;
        y1 += yi;
        glVertex2d(x1, y1);
    }
    glEnd();
    glFlush();
}
void renderFunc()
{
    dda(100, 100, 100, 125);
    dda(100, 125, 125, 125);
    dda(125, 125, 125, 150);
    dda(125, 150, 150, 150);
    dda(150, 150, 150, 175);
    dda(150, 175, 175, 175);
    dda(175, 175, 175, 200);
    dda(175, 200, 200, 200);
    dda(200, 200, 200, 225);
    dda(200, 225, 225, 225);
    dda(225, 225, 225, 100);
    dda(225, 100, 100, 100);

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Steps");

    init();
    glutDisplayFunc(renderFunc);
    glutMainLoop();

    return 0;
}