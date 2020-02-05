// C program to demonstrate 
// drawing a circle using 
// OpenGL 
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 
int i=10;
int X=1300,Y=712;
float s=40;

void increase()
{
	s+=8;
}

void decrease()
{
	if(s>8)
		s-=8;
}

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
	gluOrtho2D(-X/2, X/2, -Y/2, Y/2); 
} 

void display (void) 
{ 
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glClear(GL_COLOR_BUFFER_BIT);
/*	glBegin(GL_POINTS); 
	glVertex3i(200,200,100);
	glVertex3i(0+i,0,0);
	i+=10;
	if(i>200)
		i=10;
	glEnd(); 
	glBegin(GL_LINES);
    	glVertex2i(0,0);
    	glVertex2i(200,200);
	glEnd();*/
	//glFlush(); 
	glutSwapBuffers();
} 

void draw(int x,int y,int z)
{
	int l=s*cos(pi/6);
	int h=s*sin(pi/6);
	//glLoadIdentity();
	glPushMatrix();
	glTranslatef(x, y, z);
	glBegin(GL_TRIANGLES);
	glVertex3i(0,s,0);
	glVertex3i(l,-h,0);
	glVertex3i(-l,-h,0);	
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3i(0,-s,0);
	glVertex3i(l,h,0);
	glVertex3i(-l,h,0);	
	glEnd();
	glPopMatrix();
}

void mouse(int button,int state,int x,int y)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		if(state==GLUT_DOWN)
		{
			exit(0);
		}		
		break;
	case GLUT_RIGHT_BUTTON:
		if(state==GLUT_DOWN)
		{
			draw(x-X/2,-y+Y/2,0);
			glBegin(GL_POINTS); 
			glVertex3i(x-X/2,-y+Y/2,0);
			glEnd(); 
		}else{
			printf("%d %d\n",x,y);
		}		
		break;
	default:
		break;
	}
}

void processNormalKeys(unsigned char key, int x, int y) {

	if (key == 's')
		increase();
	if (key == 'r')
		decrease();
}

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	
	// giving window size in X- and Y- direction 
	glutInitWindowSize(X, Y); 
	glutInitWindowPosition(0, 0); 
	
	// Giving name to window 
	glutCreateWindow("Circle Drawing"); 
	glutKeyboardFunc(processNormalKeys);
	glutMouseFunc(mouse);
	myInit(); 
	
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMainLoop(); 
} 

