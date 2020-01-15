// C program to demonstrate 
// drawing a circle using 
// OpenGL 
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 

int x0=-100,py0=-50,x1=200,py1=300;

// function to initialize 
void myInit (void) 
{ 


	// making background color black as first 
	// 3 arguments all are 0.0 
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	
	// making picture color green (in RGB mode), as middle argument is 1.0 
	glColor3f(0.0, 1.0, 0.0); 
	
	// breadth of picture boundary is 1 pixel 
	glPointSize(1.0); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	
	// setting window dimension in X- and Y- direction 
	gluOrtho2D(-780, 780, -420, 420); 
} 

void dda(int a,int b,int c, int d)
{
	x0=a,py0=b,x1=c,py1=d;
	
		glBegin(GL_POINTS);
	
	float X,Y;
	int dx=x1-x0;
	int dy=py1-py0;
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy) ;
	float Xinc=(dx*1.0)/steps;
	float Yinc=(dy*1.0)/steps;
	X=x0;
	Y=py0;
	int j;
	for(j=0;j<steps;j++)
	{
		glVertex2f(X,Y);
		X=X+Xinc;
		Y=Y+Yinc;
	}
	
	glEnd(); 
}

void display (void) 
{ 

	glClear(GL_COLOR_BUFFER_BIT); 
	
	int i;
	for(i=-4;i<5;i++)
	{
		dda(100*i,-400,100*i,400);
		dda(-400,100*i,400,100*i);
	}

	glFlush(); 
} 

int main (int argc, char** argv) 
{ 

	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	
	// giving window size in X- and Y- direction 
	glutInitWindowSize(1366, 768); 
	glutInitWindowPosition(0, 0); 
	
	// Giving name to window 
	glutCreateWindow("Line drwing using DDA algorithm"); 
	myInit(); 
	
	glutDisplayFunc(display); 
	glutMainLoop(); 
} 

