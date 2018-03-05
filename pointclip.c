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
int xa, ya, xb, yb, p[50], q[50];
int j=0,k=0;


void mykeyboardfunc(unsigned char key) {
    switch (key) {
        case 'b': {int t;
            glColor3f(0,0,0);
            for(t=0;t<j;t++)
            {
                glBegin(GL_POINTS);
                glVertex2f(p[t],q[t]);
                glEnd();
            }


            glColor3f(0,1,0);
            for(t=0;t<j;t++)
            {
                if(p[t]<=xmax && p[t]>=xmin)
                {
                    if(q[t]<=ymax && q[t]>=ymin)
                    {
                        glBegin(GL_POINTS);
                        glVertex2f(p[t],q[t]);
                        glEnd();
                        glFlush();
                    }
                }
            }

        }


            break;
        case 'x':
            glutDestroyWindow(wind);

    }
    }


void mymousefunc(int button, int state, int x, int y) {

    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            p[j++] = x;
            q[k++] = y;

           // printf("x1=%f y1=%f\n", xa, ya);
        }
    }

}

void display() {


    // glClearColor(1.0, 1.0, 1.0, 1.0);


    glColor3f(0, 1, 0);
    char name[] = "NAMAN JAIN CSE GNG POINT CLIPPING";
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
    glPointSize(7);
    glutMouseFunc(mymousefunc);
    glutKeyboardFunc(mykeyboardfunc);
    glutMainLoop();
    return 0;

}