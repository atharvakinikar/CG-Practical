#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void print(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void Bresenham(float x1, float y1, float x2, float y2)
{
    int i;
    float dx, dy, xinc, yinc, inc1, inc2, p, x, y;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    xinc = 1;
    yinc = 1;

    if (x2 < x1)
        xinc = -1;
    if (y2 < y1)
        yinc = -1;

    x = x1;
    y = y1;

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
                p += inc2;
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
                p += inc2;
            y += yinc;
            print(x, y);
        }
    }

    glFlush();
}

void display(void)
{
    Bresenham(-330, 200, 330, 200);
    Bresenham(-330, -200, 330, -200);
    Bresenham(-330, 200, -330, -200);
    Bresenham(330, 200, 330, -200);

    // Outter
    Bresenham(-350, 230, 350, 230);
    Bresenham(-350, -230, -130, -230);
    Bresenham(350, -230, 130, -230);
    Bresenham(-350, 230, -350, -230);
    Bresenham(350, 230, 350, -230);

    // Stand
    Bresenham(-130, -230, -150, -270);
    Bresenham(130, -230, 150, -270);
    Bresenham(-150, -270, 150, -270);

    // Mountains
    Bresenham(-330, -200, -100, 150);
    Bresenham(-100, 150, 0, -200);
    Bresenham(0, -200, 150, 0);
    Bresenham(150, 0, 330, -200);
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
    glutInitDisplayMode(0);
    // glutInitDisplayMode(GL_SINGLE_COLOR | GL_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("N3A Solved");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}