//============================================================================
// Rush Hour — a 2D taxi pick-up / drop-off game (OpenGL / GLUT).
//
// Drive the taxi (arrow keys), pull up next to a waiting passenger and press
// Space to pick them up. Their destination then appears as a green marker;
// drive there and press Space again to drop them off and score.
//============================================================================
#include "util.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

// --- Window / canvas -------------------------------------------------------
const int WIN_W = 1020;
const int WIN_H = 840;

void SetCanvasSize(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// --- Player taxi -----------------------------------------------------------
struct Taxi { int x, y, w, h; };
Taxi taxi = { 0, 750, 35, 25 };
int score = 0;

void drawVehicle(int x, int y, float* color) {
    DrawRectangle(x, y, taxi.w, taxi.h, color);
    DrawCircle(x + 5,  y, 7, color);
    DrawCircle(x + 30, y, 7, color);
}

// --- Traffic: data-driven patrol paths (replaces 5 copy-pasted cars) -------
struct Point { float x, y; };
struct Car {
    float x, y;
    vector<Point> path;   // waypoints the car loops through
    size_t target;        // index of the waypoint being approached
    float speed;
};
vector<Car> cars;

void initCars() {
    cars = {
        { 300, 700, { {300,700}, {300,600}, {100,600} },            1, 6  },
        { 400, 410, { {400,410}, {510,410}, {510,650}, {400,650} }, 1, 5  },
        {  50,  50, { {50,50},   {210,50},  {210,350}, {50,350} },  1, 8  },
        { 350, 110, { {350,110}, {700,110} },                       1, 10 },
        { 860, 360, { {860,360}, {960,360}, {960,610}, {860,610} }, 1, 8  },
    };
}

void updateCars() {
    for (Car& c : cars) {
        Point t = c.path[c.target];
        float dx = t.x - c.x, dy = t.y - c.y;
        float dist = sqrt(dx * dx + dy * dy);
        if (dist <= c.speed) {                       // reached the waypoint
            c.x = t.x; c.y = t.y;
            c.target = (c.target + 1) % c.path.size();
        } else {                                     // step towards it
            c.x += c.speed * dx / dist;
            c.y += c.speed * dy / dist;
        }
    }
}

void drawCars() {
    for (const Car& c : cars)
        drawVehicle((int)c.x, (int)c.y, colors[BLUE]);
}

// --- Passengers, each with its own destination (fixes the shared-dest bug) -
struct Passenger {
    int x, y;            // where they wait
    int destX, destY;    // where they want to go
    bool picked;
    bool delivered;
};
vector<Passenger> passengers;
int carrying = -1;       // index of the passenger in the taxi, or -1

void initPassengers() {
    passengers = {
        { 900, 110, 300, 600, false, false },
        { 650, 760, 800, 400, false, false },
        { 400, 360, 150, 300, false, false },
        { 200, 760, 600, 200, false, false },
        { 500, 210, 250, 650, false, false },
    };
}

void drawStickFigure(int x, int y, float* color) {
    DrawLine(x, y,      x,     y + 25, 2, color);
    DrawLine(x, y,      x - 5, y - 10, 2, color);
    DrawLine(x, y,      x + 5, y - 10, 2, color);
    DrawLine(x, y + 13, x + 5, y + 3,  2, color);
    DrawLine(x, y + 13, x - 5, y + 3,  2, color);
    DrawCircle(x, y + 25, 5, color);
}

void drawPassengers() {
    for (const Passenger& p : passengers)
        if (!p.picked && !p.delivered)
            drawStickFigure(p.x, p.y, colors[BLACK]);
}

void drawDestination() {
    if (carrying >= 0) {                             // only the active fare's marker
        const Passenger& p = passengers[carrying];
        DrawSquare(p.destX, p.destY, 20, colors[GREEN]);
    }
}

static bool isNear(int ax, int ay, int bx, int by, int r) {
    return abs(ax - bx) <= r && abs(ay - by) <= r;
}

// Space bar: pick up a nearby passenger, or drop off the one on board.
void pickupOrDropoff() {
    int tx = taxi.x + taxi.w / 2;
    int ty = taxi.y + taxi.h / 2;
    if (carrying == -1) {
        for (size_t i = 0; i < passengers.size(); ++i) {
            Passenger& p = passengers[i];
            if (!p.picked && !p.delivered && isNear(tx, ty, p.x, p.y, 35)) {
                p.picked = true;
                carrying = (int)i;
                break;
            }
        }
    } else {
        Passenger& p = passengers[carrying];
        if (isNear(tx, ty, p.destX, p.destY, 35)) {
            p.delivered = true;
            carrying = -1;
            score += 10;
        }
    }
}

// --- Static world: buildings and obstacles ---------------------------------
int BuildingX[]    = {100,100,150,250,350,450,250,100,150,450,550,350,350,450,450,600,600,900,850,750,750};
int BuildingY[]    = {700,500,400,500,500,700, 50,100,100,450,150,150,300,300,  0,350,500,400, 50,100,300};
int BuildingSize[10][2] = {
    {150,50},{100,50},{50,150},{50,200},{1000,50},
    {50,250},{50,50},{200,50},{50,100},{300,50}
};
int BuildingType[] = {0,1,2,0,3,4,5,2,2,6,2,7,0,8,8,5,7,3,1,3,9};

void drawBuildings() {
    for (int i = 0; i < 21; ++i) {
        int idx = BuildingType[i];
        int w = BuildingSize[idx][0], h = BuildingSize[idx][1];
        DrawRectangle(BuildingX[i], BuildingY[i], w, h, colors[BLACK]);
    }
}

void drawObstacleBox(int x, int y)  { DrawSquare(x, y, 30, colors[BURLY_WOOD]); }
void drawObstacleTree(int x, int y) {
    DrawRectangle(x, y, 10, 70, colors[SADDLE_BROWN]);
    DrawCircle(x + 3, y + 54, 18, colors[GREEN]);
}

// --- Rendering -------------------------------------------------------------
void GameDisplay() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    DrawString(10, 800, "Score= " + to_string(score), colors[CRIMSON]);
    DrawRectangle(0,   780, 150, 10,  colors[BLACK]);
    DrawRectangle(145, 780, 5,   100, colors[BLACK]);

    drawBuildings();

    for (int i = 50;  i <= 100;  i += 50) DrawLine(i, 0, i, 780, 1, colors[BLACK]);
    for (int i = 150; i <= 1000; i += 50) DrawLine(i, 0, i, 850, 1, colors[BLACK]);

    DrawRoundRect(850, 200, 100, 50, colors[BLACK], 20);

    drawObstacleBox(460, 749); drawObstacleBox(260, 299); drawObstacleBox(410, 199);
    drawObstacleBox(660, 549); drawObstacleBox(810, 749);
    drawObstacleTree(470, 499); drawObstacleTree(520, 199);
    drawObstacleTree(820, 349); drawObstacleTree(145, 249);

    drawDestination();
    drawPassengers();
    drawCars();
    drawVehicle(taxi.x, taxi.y, colors[FIREBRICK]);

    glutSwapBuffers();
}

