#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;
// Snake direction macros
#define UP    1
#define DOWN  2
#define LEFT  3
#define RIGHT 4

float map_half_length = 30.0000;

int direction = DOWN;
int move_speed = 100;
float VAL_ADD[5]={0.00,2.00,-2.00,-2.00,2.00};
int VAL_MULT[5]={0,1,-1,-1,1};
bool moved = false;
deque< deque<float> > part_coords;

bool food_available = false;
int food_coords[2];

int growth_stage = 0;
int growth = 2;
int score = 0;
void spawnFood(){
    if(!food_available){
        while(true){
            bool collides = false;
            // Produce a temporary random coordinate
            int temp_food_coords[2] = {2*(rand()%((int)map_half_length+1))-(int)map_half_length,
                                       2*(rand()%((int)map_half_length+1))-(int)map_half_length };
            // Does it collide with the snake?
            for(int a = 0; a < part_coords.size(); a++){
                if(temp_food_coords[0] == part_coords[a][0] &&
                   temp_food_coords[1] == part_coords[a][1]){
                    collides = true;
                }
            }
            // If it doesn't collide with the snake, then make it the real food coordinates
            if(collides == false){
                food_coords[0] = temp_food_coords[0];
                food_coords[1] = temp_food_coords[1];
                food_available = true;
                break;
            }
        }
    }
    glLoadIdentity();
    glTranslatef(food_coords[0], food_coords[1], -40.0f);
    glColor3f(1.0f, 0.0f, 0.0f);	
    glBegin(GL_POLYGON);
        glVertex2d( 1.0f,  1.0f);
        glVertex2d( 1.0f, -1.0f);
        glVertex2d(-1.0f, -1.0f);
        glVertex2d(-1.0f,  1.0f);
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    // Loop over snake size and draw each part at it's respective coordinates
    for(int a = 0; a < part_coords.size(); a++){
        glLoadIdentity();
        glTranslatef(part_coords[a][0], part_coords[a][1], -40.0f);
        glColor3f(0.0f, 1.0f, 0.0f);	
        glBegin(GL_POLYGON);
            glVertex2d( 1.0f,  1.0f);
            glVertex2d( 1.0f, -1.0f);
            glVertex2d(-1.0f, -1.0f);
            glVertex2d(-1.0f,  1.0f);
        glEnd();
    }
    spawnFood();
    glutSwapBuffers();
}
void drawText(char*string,int x,int y,int z)
{
	char *c;
	glPushMatrix();
	glTranslatef(x, y,z);
	glScalef(1.0,-0.1,1);
	for (c=string; *c != '\0'; c++){
		glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
	}
	glPopMatrix();
}
void moveSnake(int new_direction){
    direction = new_direction;
    int last_part = part_coords.size() - 1;
    deque<float> new_head = part_coords[0];
	
    if(direction == UP or direction == DOWN){
        // Did we slither into ourself?
        for(int a = 0; a < part_coords.size(); a++){
            if(part_coords[0][0]        == part_coords[a][0] &&
               part_coords[0][1] + VAL_ADD[direction] == part_coords[a][1]){
				getchar();
                exit(0);
            }
        }
        // Did we slither into a wall?
        if(part_coords[0][1] == VAL_MULT[direction] * map_half_length){
			getchar();
            exit(0);
        }
        // Did we get food?
        if(part_coords[0][0]        == food_coords[0] &&
           part_coords[0][1] + VAL_ADD[direction] == food_coords[1]){
            growth_stage++;
            score++;
            food_available = false;
        }
        new_head[1] += VAL_ADD[direction];
    } 
    if(direction == LEFT or direction == RIGHT){
        // Did we slither into ourself?
        for(int a = 0; a < part_coords.size(); a++){
            if(part_coords[0][0] + VAL_ADD[direction] == part_coords[a][0] &&
               part_coords[0][1]        == part_coords[a][1]){
				getchar();
                exit(0);
            }
        }
        // Did we slither into a wall?
        if(part_coords[0][0] == VAL_MULT[direction] * map_half_length){
			getchar();
            exit(0);
        }
        // Did we get food?
        if(part_coords[0][0] + VAL_ADD[direction] == food_coords[0] &&
           part_coords[0][1]        == food_coords[1]){
            growth_stage++;
            food_available = false;
        }
        new_head[0] += VAL_ADD[direction];
    }
    part_coords.push_front(new_head);
    if(!growth_stage){
        part_coords.pop_back();
    } else if(growth_stage == growth){
        growth_stage = 0;
    } else {
        growth_stage++;
    } 
    glutPostRedisplay();
}

void keyboard(int key, int x, int y){
    switch(key){
        case GLUT_KEY_UP:{
            if(direction == LEFT  || direction == RIGHT){
                moved = true;
                moveSnake(UP);
            }
            break;
        }
        case GLUT_KEY_DOWN:{
            if(direction == LEFT || direction == RIGHT){
                moved = true;
                moveSnake(DOWN);
            }
            break;
        }
        case GLUT_KEY_LEFT:{
            if(direction == UP || direction == DOWN){
                moved = true;
                moveSnake(LEFT);
            }
            break;
        }
        case GLUT_KEY_RIGHT:{
            if(direction == UP || direction == DOWN){
                moved = true;
                moveSnake(RIGHT);
            }
            break;
        }
    }
    glutPostRedisplay();
}
void initGL(){
    glMatrixMode(GL_PROJECTION);
    gluPerspective(75.0f, 1, 0.0f, 35.0f);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
void moveSnakeAuto(int value){
    if(!moved){
        if(direction == UP){
            moveSnake(UP);
        } else if(direction == DOWN){
            moveSnake(DOWN);
        } else if(direction == LEFT){
            moveSnake(LEFT);
        } else if(direction == RIGHT){
            moveSnake(RIGHT);
        }
    } else {
        moved = false;
    }
    glutTimerFunc(move_speed, moveSnakeAuto, 0);
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Snake Game");
    glutDisplayFunc(display);
    glutSpecialFunc(keyboard);
    glutTimerFunc(move_speed, moveSnakeAuto, 0);
    int initSize = 3;
    // Specify the coordinates to each part of the snake
    for(int a = 1; a <= initSize; a++){
        deque<float> row;
        row.push_back(0.00);
        row.push_back((map_half_length + 2.00 + (initSize * 2)) - (a * 2));
        part_coords.push_front(row);
    }
    srand(time(NULL));
    initGL();
    glutMainLoop();
    return 0;
}
