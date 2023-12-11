#include<GL/glut.h>
#include<cmath>

const int windowWidth = 800;
const int windowHeight = 600;

void drawCircle( float cx, float cy, float r, int num) {
	glBegin(GL_LINE_LOOP);
	for(int i = 0; i< num; i++) {
	float theta = 2.0f*3.1415926f*float(i)/float(num);
	float x = r*cosf(theta);
	float y = r*sinf(theta);
	glVertex2f(cx+x, cy+y);
	}
	glEnd();
}
void drawSquare(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
	glBegin(GL_LINES);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glVertex2f(x2,y2);
	glVertex2f(x3,y3);
	glVertex2f(x3,y3);
	glVertex2f(x4,y4);
	glVertex2f(x4,y4);
	glVertex2f(x1,y1);
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	float x1 = -0.5f;
	float y1 = -0.5f;
	float x2 = -0.5f;
	float y2 = 0.5f;
	float x3 = 0.5f;
	float y3 = 0.5f;
	float x4 = 0.5f;
	float y4 = -0.5f;
	
	glColor3f(0.0f,1.0f,1.0f);
	drawSquare(x1, y1, x2, y2, x3, y3, x4, y4);
	
	float x11 = 0.0f;
	float y11 = -0.5f;
	float x21 = -0.5f;
	float y21 = 0.0f;
	float x31 = 0.0f;
	float y31 = 0.5f;
	float x41 = 0.5f;
	float y41 = 0.0f;
	
	glColor3f(0.0f, 1.0f, 1.0f);
	drawSquare(x11,y11,x21,y21,x31,y31,x41,y41);
	float inCircleRadius = 0.3535533906f;
	glColor3f(1.0f,0.0f,0.0f);
	drawCircle(0.0f, 0.0f, inCircleRadius, 120);
	glFlush();
}

int main (int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize( windowWidth, windowHeight);
	glutCreateWindow("PATTERN 2 ");
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
}
	
	

