#include <GL/gl.h>
#include <GL/glu.h>
#include <stdbool.h>
#include <GL/glut.h>
#include <stdio.h>
#define DELTA_TIME 300
#define round(a)((int)(a+0.5))
int wind,subwind1,subwind2,xc,yc,xe,ye;
float s1xa, s1ya, s1xb, s1yb, p[4], q[4];
float r[4];
int deltax, deltay;
float finalx1=0, finaly1=0, finalx2=0, finaly2=0;
int s1xmin=0,s1ymin=0,s1xmax=0,s1ymax=0;
int xa, ya, xb, yb;
int xmin=0;
int ymin=0;
int xmax=0;
int ymax=0;
int s2finalx1=0;
int s2finaly1=0;
int s2finalx2=0;
int s2finaly2=0;
bool stopl=false;
bool stopc=false;


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

void liang(){

    s1xa = 0;
    s1ya = 0;
    s1xb = 900;
    s1yb = 300;

    // printf("\n%d %d %d %d", s1xmin, s1ymin, s1xmax, s1ymax);


    float t1 = 0, t2 = 1;
    deltax = s1xb - s1xa;
    deltay = s1yb - s1ya;
    p[0] = -1 * deltax;
    q[0] = s1xa - s1xmin;
    p[1] = deltax;
    q[1] = s1xmax - s1xa;
    p[2] = -1 * deltay;
    q[2] = s1ya - s1ymin;
    p[3] = deltay;
    q[3] = s1ymax - s1ya;
    r[0] = q[0] / p[0];
    r[1] = q[1] / p[1];
    r[2] = q[2] / p[2];
    r[3] = q[3] / p[3];

    //printf("%f %f %f %f %f %f %f %f %f %f %f %f ",p[0],q[0],p[1],q[1],p[2],q[2],p[3],q[3],r[0],r[1],r[2],r[3]);

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
    // printf("t1=%f t2=%f",t1,t2);
    if (t1 < t2) {
        glColor3f(1, 0, 1);
        finalx1 = s1xa + (deltax * t1);
        finaly1 = s1ya + (deltay * t1);
        finalx2 = s1xa + (deltax * t2);
        finaly2 = s1ya + (deltay * t2);

        //glFlush();
    } else {
        finaly2 = 0;
        finaly1 = 0;
        finalx2 = 0;
        finalx1 = 0;
    }

}

void cohen(){

    xa = 0;
    ya = 100;
    xb = 900;
    yb = 200;

    printf("\nGeneral %d %d %d %d", code.top, code.bottom, code.right, code.left);
    struct codes code1 = compute(xa, ya);
    code.top = 0;
    code.left = 0;
    code.right = 0;
    code.bottom = 0;
    struct codes code2 = compute(xb, yb);
    code.top = 0;
    code.left = 0;
    code.right = 0;
    code.bottom = 0;

    printf("\nFirst point %d %d %d %d", code1.top, code1.bottom, code1.right, code1.left);
    printf("\nSecond point%d %d %d %d", code2.top, code2.bottom, code2.right, code2.left);

    bool accept = false;

    while (true) {
        if (code1.top == 0 && code1.right == 0 && code1.left == 0 && code1.bottom == 0 && code2.top == 0 &&
            code2.right == 0 && code2.left == 0 && code2.bottom == 0) {
            accept = true;
            break;
        } else if ((code1.top == code2.top) && (code1.bottom == code2.bottom) &&
                   (code1.right == code2.right) &&
                   (code1.left == code2.left)) {
            break;
        } else {
            struct codes code_out;
            double x, y;


            if (code1.top == 0 && code1.left == 0 && code1.right == 0 && code1.bottom == 0)
                code_out = code2;
            else
                code_out = code1;

            if (code_out.bottom == 1) {

                x = xa + (xb - xa) * (ymax - ya) / (yb - ya);
                y = ymax;
            } else if (code_out.top == 1) {
                x = xa + (xb - xa) * (ymin - ya) / (yb - ya);
                y = ymin;
            } else if (code_out.right == 1) {

                y = ya + (yb - ya) * (xmax - xa) / (xb - xa);
                x = xmax;
            } else if (code_out.left == 1) {

                y = ya + (yb - ya) * (xmin - xa) / (xb - xa);
                x = xmin;
            }

            if (code_out.top == code1.top && code_out.right == code1.right && code_out.left == code1.left &&
                code_out.bottom == code1.bottom) {
                xa = x;
                ya = y;
                code1 = compute(xa, ya);
            } else {
                xb = x;
                yb = y;
                code2 = compute(xb, yb);
            }
        }
    }
    if (accept) {
        s2finalx1 = xa;
        s2finaly1 = ya;
        s2finalx2 = xb;
        s2finaly2 = yb;
    } else {
        s2finalx1 = 0;
        s2finaly1 = 0;
        s2finalx2 = 0;
        s2finaly2 = 0;
    }


}