// --- Input -----------------------------------------------------------------
void SpecialKeys(int key, int, int) {
    if (key == GLUT_KEY_LEFT  && taxi.x > 5)   taxi.x -= 10;
    if (key == GLUT_KEY_RIGHT && taxi.x < 985) taxi.x += 10;
    if (key == GLUT_KEY_UP    && taxi.y < 815) taxi.y += 10;
    if (key == GLUT_KEY_DOWN  && taxi.y > 5)   taxi.y -= 10;
    glutPostRedisplay();
}

void Keyboard(unsigned char key, int, int) {
    if (key == 27) exit(0);            // Esc quits
    if (key == 32) pickupOrDropoff();  // Space picks up / drops off
    glutPostRedisplay();
}

void Timer(int) {
    updateCars();
    glutPostRedisplay();
    glutTimerFunc(100, Timer, 0);
}

// --- Entry point -----------------------------------------------------------
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(WIN_W, WIN_H);
    glutCreateWindow("Rush Hour");
    SetCanvasSize(WIN_W, WIN_H);

    initCars();
    initPassengers();

    glutDisplayFunc(GameDisplay);
    glutSpecialFunc(SpecialKeys);
    glutKeyboardFunc(Keyboard);
    glutTimerFunc(100, Timer, 0);

    glutMainLoop();
    return 0;
}
