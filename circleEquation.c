#ifdef _WIN32
	#include <windows.h>
	#include <math.h>
#else
	#include <stdio.h>
	#include <math.h>
#endif

int circleDrawerEqu(int, int , int, int);

int main(int argc, char *argv[]) {
	int radius = 5;
	int a = 0, b = 0;
	#ifdef _WIN32		// check whether you are on windows or not
		while(1) {
			for(int y = 10; y > -10; y--) {
				for(int x = -10; x < 10; x++) {
					if(circleDrawerEqu(x, y, a, b) == radius) {
						printf(".");
					} else {
						printf(" ");
					}
				}
				printf("\n");
			}
			system("cls");
			if(GetAsyncKeyState(VK_UP)) {
				b++;
			} else if(GetAsyncKeyState(VK_DOWN)) {
				b--;
			} else if(GetAsyncKeyState(VK_LEFT)) {
				a--;
			} else if(GetAsyncKeyState(VK_RIGH)) {
				a++;
			}

			if(a >= 10) {
				a = -10;
			} else if(a <= -10) {
				a = 10;
			} else if(b >= 10) {
				b = -10;
			} else if(b <= -10) {
				b = 10;
			}
		}
	#else
		while(1) {
			for(int y = 10; y > -10; y--) {
				for(int x = -10; x < 10; x++) {
					if(circleDrawerEqu(x, y, a, b) == radius) {
						printf(".");
					} else {
						printf(" ");
					}
				}
				printf("\n");
}
			system("clear");
		}
	#endif
}


int circleDrawerEqu(int x, int y, int a, int b) {
	// (x-a)^2 + (y-b)^2 = r^	where a and b are the center of the circle
	return sqrt(pow((x-a), 2) + pow((y-b), 2));
}