void mykeyboardfunc(unsigned char key) {
    switch (key) {
        case 'l':break;

        case 'c':break;

        case 'x':
            glutDestroyWindow(wind);
    }
}




void display2() {

    glClearColor(0,0,1,0.5);
    glClear(GL_COLOR_BUFFER_BIT);

    s1xmin = rand() % 900;
    s1ymin = rand() % 100;
    s1xmax = s1xmin + 200;
    s1ymax = s1ymin + 200;
    liang();

    glColor3f(1,1,1);
    char name[] = "SUB WINDOW 1 Liang Barsky";
    glRasterPos2f(0, 300);
    for (int i = 0; name[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, name[i]);
    }
    glLineWidth(5);
    glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex2f(0,0);
    glVertex2f(900,300);
    glEnd();

    glColor3f(1,1,1);
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glVertex2f(s1xmin,s1ymin);
    glVertex2f(s1xmax,s1ymin);
    glVertex2f(s1xmax,s1ymax);
    glVertex2f(s1xmin,s1ymax);
    glEnd();

//    glColor3f(0,0,0);
//    glLineWidth(1);
//    glBegin(GL_LINE_LOOP);
//    glVertex2f(100,10);
//    glVertex2f(300,10);
//    glVertex2f(300,250);
//    glVertex2f(100,250);
//    glEnd();

    glLineWidth(5);
    glColor3f(0,0,1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(finalx1,finaly1);
    glVertex2f(finalx2,finaly2);
    glEnd();

    glFlush();
//    finalx1=0;
//    finalx2=0;
//    finaly1=0;
//    finaly2=0;
    Sleep(DELTA_TIME);
    glutPostRedisplay();

}

void display3() {


    glClearColor(0,1,0,1);
    glClear(GL_COLOR_BUFFER_BIT);

    xmin = rand() % 900;
    ymin = rand() % 100;
    xmax = xmin + 200;
    ymax = ymin + 200;
    cohen();

    glColor3f(1,1,1);
    char name[] = "SUB WINDOW 2 Cohen Sutherland";
    glRasterPos2f(0,300);
    for (int i = 0; name[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, name[i]);
    }



    glLineWidth(5);
    glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex2f(0,100);
    glVertex2f(900,200);
    glEnd();


    glColor3f(1,1,1);
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin,ymin);
    glVertex2f(xmax,ymin);
    glVertex2f(xmax,ymax);
    glVertex2f(xmin,ymax);
    glEnd();

    glColor3f(0,0,0);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(s2finalx1,s2finaly1);
    glVertex2f(s2finalx2,s2finaly2);
    glEnd();


    glFlush();
    Sleep(DELTA_TIME);
    glutPostRedisplay();
}


void display() {

    glColor3f(0, 1, 0);
    char name[] = "MAIN WINDOW NAMAN JAIN CSE GNG";
    glRasterPos2f(50,50);
    for (int i = 0; name[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, name[i]);
    }
    glFlush();
    glutPostRedisplay();

}


int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1000,700);
    wind = glutCreateWindow("MAIN WINDOW");

    glClearColor(1,1,1,1);
    gluOrtho2D(0,1000,700,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    glutKeyboardFunc(mykeyboardfunc);
    glutDisplayFunc(display);

    subwind1=glutCreateSubWindow(wind,50,50,900,300);            //subwindow 1
    glClearColor(0,0,1,0.5);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0,900,300,0);
    glutDisplayFunc(display2);

    subwind2=glutCreateSubWindow(wind,50,350,900,300);           //subwindow 2
    glClearColor(0,1,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0,900,300,0);
    glutDisplayFunc(display3);

    glutMainLoop();
    return 0;

}

