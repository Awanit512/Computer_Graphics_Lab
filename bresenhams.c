// C program to demonstrate 
// drawing a circle using 
// OpenGL 
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#include<time.h>
#define pi 3.142857 

int x1=-100,py0=-50,x2=200,py1=300;

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
	int y1=py0,y2=py1;
	int m_new = 2 * (y2 - y1); 
	//int slope_error_new = m_new - (x2 - x1); 
	int slope_error_new = - (x2 - x1);
   for (int x = x1, y = y1; x <= x2; x++) 
   { 
      glVertex2i(x,y);
  
      // Add slope to increment angle formed 
      slope_error_new += m_new; 
  
      // Slope error reached limit, time to 
      // increment y and update slope error. 
      if (slope_error_new >= 0) 
      { 
         y++; 
         slope_error_new  -= 2 * (x2 - x1); 
      } 
      
   } 
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
	scanf("%d %d",&x1,&py0);
	printf("Enter coordinate of point-2\n");
	scanf("%d %d",&x2,&py1);

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

