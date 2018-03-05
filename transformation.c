#include<stdio.h>
#include<windows.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<string.h>
#include<math.h>
int menu_id;
int submenu_id,submenu_id_t,submenu_id_s,submenu_id_rf,submenu_id_rt,submenu_id_sh;
double co_mat[3][4]={
              {-50,90,90,-50},
              {-50,-50,90,90},
              {1,1,1,1},
              };
double tra_mat[3][3]={
              {1,0,0},
              {0,1,0},
              {0,0,1},
              };
double res_mat[3][4]={
              {0,0,0,0},
              {0,0,0,0},
              {0,0,0,0},
              };

void id_mat(){
 //creating identity matrix
for(int i=0;i<3;i++)
    for(int j=0;j<4;j++){
    if(i==j)
        res_mat[i][j]=1;
    else
        res_mat[i][j]=0;
    }
}

void mult_mat(){
//multipling matrix and copying again to co_matrix
for(int i=0;i<3;i++)
    for(int j=0;j<4;j++)
       res_mat[i][j]=tra_mat[i][0]*co_mat[0][j]+tra_mat[i][1]*co_mat[1][j]+tra_mat[i][2]*co_mat[2][j];

for(int i=0;i<3;i++)
    for(int j=0;j<4;j++)
       co_mat[i][j]=res_mat[i][j];

}
//main functions
void translate(int tx,int ty){
    id_mat();//creating identity matrix
    tra_mat[0][2]=tx;//adding tx and ty in identity matrix
    tra_mat[1][2]=ty;
     mult_mat();//callling for multiplication
}

void scale(int sx,int sy){
    id_mat();//creating identity matrix
    tra_mat[0][0]=sx;
    tra_mat[1][1]=sy;
     mult_mat();
}

void reflection(int rx,int ry)
{   //rx for y axis and ry for x axis
    id_mat();
    tra_mat[0][0]=rx;
    tra_mat[1][1]=ry;
    mult_mat();
}

void shear(int shx,int shy)
{
    id_mat();
    tra_mat[1][0]=shx;
    tra_mat[0][1]=shy;
     mult_mat();

}

void rotation(double Q){
    id_mat();
    tra_mat[0][0]=cos(Q);
    tra_mat[0][1]=-sin(Q);
    tra_mat[1][0]=sin(Q);
    tra_mat[1][1]=cos(Q);
    mult_mat();
}
//display function
void draw()
{
    glLineWidth(5);
  glBegin(GL_LINE_LOOP);
   glVertex2i(co_mat[0][0],co_mat[1][0]);
   glVertex2i(co_mat[0][1],co_mat[1][1]);
   glVertex2i(co_mat[0][2],co_mat[1][2]);
   glVertex2i(co_mat[0][3],co_mat[1][3]);
  glEnd();
printf("\n");

for(int i=0;i<3;i++){
for(int j=0;j<4;j++)
printf("%f \t",co_mat[i][j]);
printf("\n");
}

}
//creating menu
void menu(int num){
  if(num == 0){
    //glutDestroyWindow(window);
    exit(0);
  }else if(num ==11){
      translate(10,0);
  }else if(num ==12){
      translate(0,10);
  }else if(num ==13){
      translate(10,10);
  }else if(num ==14){
      translate(-10,0);
  }else if(num ==15){
      translate(0,-10);
  }else if(num ==21){
      scale(2,1);
  }else if(num ==22){
     scale(1,2);
  }else if(num ==24){
      scale(-2,1);
  }else if(num ==25){
     scale(1,-2);
  }else if(num ==23){
     scale(2,2);
  }else if(num ==31){
     reflection(1,-1);
  }else if(num ==32){
     reflection(-1,1);
  }else if(num ==33){
     reflection(-1,-1);
  }else if(num ==41){
     rotation(-0.5);
  }else if(num ==42){
     rotation(0.5);
  }else if(num ==51){
     shear(2,0);
  }else if(num ==52){
     shear(0,2);
  }else if(num ==54){
     shear(-2,0);
  }else if(num ==55){
     shear(0,-2);
  }else if(num ==53){
     shear(2,2);
  }else if(num==2){
  int tx=co_mat[0][0]+50;
  int ty=co_mat[1][0]+50;
  translate(-tx,-ty);
  }

  glutPostRedisplay();
}

void createMenu(void){
  submenu_id_t = glutCreateMenu(menu);
    glutAddMenuEntry("Translate X++", 11);
    glutAddMenuEntry("Translate Y++", 12);
    glutAddMenuEntry("Translate BOTH", 13);
    glutAddMenuEntry("Translate X--", 14);
    glutAddMenuEntry("Translate Y--", 15);

    submenu_id_s = glutCreateMenu(menu);
    glutAddMenuEntry("SCALE X++", 21);
    glutAddMenuEntry("SCALE Y++", 22);
    glutAddMenuEntry("SCALE X--", 24);
    glutAddMenuEntry("SCALE Y--", 25);
    glutAddMenuEntry("SCALE BOTH", 23);

    submenu_id_rf = glutCreateMenu(menu);
    glutAddMenuEntry("Reflection X-AXIS", 31);
    glutAddMenuEntry("Reflection Y-AXIS", 32);
    glutAddMenuEntry("Reflection ORIGIN", 33);

    submenu_id_rt = glutCreateMenu(menu);
    glutAddMenuEntry("Rotate clock-wise", 41);
    glutAddMenuEntry("Rotate anti-clock-wise", 42);

    submenu_id_sh = glutCreateMenu(menu);
    glutAddMenuEntry("Shear X++", 51);
    glutAddMenuEntry("Shear Y++", 52);
    glutAddMenuEntry("Shear X--", 54);
    glutAddMenuEntry("Shear Y--", 55);
    glutAddMenuEntry("Shear BOTH", 53);

    submenu_id = glutCreateMenu(menu);
    glutAddSubMenu("Translate", submenu_id_t);
    glutAddSubMenu("Scale", submenu_id_s);
    glutAddSubMenu("Reflection", submenu_id_rf);
    glutAddSubMenu("Rotate", submenu_id_rt);
    glutAddSubMenu("Shear", submenu_id_sh);     menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Clear", 1);
    glutAddSubMenu("Transformations", submenu_id);
    glutAddMenuEntry("Move to Initial position", 2);
    glutAddMenuEntry("Quit", 0);     glutAttachMenu(GLUT_RIGHT_BUTTON);}

void reshape(GLsizei WIDTH,GLsizei HEIGHT){
    glViewport(0, 0,WIDTH,HEIGHT);
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    gluOrtho2D(-250.0f,250.0f,-250.0f,250.0f);
    createMenu();
}


void display(){
  glClearColor(0.0,1.0,1.0,0.0);
  glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(0, 1, 0);
    char name[] = "NAMAN JAIN CSE GNG TRANSFORMATION";
    glRasterPos2f(-250,0);
    for (int i = 0; name[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, name[i]);
    }

    glColor3f(0.0f,0.0f,1.0f);
    glLineWidth(2);
  glBegin(GL_LINES);
  glVertex2i(-250,0);
  glVertex2i(250,0);
  glEnd();
  glBegin(GL_LINES);
  glVertex2i(0,250);
  glVertex2i(0,-250);
  glEnd();

  draw();
  glFlush();
}


int main(int argc, char **argv)
{    glutInit(&argc, argv);
     glutCreateWindow("Hello");
     glutInitWindowSize(640,480);
     glutReshapeWindow(500,500);
     glutInitWindowPosition(100,100);
     glutReshapeFunc(reshape);
     glutDisplayFunc(display);
     glutMainLoop();
     return 0;
}
