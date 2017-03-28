#include <GL/glut.h>

void init2D(float r, float g, float b)
{
	glClearColor(r,g,b,0.0);  
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (0.0, 200.0, 0.0, 150.0);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);

	//1.draw two points
	glBegin(GL_POINTS);
	for(int i = 0; i < 10; i++)
	{
		glVertex2i(10+5*i,110);
	}
	glEnd();

	//2.draw a Lines (pairs of vertices interpreted as individual line segments)
	/*glBegin(GL_LINES);
		glVertex2i(10,10);
		glVertex2i(100,100);
		glVertex2i(15,75);
		glVertex2i(75,15);
	glEnd();*/
	//3.draw a Line Strip (series of connected line segments)
	/*glBegin(GL_LINES_STRIP);
		glVertex2i(25,105);
		glVertex2i(12,18);
		glVertex2i(19,75);
		glVertex2i(75,15);
	glEnd();*/
	//4.draw Line Loop (same as above, with a segment added between last and first vertices)
	/*glBegin(GL_LINE_LOOP);
		glVertex2i(25,105);
		glVertex2i(12,18);
		glVertex2i(19,75);
		glVertex2i(75,15);
	glEnd();*/
	//5.draw triples of vertices interpreted as triangles
	/*glBegin(GL_TRIANGLES);
		glVertex2i(25,105);
		glVertex2i(12,18);
		glVertex2i(45,35);
		glVertex2i(70,70);
		glVertex2i(100,30);
		glVertex2i(120,50);
	glEnd();*/

	//6.draw linked strip of triangles
	/*glBegin(GL_TRIANGLE_STRIP);
		glVertex2i(25,100);
		glVertex2i(25,50);
		glVertex2i(50,100);
		glVertex2i(70,70);
		//glVertex2i(100,30);
		//glVertex2i(120,50);
	glEnd();*/
	//7. draw Traingle Fan (linked fan of traingles)
	/*glBegin(GL_TRIANGLE_FAN);
		glVertex2i(25,100);
		glVertex2i(25,50);
		glVertex2i(50,100);
		glVertex2i(70,70);
		//glVertex2i(100,30);
		//glVertex2i(120,50);
	glEnd();*/
	//8. draw Quads (quadruples of vertices interpreted as four sided polygons)
	/*glBegin(GL_QUADS);
		glVertex2i(25,100);
		glVertex2i(25,50);
		glVertex2i(50,100);
		glVertex2i(70,70);
		//glVertex2i(100,30);
		//glVertex2i(120,50);
	glEnd();*/
	//9.draw Quad Strip (linked strip of quadrilaterals)
	/*glBegin(GL_QUAD_STRIP);
		glVertex2i(25,100);
		glVertex2i(25,50);
		glVertex2i(50,100);
		glVertex2i(70,70);
		//glVertex2i(100,30);
		//glVertex2i(120,50);
	glEnd();*/
	//10.draw Quad Strip (linked strip of quadrilaterals)
	glBegin(GL_POLYGON);
		glVertex2i(25,100);
		glVertex2i(25,50);
		glVertex2i(50,100);
		glVertex2i(70,70);
		//glVertex2i(100,30);
		//glVertex2i(120,50);
	glEnd();
	glFlush();
}

int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("points and lines");
	init2D(0.0,0.0,0.0);
	glutDisplayFunc(display);
	glutMainLoop();
}
