#include <GL/gl.h>
#include <GL/glu.h>
#include <time.h>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
float WINDOW_SIZE = 1000;
int bot=450,top=450;
int ballx=500,bally=750;
int dir=0;
bool res=1;

void display(void)
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

    //Sleep(1000);
    glPointSize(15);        //ball
    glColor3f(0,0,1);
    glBegin(GL_POINTS);
    glVertex2f(ballx,bally);
    glEnd();

    glFlush();
    //glutPostRedisplay();

}
void iscollide(int x,int y,int pos)
{
    if(x>=pos&&x<=pos+100)
    {
        //int x;
        if(dir)
        {
            dir = 0;
            ballmove(dir);
        }
            else
        {
            dir=1;
            ballmove(dir);
        }
       // ballmove(x);
        //return 1;
    }
    //return 0;


}

int pointyehai(int tx,int bx)
{
    float X, Y;
    int dx = bx - tx;
    int dy;
    if(dir)
        dy = 500;
    else
        dy=-500;

    int step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xinc = dx / (float) step;
    float yinc = dy / (float) step;
    X = tx;

    if(dir)
    Y = 250;
    else
        Y=750;

    //  printf("%d %d", xa, ya);
//    printf("\n%d %d\n", xb, yb);
    //glBegin(GL_POINTS);
    for (int i = 0; i <= step; i++) {

      //  glVertex2f(X, Y);
        ballx=int(X);
        bally=int(Y);
        cout<<"ballx="<<ballx<<" bally="<<bally<<endl;
       Sleep(5);
        //display(void);
        //glutPostRedisplay();
        glPointSize(15);        //ball
        glColor3f(0,0,1);
        glBegin(GL_POINTS);
        glVertex2f(ballx,bally);
        glEnd();

        glFlush();
        X = X + xinc;
        Y = Y + yinc;

    }
    //glEnd();

    if(dir)
    {
         iscollide(ballx, bally, bot);
    }
        else
        iscollide(ballx,bally,top);

    //glEnd();
    //glFlush();
}



int ballmove(int dir)
{
    int topx=rand()%(top+90)+top;
    int botx=rand()%(bot+90)+bot;

    if(dir)                 //upar se niche
    {
        int yoyo;
        yoyo=rand()%749+251;
        if(yoyo>749)
            yoyo=749;
        cout<<"upar ka x="<<topx<<" "<<" niche ka x="<<yoyo<<endl;
        pointyehai(ballx,yoyo);
    }
    else                   //niche se upar
    {
        int yeye;
        yeye=rand()%749+251;
        if(yeye>749)
            yeye=749;
        cout<<"upar ka xu="<<yeye<<" "<<" niche ka x="<<botx<<endl;
        pointyehai(ballx, yeye);
    }

}


void keyboard(unsigned char key, int i, int i1) {
    switch (key) {
        case 'a':
            if(top>=260)
            {
                top=top-10;

            }

            break;

        case 'd':if(top<=640) {

                top = top + 10;

            }

            break;

        case 'j':if(bot>=260)
            {
                bot=bot-10;
            }

            break;

        case 'l':if(bot<=640)
            {
                bot=bot+10;
            }

            break;

        case 's':

                ballmove(dir);

            if(!res)
            {
                cout<<"Game Over";
            }

            break;

    }
   glutPostRedisplay();
}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(WINDOW_SIZE, WINDOW_SIZE);
    glutCreateWindow ("PONG-PING");

    //glClearColor(1.0, 1.0, 1.0, 0.0);         // background
    glMatrixMode(GL_PROJECTION);              // setup viewing projection
    glLoadIdentity();
    gluOrtho2D(0,1000,1000,0);
    //srand(time(NULL));

    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);


    glutMainLoop();
    return 0;
}