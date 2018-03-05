#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <windows.h>


int circledrawn=0,ellipsedrawn=0,redcol=0,greencol=0,win;

void setup(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-500,500,-500,500);
    glLineWidth(10);
}

void drawellipse(int h,int k,int a,int b){
    double I,J,A;
    int i,j;
    float theta;
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2s(h,k);
    for( theta=0 ; theta<=90 ; theta++)
    {
        A=theta*11/630;
        J=b*sin(A);
        I=a*cos(A);
        i=(int)(I);
        j=(int)(J);
        glVertex2s(h+i,k+j);
        glVertex2s(h-i,k+j);
        glVertex2s(h-i,k-j);
        glVertex2s(h+i,k-j);
    }
    //glColor3f (1.0, 1.0, 1.0);
    for(int i=-100 ; i<=100 ; i++)
    {
        glVertex2s(i,0);
        glVertex2s(0,i);
    }
    for(int i=-2; i<=2 ; i++)
    {
        glVertex2s(95+i,4+i);
        glVertex2s(95-i,4+i);
    }
    for(int i=0; i<=2 ; i++)
    {
        glVertex2s(4+i,95+i);
        glVertex2s(4-i,95+i);
        glVertex2s(4,95-i);
    }
    ellipsedrawn=1;
    //circledrawn=0;
    glEnd();

    glFlush();
}

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius){
    int i;
    int triangleAmount = 40; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    float PI=3.14519;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    circledrawn=1;
    //ellipsedrawn=0;
    glEnd();
    glFlush();
}

void mykeyboardfunc(unsigned char key){
    switch(key){
        case 'c':{glColor3f(1,0,0);
            redcol=1;
            greencol=0;
            drawFilledCircle(-300,200,100);
            break;}

        case 'e':{glColor3f(1,0,0);
            redcol=1;
            greencol=0;
            drawellipse(100,50,-300,200);
            break;}

        case 'x':glutDestroyWindow(win);
           // break;

    };

}

void mymousefunc(int button,int state,int x,int y){

    if(button==GLUT_LEFT_BUTTON)
    {
        if(state==GLUT_DOWN)
        {
            if (redcol == 1 && circledrawn == 1 &&(x>=50&&x<=150)&& (y>=100&&y<=200)) {
                glColor3f(0, 1, 0);
                greencol = 1;
                redcol = 0;
                drawFilledCircle(-300, 200, 100);
            } else if (greencol == 1 && circledrawn == 1&&(x>=50&&x<=150)&& (y>=100&&y<=200)) {
                glColor3f(1, 0, 0);
                redcol = 1;
                greencol = 0;
                drawFilledCircle(-300, 200, 100);
            } else if (redcol == 1 && ellipsedrawn == 1&&(x>=150&&x<=450)&& (y>=175&&y<=325)) {
                glColor3f(0, 1, 0);
                greencol = 1;
                redcol = 0;
                drawellipse(100, 50, -300, 200);
            }  else if (greencol == 1 && ellipsedrawn == 1&&(x>=150&&x<=450)&& (y>=175&&y<=325)) {
                glColor3f(1, 0, 0);
                redcol = 1;
                greencol = 0;
                drawellipse(100, 50, -300, 200);
            }
        }
    }
}

void display(){

    //glColor3f(1.0, 0.0, 0.0);
    glColor3f(1,1,1);
    char name[]="NAMAN JAIN CSE GNG CIRCLE OR ELLIPSE";
    glRasterPos2f(-250,400);
    for(int i=0;name[i]!='\0';i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,name[i]);
    }
    glFlush();
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(200, 100);
    glutInitWindowSize(500, 500);
    win=glutCreateWindow("Hello World");
    setup();
    glutDisplayFunc(display);
    glutKeyboardFunc(mykeyboardfunc);
    glutMouseFunc(mymousefunc);

    glutMainLoop();

    return 0;

}

