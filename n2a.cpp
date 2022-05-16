#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void DDA(float x1, float y1, float x2, float y2)
{
    float dx, dy, x, y, step, xin, yin;
    int counter = 0;

    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
    {
        step = abs(dx);
    }
    else
    {
        step = abs(dy);
    }

    xin = dx / step;
    yin = dy / step;
    x = x1;
    y = y1;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();

    for (int k = 1; k <= step; k++)
    {
        x = x + xin;
        y = y + yin;
        if (counter != 39)
        {
            counter++;
        }
        else
        {
            counter = 0;
        }
        if (counter < 20)
        {
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
        }
    }

    glFlush();
}

void DDAdashdot(float x1, float y1, float x2, float y2)
{
    float dx, dy, x, y, step, xin, yin;
    int counter = 0;

    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
    {
        step = abs(dx);
    }
    else
    {
        step = abs(dy);
    }

    xin = dx / step;
    yin = dy / step;
    x = x1;
    y = y1;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();

    for (int k = 1; k <= step; k++)
    {
        x = x + xin;
        y = y + yin;
        if (counter != 79)
        {
            counter++;
        }
        else
        {
            counter = 0;
        }
        if (counter < 40)
        {
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
        }
        else
        {
            if (counter == 60)
            {
                glBegin(GL_POINTS);
                glVertex2i(x, y);
                glEnd();
            }
        }
    }

    glFlush();
}

void display(void)
{
    DDA(-400, 0, 400, 0);
    DDAdashdot(-400, 50, 400, 50);
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-640, 640, -480, 480);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("N2A Solved");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}