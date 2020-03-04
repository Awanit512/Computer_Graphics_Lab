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

void recurse(int x1,int y1,int x2,int y2,int x3,int y3,int n)
{
if(n>0)
{
	n--;
	int mx1,my1,mx2,my2,mx3,my3;
	mx1=(x1+x2)/2;
	mx2=(x1+x3)/2;
	mx3=(x2+x3)/2;
	my1=(y1+y2)/2;
	my2=(y1+y3)/2;
	my3=(y2+y3)/2;
	glBegin(GL_TRIANGLES);
	glVertex2i(mx1,my1);
	glVertex2i(mx2,my2);
	glVertex2i(mx3,my3);
	glEnd();
	recurse(x1,y1,mx1,my1,mx2,my2,n);
	recurse(mx1,my1,x2,y2,mx3,my3,n);
	recurse(mx2,my2,mx3,my3,x3,y3,n);
}
}

void display (void) 
{ 
	glClear(GL_COLOR_BUFFER_BIT);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLES);
	glVertex2i(0,300);
	glVertex2i(461,-300);
	glVertex2i(-461,-300);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	recurse(0,300,461,-300,-461,-300,n);
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
