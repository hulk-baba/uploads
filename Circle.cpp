#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <GL/glut.h>
#include <time.h>
using namespace std;
#define PIE 3.14

double X1, Y1, X2, Y2;
clock_t start, end;
double cpu_time_used;
void midline(){
	start = clock();
	int x,y;
	int x0,y0;
	int R;
	cout<<"Enter co-ordinates of centre\n";
	cin>>x0>>y0;
	cout<<"Enter Radius of circle\n";
	cin>>R;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	float theta = 0;
	while(theta <= 2*PIE){
		x = x0 + R * cos(theta);
		y = y0 + R * sin(theta);
		glVertex2d(x,y);
		theta += 0.05;
		
		
	}	
	glEnd();
	glFlush();
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time Takes Is : %f\n",cpu_time_used);

}

void bresenhem_circle(){
	start = clock();
	int x,y;
	int x0,y0;
	int R;
	cout<<"Enter co-ordinates of centre\n";
	cin>>x0>>y0;
	cout<<"Enter Radius of circle\n";
	cin>>R;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	x=0;y=R;
	int h = 1-R;
	glVertex2d(x0+x,y0+y);
	while(y>x){
		if(h<0){
			h = h + 2*x+3;
		}
		else{
			h = h + 2*(x-y)+5;
			y = y-1;
		}
		x = x+1;
		glVertex2d(x0+x,y0+y);
		glVertex2d(x0+x,y0-y);
		
		glVertex2d(x0+y,y0+x);
		glVertex2d(x0+y,y0-x);
		
		glVertex2d(x0-x,y0+y);
		glVertex2d(x0-x,y0-y);
		
		glVertex2d(x0-y,y0+x);
		glVertex2d(x0-y,y0-x);	
	}
	glEnd();
	glFlush();
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time Takes Is : %f\n",cpu_time_used);
}
void Init()
{
/* Set clear color to white */
glClearColor(1.0,1.0,1.0,0);
/* Set fill color to black */
glColor3f(0.0,0.0,0.0);
/* glViewport(0 , 0 , 640 , 480); */
/* glMatrixMode(GL_PROJECTION); */
/* glLoadIdentity(); */
gluOrtho2D(0 , 640 , 0 , 480);
}


int main(int argc, char **argv){
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(640,480);
	glutCreateWindow("MidPoint");
	
	Init();
	
	glutDisplayFunc(bresenhem_circle);
	
	glutMainLoop();
	return 0;
}
