#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

// Plot eight points using circle's symmetrical property
void plot_point(int x, int y, int xc, int yc)
{
    glBegin(GL_POINTS);
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc - y, yc - x);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc - y, yc + x);
    glEnd();
}

void bresenham_circle(int r, float xc, float yc)
{
    int x = 0, y = r;
    float pk = (5.0 / 4.0) - r;
    /* Plot the first point */
    plot_point(x, y, xc, yc);
    int k;
    /* Find all vertices till x=y */
    while (x < y)
    {
        x = x + 1;
        if (pk < 0)
            pk = pk + 2 * x + 1;
        else
        {
            y = y - 1;
            pk = pk + 2 * (x - y) + 1;
        }
        plot_point(x, y, xc, yc);
    }
    glFlush();
}

// Function to draw two concentric circles
void concentric_circles(void)
{
    // Center of the cicle = (320, 240)
    bresenham_circle(300, 0, 0);
    bresenham_circle(280, 0, 0);

    bresenham_circle(60, 360, 0);
    bresenham_circle(60, -360, 0);
    bresenham_circle(60, 0, 360);
    bresenham_circle(60, 0, -360);
    bresenham_circle(60, 340, 120);
    bresenham_circle(60, 340, -120);
    bresenham_circle(60, -340, 120);
    bresenham_circle(60, -340, -120);
    bresenham_circle(60, 120, 340);
    bresenham_circle(60, -120, 340);
    bresenham_circle(60, 120, -340);
    bresenham_circle(60, -120, -340);
}

void Init()
{
    glClearColor(1.0, 1.0, 1.0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // glColor3f(0.0, 0.0, 0.0);
    gluOrtho2D(-640, 640, -480, 480);
    // glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(640, 480);
    glutCreateWindow("bresenham_circle");
    Init();
    glutDisplayFunc(concentric_circles);
    glutMainLoop();
    return 0;
}