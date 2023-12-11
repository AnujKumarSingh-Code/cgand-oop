#include<iostream>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

double X1 , Y1 , X2 , Y2;
int selection=1;

class Line{

	void LineDDA(void)
	{
		cout<<"DDA"<<endl;
		float dy,dx,step,x,y,k,Xin,Yin;
		dx=X2-X1;
		dy=Y2-Y1;
		
		if(abs(dx) > abs(dy))
		{
			step = abs(dx);
		}	
		else
		{
			step = abs(dy);
		}
		
		Xin = dx/step;
		Yin = dy/step;
		
		x=X1;
		y=Y1;
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
		
		for(k=1 ; k<= step ; k++)
		{
			x = x + Xin ;
			y = y + Yin;
			
			glBegin(GL_POINTS);
			glVertex2i(x,y);
		}
		
		glEnd();
		glutPostRedisplay();
		glFlush();
	}

	void Bresenham(void)
	{
		int dx = abs(x2 - x1);
		int dy = abs(y2 - y1);

		int x, y;

		if (dx >= dy)
		{
			int decision = 2 * dy - dx;

			glBegin(GL_POINTS);
			glVertex2i(x1, y1);

			for (x = x1, y = y1; x < x2; x++)
			{
				if (decision > 0)
				{
					y += (y2 > y1 ? 1 : -1);
					decision -= 2 * dx;
				}

				decision += 2 * dy;
				glVertex2i(x + 1, y);
			}

			glEnd();
		}
		else
		{
			int decision = 2 * dx - dy;

			glBegin(GL_POINTS);
			glVertex2i(x1, y1);

			for (x = x1, y = y1; y < y2; y++)
			{
				if (decision > 0)
				{
					x += (x2 > x1 ? 1 : -1);
					decision -= 2 * dy;
				}

				decision += 2 * dx;
				glVertex2i(x, y + 1);
			} 

			glEnd();
		}
	}
	
	public:
 	static void display()
	{
		Line l;
		switch(selection)
		{
			case 1: l.LineDDA() ; break;
			case 2: l.Bresenham(); break;
		}
 	}
};
	
	

void Init()
{

	glClearColor(0.0 , 0.0 , 0.2 , 0.0);
	glViewport(0,0,640 ,480);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-500 , 500 , -500 , 500 ,-1 ,1);
	
}


void lineGeneration(int i)
{
 if(i==4) exit(0);
 selection = i;
} 


void keyboard(unsigned char key , int x , int y)
{
	if(key == 27) exit(0);
	else if(key == 'd' || key =='D') selection=1; 
}

void createMenu()
{
	int s_id = glutCreateMenu(lineGeneration);
		glutAddMenuEntry("DDA Algorithm" , 1);
		glutAddMenuEntry("Bresenham Algo" , 2);
		int m_id = glutCreateMenu(lineGeneration);
		glutAddSubMenu("Algorithm" , s_id);
		glutAddMenuEntry("Exit" , 4);
		glutAttachMenu(GLUT_RIGHT_BUTTON);
}
int main(int argc , char **argv)
{
	cout<<"Enter the First co-ordinates \n";
	cin>>X1>>Y1;
	cout<<"Enter the Second co-ordinates \n";
	cin>>X2>>Y2;
	
	glutInit(&argc , argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(500 , 500);
	glutCreateWindow("Line Generation");
	Init();
	glutDisplayFunc(Line::display);
	//glutKeyboardFunc(keyboard);
	createMenu();
	glutMainLoop();
	return 0 ;

}


