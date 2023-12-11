#include <GL/glut.h>
#include <iostream>

using namespace std;

// Function to draw a circle using DDA algorithm


// Function to draw a circle using Bresenham's algorithm
void drawCircleBresenham(int xc, int yc, int radius)
{
    glBegin(GL_POINTS);

    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;

    while (x <= y)
    {
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);

        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc - x);

        x++;

        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
    }

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

   
    glColor3f(0.0, 0.0, 1.0); // Blue color for Bresenham circle
    drawCircleBresenham(300, 400, 100);

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Circle Drawing Algorithms");

    gluOrtho2D(0, 600, 0, 600);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}