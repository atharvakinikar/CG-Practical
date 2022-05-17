#include <GL/gl.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cmath>
using namespace std;
void displayPoint(int x, int y)
{
    glColor3f(1, 1, 0);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}
double ang(double theta)
{
    return theta * 3.142 / 180;
}
void octant(int xc, int yc, int x, int y)
{
    displayPoint(xc + x, yc + y);
    displayPoint(xc + x, yc - y);
    displayPoint(xc - x, yc + y);
    displayPoint(xc - x, yc - y);
    displayPoint(xc - y, yc - x);
    displayPoint(xc + y, yc + x);
    displayPoint(xc - y, yc + x);
    displayPoint(xc + y, yc - x);
}
void CircleMp(int xc, int yc, int r)
{
    int p = 3 - 2 * r, x = 0, y = r; // loop til the x become y equal to radius (r,r) 1-r
    while (x < y)
    {
        octant(xc, yc, x, y);
        x++;
        if (p > 0)
        { // if p>0 decrement the y and2(x-y)+1
            y--;
            p += 4 * (x - y) + 10;
        }
        else
        { // if p<=0 add 2x+1 to p
            p += 4 * x + 6;
        }
    }
}
void renderfunction(int xc, int yc, int r)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 500, 0, 500);
    CircleMp(xc, yc, r);
    double r1 = (0.2) * r;
    double var1 = (xc - (r + r1) * (cos(ang(45))));
    double var2 = (yc + (r + r1) * (sin(ang(45))));
    double var3 = (xc + (r + r1) * (cos(ang(45))));
    double var4 = (yc + (r + r1) * (sin(ang(45))));
    double var5 = xc;
    double var6 = yc - r - r1;
    double var7 = yc - r - r1 - r1 - r1;
    CircleMp(var5, var6, r1);
    CircleMp(var5, var7, r1);
    double var8 = xc - (0.4 * r);
    double var9 = var6;
    double var10 = xc + (0.4 * r);
    double var11 = var6;
    CircleMp(var8, var6, r1);
    CircleMp(var10, var6, r1);

    CircleMp(var1, var2, r1);
    CircleMp(var3, var4, r1);

    double temp = var1;
    double temp1 = var2;
    double temp2 = var3;
    double temp3 = var4;
    for (double i = 5; i <= 30; i += 5)
    {
        double x1 = temp - (r1 * 2) * (cos(ang(45 + i)));
        double y1 = temp1 + (r1 * 2) * (sin(ang(45 + i)));
        CircleMp(x1, y1, r1);
        temp = x1;
        temp1 = y1;
    }

    for (double i = 5; i <= 30; i += 5)
    {
        double x1 = temp2 + (r1 * 2) * (cos(ang(45 + i)));
        double y1 = temp3 + (r1 * 2) * (sin(ang(45 + i)));
        CircleMp(x1, y1, r1);
        temp2 = x1;
        temp3 = y1;
    }

    glFlush();
}
int main(int argc, char **argv)
{
    int xc, yc, r;
    cout << "enter x-co";
    cin >> xc;
    cout << "enter y-co";
    cin >> yc;
    cout << "enter radius";
    cin >> r;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(500, 500);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Circle");
    renderfunction(xc, yc, r);
    glutMainLoop();
    return 0;
}