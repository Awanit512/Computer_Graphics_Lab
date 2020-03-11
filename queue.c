// C program to demonstrate 
// drawing a circle using 
// OpenGL 
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#include<string.h>

int queue[12]={-1};

int cur=-1; //dsdd

int front=-1;
int rear=-1;

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
	if((((rear-1+24)%12)==front && rear!=11 )||(10==front && rear==11))
	{
		so_flag=1;
		return;
	}
	else if(front==-1 && rear == -1)
	{
		front=11;
		rear=12;
	}
	int a=rand()%100;
	
	if(rear!=11)
		rear=(rear-1+24)%12;
	else
		rear=10;
	queue[rear]=a;
	
	count=1000;
	sprintf(statement,"Inserting element : %d",a);
	
}

void pop()
{
	so_flag=0;
	if(rear==front && rear!=-1)
	{
		se_flag=1;
		count=1000;
		sprintf(statement,"Deleting element : %d",queue[front]);
		se_flag=-1;
		rear=-1;
		front=-1;
		return;
	}
	else if(rear==-1)
	{
		return;
	}
	front=(front-1+24)%12;
	count=1000;
	sprintf(statement,"Deleting element : %d",queue[(front+1)%12]);
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
 	glVertex2i(501-pos*100,300);
 	glVertex2i(600-pos*100,300);
 	glVertex2i(600-pos*100,-100);
 	glVertex2i(501-pos*100,-100);
 	glEnd();
 	char temp[5];
 	sprintf(temp,"%d",val);
 	output(545-pos*100,100,temp);
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
 	glVertex2i(600,310);
 	glVertex2i(600,301);
 	glVertex2i(-600,301);
 	glVertex2i(-600,310);
 	glEnd();
 	
 	glBegin(GL_POLYGON);
 	glVertex2i(600,-101);
 	glVertex2i(600,-110);
 	glVertex2i(-600,-110);
 	glVertex2i(-600,-101);
 	glEnd();
 	
 	//printNode(0,32);
 	//printNode(1,234);
 	
 	int i=-1,j;
 	if(front!=-1)
 	{
 		for(j=front;j!=rear;j=(j-1)%12)
 		{
 			i++;
 			printNode(i,queue[j]);
 		}
 		printNode(i+1,queue[rear]);
 	}
 	if(so_flag)
		output(0,-300,"Queue is Full");
	if(se_flag)
		output(0,-300,"Queue is Empty");
		
	if(count)
	{
		output(350,-300,statement);
		count--;
	}

	glutSwapBuffers(); 
}

void processNormalKeys(unsigned char key, int x, int y) {
	//printf("%d ",key);
	printf("%d %d\n",front,(rear-1+144)%12);
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

