#include<windows.h>
#ifdef APPLE
#include <GLUT/glut.h>   // Header file required for OpenGL
#else
#include <GL/glut.h>    // Header file required for OpenGL
#endif
#include <stdlib.h>    // Header file standard library
#include<iostream>     // Header file  input/output stream
#include<stdio.h>
#include<math.h>
using namespace std;   // Standard name space

double  xx1,xx2,yy1,yy2;

void DDA(int X1,int X2, int Y1,int Y2)
{
    glColor3d(0.9, 0.3 ,0.5);
    double dy,dx,step,x,y,k,Xin,Yin;

    dx = abs(X1-X2);
    dy = abs(Y1-Y2);

    if(dy < dx) step = dx;
    else        step = dy;

    Xin = (double)(X2-X1)/step;
    Yin =(double) (Y2-Y1)/step;

    x= X1;
    y= Y1;
    glPointSize(3.0);


    for (k=1 ;k<=step;k++){
        x= x + Xin;
        y= y + Yin;
        //sleep(20);
        glBegin(GL_POINTS);

        glVertex2i(x,y);
        glEnd();
        glFlush();
    }

    glFlush();
}

void DDAcircle(void)
{
    double   r=141;
    double   si;
    double n=(log2(r));


    si=1/pow(2,n);
    glPointSize(2.0);
  int k=1;
    double Start_x=0, Start_y=r, x1=Start_x, y1=Start_y,x2,y2;
    do{
        x2=x1+si*y1;
        y2=y1-si*x2;

        glColor3d(((double) rand() / (RAND_MAX)), ((double) rand() / (RAND_MAX)) ,((double) rand() / (RAND_MAX)));

        glBegin(GL_POINTS);

        glVertex2f(x2,y2);
        glEnd();
        glFlush();
        x1=x2;

        y1=y2 ;
        k++;        //to stop loop from going infinite

    }
    while( ((y1-Start_y)<si  || (Start_x-x1)> si )&&(k<r*20) );

    glFlush();
}
void display(){
    DDA(-200,200,-200,-200);
    DDA(200,200,-200,200);
    DDA(200,-200,200,200);
    DDA(-200,-200,200,-200);
    DDA(200,0,0,200);
    DDA(0,200,-200,0);
    DDA(-200,0,0,-200);
    DDA(-200,0,0,200);
    DDAcircle();

}
void init(void)
{
    glClearColor(0.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500,500,-500,500);

}

int main(int argc, char** argv)
{


    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 800);
    glutInitWindowPosition (0,0);
    glutCreateWindow ("DDA Line Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();                     //Enters the main event loop
  return 0;
}