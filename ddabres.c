#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>

int wind, xa, ya, xb, yb;

void setup(){
    glClearColor(1,1,1,1);
    gluOrtho2D(0,1000,1000,0);

}

void mykeyboardfunc(unsigned char key) {
    switch (key) {
        case 'd': {
            glColor3f(1,0,0);
            float X, Y;
            int dx = xb - xa;
            int dy = yb - ya;
            int step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
            float xinc = dx / (float) step;
            float yinc = dy / (float) step;
            X = xa;
            Y = ya;
            printf("%d %d", xa, ya);
            printf("\n%d %d\n", xb, yb);
            glBegin(GL_POINTS);
            for (int i = 0; i <= step; i++) {

                glVertex2f(X, Y);
                X = X + xinc;
                Y = Y + yinc;

            }
            glEnd();
            glFlush();

        }
            break;

        case 'b': {

                glColor3f(0,1,0);
            int XA=xa;
            int XB=xb;
            int YA=ya;
            int YB=yb;


            int dx,dy,p,xcheck,ycheck,steps;
            dx=abs(xb-xa);
            dy=abs(yb-ya);

            if(dx>dy)
            {
                steps=abs(dx);
            }
            else
            {
                steps=abs(dy);
            }

            if(steps==dx)
            {
                p = (2 * dy) - dx;
                if(xa>xb)
                {
                    int temp;
                    temp=XA;
                    XA=XB;
                    XB=temp;
                    temp=YA;
                    YA=YB;
                    YB=temp;

                }
                xcheck = XA;
                ycheck = YA;
                glBegin(GL_POINT);
                glVertex2f(xcheck, ycheck);
                glEnd();
                glBegin(GL_POINTS);
                int k=0;
                while (k<steps) {
                    if (p < 0) {
                        p = p + (2 * dy);
                    } else {
                        p = p + (2 * (dy - dx));
                        if(YA<YB)
                            ++ycheck;
                        else
                            --ycheck;
                    }
                    ++xcheck;
                    glVertex2f(xcheck, ycheck);
                    k++;
                }
                glEnd();
            }
            else
            {
                p=2*dx-dy;
                if(YA>YB)
                {
                    int temp;
                    temp=XA;
                    XA=XB;
                    XB=temp;
                    temp=YA;
                    YA=YB;
                    YB=temp;
                }
                ycheck=YA;
                xcheck=XA;
                glBegin(GL_POINT);
                glVertex2f(xcheck, ycheck);
                glEnd();
                glBegin(GL_POINTS);
                int k=0;
                while (k<steps) {
                    if (p < 0) {
                        p = p + (2 * dx);
                    } else {
                        p = p + (2 * (dx - dy));
                        if(XA<XB)
                            ++xcheck;
                        else
                            --xcheck;
                    }
                    ++ycheck;
                    glVertex2f(xcheck, ycheck);
                    k++;
                }
                glEnd();


            }

            glFlush();


            break;
        }

        case 'x':
            glutDestroyWindow(wind);

    }
};

void mymousefunc(int button, int state, int x, int y) {

    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            xa = x;
            ya = y;

        }
    }
    if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN) {
            xb = x;
            yb = y;
        }
    }
}

void display() {


   // glClearColor(1.0, 1.0, 1.0, 1.0);


    glColor3f(0, 1, 0);
    char name[] = "NAMAN JAIN CSE GNG DDA(RED) AND BRESENHAMS(GREEN)";
    glRasterPos2f(200, 800);
    for (int i = 0; name[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, name[i]);
    }
    glFlush();

}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1000, 1000);
    wind = glutCreateWindow("Hello World");

    setup();
//    gluOrtho2D(0, 1000, 1000, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    glutDisplayFunc(display);
    glutMouseFunc(mymousefunc);
    glutKeyboardFunc(mykeyboardfunc);
    glutMainLoop();
    return 0;

}




