#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

void setup(){
    glClearColor(0.0,0.0,0.5,1);
  gluOrtho2D(-1000,1000,-1000,1000);
    //glPointSize(10);
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
    glEnd();
}

void drawHollowCircle(GLfloat x, GLfloat y, GLfloat radius){
    int i;
    int lineAmount = 1000; //# of triangles used to draw circle
    float PI=3.14159;
    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_LINE_LOOP);
    for(i = 0; i <= lineAmount;i++) {
        glVertex2f(
                x + (radius * cos(i *  twicePi / lineAmount)),
                y + (radius* sin(i * twicePi / lineAmount))
        );
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);//grass big
    glColor3f(0,0.5,0);
    glBegin(GL_POLYGON);
    glVertex2f(-1000,-250);
    glColor3f(0,0.2,0);
    glVertex2f(-1000,-1000);
    glVertex2f(1000,-1000);
    glColor3f(0,0.5,0);
    glVertex2f(1000,-250);
    glEnd();

    int t;
    glColor3f(1,1,1);//stars
    glBegin(GL_POINTS);
    for(int i=-1000;i<=1000;i=i+100)
    {
        for (int j = 1000;j>-250;j = j-100)
        {
          t=  rand()%2;
            if(t==1)
            glVertex2f(i, j);
        }
    }
    glEnd();

    glColor3f(1,1,1);
    drawFilledCircle(-150,300,350);//moon

    glColor3f(1,0.5,0);//walls
    glBegin(GL_POLYGON);
    glVertex2f(-400,-250);
    glVertex2f(-400,250);
    glVertex2f(400,250);
    glVertex2f(400,-250);
    glEnd();

    glColor3f(1,0.95,0.4);//door
    glBegin(GL_POLYGON);
    glVertex2f(-150,-250);
    glVertex2f(-150,0);
    glVertex2f(150,0);
    glVertex2f(150,-250);
    glEnd();

    glColor3f(1,0.8,0);//roof
    glBegin(GL_TRIANGLES);
    glVertex2f(0,500);
    glVertex2f(475,200);
    glVertex2f(-475,200);
    glEnd();

    glColor3f(1,0.95,0.4);//window
    drawFilledCircle(0,350,90);

    glColor3f(0,0,0);//roof railing
    glBegin(GL_POLYGON);
    glVertex2f(-5,440);
    glVertex2f(5,440);
    glVertex2f(5,260);
    glVertex2f(-5,260);
    glEnd();
    glColor3f(0,0,0);//roof railing
    glBegin(GL_POLYGON);
    glVertex2f(-90,355);
    glVertex2f(90,355);
    glVertex2f(90,345);
    glVertex2f(-90,345);
    glEnd();

    drawHollowCircle(0,350,90);


    glColor3f(0,0,0);//door line
    glBegin(GL_POLYGON);
    glVertex2f(-5,0);
    glVertex2f(5,0);
    glVertex2f(5,-250);
    glVertex2f(-5,-250);
    glEnd();

    glColor3f(0,0,0);//door outline
    glBegin(GL_POLYGON);
    glVertex2f(-160,-250);
    glVertex2f(-160,10);
    glVertex2f(-150,10);
    glVertex2f(-150,-250);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(160,-250);
    glVertex2f(160,10);
    glVertex2f(150,10);
    glVertex2f(150,-250);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-150,10);
    glVertex2f(150,10);
    glVertex2f(150,0);
    glVertex2f(-150,0);
    glEnd();

    for(int x=-1000;x<1000;x=x+60)//grass
    {
        glBegin(GL_TRIANGLES);
        glColor3f(0,0.5,0);
        glVertex2f(x,-250);
        glVertex2f(x+60,-250);
        glColor3f(0,0.2,0);
        glVertex2f(x+30,-220);
        glEnd();
    }


    glColor3f(1,1,1);
    char name[]="NAMAN JAIN CSE GNG";
    glRasterPos2f(200,900);
    for(int i=0;name[i]!='\0';i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,name[i]);
    }

    glFlush();
}


int main(int argc,char *argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1000,800);
    glutCreateWindow("House");
    setup();
    glutDisplayFunc(display);

    glutMainLoop();


    return 0;
}