// C program to demonstrate 
// drawing a circle using 
// OpenGL 
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#include<string.h>

int stack[16]={-1};

int cur=-1;

int so_flag=0;
int se_flag=1;

int count=0;
char statement[50]="Inserting an element!";

void output(int x, int y, char *string)
{
  glColor3f(0.0,1.0,1.0 );
  glRasterPos2f(x, y);
  int len, i;
  len = (int)strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
  }
}

void push()
{
	se_flag=0;
	if(cur==15)
	{
		so_flag=1;
		return;
	}
	int a=rand()%100;
	cur++;
	stack[cur]=a;
	count=1000;
	sprintf(statement,"Inserting element : %d",a);
	
}

void pop()
{
	so_flag=0;
	if(cur==-1)
	{
		//printf("Stack is Empty\n");
		se_flag=1;
		return;
	}
	cur--;
	if(cur==-1)
		se_flag=1;
	count=1000;
	sprintf(statement,"Deleting element : %d",stack[cur+1]);
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
	gluOrtho2D(-780, 780, -420, 420); 
} 

void printNode(int pos,int val)
{
 	glColor3f(1.0, 0.0, 0.0);
 	glBegin(GL_POLYGON);
 	glVertex2i(249,-351+50*pos);
 	glVertex2i(249,-400+50*pos);
 	glVertex2i(-249,-400+50*pos);
 	glVertex2i(-249,-351+50*pos);
 	glEnd();
 	char temp[5];
 	sprintf(temp,"%d",val);
 	output(-10,-370+50*pos,temp);
}

void drawArrow()
{
	int x=265,y=-375;
	float d=cur;
	if(cur==-1)
	{
		d=-0.5;
	}
	y=y+50*d;
	glColor3f(0.0, 1.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	
	glBegin(GL_POLYGON);
	glVertex2i(x,y);
	glVertex2i(x+40,y+10);
	glVertex2i(x+40,y+3);
	glVertex2i(x+100,y+3);
	glVertex2i(x+100,y-3);
	glVertex2i(x+40,y-3);
	glVertex2i(x+40,y-10);
	glEnd();
}


void display (void) 
{ 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
 	glColor3f(0.0, 1.0, 0.0);
 	glBegin(GL_POLYGON);
 	glVertex2i(250,400);
 	glVertex2i(260,400);
 	glVertex2i(260,-410);
 	glVertex2i(-260,-410);
 	glVertex2i(-260,400);
 	glVertex2i(-250,400);
 	glVertex2i(-250,-401);
 	glVertex2i(250,-401);
 	glEnd();
 	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
 	
	int i;
	for(i=0;i<=cur;i++)
	{
		printNode(i,stack[i]);
	}
	drawArrow();
	if(so_flag)
		output(300,300,"Stack Overflow");
	if(se_flag)
		output(300,300,"Stack Empty");
		
	if(count)
	{
		output(350,-300,statement);
		count--;
	}
	glutSwapBuffers(); 
}

void processNormalKeys(unsigned char key, int x, int y) {
	//printf("%d ",key);
	if (key == 27)
		exit(0);
	else if(key==73||key==105)
		push();
	else if(key==68||key==100)
		pop();
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
	glutIdleFunc(display);
	
	glutKeyboardFunc(processNormalKeys);
	glutMainLoop(); 
} 

