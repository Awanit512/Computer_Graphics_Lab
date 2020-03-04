#include <GL/glut.h>

// GLfloat xRotated, yRotated, zRotated;
GLdouble size=1;
int flag = 0;




void display(void)
{

    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0,0.0,-4.5);
    glColor3f(0.8, 0.2, 0.1); 
    // glRotatef(xRotated,1.0,0.0,0.0);
    // glRotatef(yRotated,0.0,1.0,0.0);
    // glRotatef(zRotated,0.0,0.0,1.0);
    glScalef(1.0,1.0,1.0);
    if(flag == 1)
        glutSolidTeapot(size);
    if(flag == 2)
        glutWireTeapot(size);
    glFlush();        
}

void menu(int num){
  if(num == 1)
    flag = 1;
 else if(num == 2)
    flag = 2;
  glutPostRedisplay();
} 


void reshapeFunc(int x, int y)
{
    if (y == 0 || x == 0) return;  //Nothing is visible then, so return
    //Set a new projection matrix
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
 
    glViewport(0,0,x,y);  //Use the whole window for rendering
}

// void idleFunc(void)
// {
 
//      yRotated += 0.01;
     
//     display();
// }


int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(400,350);
    glutCreateWindow("Teapot");
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    // xRotated = yRotated = zRotated = 30.0;
    //  xRotated=33;
    //  yRotated=40;
    glClearColor(0.0,0.0,0.0,0.0);
    //Assign  the function used in events
    glutDisplayFunc(display);
   glutReshapeFunc(reshapeFunc);

   glutCreateMenu(menu);
    glutAddMenuEntry("Cross", 1);
    glutAddMenuEntry("straight", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);


    // glutIdleFunc(idleFunc);
    //Let start glut loop
    glutMainLoop();
    return 0;
}
