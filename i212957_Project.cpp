//============================================================================
// Name        : .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include <time.h>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...



/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

int score=0;

int xI = 0, yI = 750;
int width = 35, height = 25;

void drawCar() {
	
	DrawRectangle(xI, yI, width, height, colors[FIREBRICK]);
	DrawCircle(xI+5,yI,7,colors[FIREBRICK]);
	DrawCircle(xI+30,yI,7,colors[FIREBRICK]);
	
	glutPostRedisplay();
}
int xCar1 = 300, yCar1 = 700;
int xCar2 = 400, yCar2 = 410;
int xCar3 = 50, yCar3 = 50;
int xCar4 = 350, yCar4 = 110;
int xCar5 = 860, yCar5 = 360;

void Cars() {

	DrawRectangle(xCar1, yCar1, width, height, colors[BLUE]);
	DrawCircle(xCar1+5,yCar1,7,colors[BLUE]);
	DrawCircle(xCar1+30,yCar1,7,colors[BLUE]);
	
	DrawRectangle(xCar2, yCar2, width, height, colors[BLUE]);
	DrawCircle(xCar2+5,yCar2,7,colors[BLUE]);
	DrawCircle(xCar2+30,yCar2,7,colors[BLUE]);
	
	DrawRectangle(xCar3, yCar3, width, height, colors[BLUE]);
	DrawCircle(xCar3+5,yCar3,7,colors[BLUE]);
	DrawCircle(xCar3+30,yCar3,7,colors[BLUE]);
	
	DrawRectangle(xCar4, yCar4, width, height, colors[BLUE]);
	DrawCircle(xCar4+5,yCar4,7,colors[BLUE]);
	DrawCircle(xCar4+30,yCar4,7,colors[BLUE]);
	
	DrawRectangle(xCar5, yCar5, width, height, colors[BLUE]);
	DrawCircle(xCar5+5,yCar5,7,colors[BLUE]);
	DrawCircle(xCar5+30,yCar5,7,colors[BLUE]);
	
	glutPostRedisplay();
}

int xPassenger1=900,yPassenger1=110;
int xPassenger2=650,yPassenger2=760;
int xPassenger3=400,yPassenger3=360;
int xPassenger4=200,yPassenger4=760;
int xPassenger5=500,yPassenger5=210;


