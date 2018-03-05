
#include <GL/glut.h>
#include <math.h>
float WINDOW_SIZE = 1000;

void squares(float topLeftx,  float topLefty, float topRightx, float topRighty, float n)
{

    float Q1x = topLeftx;
    float Q1y = topLefty;


    float Q2x = topRightx;
    float Q2y = topRighty;


    float Q3x = Q2x - (Q1y - Q2y);
    float Q3y = Q2y + (Q1x - Q2x);


    float Q4x = (Q1x-Q2x) + Q3x;
    float Q4y = (Q1y-Q2y) + Q3y;

    //display filled square
    glBegin(GL_LINE_LOOP);
    glColor3f(0,1,0);
    glVertex2f(Q1x, Q1y);
    glVertex2f(Q2x, Q2y);
    glVertex2f(Q3x, Q3y);
    glVertex2f(Q4x, Q4y);
    glEnd();


    //calculate begining of next square
    float ACx = (Q3x - Q1x)/2;	//half of the diagonal
    float ACy = (Q3y - Q1y)/2;
    float newx = ACx + Q4x;		// point of iscoceles right triangle
    float newy = ACy + Q4y;		// off of the bottom of the square


    //length of a side of the square
    float dist = sqrt(((Q1x-Q2x)*(Q1x-Q2x)) + ((Q1y-Q2y)*(Q1y-Q2y)));


    if( dist > (20.0/WINDOW_SIZE)*6) {
        //left recursion
        squares(newx, newy, Q3x, Q3y, n+0.3); //right recursion
        squares(Q4x, Q4y, newx, newy, n+0.08);
    }


}




void display(void)
{
    glClear( GL_COLOR_BUFFER_BIT);

    glColor3f(0, 1, 0);
    char name[] = "NAMAN JAIN CSE GNG FRACTAL";
    glRasterPos2f(-9,9);
    for (int i = 0; name[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, name[i]);
    }


    squares(-1.0, 1.0, 1.0, 1.0, 0.0);

    glFlush();
}




int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100,100);
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