#include <GL/freeglut.h>
#include <iostream>
#include <math.h>
#include <GL/glut.h>

void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 500, 0, 500);
    glMatrixMode(GL_PROJECTION);
    glColor3f(1.0, 1.0, 1.0);
}

void dda(float x1, float y1, float x2, float y2)
{
    float steps, xi, yi, dx, dy, k;
    dx = x2 - x1;
    dy = y2 - y1;
    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    xi = dx / steps;
    yi = dy / steps;
    glBegin(GL_POINTS);
    glPointSize(5);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2d(x1, y1);
    for (k = 1; k < steps; k++)
    {
        x1 += xi;
        y1 += yi;
        glVertex2d(x1, y1);
    }
    glEnd();
    glFlush();
}

void draw()
{
    dda(100, 100, 100, 300);
    dda(300, 100, 300, 300);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("1a");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
}