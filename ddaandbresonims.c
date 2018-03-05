#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <windows.h>

int wind;

int abs (int n)
{
    return ( (n>0) ? n : ( n * (-1)));
}

void setup(){
    glClearColor(1,1,1,1);
    gluOrtho2D(-250,250,-250,250);
    //glPointSize(1);

}



void mykeyboardfunc(unsigned char key,int q,int w){
    switch(key){
        case 'e':{
            glColor3f(0,0,0);
            int x1=-200,y1=-200,x2=200,y2=200,X,Y;
            int dx=x2-x1;
            int dy=y2-y1;
            int step= abs(dx) > abs(dy) ? abs(dx) : abs(dy);
            float xinc=dx/(float)step;
            float yinc=dy/(float)step;
            X=x1;
            Y=y1;

            for(int i=0;i<=step;i++) {
                glBegin(GL_POINT);
                glVertex2f(X,Y);
                X=X+xinc;
                Y=Y+yinc;
                glEnd();
                glFlush();

            }

           // glFlush();
        }

            break;

        case 'b':{

            break;}

        case 'x':glutDestroyWindow(wind);
            // break;

    };

}

void mymousefunc(int button,int state,int x,int y){

    if(button==GLUT_LEFT_BUTTON)
    {
        if(state==GLUT_DOWN)
        {

        }
    }
}

void display(){


    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0,1,0);
    char name[]="NAMAN JAIN CSE GNG DDA AND BRESONIMS";
    glRasterPos2f(-150,200);
    for(int i=0;name[i]!='\0';i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,name[i]);
    }


}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(200, 100);
    glutInitWindowSize(500, 500);
    wind=glutCreateWindow("Hello World");
    setup();
    glutDisplayFunc(display);
    glutKeyboardFunc(mykeyboardfunc);
    glutMouseFunc(mymousefunc);
    glutMainLoop();
    return 0;

}

