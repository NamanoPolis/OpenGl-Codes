#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

void setup()
{
    glClearColor(1.0,1.0,1.0,1.0);
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.25,-0.5);
    glVertex2f(-0.5,0.0);
    glVertex2f(-0.25,0.5);
    glVertex2f(0.25,0.5);
    glVertex2f(0.5,0.0);
    glVertex2f(0.25,-0.5);
    glEnd();
    glColor3f(1,0,1);
    char name[]="NAMAN JAIN CSE GNG";
    glRasterPos2f(0,-0.5);
    for(int i=0;name[i]!='\0';i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,name[i]);
    }
    glFlush();

}

int main(int argc,char *argv[]){

        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
        glutInitWindowPosition(0,0);
        glutInitWindowSize(400,400);
        glutCreateWindow("Hexagon");
        glutDisplayFunc(display);
        setup();
        glutMainLoop();
    return 0;
}