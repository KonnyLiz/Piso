//* Piso
#include <GL/gl.h>
#include <GL/glut.h>

GLfloat s = 0.8f;

void init(){
    glClearColor(0.0, 1.0, 0.9, 0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-5,10,-5,10,-10,10);
}


void ejes(){
    //EjesDeReferencia
    glBegin (GL_LINES);
    glColor3f(1.0,0.0,0.0); //rojo
    glVertex3f (-1000.0, 0.0, 0.0);
    glVertex3f (1000.0, 0.0, 0.0);
    glColor3f(0.0,1.0,0.0); //verde
    glVertex3f ( 0.0, -1000.0, 0.0);
    glVertex3f ( 0.0,1000.0, 0.0);
    glColor3f(1.0,1.0,1.0); //blanco
    glVertex3f ( 0.0, 0.0, -1000.0);
    glVertex3f ( 0.0, 0.0,1000.0);
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
  	glPushMatrix();
  	//ejes();
  	//glRotatef(180,1,0,0);
    glRotatef(50,1,0,0);
    glRotatef(10,0,1,0);
    glTranslatef(0.0,3.0,0.0);
    glScalef(s, s, s);
   // gluPerspective(40, 30, 1.0, 200.0);
    GLfloat ejez=-1.0f,ejex=-1.0f,cons=1.0f;
    int col=0;
    for(int z=0; z<=6;z++){
        ejex=-1.0;
        for(int x=0; x<=6;x++){
             if(col==0){
                glColor3f(0,0,0);
                col=1;
            }
            else{
                glColor3f( 1.0, 1.0, 1.0 );
                col=0;
            }
           glBegin(GL_QUADS);
                glVertex3f(ejex,0,ejez);
                glVertex3f(ejex+cons,0,ejez);
               glVertex3f(ejex+cons,0,ejez+cons);
                glVertex3f(ejex,0,ejez+cons);
            glEnd();     
            ejex=ejex+cons;
        }
        ejez=ejez+cons;
    }
    //dibujando paredes
     glBegin(GL_QUADS);
    glColor3f(1.0,0.0,1.0); //pared magenta
    glVertex3f(6,0,6);
    glVertex3f(6,5,6);
    glVertex3f(6,5,-1);
    glVertex3f(6,0,-1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,1.0); //pared azul
    glVertex3f(-1,0,-1);
    glVertex3f(-1,5,-1);
    glVertex3f(6,5,-1);
    glVertex3f(6,0,-1);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.0,1.0,0.0); //pared verde
    glVertex3f(-1.0,0,-1);
    glVertex3f(-1.0,0,6);
    glVertex3f(-1.0,5,6);
    glVertex3f(-1.0,5,-1);
    glEnd();
    glFlush(); 
    
    glPopMatrix();
    glutSwapBuffers();
}
int main(int agrc, char ** argv){
    glutInit(&agrc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(150, 200);
    glutInitWindowSize(800, 600);
    glutCreateWindow ("Piso");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

}
