// C program to demonstrate 
// drawing a circle using 
// OpenGL 
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 

int xc,yc,r;

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
}

void display (void) 
{ 
	glClear(GL_COLOR_BUFFER_BIT); 
	glBegin(GL_POINTS); 
	
	circle(xc,yc,r); 
	
	glEnd(); 
	glFlush(); 
} 

int main (int argc, char** argv) 
{ 
	printf("Enter X-center, Y-center, radius\n");
	scanf("%d %d %d",&xc,&yc,&r);

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

