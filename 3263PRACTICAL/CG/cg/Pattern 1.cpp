#include<GL/glut.h>
#include<cmath>

const int windowWidth = 800;
const int windowHeight = 600;

void drawCircle( float cx, float cy, float r, int num) 
{
	glBegin(GL_LINE_LOOP);

	for(int i = 0; i< num; i++) 
	{
		float theta = 2.0f*3.1415926f*float(i)/float(num);
		float x = r*cosf(theta);
		float y = r*sinf(theta);
		glVertex2f(cx+x, cy+y);
	}

	glEnd();
}

void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) 
{
	glBegin(GL_LINES);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glVertex2f(x2,y2);
	glVertex2f(x3,y3);
	glVertex2f(x3,y3);
	glVertex2f(x1,y1);
	glEnd();
}

void display() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f,1.0f,0.0f);
	drawCircle(0.0f, -0.015f, 0.52f, 105);
	
	float x1 = 0.0f;
	float y1 = 0.50f;
	float x2 = -0.35f;
	float y2 = -0.40f;
	float x3 = 0.35f;
	float y3 = -0.40f;
	
	glColor3f(0.0f,1.0f,1.0f);
	drawTriangle(x1, y1, x2, y2, x3, y3);
	
	float inCircleRadius = 0.225f;
	glColor3f(1.0f,0.0f,.0f);
	drawCircle(0.0f, -0.15f, inCircleRadius, 120);
	glFlush();
}

int main (int argc, char** argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize( windowWidth, windowHeight);
	glutCreateWindow("PATTERN 1 ");
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
}
	
	

