#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdbool.h>

#define cp1x 100
#define cp1y 300
#define cp2x 200
#define cp2y 100
#define cp3x 400
#define cp3y 100
#define cp4x 500
#define cp4y 300
#define cp5x 400
#define cp5y 500
#define cp6x 200
#define cp6y 500
#define screenw 600
#define screenh 600

double cpxpoints[4];
double cpypoints[4];
int wind;
int dist(int xa,int ya,int xb,int yb)
{
    int d=sqrt((yb-ya)*(yb-ya)+(xb-xa)*(xb-xa));
    return d;
}
void display() {


    // glClearColor(1.0, 1.0, 1.0, 1.0);


    cpxpoints[0]=cp1x;
    cpxpoints[1]=cp2x;
    cpxpoints[2]=cp3x;
    cpxpoints[3]=cp4x;
    cpxpoints[4]=cp5x;
    cpxpoints[5]=cp6x;
    cpypoints[0]=cp1y;
    cpypoints[1]=cp2y;
    cpypoints[2]=cp3y;
    cpypoints[3]=cp4y;
    cpypoints[4]=cp5y;
    cpypoints[5]=cp6y;


    glColor3f(0, 1, 0);
    char name[] = "NAMAN JAIN CSE GNG BEIZER CURVE";
    glRasterPos2f(50,75);
    for (int i = 0; name[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, name[i]);
    }
    glBegin(GL_POINTS);
    double t=0;
    for(t=0;t<=1;t=t+0.0001){
        int px=pow(1-t,3)*cpxpoints[0]+3*t*pow(1-t,2)*cpxpoints[1]+3*t*t*(1-t)*cpxpoints[2]+pow(t,3)*cpxpoints[3];
        int py=pow(1-t,3)*cpypoints[0]+3*t*pow(1-t,2)*cpypoints[1]+3*t*t*(1-t)*cpypoints[2]+pow(t,3)*cpypoints[3];
        glVertex2f(px,py);
    }
    glEnd();

    glBegin(GL_POINTS);
    //double t=0;
    for(t=0;t<=1;t=t+0.0001){
        int px=pow(1-t,3)*cpxpoints[3]+3*t*pow(1-t,2)*cpxpoints[4]+3*t*t*(1-t)*cpxpoints[5]+pow(t,3)*cpxpoints[0];
        int py=pow(1-t,3)*cpypoints[3]+3*t*pow(1-t,2)*cpypoints[4]+3*t*t*(1-t)*cpypoints[5]+pow(t,3)*cpypoints[0];
        glVertex2f(px,py);
    }
    glEnd();


    cpxpoints[0]=cp1x;
    cpxpoints[1]=cp2x;
    cpxpoints[2]=cp3x;
    cpxpoints[3]=cp4x;
    cpypoints[0]=cp1y;
    cpypoints[1]=200;
    cpypoints[2]=400;
    cpypoints[3]=cp4y;


    glBegin(GL_POINTS);
    t=0;
    for(t=0;t<=1;t=t+0.0001){
        int px=pow(1-t,3)*cpxpoints[0]+3*t*pow(1-t,2)*cpxpoints[1]+3*t*t*(1-t)*cpxpoints[2]+pow(t,3)*cpxpoints[3];
        int py=pow(1-t,3)*cpypoints[0]+3*t*pow(1-t,2)*cpypoints[1]+3*t*t*(1-t)*cpypoints[2]+pow(t,3)*cpypoints[3];
        glVertex2f(px,py);
    }
    glEnd();



    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(cp1x,cp1y);
    glVertex2f(cp2x,cp2y);
   glEnd();

    glBegin(GL_LINES);
    glVertex2f(cp2x,cp2y);
    glVertex2f(cp3x,cp3y);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(cp3x,cp3y);
    glVertex2f(cp4x,cp4y);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(cp4x,cp4y);
    glVertex2f(cp5x,cp5y);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(cp5x,cp5y);
    glVertex2f(cp6x,cp6y);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(cp6x,cp6y);
    glVertex2f(cp1x,cp1y);
    glEnd();


    glFlush();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(200,20);
    glutInitWindowSize(screenw, screenh);
    wind = glutCreateWindow("Hello World");
    glutDisplayFunc(display);
    gluOrtho2D(0, screenw, screenh, 0);
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glutMainLoop();
    return 0;

}