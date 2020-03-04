#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 
int n=-1;
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

void draw_sq(int x1,int y1,int l)
{
    glBegin(GL_POLYGON);

    glVertex2d(x1 + l, y1 + l);
    glVertex2d(x1 + l, y1 - l);
    glVertex2d(x1 - l, y1 - l);
    glVertex2d(x1 - l, y1 + l);

    glEnd();
}

void recurse(int x,int y,int l,int n)
{
if(n>0)
{
	n--;
	l=2*l/3;
	draw_sq(x,y,l/2);
	recurse(x+l,y+l,l/2,n);
	recurse(x+l,y,l/2,n);
	recurse(x+l,y-l,l/2,n);
	recurse(x-l,y+l,l/2,n);
	recurse(x-l,y,l/2,n);
	recurse(x-l,y-l,l/2,n);
	recurse(x,y+l,l/2,n);
	recurse(x,y-l,l/2,n);
}
}

void display (void) 
{ 
	glClear(GL_COLOR_BUFFER_BIT);
	draw_sq(0,0,400);
	glColor3f(0.0, 0.0, 0.0);
	recurse(0,0,400,n);
	glFlush(); 
} 

int main (int argc, char** argv) 
{ 
	while(n<0)
	{
		printf("Enter number of recursive steps\n");
		scanf("%d",&n);
	}
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
