#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

typedef struct pixel
{
    float r, g, b;
} pixel;
pixel fcolor, bcolor;

void fillPixel(int x, int y, pixel fcolor)
{
    glBegin(GL_POINTS);
    glColor3f(fcolor.r, fcolor.g, fcolor.b);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void floodFill(int x, int y)
{
    pixel c;
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &c);
    if ((c.r != bcolor.r || c.g != bcolor.g || c.b != bcolor.b) && (c.r != fcolor.r || c.g != fcolor.g || c.b != fcolor.b))
    {
        fillPixel(x, y, fcolor);
        floodFill(x + 1, y);
        floodFill(x, y + 1);
        floodFill(x - 1, y);
        floodFill(x, y - 1);
    }
    glFlush();
}

void display(void)
{

    fcolor.r = 1.0f;
    fcolor.g = 0.0f;
    fcolor.b = 0.0f;

    glBegin(GL_LINES);

    glVertex2f(200, 200);
    glVertex2f(300, 200);

    glVertex2f(300, 200);
    glVertex2f(300, 175);

    glVertex2f(300, 175);
    glVertex2f(200, 175);

    glVertex2f(200, 175);
    glVertex2f(200, 75);

    glVertex2f(200, 75);
    glVertex2f(175, 75);

    glVertex2f(175, 75);
    glVertex2f(175, 175);

    glVertex2f(175, 175);
    glVertex2f(75, 175);

    glVertex2f(75, 175);
    glVertex2f(75, 200);

    glVertex2f(75, 200);
    glVertex2f(175, 200);

    glVertex2f(175, 200);
    glVertex2f(175, 300);

    glVertex2f(175, 300);
    glVertex2f(200, 300);

    glVertex2f(200, 300);
    glVertex2f(200, 200);

    glEnd();

    bcolor.r = 0.0f;
    bcolor.r = 0.0f;
    bcolor.r = 0.0f;

    floodFill(250, 185);

    glFlush();
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    gluOrtho2D(0, 640, 0, 480);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("N4A Solved");
    init();
    display();
    glutMainLoop();
    return 0;
}