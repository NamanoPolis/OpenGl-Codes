#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdbool.h>

#define xmax 450
#define xmin 150
#define ymax 450
#define ymin 150
#define screenw 600
#define screenh 600

int wind;
int xa, ya, xb, yb, p[4], q[4];
float r[4];
int deltax, deltay;

struct codes{
    int top;
    int bottom;
    int right;
    int left;
};
struct codes code={0,0,0,0};


struct codes compute(int x,int y){
    if(x<xmin)
        code.left=1;
    else if(x>xmax)
        code.right=1;
    if(y<ymin)
        code.top=1;
    else if(y>ymax)
        code.bottom=1;
    return code;

}

void mykeyboardfunc(unsigned char key) {
    switch (key) {
        case 'b': {
//            xa=460;
//            ya=140;
//            xb=140;
//            yb=460;

            glLineWidth(1);
            glColor3f(0, 0, 0);
            glBegin(GL_LINES);
            glVertex2f(xa, ya);
            glVertex2f(xb, yb);
            glEnd();
            glFlush();

            printf("\nGeneral %d %d %d %d",code.top,code.bottom,code.right,code.left);
            struct codes code1=compute(xa,ya);
            code.top=0;
            code.left=0;
            code.right=0;
            code.bottom=0;
            struct codes code2=compute(xb,yb);
            code.top=0;
            code.left=0;
            code.right=0;
            code.bottom=0;

            printf("\nFirst point %d %d %d %d",code1.top,code1.bottom,code1.right,code1.left);
            printf("\nSecond point%d %d %d %d",code2.top,code2.bottom,code2.right,code2.left);

            bool accept = false;

            while (true)
            {
                if (code1.top==0 && code1.right==0 && code1.left==0 && code1.bottom==0 && code2.top==0 && code2.right==0 && code2.left==0 && code2.bottom==0)
                {
                    accept = true;
                    break;
                }
                else if ((code1.top==code2.top) && (code1.bottom==code2.bottom) &&(code1.right==code2.right) &&(code1.left==code2.left))
                {
                    break;
                }
                else
                {
                    struct codes code_out;
                    double x, y;


                    if (code1.top==0 && code1.left==0 && code1.right==0 && code1.bottom==0 )
                        code_out = code2;
                    else
                        code_out = code1;

                    if (code_out.bottom==1)
                    {

                        x = xa + (xb - xa) * (ymax - ya) / (yb - ya);
                        y = ymax;
                    }
                    else if (code_out.top==1)
                    {
                        x = xa + (xb - xa) * (ymin - ya) / (yb - ya);
                        y = ymin;
                    }
                    else if (code_out.right==1)
                    {

                        y = ya + (yb - ya) * (xmax - xa) / (xb - xa);
                        x = xmax;
                    }
                    else if (code_out.left==1)
                    {

                        y = ya + (yb - ya) * (xmin - xa) / (xb - xa);
                        x = xmin;
                    }

                    if (code_out.top==code1.top && code_out.right==code1.right && code_out.left==code1.left && code_out.bottom==code1.bottom )
                    {
                        xa = x;
                        ya = y;
                        code1 = compute(xa, ya);
                    }
                    else
                    {
                        xb = x;
                        yb = y;
                        code2 = compute(xb, yb);
                    }
                }
            }
            if (accept)
            {
                glLineWidth(5);
                glColor3f(0,1,0);
                glBegin(GL_LINES);
                glVertex2f(xa,ya);
                glVertex2f(xb,yb);
                glEnd();
                glFlush();
            }

        }
            glFlush();




            break;
        case 'x':
            glutDestroyWindow(wind);


    }
};

void mymousefunc(int button, int state, int x, int y) {

    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            xa = x;
            ya = y;
            printf("\nx1=%d y1=%d\n", xa, ya);
        }
    }
    if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN) {
            xb = x;
            yb = y;
            printf("\nx2=%d y2=%d\n", xb, yb);
        }
    }
}

void display() {


    // glClearColor(1.0, 1.0, 1.0, 1.0);


    glColor3f(0, 1, 0);
    char name[] = "NAMAN JAIN CSE GNG COHEN-SUTHERLAND ALGORITHM";
    glRasterPos2f(50,75);
    for (int i = 0; name[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, name[i]);
    }

    glColor3f(1, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin, ymin);
    glVertex2f(xmax, ymin);
    glVertex2f(xmax, ymax);
    glVertex2f(xmin, ymax);
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
    glutMouseFunc(mymousefunc);
    glutKeyboardFunc(mykeyboardfunc);
    glutMainLoop();
    return 0;

}
