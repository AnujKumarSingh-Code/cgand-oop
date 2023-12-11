#include<iostream>
#include<GL/glut.h>
#include<stdlib.h>

void initGL() {
glClearColor(0.0f,0.0f,0.0f,1.0f);
}
 
 void display() {
 glClear(GL_COLOR_BUFFER_BIT);
 glBegin(GL_TRIANGLES);
 glColor3f(0.0f,0.0f,1.0f);
 glVertex2f(0.1f,-0.6f);
 glVertex2f(0.7f,-0.6f);
 glVertex2f(0.4f,-0.1f);
 glColor3f(1.0f,0.0f,0.0f);
 glVertex2f(0.3f,-0.4f);
 glColor3f(0.0f,1.0f,0.0f);
 glVertex2f(0.9f,-0.4f);
 glColor3f(0.0f,0.0f,1.0f);
 glVertex2f(0.6f,-0.9f);
 glEnd();
 
 glBegin(GL_POLYGON);
 glColor3f(0.0f,1.0f,0.0f);
 glVertex2f(0.6f,0.6f);
 glVertex2f(0.4f,0.2f);
 glVertex2f(0.6f,0.2f);
 glVertex2f(0.6f,0.2f);
 glVertex2f(0.4f,0.6f);
 glEnd();
 
 glFlush();
 }
void keyFunc(unsigned char ch, int x,int y) {
	if (ch==97)
		exit(0);
}
/*void mouseFunc(int button, int buttonState, int x, int y)
{
	if (buttonState == GLUT_DOWN){
	// handle mousePressed event
	}
	else {// buttonState is GLUT_UP
	// handle mouseReleased event
	}
}*/

 int main (int argc, char** argv){
 glutInit(&argc,argv);
 glutCreateWindow("Vertex,Primitive & Color");
 glutInitWindowSize(320,320);
 glutInitWindowPosition(50,50);
 glutDisplayFunc(display);
 glutKeyboardFunc(keyFunc);

 initGL();
 glutMainLoop();
 return 0;
 }
 
