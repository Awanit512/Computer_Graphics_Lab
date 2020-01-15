// C program to demonstrate 
// drawing a circle using 
// OpenGL 
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#include<time.h>
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

void display (void) 
{ 
	clock_t start,end;
	double cpu_time_used;
	start = clock();

	glClear(GL_COLOR_BUFFER_BIT); 
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
	
	
	
/*	float x, y, i; 
	
	// iterate y up to 2*pi, i.e., 360 degree 
	// with small increment in angle as 
	// glVertex2i just draws a point on specified co-ordinate 
	for ( i = 0; i < (2 * pi); i += 0.001) 
	{ 
		// let 200 is radius of circle and as, 
		// circle is defined as x=r*cos(i) and y=r*sin(i) 
		x = 200 * i; 
		y = 200 * i; 
		
		glVertex2i(x, y); 
	} */
	   	end=clock();
      cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
      printf("Time used : %f\n",cpu_time_used);

	
	glEnd(); 
	glFlush(); 
} 

int main (int argc, char** argv) 
{ 
	printf("==============================================================");
	printf("Ranges of X & Y are (-780,780) & (-420,420) respectively.");
	printf("Enter coordinate of point-1\n");
	scanf("%d %d",&x0,&py0);
	printf("Enter coordinate of point-2\n");
	scanf("%d %d",&x1,&py1);

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