bool passenger1Picked = false;
bool passenger2Picked = false;
bool passenger3Picked = false;
bool passenger4Picked = false;
bool passenger5Picked = false;
void Passengers()
{
	
	//for(int i=0;i<=3;i++,x1+=100,y1+=100)
	if(!passenger1Picked)
	{
	DrawLine( xPassenger1 , yPassenger1 , xPassenger1  , yPassenger1+25 , 2 , colors[BLACK] );
	DrawLine( xPassenger1 , yPassenger1 , xPassenger1-5  , yPassenger1-10 , 2 , colors[BLACK] );
	DrawLine( xPassenger1 , yPassenger1 , xPassenger1+5  , yPassenger1-10 , 2 , colors[BLACK] );
	DrawLine( xPassenger1 , yPassenger1+13 , xPassenger1+5  , yPassenger1+3 , 2 , colors[BLACK] );
	DrawLine( xPassenger1 , yPassenger1+13 , xPassenger1-5  , yPassenger1+3 , 2 , colors[BLACK] );
	DrawCircle(xPassenger1,yPassenger1+25,5,colors[BLACK]);
	}
	
	if(!passenger2Picked)
	{
	DrawLine( xPassenger2 , yPassenger2 , xPassenger2  , yPassenger2+25 , 2 , colors[BLACK] );
	DrawLine( xPassenger2 , yPassenger2 , xPassenger2-5  , yPassenger2-10 , 2 , colors[BLACK] );
	DrawLine( xPassenger2 , yPassenger2 , xPassenger2+5  , yPassenger2-10 , 2 , colors[BLACK] );
	DrawLine( xPassenger2 , yPassenger2+13 , xPassenger2+5  , yPassenger2+3 , 2 , colors[BLACK] );
	DrawLine( xPassenger2 , yPassenger2+13 , xPassenger2-5  , yPassenger2+3 , 2 , colors[BLACK] );
	DrawCircle(xPassenger2,yPassenger2+25,5,colors[BLACK]);
	}
	
	if(!passenger3Picked)
	{
	DrawLine( xPassenger3 , yPassenger3 , xPassenger3  , yPassenger3+25 , 2 , colors[BLACK] );
	DrawLine( xPassenger3 , yPassenger3 , xPassenger3-5  , yPassenger3-10 , 2 , colors[BLACK] );
	DrawLine( xPassenger3 , yPassenger3 , xPassenger3+5  , yPassenger3-10 , 2 , colors[BLACK] );
	DrawLine( xPassenger3 , yPassenger3+13 , xPassenger3+5  , yPassenger3+3 , 2 , colors[BLACK] );
	DrawLine( xPassenger3 , yPassenger3+13 , xPassenger3-5  , yPassenger3+3 , 2 , colors[BLACK] );
	DrawCircle(xPassenger3,yPassenger3+25,5,colors[BLACK]);
	}
	
	if(!passenger4Picked)
	{
	DrawLine( xPassenger4 , yPassenger4 , xPassenger4  , yPassenger4+25 , 2 , colors[BLACK] );
	DrawLine( xPassenger4 , yPassenger4 , xPassenger4-5  , yPassenger4-10 , 2 , colors[BLACK] );
	DrawLine( xPassenger4 , yPassenger4 , xPassenger4+5  , yPassenger4-10 , 2 , colors[BLACK] );
	DrawLine( xPassenger4 , yPassenger4+13 , xPassenger4+5  , yPassenger4+3 , 2 , colors[BLACK] );
	DrawLine( xPassenger4 , yPassenger4+13 , xPassenger4-5  , yPassenger4+3 , 2 , colors[BLACK] );
	DrawCircle(xPassenger4,yPassenger4+25,5,colors[BLACK]);
	}
	
	if(!passenger5Picked)
	{
	DrawLine( xPassenger5 , yPassenger5 , xPassenger5  , yPassenger5+25 , 2 , colors[BLACK] );
	DrawLine( xPassenger5 , yPassenger5 , xPassenger5-5  , yPassenger5-10 , 2 , colors[BLACK] );
	DrawLine( xPassenger5 , yPassenger5 , xPassenger5+5  , yPassenger5-10 , 2 , colors[BLACK] );
	DrawLine( xPassenger5 , yPassenger5+13 , xPassenger5+5  , yPassenger5+3 , 2 , colors[BLACK] );
	DrawLine( xPassenger5 , yPassenger5+13 , xPassenger5-5  , yPassenger5+3 , 2 , colors[BLACK] );
	DrawCircle(xPassenger5,yPassenger5+25,5,colors[BLACK]);
	}
	
}


int xDest1=300,yDest1=600;
bool Destination1Flg = false;
bool Destination2Flg = false;
bool Destination3Flg = false;
bool Destination4Flg = false;
bool Destination5Flg = false;
void Destination()
{
	if(Destination1Flg)
		DrawSquare(xDest1, yDest1, 20, colors[GREEN]);
	
	
	if(Destination2Flg)
		DrawSquare(xDest1, yDest1, 20, colors[GREEN]);
	
	
	if(Destination3Flg)
		DrawSquare(xDest1, yDest1, 20, colors[GREEN]);
	
	
	if(Destination3Flg)
		DrawSquare(xDest1, yDest1, 20, colors[GREEN]);
	
	
	if(Destination3Flg)
		DrawSquare(xDest1, yDest1, 20, colors[GREEN]);
}

void ObstacleBox(int X,int Y)
{	
	DrawSquare(X, Y, 30, colors[BURLY_WOOD]);
	
}

void ObstacleTree(int X,int Y)
{	
	DrawRectangle(X, Y, 10, 70, colors[SADDLE_BROWN]);
	DrawCircle(X+3,Y+54,18,colors[GREEN]);
}

