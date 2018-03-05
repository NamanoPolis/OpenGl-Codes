#include <GL/gl.h>
#include <GL/glu.h>
#include <time.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

float WINDOW_SIZE = 1000;
int bot=450,top=450;
int wind;
int ballx=500,bally=750;
int xdelta=1,ydelta=-1;
int delta;
//bool res=1;

void collide(int x,int base)
{
    if(!(x>=base && x<=base+100))
    {
        glutDestroyWindow(wind);
    }
}

void display(void)
{


    if (ballx<250)
    {
        xdelta=-1*xdelta;
    }
    if (ballx>750)
    {
        xdelta=-1*xdelta;
    }

    if (bally<250)
    {
        ydelta=-1*ydelta;
        collide(ballx,top);
        delta=rand()%5;
        xdelta=delta;
        if(xdelta<0)
            xdelta=-delta;
        else
            xdelta=delta;
    }
    if(bally>750)
    {
        ydelta=-1*ydelta;
        collide(ballx,bot);
        delta=rand()%5;
        if(xdelta<0) {
            xdelta = -delta;
        }
            else {
            xdelta = delta;
        }
    }


    ballx=ballx+xdelta;
    bally=bally+ydelta;

    Sleep(5);
    draw();
    glutPostRedisplay();
}

void draw()
{
    glClearColor(0.9,0.9,0.9,1);
    glClear( GL_COLOR_BUFFER_BIT);

    glLineWidth(3);
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(250,250);    //border
    glVertex2f(750,250);
    glVertex2f(750,750);
    glVertex2f(250,750);
    glEnd();

    glLineWidth(7);         //net
    glColor3f(0,1,0);
    glBegin(GL_LINES);
    glVertex2f(230,500);
    glVertex2f(770,500);
    glEnd();

    glLineWidth(6);
    glColor3f(1,0,0);   //top
    glBegin(GL_LINES);
    glVertex2f(top,250);
    glVertex2f(top+100,250);
    glEnd();

    glLineWidth(6);
    glColor3f(1,0,0);   //bottom
    glBegin(GL_LINES);
    glVertex2f(bot,750);
    glVertex2f(bot+100,750);
    glEnd();

   // ballmove(dir);
    //Sleep(1);
    glPointSize(15);        //ball
    glColor3f(0,0,1);
    glBegin(GL_POINTS);
    glVertex2f(ballx,bally);
    glEnd();

    glFlush();

}

void keyboard(unsigned char key, int i, int i1) {
        switch (key) {
                case 'a':
                        if(top>=260)
                        {
                                top=top-10;
                            printf("%d\n",top);

                        }
                glutPostRedisplay();

                break;

                case 'd':if(top<=640) {

                                top = top + 10;

                        }
                glutPostRedisplay();

                break;

                case 'j':if(bot>=260)
                        {
                                bot=bot-10;
                        }
                glutPostRedisplay();
                break;

                case 'l':if(bot<=640)
                        {
                                bot=bot+10;
                        }
                glutPostRedisplay();
                break;

        }


}


int main(int argc, char **argv)
{
        glutInit(&argc, argv);
        glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowPosition(10,10);
        glutInitWindowSize(WINDOW_SIZE, WINDOW_SIZE);
        wind=glutCreateWindow ("PONG-PING");


        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0,1000,1000,0);
        srand(time(NULL));

        glutKeyboardFunc(keyboard);
        glutDisplayFunc(display);

        glutMainLoop();
        return 0;
}