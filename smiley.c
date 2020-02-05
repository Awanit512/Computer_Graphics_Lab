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
int angle=0;
float R=80;
int cx=0,cy=0;

void reset()
{
	angle=0;
	R=80;
	cx=0;
	cy=0;
}

void semi_circle(int tx,int ty,int r)  
{  
    glBegin(GL_POINTS); 
    float x, y, i; 
    for ( i = pi+pi/6; i < (2 * pi)-pi/6; i += 0.001) 
    { 
        x = r * cos(i)+tx; 
        y = r * sin(i)+ty; 
        glVertex2i(x, y); 
    } 
    glEnd();  
} 

void circle(int tx,int ty,int r)  
{  
    glBegin(GL_POINTS); 
    float x, y, i; 
    for ( i = 0; i < (2 * pi); i += 0.001) 
    { 
        x = r * cos(i)+tx; 
        y = r * sin(i)+ty; 
          
        glVertex2i(x, y); 
    } 
    glEnd();  
} 

void myInit (void) 
{ 
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	
	glColor3f(0.0, 1.0, 0.0); 
	
	glPointSize(1.0); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	
	gluOrtho2D(-X/2, X/2, -Y/2, Y/2); 
} 

void smiley(int x,int y,int R)
{
	glPushMatrix();
	glTranslatef(x,y,0);
	//glRotatef(angle,0,0,1);

	
	circle(0,0,1.2*R);
	circle(-R/2,R/2,R/3);
	circle(R/2,R/2,R/3);
	
	
	glPushMatrix();
	glTranslatef(-R/2,R/2,0);
	glRotatef(angle,0,0,1);
	circle(0,-R/6,R/6);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(R/2,R/2,0);
	glRotatef(angle,0,0,1);
	circle(0,-R/6,R/6);
	glPopMatrix();


	circle(0,-R/3,R/6);

	semi_circle(0,-R/6,2*R/3);

	glPopMatrix();
}

void display (void) 
{ 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if(R>0)
		smiley(cx,cy,R); 
	glutSwapBuffers();
} 


void processNormalKeys(unsigned char key, int x, int y) {
	if(key == 'r')
		reset();
	if (key == 'x')
		exit(0);
	if(key == 'a')
		angle-=5;
	if(key=='b')
		angle+=5;
	if(key=='e')
		cx+=10;
	if(key=='f')
		cx-=10;
	if(key=='c')
		R+=5;
	if(key=='d')
	{
		if(R>0)
			R-=5;
	}
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
	myInit(); 
	
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMainLoop(); 
} 

