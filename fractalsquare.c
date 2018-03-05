
#include <GL/glut.h>
#include <math.h>

float WINDOW_SIZE = 1000;
int n=1;
int s=5;
void squares(float topleftx,float toplefty,float toprightx,float toprighty,float bottomrightx,float bottomrighty,float bottomleftx,float bottomlefty, int i)
{

    float d=sqrt(((toprightx-topleftx)*(toprightx-topleftx))+((toprighty-toplefty)*(toprighty-toplefty)));
    float diff=(d/4);

    Sleep(5);

    glLineWidth(diff);
    glColor3f(0,0,0);
//    glColor3f(1,0,0);
//    glBegin(GL_POLYGON);
    if(i!=1){
    glBegin(GL_LINE_LOOP);
    glVertex2f(topleftx-diff,toplefty+diff);
    glVertex2f(topleftx+diff,toplefty+diff);
    glVertex2f(topleftx+diff,toplefty-diff);
    glVertex2f(topleftx-diff,toplefty-diff);
    glEnd();}
    Sleep(5);

//    glColor3f(0,1,0);
//    glBegin(GL_POLYGON);
    if(i!=2){
   glBegin(GL_LINE_LOOP);
    glVertex2f(toprightx-diff,toprighty+diff);
    glVertex2f(toprightx+diff,toprighty+diff);
    glVertex2f(toprightx+diff,toprighty-diff);
    glVertex2f(toprightx-diff,toprighty-diff);
    glEnd();}
    Sleep(5);

//    glColor3f(0,0,1);
//    glBegin(GL_POLYGON);
        if(i!=3){
    glBegin(GL_LINE_LOOP);
    glVertex2f(bottomrightx-diff,bottomrighty+diff);
    glVertex2f(bottomrightx+diff,bottomrighty+diff);
    glVertex2f(bottomrightx+diff,bottomrighty-diff);
    glVertex2f(bottomrightx-diff,bottomrighty-diff);
    glEnd();}
    Sleep(5);

//    glColor3f(1,1,0);
//    glBegin(GL_POLYGON);
            if(i!=4){
    glBegin(GL_LINE_LOOP);
    glVertex2f(bottomleftx-diff,bottomlefty+diff);
    glVertex2f(bottomleftx+diff,bottomlefty+diff);
    glVertex2f(bottomleftx+diff,bottomrighty-diff);
    glVertex2f(bottomleftx-diff,bottomrighty-diff);
    glEnd();}

    n++;
    //s=s-0.5;

    glFlush();

    if(n<10000 && diff>(20.0/WINDOW_SIZE)*7)
    {

        squares(topleftx-diff,toplefty+diff,topleftx+diff,toplefty+diff,topleftx+diff,toplefty-diff,topleftx-diff,toplefty-diff,3);
        squares(toprightx-diff,toprighty+diff,toprightx+diff,toprighty+diff,toprightx+diff,toprighty-diff,toprightx-diff,toprighty-diff,4);
        squares(bottomrightx-diff,bottomrighty+diff,bottomrightx+diff,bottomrighty+diff,bottomrightx+diff,bottomrighty-diff,bottomrightx-diff,bottomrighty-diff,1);
        squares(bottomleftx-diff,bottomlefty+diff,bottomleftx+diff,bottomlefty+diff,bottomleftx+diff,bottomlefty-diff,bottomleftx-diff,bottomlefty-diff,2);

    }



}




void display(void)
{
    glClear( GL_COLOR_BUFFER_BIT);

    glColor3f(0, 1, 0);
    char name[] = "NAMAN JAIN CSE GNG SQUARE FRACTAL";
    glRasterPos2f(-9,9);
    for (int i = 0; name[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, name[i]);
    }

    int x=4;
    glLineWidth(4);
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-x,x);
    glVertex2f(x,x);
    glVertex2f(x,-x);
    glVertex2f(-x,-x);
    glEnd();

    squares(-x,x,x,x,x,-x,-x,-x,0);

    glFlush();
}




int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(WINDOW_SIZE, WINDOW_SIZE);
    glutCreateWindow ("HEllO");

    glClearColor(1.0, 1.0, 1.0, 0.0);         // background
    glMatrixMode(GL_PROJECTION);              // setup viewing projection
    glLoadIdentity();
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}