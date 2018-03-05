#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#define round(a)((int)(a+0.5))
int wind,subwind1,subwind2,xc,yc,xe,ye;
int arr[2];
int arrel[2];
void mymousefunc(int button, int state, int x, int y) {


}

void mouse2(int button, int state, int x, int y) {
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        arr[0]=x;
        arr[1]=y;
       // glClear(GL_COLOR_BUFFER_BIT);
    }

}

void mouse3(int button, int state, int x, int y) {
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        arrel[0]=x;
        arrel[1]=y;
        glClear(GL_COLOR_BUFFER_BIT);
    }

}

void ellipsemid(int XCentre,int YCentre,int Rx,int Ry){

    int Rx2=Rx*Rx;
    int Ry2=Ry*Ry;
    int twoRx2=2*Rx2;
    int twoRy2=2*Ry2;
    int p;
    int x=0;
    int y=Ry;
    int px=0;
    int py=twoRx2*y;
    ellipsePlotpoints(XCentre,YCentre,x,y);
    //Region 1
    p=round(Ry2-(Rx2*Ry)+(0.25*Rx2));
    while(px<py){
        x++;
        px+=twoRy2;
        if(p<0)
            p+=Ry2+px;
        else
        {
            y--;
            py-=twoRx2;
            p+=Ry2+px-py;
        }
        ellipsePlotpoints(XCentre,YCentre,x,y);
    }

    //Region 2
    p=round(Ry2*(x+0.5)*(x+0.5)+Rx2*(y-1)*(y-1)-Rx2*Ry2);
    while(y>0){
        y--;
        py-=twoRx2;
        if(p>0)
            p+=Rx2-py;
        else
        {
            x++;
            px+=twoRy2;
            p+=Rx2-py+px;
        }
        ellipsePlotpoints(XCentre,YCentre,x,y);
    }

}

void ellipsePlotpoints(int a,int b,int c,int d){
    glBegin(GL_POINTS);
    glVertex2f(a+c,b+d);
    glVertex2f(a-c,b+d);
    glVertex2f(a+c,b-d);
    glVertex2f(a-c,b-d);
    glEnd();
  //  glFlush();

}

void midcircle(int XCentre,int YCentre,int Radius){

    int x=0;
    int y=Radius;
    int p=1-Radius;
    plotpoints(XCentre,YCentre,x,y);

    while(x<y)
    {
        x++;
        if(p<0)
            p=p+(2*x)+1;
        else{
            y--;
            p=p+2*(x-y)+1;
        }
        plotpoints(XCentre,YCentre,x,y);
    }
}

void plotpoints(int a,int b,int c,int d){

    glColor3f(1,1,1);
    glBegin(GL_POINTS);
    glVertex2f(a+c,b+d);
    glVertex2f(a-c,b+d);
    glVertex2f(a+c,b-d);
    glVertex2f(a-c,b-d);
    glVertex2f(a+d,b+c);
    glVertex2f(a-d,b+c);
    glVertex2f(a+d,b-c);
    glVertex2f(a-d,b-c);
    glEnd();
    //glFlush();
}

void display2() {

    glColor3f(1,1,1);
    midcircle(arr[0],arr[1],50);

    printf("%d %d\n",arr[0],arr[1]);
    glColor3f(1,1,1);
    char name[] = "SUB WINDOW 1";
    glRasterPos2f(0, 300);
    for (int i = 0; name[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, name[i]);
    }
    glFlush();
    glutPostRedisplay();

}

void display3() {


    glColor3f(1,1,1);
    ellipsemid(arrel[0],arrel[1],150,90);
    char name[] = "SUB WINDOW 2";
    glRasterPos2f(0,300);
    for (int i = 0; name[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, name[i]);
    }
    glFlush();
    glutPostRedisplay();
}


void display() {

    glColor3f(0, 1, 0);
    char name[] = "MAIN WINDOW NAMAN JAIN CSE GNG";
    glRasterPos2f(50,50);
    for (int i = 0; name[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, name[i]);
    }
    glFlush();
    glutPostRedisplay();

}


int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1000,700);
    wind = glutCreateWindow("MAIN WINDOW");

    glClearColor(1,1,1,1);
    gluOrtho2D(0,1000,700,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    glutDisplayFunc(display);
    glutMouseFunc(mymousefunc);

    subwind1=glutCreateSubWindow(wind,50,50,900,300);            //subwindow 1
    glClearColor(0,0,1,0.5);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0,900,300,0);
    glutDisplayFunc(display2);
    glutMouseFunc(mouse2);

    subwind2=glutCreateSubWindow(wind,50,350,900,300);           //subwindow 2
    glClearColor(0,1,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0,900,300,0);
    glutDisplayFunc(display3);
    glutMouseFunc(mouse3);

    glutMainLoop();
    return 0;

}

