#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>


void setup() {
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(-100, 100, -100, 100);
    glLineWidth(5);
}

void display() {
    srand(time(NULL));
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);

    glBegin(GL_POINTS);
    for (int i = -100; i <= 100; i = i + 10) {
        for (int j = 100; j >= -100; j = j - 10) {
            glVertex2f(i, j);
        }
    }
    glEnd();


    int l, r, u, d, n = 4;

    for (int i = -100; i <= 100; i = i + 10) {
        for (int j = 100; j >= -100; j = j - 10) {
            l = rand() % n;
            r = rand() % n;
            u = rand() % n;
            d = rand() % n;
            if (l == 1) {
                glBegin(GL_LINES);
                glVertex2f(i, j);
                glVertex2f(i - 10, j);
                glEnd();
            }
            Sleep(1);
            glFlush();

            if (r == 1) {
                glBegin(GL_LINES);
                glVertex2f(i, j);
                glVertex2f(i + 10, j);
                glEnd();
            }
            Sleep(1);
            glFlush();
            if (u == 1) {
                glBegin(GL_LINES);
                glVertex2f(i, j);
                glVertex2f(i, j + 10);
                glEnd();
            }
            Sleep(1);
            glFlush();
            if (d == 1) {
                glBegin(GL_LINES);
                glVertex2f(i, j);
                glVertex2f(i, j - 10);
                glEnd();
            }
            Sleep(1);
            glFlush();
        }
    }


}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Hello World");
    glutDisplayFunc(display);

    setup();
    glutMainLoop();

    return 0;

}

