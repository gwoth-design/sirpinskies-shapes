#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int windowWidth = 800;
int windowHeight = 800;
int p1x = 0;
int p1y = 0;
int p2x = 800;
int p2y = 0;
int p3x = 400;
int p3y = 700;
int rpx = 200;
int rpy = 200;

void drawDot(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
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
    
    srand(time(NULL));
    int i = 0;
    for (i; i <= 1000000; i++) {
        int x = rand() % 3 + 1;
        int a = 0;
        int b = 0;
        
        if (x == 1) {
            if (rpx > p1x)
                a = (rpx + p1x) / 2;
            else
                a = (p1x + rpx) / 2;
            
            if (rpy > p1y)
                b = (rpy + p1y) / 2;
            else
                b = (p1y + rpy) / 2;
            
            rpx = a;
            rpy = b;
            
            glColor3f(1.0, 1.0, 0.0); // Yellow color
            drawDot(a, b);
        }
        else if (x == 2) {
            if (rpx > p2x)
                a = (rpx + p2x) / 2;
            else
                a = (p2x + rpx) / 2;
            
            if (rpy > p2y)
                b = (rpy + p2y) / 2;
            else
                b = (p2y + rpy) / 2;
            
            rpx = a;
            rpy = b;
            
            glColor3f(1.0, 0.0, 1.0); // Magenta color
            drawDot(a, b);
        }
        else if (x == 3) {
            if (rpx > p3x)
                a = (rpx + p3x) / 2;
            else
                a = (p3x + rpx) / 2;
            
            if (rpy > p3y)
                b = (rpy + p3y) / 2;
            else
                b = (p3y + rpy) / 2;
            
            rpx = a;
            rpy = b;
            
            glColor3f(0.0, 1.0, 1.0); // Cyan color
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
