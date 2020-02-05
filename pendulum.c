// C program to demonstrate 
// drawing a circle using 
// OpenGL 
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 



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

void line(int x0,int py0,int x1, int py1)
{
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

void draw8(int xc,int yc,int x,int y)
{
	glVertex2i(xc+x, yc+y);
	glVertex2i(xc+x, yc-y);
	glVertex2i(xc-x, yc+y);
	glVertex2i(xc-x, yc-y);
	glVertex2i(xc+y, yc+x);
	glVertex2i(xc+y, yc-x);
	glVertex2i(xc-y, yc+x);
	glVertex2i(xc-y, yc-x);
}

void circle(int xc,int yc, int r)
{
	glBegin(GL_POINTS);
	int x=0,y=r;
	int p=3-2*r;
	draw8(xc,yc,x,y);
	while(x<y)
	{
		if(p<0){
			draw8(xc,yc,++x,y);
			p+=4*x;
		}
		else{
			draw8(xc,yc,++x,--y);
			p+=4*(x-y);
		}
	}
	glEnd();
}

void pendulum(float xc, float yc,int ox,int oy,float theta)
{
	circle(xc,yc,100);
	line(xc+100*sin(theta),yc+100*cos(theta),ox,oy);
}

float mod_(float a)
{
	return a>=0?a:-a;
}

void display (void) 
{ 	
	int ox=0,oy=350;
	float theta=pi/3,L=600;
	float xc=ox-L*sin(theta),g=9.8,yc=oy-L*cos(theta),dt=0.005;

	float alpha=-(g/L)*sin(theta);
	float w=0;
	
	while(1){
	
	alpha=-(g/L)*sin(theta);
	w+=alpha*dt;
	theta+=w*dt;
	
	glClear(GL_COLOR_BUFFER_BIT); 
	 
	pendulum(ox-L*sin(theta),oy-L*cos(theta),ox,oy,theta);
	 
	glFlush();
	
	} 
} 

int main (int argc, char** argv) 
{ 

	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	
	// giving window size in X- and Y- direction 
	glutInitWindowSize(1366, 768); 
	glutInitWindowPosition(0, 0); 
	
	// Giving name to window 
	glutCreateWindow("Circle Drawing"); 
	myInit(); 
	
	glutDisplayFunc(display); 
	glutMainLoop(); 
} 

