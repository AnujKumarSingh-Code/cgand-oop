#include<GL/glut.h>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
float X1, Y1, X2, Y2;

 void display(void)
 {
 	cout<<"DDA"<<endl;
 	float dy,dx,step,x,y,k,Xin,Yin;
 	dx=X2-X1;
 	dy=Y2-Y1;
 	
 	if(abs(dx)> abs(dy))
 	{
 		step = abs(dx);
 	}
 	else {
 		step = abs(dy);
 	}
 		
 	Xin = dx/step;
 	Yin = dy/step;
 	
 	x = X1;
 	y = Y1;
 	glBegin(GL_POINTS);
 	glVertex2i(x,y);
 	glEnd();
 	
 	for (k=1;k<=step;k++)
 	{
 		x = x + Xin;
 		y = y + Yin;
 		
 		glBegin(GL_POINTS);
 		glVertex2i(x,y);
 		glEnd();
 	}
 		glFlush();
 	}
 	
 void Init(void)	{
 	glClearColor(0.0, 0.0, 0.2, 0.0);
 	glViewport(0, 0, 640, 480);
 	glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();
 	gluOrtho2D(0.0,640.0,0.0,480.0);
 }
 	
 /*void createMenu() {
 	int s_id = glutCreateMenu(lineGeneration);
 		glutAddMenuEntry("DDA Algorithm", 1);
 		int m_id = glutCreateMenu(lineGeneration);
 		glutAddSubMenu("Algorithm", s_id);
 		glutAddMenuEntry("Exit", 4);
 		glutAttachMenu(GLUT_RIGHT_BUTTON);
 }*/
 
 int main(int argc, char **argv){
 	cout<<"Enter the First co-ordinates \n";
 	cin>>X1>>Y1;
 	cout<<"Enter the Second co-ordinates \n";
 	cin>>X2>>Y2;
 	
 	glutInit(&argc,argv);
 	glutInitDisplayMode(GLUT_RGB);
 	glutInitWindowPosition(100,100);
 	glutInitWindowSize(500,500);
 	glutCreateWindow("Line Generation");
 	//createMenu();
 	Init();
 	glutDisplayFunc(display);
 	glutMainLoop();
 	return 0;
 	}
 	
 	
 	
 	
 	
 
 
