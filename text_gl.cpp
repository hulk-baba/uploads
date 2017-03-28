#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <gl\GLU.h>
#include <glut.h>
#include <math.h>
#include <cstring>
 
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")
 
/*
 Drawing text 2D screen.
*/
void drawText(const char *text, int length, int x, int y){
 glMatrixMode(GL_PROJECTION); // change the current matrix to PROJECTION
 double matrix[16]; // 16 doubles in stack memory
 glGetDoublev(GL_PROJECTION_MATRIX, matrix); // get the values from PROJECTION matrix to local variable
 glLoadIdentity(); // reset PROJECTION matrix to identity matrix
 glOrtho(0, 800, 0, 600, -5, 5); // orthographic perspective
 glMatrixMode(GL_MODELVIEW); // change current matrix to MODELVIEW matrix again
 glLoadIdentity(); // reset it to identity matrix
 glPushMatrix(); // push current state of MODELVIEW matrix to stack
 glLoadIdentity(); // reset it again. (may not be required, but it my convention)
 glRasterPos2i(x, y); // raster position in 2D
 for(int i=0; i<length; i++){
  glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]); // generation of characters in our text with 9 by 15 GLU font
 }
 glPopMatrix(); // get MODELVIEW matrix value from stack
 glMatrixMode(GL_PROJECTION); // change current matrix mode to PROJECTION
 glLoadMatrixd(matrix); // reset
 glMatrixMode(GL_MODELVIEW); // change current matrix mode to MODELVIEW
}
 
void DrawScreen(SDL_Surface* screen, int h)
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
 gluLookAt(0,0,-10, 0,0, 3, 0, 1, 0);
 
 glColor3f(1,0,0);
 
 glBegin(GL_LINES);
 glVertex3f(0,0,0);
 glVertex3f(1,0,0);
 glEnd();
 
 std::string text;
 text = "This is a simple text.";
 glColor3f(0, 1, 0);
 drawText(text.data(), text.size(), 50, 200);
 
 SDL_GL_SwapBuffers();
}
 
static void reshape(int width, int height)
{
 GLfloat h = (GLfloat) height / (GLfloat) width;
 glViewport(0, 0, (GLint) width, (GLint) height);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluPerspective( 45.0, h, 1.0, 1000.0 );
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
}
 
SDL_Surface *surface;
int main(int argc, char **argv)
{
 
 if (SDL_Init(SDL_INIT_VIDEO || SDL_INIT_AUDIO)<0)
 {
  return 1;
 }
 
 surface = SDL_SetVideoMode(800, 600, 32, SDL_OPENGL | SDL_RESIZABLE | SDL_DOUBLEBUF);
 glShadeModel(GL_SMOOTH);
 glEnable(GL_DEPTH_TEST);
 glDepthFunc(GL_LEQUAL);
 
 glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
 
 glLineWidth(1.5f);
 
 glMatrixMode(GL_MODELVIEW);
 
 reshape(800,600);
 SDL_Event event;
 
 int keypress = 0;
 int h=0;
 
 while(!keypress)
 {
 
  while(SDL_PollEvent(&event))
  {
   switch (event.type)
   {
   case SDL_QUIT:
    keypress = 1;
    break;
   case SDL_KEYDOWN:
    switch(event.key.keysym.sym){
    case SDLK_LEFT:
 
     break;
    case SDLK_RIGHT:
 
     break;
    case SDLK_UP:
 
     break;
    case SDLK_DOWN:
 
     break;
    default:
     break;
    }
   default:
    break;
   }
 
  }
  DrawScreen(surface,h++);
 }
 
 SDL_Quit();
 return 0;
}
