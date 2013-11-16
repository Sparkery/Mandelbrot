#include <stdio.h>
#include <GL/glut.h>

#define N 600

int count =  0 ; 
int ascii = 48 ; 

void idlefunc(void)
{
	++count ;
	//
	if( count == 1000000 )
	{
		count = 0 ;
		//
		++ascii ;
		//
		if( ascii ==  58 ) ascii = 65 ;
		if( ascii ==  91 ) ascii = 97 ;
		if( ascii == 123 ) ascii = 48 ;
		//
		glutPostRedisplay() ;
	}
}

void reshapefunc(int wscr,int hscr)
{
	glViewport(0,0,(GLsizei)800,(GLsizei)600);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,1.0*800,0.0,1.0*600);
	glMatrixMode(GL_MODELVIEW);
}
void mousefunc(int button,int state,int xscr,int yscr)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		printf("Left mouse clicked.\n");
	}
	else if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
	{
		printf("Right mouse clicked.\n");
	}
}
void motionfunc(int xscr,int yscr)
{
	printf("Motion ( %d , %d ).\n" , xscr , yscr ) ;
}
void keyfunc(unsigned char key,int xscr,int yscr)
{
	printf("Key %c pressed.\n" , key);
}
void specialfunc(int key,int xscr,int yscr)
{
	if( key == GLUT_KEY_UP )
	{
		printf("Up arrow pressed.\n");
	}
	if( key == GLUT_KEY_DOWN )
	{
		printf("Down arrow pressed.\n");
	}
	if( key == GLUT_KEY_LEFT )
	{
		printf("Left arrow pressed.\n");
	}
	if( key == GLUT_KEY_RIGHT )
	{
		printf("Right arrow pressed.\n");
	}
}
void closefunc(void)
{
	printf("Window closed.\n");
}

//
//
//
//
//

float color(float x, float y)
{
	float a = 0;
	float b = 0;
	int t = 0;
	int i;
	for(i = 0; i < 200; ++i)
	{
		if(a*a + b*b > 4.0)
			return t/200.0;
		float temp = a;
		a = a*a - b*b + x;
		b = 2*temp*b + y;
		++t;
	}

	return 1.0;
}

void displayfunc(void)
{
	int xlen = 800;
	int ylen = 600;
	int i, k;
	for(i = 0; i < xlen; ++i)
	{
		for(k = 0; k < ylen; ++k)
		{
			float x = (float)i;
			float y = (float)k;
			x -= 400;
			y -= 300;
			x /= 200;
			y /= 200;

			float colo = color(x, y);
			colo = 1 - colo;
			glColor3f( colo , colo , colo );
			//
			glBegin(GL_POINTS);
			glVertex2f(i, k);
			glEnd();
		}
	}
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(100,50);
	glutCreateWindow("");
	glClearColor(1.0,1.0,1.0,0.0);
	glShadeModel(GL_SMOOTH);
	//
	glutIdleFunc(idlefunc);
	glutDisplayFunc(displayfunc);
	glutReshapeFunc(reshapefunc);
	glutMouseFunc(mousefunc);
	glutMotionFunc(motionfunc);
	glutKeyboardFunc(keyfunc);
	glutSpecialFunc(specialfunc);
	glutWMCloseFunc(closefunc);
	//
	glutMainLoop();
	//
	return 0;
}
