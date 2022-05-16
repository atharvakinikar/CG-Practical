#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

void print(float x, float y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void Bresenham(float x1, float y1, float x2, float y2)
{
    float x, y, dx, dy, xinc, yinc, inc1, inc2, p;
    int i;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    x = x1;
    y = y1;

    xinc = 1;
    yinc = 1;

    if (x2 < x1)
    {
        xinc = -1;
    }

    if (y2 < y1)
    {
        yinc = -1;
    }

    if (dx > dy)
    {
        print(x, y);

        p = 2 * dy - dx;
        inc1 = 2 * (dy - dx);
        inc2 = 2 * dy;

        for (i = 0; i < dx; i++)
        {
            if (p > 0)
            {
                y += yinc;
                p += inc1;
            }
            else
            {
                p += inc2;
            }
            x += xinc;
            print(x, y);
        }
    }
    else
    {
        print(x, y);

        p = 2 * dx - dy;
        inc1 = 2 * (dx - dy);
        inc2 = 2 * dx;

        for (i = 0; i < dy; i++)
        {
            if (p > 0)
            {
                x += xinc;
                p += inc1;
            }
            else
            {
                p += inc2;
            }
            y += yinc;
            print(x, y);
        }
    }
    glFlush();
}

void DDA(float x1, float y1, float x2, float y2)
{
    float dx, dy, x, y, step, xinc, yinc;
    dx = x2 - x1;
    dy = y2 - y2;

    if (abs(dx) > abs(dy))
    {
        step = abs(dx);
    }
    else
    {
        step = abs(dy);
    }

    xinc = dx / step;
    yinc = dy / step;

    x = x1;
    y = y1;

    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();

    for (int k = 1; k < step; k++)
    {
        x += xinc;
        y += yinc;
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
    }

    glFlush();
}

void plotPoints(float x, float y, float xc, float yc)
{
    glBegin(GL_POINTS);
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - y, yc - x);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc - y, yc + x);
    glEnd();
}

void BresenhamCircle(float r, float xc, float yc)
{
    int x = 0, y = r;
    float p = (5 / 4) - r;
    plotPoints(x, y, xc, yc);
    while (x < y)
    {

        x = x + 1;

        if (p < 0)
        {
            p = p + 2 * (x) + 1;
        }
        else
        {
            p = p + 2 * (x - y) + 1;
            y = y - 1;
        }
        plotPoints(x, y, xc, yc);
    }
    glFlush();
}

void display(void)
{
    // DDA(0, 0, 400, 400);
    Bresenham(0, 0, 400, 0);
    Bresenham(400, 0, 400, 300);
    Bresenham(400, 300, 0, 300);
    Bresenham(0, 300, 0, 0);

    Bresenham(-40, 0, -240, 0);
    Bresenham(-240, 0, -240, 200);
    Bresenham(-240, 200, -40, 200);
    Bresenham(-40, 200, -40, 0);

    BresenhamCircle(50, -140, -50);
    BresenhamCircle(50, 100, -50);
    BresenhamCircle(50, 300, -50);
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-640, 640, -480, 480);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("N15B Solved");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}