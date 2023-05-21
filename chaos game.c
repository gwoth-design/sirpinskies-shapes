#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <GL/glut.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define HEXAGON_RADIUS 200
#define ITERATIONS 500000

typedef struct {
    double x;
    double y;
} Point;

Point createPoint(double x, double y) {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

void drawHexagon() {
    glColor3f(1.0, 1.0, 1.0);
    
    Point center = createPoint(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    Point vertex[6];
    
    double angle = M_PI / 3;
    int i = 0;
    for (i; i < 6; i++) {
        double theta = angle * i;
        double x = center.x + HEXAGON_RADIUS * cos(theta);
        double y = center.y + HEXAGON_RADIUS * sin(theta);
        vertex[i] = createPoint(x, y);
    }
    
    glBegin(GL_LINE_LOOP);
    int j = 0;
    for (j; j < 6; j++) {
        glVertex2d(vertex[j].x, vertex[j].y);
    }
    glEnd();
}

void drawPoint(Point p) {
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(1.0);
    
    glBegin(GL_POINTS);
    glVertex2d(p.x, p.y);
    glEnd();
}


Point getRandomPoint() {
    double x = rand() % (SCREEN_WIDTH - HEXAGON_RADIUS * 2) + HEXAGON_RADIUS;
    double y = rand() % (SCREEN_HEIGHT - HEXAGON_RADIUS * 2) + HEXAGON_RADIUS;
    return createPoint(x, y);
}

Point getNewPoint(Point current, Point target) {
    double dx = ((target.x - current.x) / 3) * 2;
    double dy = ((target.y - current.y) / 3) * 2;
    Point newPoint = createPoint(current.x + dx, current.y + dy);
    return newPoint;
}

int getRandomVertex() {
    return rand() % 6;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    drawHexagon();
    
    Point currentPoint = getRandomPoint();
    drawPoint(currentPoint);
    
    int i;
    for (i = 0; i < ITERATIONS; i++) {
        int randomVertex = getRandomVertex();
        Point targetPoint;
        
        switch (randomVertex) {
            case 0:
                targetPoint = createPoint(SCREEN_WIDTH / 2 + HEXAGON_RADIUS, SCREEN_HEIGHT / 2);
                break;
            case 1:
                targetPoint = createPoint(SCREEN_WIDTH / 2 + HEXAGON_RADIUS * cos(M_PI / 3), SCREEN_HEIGHT / 2 - HEXAGON_RADIUS * sin(M_PI / 3));
                break;
            case 2:
                targetPoint = createPoint(SCREEN_WIDTH / 2 + HEXAGON_RADIUS * cos(M_PI / 3), SCREEN_HEIGHT / 2 + HEXAGON_RADIUS * sin(M_PI / 3));
                break;
            case 3:
                targetPoint = createPoint(SCREEN_WIDTH / 2 - HEXAGON_RADIUS, SCREEN_HEIGHT / 2);
                break;
            case 4:
                targetPoint = createPoint(SCREEN_WIDTH / 2 - HEXAGON_RADIUS * cos(M_PI / 3), SCREEN_HEIGHT / 2 + HEXAGON_RADIUS * sin(M_PI / 3));
                break;
            case 5:
                targetPoint = createPoint(SCREEN_WIDTH / 2 - HEXAGON_RADIUS * cos(M_PI / 3), SCREEN_HEIGHT / 2 - HEXAGON_RADIUS * sin(M_PI / 3));
                break;
        }
        
        currentPoint = getNewPoint(currentPoint, targetPoint);
        drawPoint(currentPoint);
    }
    
    glFlush();
}

int main(int argc, char **argv) {
    srand(time(NULL));
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutCreateWindow("Hexagon Random Walk");
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, -1.0, 1.0);
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
    
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}

