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
float xa, ya, xb, yb, p[4], q[4];
float r[4];
int deltax, deltay;


void mykeyboardfunc(unsigned char key) {
    switch (key) {
        case 'b': {

            glLineWidth(1);
            glColor3f(0, 0, 0);
            glBegin(GL_LINES);
            glVertex2f(xa, ya);
            glVertex2f(xb, yb);
            glEnd();
            glFlush();
/*
            xa=200;
            ya=200;
            xb=900;
            yb=900;*/


            float t1 = 0, t2 = 1;
            deltax = xb - xa;
            deltay = yb - ya;
            p[0] = -1 * deltax;
            q[0] = xa - xmin;
            p[1] = deltax;
            q[1] = xmax - xa;
            p[2] = -1 * deltay;
            q[2] = ya - ymin;
            p[3] = deltay;
            q[3] = ymax - ya;
            r[0] = q[0] / p[0];
            r[1] = q[1] / p[1];
            r[2] = q[2] / p[2];
            r[3] = q[3] / p[3];

            printf("%f %f %f %f %f %f %f %f %f %f %f %f ",p[0],q[0],p[1],q[1],p[2],q[2],p[3],q[3],r[0],r[1],r[2],r[3]);

            int i;
            for (i = 0; i < 4; i++) {
                if (p[i] != 0) {
                    if (p[i] < 0)//outside to inside
                    {
                        if (r[i] >= t1)
                            t1 = r[i];

                    } else//inside to outside
                    {
                        if (r[i] <= t2)
                            t2 = r[i];
                    }

                }

            }
            printf("t1=%f t2=%f",t1,t2);

            glLineWidth(5);
            float j,k,finalx1, finaly1, finalx2, finaly2;
            if (t1 < t2) {
                glColor3f(1, 0, 1);
                finalx1 = xa + (deltax * t1);
                finaly1 = ya + (deltay * t1);
                finalx2 = xa + (deltax * t2);
                finaly2 = ya + (deltay * t2);
                glBegin(GL_LINE_LOOP);
                glVertex2f(finalx1,finaly1);
                glVertex2f(finalx2,finaly2);
                glEnd();
                glFlush();
            }


        }
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
            printf("x1=%f y1=%f\n", xa, ya);
        }
    }
    if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN) {
            xb = x;
            yb = y;
            printf("x2=%f y2=%f\n", xb, yb);
        }
    }
}

void display() {


    // glClearColor(1.0, 1.0, 1.0, 1.0);


    glColor3f(0, 1, 0);
    char name[] = "NAMAN JAIN CSE GNG LIANG-BARSKY ALGORITHM";
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