#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int windowWidth = 800;
int windowHeight = 800;
int p1x = 0;
int p1y = 0;
int p2x = 1000;
int p2y = 0;
int p3x = 2000;
int p3y = 0;
int p4x = 2000;
int p4y = 1000;

int p5x = 2000;
int p5y = 2000;
int p6x = 1000;
int p6y = 2000;
int p7x = 0;
int p7y = 2000;
int p8x = 0;
int p8y = 1000;
int rpx = 200;
int rpy = 200;

void drawDot(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void calculatePoint(float* currentPointX, float* currentPointY, float* ChosenPointX, float* ChosenPointY, float* a, float* b){
	if (*currentPointX > *ChosenPointX)
        *a = ((*currentPointX + *ChosenPointX) / 3);
    else
        *a = ((*ChosenPointX + *currentPointX) / 3);
	if (*currentPointY > *ChosenPointY)
        *b = ((*currentPointY + *ChosenPointY) / 3);
    else
        *b = ((*ChosenPointY + *currentPointY) / 3);
        
    return a, b;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Draw the first 3 points
    glColor3f(1.0, 0.0, 0.0); // Red color
    drawDot(p1x, p1y);
    
    glColor3f(0.0, 1.0, 0.0); // Green color
    drawDot(p2x, p2y);
    
    glColor3f(0.0, 0.0, 1.0); // Blue color
    drawDot(p3x, p3y);
    
    glColor3f(1.0, 1.0, 1.0); // Blue color
    drawDot(p4x, p4y);
    
    srand(time(NULL));
    int i = 1;
    for (i; i <= 10000000; i++) {
        int x = rand() % 8 + 1;
        int a = 0;
        int b = 0;
        
        if (x == 1) {
            calculatePoint(&rpx, &rpy, &p1x, &p1y, &a, &b);
            rpx = a;
            rpy = b;
            glColor3f(0.27, 0.51, 0.71);
            drawDot(a, b);
        }
        else if (x == 2) {
            calculatePoint(&rpx, &rpy, &p2x, &p2y, &a, &b);
            rpx = a;
            rpy = b;
            glColor3f(1.0, 0.08, 0.58);
            drawDot(a, b);
        }
        else if (x == 3) {
            calculatePoint(&rpx, &rpy, &p3x, &p3y, &a, &b);
            rpx = a;
            rpy = b;
            glColor3f(1.0, 0.55, 0.0);
            drawDot(a, b);
        }
        else if (x == 4){
			calculatePoint(&rpx, &rpy, &p4x, &p4y, &a, &b);
            rpx = a;
            rpy = b;
            glColor3f(0.58, 0.44, 0.86);
            drawDot(a, b);
		}
		
		else if (x == 5) {
            calculatePoint(&rpx, &rpy, &p5x, &p5y, &a, &b);
            rpx = a;
            rpy = b;
            glColor3f(0.85, 0.65, 0.63);
            drawDot(a, b);
        }
        else if (x == 6) {
            calculatePoint(&rpx, &rpy, &p6x, &p6y, &a, &b);
            rpx = a;
            rpy = b;
            glColor3f(0.12, 0.56, 1.0);
            drawDot(a, b);
        }
        else if (x == 7) {
            calculatePoint(&rpx, &rpy, &p7x, &p7y, &a, &b);
            rpx = a;
            rpy = b;
            glColor3f(0.13, 0.55, 0.13);
            drawDot(a, b);
        }
        else if (x == 8){
			calculatePoint(&rpx, &rpy, &p8x, &p8y, &a, &b);
            rpx = a;
            rpy = b;
            glColor3f(0.86, 0.08, 0.24);
            drawDot(a, b);
		}
    }
    
    glFlush();
}

void reshape(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("OpenGL Dots");

	glClearColor(0.0, 0.0, 0.0, 1.0); // Black background color

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMainLoop();

	return 0;
}
