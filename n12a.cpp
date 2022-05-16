#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void print(float x, float y, float xc, float yc)
{
    glBegin(GL_POINTS);
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - y, yc - x);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc + y, yc + x);
    glEnd();
}

void bresenhamCircle(float r, float xc, float yc)
{
    int x = 0, y = r;
    float p = (5 / 4) - r;

    print(x, y, xc, yc);
    while (x < y)
    {
        x++;
        if (p < 0)
        {
            p = p + 2 * x + 1;
        }
        else
        {
            p = p + 2 * (x - y) + 1;
            y--;
        }
        print(x, y, xc, yc);
    }
    glFlush();
}

void display(void)
{
    bresenhamCircle(100, 0, 0);

    // Lower
    bresenhamCircle(40, 0, -140);
    bresenhamCircle(40, 0, -220);
    bresenhamCircle(40, -80, -120);
    bresenhamCircle(40, 80, -120);

    // Upper
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    gluOrtho2D(-640, 640, -480, 480);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("N12A Solved");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}