int BuildingXArray[] = {100,100,150,250,350,450,250,100,150,450,550,350,350,450,450,600,600,900,850,750,750};
int BuildingYArray[] = {700,500,400,500,500,700,50,100,100,450,150,150,300,300,0,350,500,400,50,100,300};
int BuildingObjectArray[10][2] = 
	{	
		{150,50},{100,50},{50,150},{50,200},{1000,50},
		{50,250},{50,50},{200,50},{50,100},{300,50}
	};
int BuildingObstacleTypeArray[] = {0,1,2,0,3,4,5,2,2,6,2,7,0,8,8,5,7,3,1,3,9};

void Buildings()
{
	for(int i=0;i<21;i++)
	{	
		int idx = BuildingObstacleTypeArray[i];	
		int height = BuildingObjectArray[idx][1] ,width = BuildingObjectArray[idx][0];
		
		DrawRectangle(BuildingXArray[i], BuildingYArray[i], width, height, colors[BLACK]);
	}

}

bool car1flag = true;
void moveCar1() 
{
	if (yCar1 > 600 && car1flag) {
		yCar1 -= 15;
	}
	else if (xCar1 < 350 && car1flag) {
		xCar1 -= 15;
		if (xCar1 <= 100)
			car1flag = false;
	}
	
	else if (xCar1 < 300 && !car1flag) {
		xCar1 += 15;		
	}
	else if (yCar1 < 700 && !car1flag) {
		yCar1 += 15;
		if (yCar1 >= 700)
			car1flag=true;
	}
}

bool car2flag1 = true;
bool car2flag2 = false;
void moveCar2()
{
	if (xCar2 > 350 && car2flag1) {
		xCar2 += 10;
		if(xCar2 >= 510)
			car2flag1 = false;

	}
	else if (yCar2 <= 650 && !car2flag2) {
		yCar2 += 10;
	}
	else if (xCar2 >= 420 && !car2flag1) {
		xCar2 -= 10;
		if(xCar2 <= 420)	
			car2flag2 = true;
	}
	else if (xCar2 <= 420 && car2flag2) 
	{
		yCar2 -= 10;
		if(yCar2 < 420){
			car2flag1 = true;
			car2flag2 = false;}	
	}
}	

bool car3flag1 = true;
bool car3flag2 = false;
void moveCar3()
{
	
	if (xCar3 > 0 && car3flag1) {
		xCar3 += 20;
		if(xCar3 >= 210)
			car3flag1 = false;

	}
	else if (yCar3 <= 350 && !car3flag2) {
		yCar3 += 20;
	}
	else if (xCar3 > 50 && !car3flag1) {
		xCar3 -= 20;
		if(xCar3 <= 60)	
			car3flag2 = true;
	}
	else if (xCar3 <= 60 && car3flag2) 
	{
		yCar3 -= 20;
		if(yCar3 <= 50){
			car3flag1 = true;
			car3flag2 = false;}	
	}	
}

bool car4flag = true;
void moveCar4() 
{
	if (xCar4 > 300 && car4flag) {
		xCar4 += 25;
		if(xCar4 >=700)
			car4flag = false;
	}
	else if (xCar4 >= 350 && !car4flag) {
		xCar4 -= 25;
		if (xCar4 <= 350)
			car4flag = true;
	}
}


bool car5flag1 = true;
bool car5flag2 = false;
void moveCar5()
{
	if (xCar5 > 800 && car5flag1) {
		xCar5 += 20;
		if(xCar5 >= 960)
			car5flag1 = false;

	}
	else if (yCar5 < 610 && !car5flag2) {
		yCar5 += 20;
	}
	else if (xCar5 > 860 && !car5flag1) {
		xCar5 -= 20;
		if(xCar5 <= 870)	
			car5flag2 = true;
	}
	else if (yCar5 >= 370 && car5flag2) 
	{
		yCar5 -= 20;
		if(yCar5 <= 370){
			car5flag1 = true;
			car5flag2 = false;}	
	}
}	


/*
 * Main Canvas drawing function.
 * */

