

#include <iostream>
#include <iomanip>
#include <stdlib.h> 

using namespace std;

const unsigned int DIM1 = 30; //vertical
const unsigned int DIM2 = 40;  //horizontal

char screen[DIM1][DIM2];

void fill(char ary[30][40]) {
	for (int i = 0; i < DIM1; i++) {
			for (int j = 0; j < DIM2; j++) {
				if (j == 0 || j==39) {
					ary[i][j] = '|';
				}
				else if (i == 0 || i == 29) {
					ary[i][j] = '~';
				}
				else {
					ary[i][j] = ' ';
				}
				
			}
		}
}

void output(char ary[30][40]) {
	for (int i = 0; i < DIM1; i++) {
		for (int j = 0; j < DIM2; j++) {
			cout << ary[i][j];
		}
		cout << endl;
	}
}

int bumps(int xpos, int ypos, int dir) {
	//~~~~~~~~~~~~~~~~~~~VERTICAL~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	if (ypos == 1 && dir == 1) {
		dir = 5;
	}
	if (ypos == 1 && dir == 2) {
		dir = 4;
	}
	if (ypos == 1 && dir == 8) {
		dir = 6;
	}
	if (ypos == 28 && dir == 5) {
		dir = 1;
	}
	if (ypos == 28 && dir == 4) {
		dir = 2;
	}if (ypos == 28 && dir == 6) {
		dir = 8;
	}
	//~~~~~~~~~~~~~~~~~~HORIZONTAL~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	if (xpos == 1 && dir == 7) {
		dir = 3;
	}
	if (xpos == 1 && dir == 8) {
		dir = 2;
	}if (xpos == 1 && dir == 6) {
		dir = 4;
	}
	if (xpos == 38 && dir == 3) {
		dir = 7;
	}
	if (xpos == 38 && dir == 2) {
		dir = 8;
	}if (xpos == 38 && dir == 4) {
		dir = 6;
	}
	return dir;
}

void move(int xpos, int ypos, int dir, char screen[30][40]) {
	for (int i = 0; i < 1000; i++) {
		system("cls");
		dir=bumps(xpos, ypos, dir);
		switch (dir) {
			case 1:
				ypos -= 1;
			break;
			case 2:
				ypos -= 1;
				xpos += 1;
			break;
			case 3:
				xpos += 1;
			break;
			case 4:
				ypos += 1;
				xpos += 1;
			break;
			case 5:
				ypos += 1;
			break;
			case 6:
				ypos += 1;
				xpos -= 1;
			break;
			case 7:
				xpos -= 1;
			break;
			case 8:
				xpos -= 1;
				ypos -= 1;
			break;
		}
		screen[ypos][xpos] = 'o';
		output(screen);
		screen[ypos][xpos] = ' ';
		
		cout << xpos << " " << ypos <<" "<<i<< endl;

	}
}

int main() {

	fill(screen);
	output(screen);
	int xpos=15, ypos=20;
	int dir= rand() % 8 + 1;
	move(xpos, ypos, dir, screen);
	return 0;
}