void GameDisplay()/**/
{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//For Score
	string StringScore="Score= "+to_string(score);
	//Display Score
	DrawString( 10, 800, StringScore , colors[CRIMSON]);
	DrawRectangle(0,780 ,150 ,10 , colors[BLACK]);
	DrawRectangle(145, 780, 5, 100, colors[BLACK]);
	
	//Draws Buildings	
	Buildings();
		
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	for(int i=50;i<=100;i=i+50)
		DrawLine( i , 0 ,  i , 780 , 1 , colors[BLACK] );
	
	for(int i=150;i<=1000;i = i+50)
		DrawLine( i , 0 ,  i , 850 , 1 , colors[BLACK] );
	
	//Draws Round about
	DrawRoundRect(850,200,100,50,colors[BLACK],20);	
	
	//Display Destination only if Passenger picked
	if(passenger1Picked)
	{
		Destination();
		Destination1Flg = true;
	}
	if(passenger2Picked)
	{
		Destination();
		Destination2Flg = true;
	}
	if(passenger3Picked)
	{
		Destination();
		Destination3Flg = true;
	}
	if(passenger4Picked)
	{
		Destination();
		Destination4Flg = true;
	}
	if(passenger5Picked)
	{
		Destination();
		Destination5Flg = true;
	}
		
	int count=0;
	
	ObstacleBox(460,749);	
	ObstacleBox(260,299);
	ObstacleBox(410,199);
	ObstacleBox(660,549);
	ObstacleBox(810,749);
	ObstacleTree(470,499);
	ObstacleTree(520,199);
	ObstacleTree(820,349);
	ObstacleTree(145,249);	
		
	Passengers();
	
	Cars();
	
	drawCar();
	
	glutSwapBuffers(); // do not modify this line..

}



/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) 
	{
		if(xI>5)
			xI -= 10;
	} 
	
	else if (key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) 
	{
		if(xI<985)
			xI += 10;
	} 
	
	else if (key == GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) 
	{
		if(yI<815)
			yI += 10;
	}

	else if (key == GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) 
	{
		if(yI>5)
			yI -= 10;
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		cout << "b pressed" << endl;
	}
	
	
	
	if(key == 32 ) //Spacebar
	{  
		if(xI + width >= xPassenger1-10-5 && xI <= xPassenger1+5+10)
		{
			glutPostRedisplay();
			passenger1Picked=true;
		}
		if(xI + width >= xDest1-10 && xI <= xDest1+20+10)
		{
			Destination1Flg = true;
			glutPostRedisplay();
			
		}
		
				
		if(xI + width >= xPassenger2-10-5 && xI <= xPassenger2+5+10)
		{
			glutPostRedisplay();
			passenger2Picked=true;
		}
		if(xI + width >= xDest1-10 && xI <= xDest1+20+10)
		{
			Destination2Flg=true;
			glutPostRedisplay();
		}
		
		
		if(xI + width >= xPassenger3-10-5 && xI <= xPassenger3+5+10)
		{
			glutPostRedisplay();
			passenger3Picked=true;
		}
		if(xI + width >= xDest1-10 && xI <= xDest1+20+10)
		{
			Destination3Flg=true;
			glutPostRedisplay();
		}
			
			
		if(xI + width >= xPassenger4-10-5 && xI <= xPassenger4+5+10)
		{
			glutPostRedisplay();
			passenger4Picked=true;
		}
		if(xI + width >= xDest1-10 && xI <= xDest1+20+10)
		{
			Destination4Flg=true;
			glutPostRedisplay();
		}
			
			
		if(xI + width >= xPassenger5-10-5 && xI <= xPassenger5+5+10)
		{
			glutPostRedisplay();
			passenger5Picked=true;
		}
		if(xI + width >= xDest1-10 && xI <= xDest1+20+10)
		{
			Destination5Flg=true;
			glutPostRedisplay();
		}
	}
		
	
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	moveCar1();
	moveCar2();
	moveCar3();
	moveCar4();
	moveCar5();

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		//cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			//cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
 
int main(int argc, char*argv[]) {

	int width = 1020, height = 840; // i have set my window size to be 800 x 600

	srand (time(NULL));
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	
	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */

