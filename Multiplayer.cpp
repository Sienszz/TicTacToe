#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
char map[13][26];
int CursorX = 4, CursorY = 2;
int coorX= 0, coorY= 0;
void Hide(){
    printf("\e[?25l");
    COORD Curp;
    Curp.X = 0;
    Curp.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Curp);
}
void gotoxy(int x, int y){
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    dwCursorPosition.X = x;
    dwCursorPosition.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}
void printmap(int turn){
	gotoxy(0,1);
	if(turn%2 == 1){
		puts("\033[0;32m					    _____  _                         __         ");
		puts("					   |  __ \\| |                       /_ |       ");
		puts("					   | |__) | | __ _ _   _  ___ _ __   | |         ");
		puts("					   |  ___/| |/ _` | | | |/ _ \\ '__|  | |      ");
		puts("					   | |    | | (_| | |_| |  __/ |     | |       ");
		puts("					   |_|    |_|\\__,_|\\__, |\\___|_|     |_|      ");
		puts("					                    __/ |                      ");
		puts("					                   |___/                      ");
	}else{
		puts("\033[0;31m					    _____  _                         ___  ");
		puts("					   |  __ \\| |                       |__ \\ ");
		puts("					   | |__) | | __ _ _   _  ___ _ __     ) |");
		puts("					   |  ___/| |/ _` | | | |/ _ \\ '__|   / / ");
		puts("					   | |    | | (_| | |_| |  __/ |     / /_ ");
		puts("					   |_|    |_|\\__,_|\\__, |\\___|_|    |____|");
		puts("					                    __/ |               ");
		puts("					                   |___/                ");
	}
	puts("						  _____                 ");
	puts("						 |_   _|   _ _ __ _ __  ");
	puts("						   | || | | | '__| '_ \\ ");
	puts("						   | || |_| | |  | | | |");
	puts("						   |_| \\__,_|_|  |_| |_|");
	for(int i = 0;i<13;i++){
		gotoxy(49,16+i);
		printf("\033[0;37m%s\n", map[i]);
	}
}
void newmap(){
	map[0][0] = 201;
	for(int i = 1;i<24;i++){
		if(i%8 == 0){
			map[0][i] = 209;
		}else{
			map[0][i] = 205;
		}
	}
	map[0][24] = 187;
	for(int i = 0;i<8;i+=4){
		for(int j = 1+i;j<4+i;j++){
			map[j][0] = 186;
			for(int k = 1;k<24;k++){
				if(k%8 == 0){
					map[j][k] = 179;
				}else{
					map[j][k] = 32;
				}
			}
			map[j][24] = 186;	
		}
		map[4+i][0] = 186;
		for(int j = 1;j<24;j++){
			if(j%8 == 0){
				map[4+i][j] = 197;
			}else{
				map[4+i][j] = 196;
			}
		}
		map[4+i][24] = 186;
	}
	for(int j = 9;j<12;j++){
		map[j][0] = 186;
		for(int k = 1;k<24;k++){
			if(k%8 == 0){
				map[j][k] = 179;
			}else{
				map[j][k] = 32;
			}
		}
		map[j][24] = 186;	
	}
	map[12][0] = 200;
	for(int i = 1;i<24;i++){
		if(i%8 == 0){
			map[12][i] = 207;
		}else{
			map[12][i] = 205;
		}
	}
	map[12][24] = 188;
	map[CursorY+1][CursorX] = '^';
}
int movefunc(int turn){
	char key;
	if(kbhit()){
		key = getch();
		if(key == 72 && CursorY != 2){
			map[CursorY+1][CursorX] = ' ';
			CursorY-=4;
			coorY--;
			map[CursorY+1][CursorX] = '^';
		}else if(key == 80 && CursorY != 10){
			map[CursorY+1][CursorX] = ' ';
			CursorY+=4;
			map[CursorY+1][CursorX] = '^';
			coorY++;
		}else if(key == 75 && CursorX != 4){
			map[CursorY+1][CursorX] = ' ';
			CursorX-=8;
			map[CursorY+1][CursorX] = '^';
			coorX--;
		}else if(key == 77 && CursorX != 20){
			map[CursorY+1][CursorX] = ' ';
			CursorX+=8;
			map[CursorY+1][CursorX] = '^';
			coorX++;
		}else if(key == 13){
			if(turn%2 == 1 && map[CursorY][CursorX] == ' '){
				map[CursorY][CursorX] = 'X';
				turn++;
			}else if(turn%2 == 0 && map[CursorY][CursorX] == ' '){
				map[CursorY][CursorX] = 'O';
				turn++;
			}
		}
	}
	return turn;
}
int winvalidation(int vertical, int horizontal,int diagonal){
	int value = 0;
	if(vertical!=0){
		if(map[2][CursorX] == map[6][CursorX] && map[2][CursorX] == map[10][CursorX]){
			map[2][CursorX] == 88? value =1 :value = 2;
			return value;
		}else{
			return -1;
		}
	}else if(horizontal !=0){
		if(map[CursorY][4] == map[CursorY][12] && map[CursorY][4] == map[CursorY][20]){
			map[CursorY][4] == 88? value =1 :value = 2;
			return value;
		}else{
			return -1;
		}
	}else{
		if(diagonal == 1 && map[2][4] == map[6][12] && map[2][4] == map[10][20]){
			map[6][12] == 88? value =1 :value = 2;
			return value;	
		}else if(diagonal ==2 && map[2][20] == map[6][12] && map[2][20] == map[10][4]){
			map[6][12] == 88? value =1 :value = 2;
			return value;	
		}else{
			return -1;
		}
	}
}
void printwin(int win){
	system("cls");
	if(win == 0){
		gotoxy(0,10);
		puts("					       ________  ______  ________ ");
		puts("					      |        \\|      \\|        \\");
		puts("					       \\$$$$$$$$ \\$$$$$$| $$$$$$$$");
		puts("					         | $$     | $$  | $$__    ");
		puts("					         | $$     | $$  | $$  \\   ");
		puts("					         | $$     | $$  | $$$$$   ");
		puts("					         | $$    _| $$_ | $$_____ ");
		puts("					         | $$   |   $$ \\| $$     \\");
		puts("					          \\$$    \\$$$$$$ \\$$$$$$$$");
	}else{
		gotoxy(0,6);
		if(win == 1){
			puts("					    _____  _                         __         ");
			puts("					   |  __ \\| |                       /_ |       ");
			puts("					   | |__) | | __ _ _   _  ___ _ __   | |         ");
			puts("					   |  ___/| |/ _` | | | |/ _ \\ '__|  | |      ");
			puts("					   | |    | | (_| | |_| |  __/ |     | |       ");
			puts("					   |_|    |_|\\__,_|\\__, |\\___|_|     |_|      ");
			puts("					                    __/ |                      ");
			puts("					                   |___/                      ");
		}else if(win == 2){
			puts("					    _____  _                         ___  ");
			puts("					   |  __ \\| |                       |__ \\ ");
			puts("					   | |__) | | __ _ _   _  ___ _ __     ) |");
			puts("					   |  ___/| |/ _` | | | |/ _ \\ '__|   / / ");
			puts("					   | |    | | (_| | |_| |  __/ |     / /_ ");
			puts("					   |_|    |_|\\__,_|\\__, |\\___|_|    |____|");
			puts("					                    __/ |               ");
			puts("					                   |___/                ");
		}
		puts("					       __       __  ______  __    __ ");
		puts("					      |  \\  _  |  \\|      \\|  \\  |  \\");
		puts("					      | $$ / \\ | $$ \\$$$$$$| $$\\ | $$");
		puts("					      | $$/  $\\| $$  | $$  | $$$\\| $$");
		puts("					      | $$  $$$\\ $$  | $$  | $$$$\\ $$");
		puts("					      | $$ $$\\$$\\$$  | $$  | $$\\$$ $$");
		puts("					      | $$$$  \\$$$$ _| $$_ | $$ \\$$$$");
		puts("					      | $$$    \\$$$|   $$ \\| $$  \\$$$");
		puts("					       \\$$      \\$$ \\$$$$$$ \\$$   \\$$");
		}
	getchar();
}
void play(){
	int verticalfill[3] = {0}, horizontalfill[3] = {0};
	int diagonal[2] = {0};
	system("cls");
	int turn = 1;
	int win = -1;
	do{
		Hide();
		printf("%d %d", CursorX, CursorY);
		int move = movefunc(turn);
		printmap(turn);
		if(move != turn){
			turn = move;
			verticalfill[coorX] ++;
			horizontalfill[coorY]++;
			if(coorX == 1 && coorY == 1){
				diagonal[0]++;
				diagonal[1]++;
			}else if(coorX == coorY){
				diagonal[0]++;
			}else if((coorX == 0 && coorY==2) || (coorX == 2 && coorY == 0)){
				diagonal[1]++;
			}
			if(verticalfill[coorX] == 3 && win == -1){
				win = winvalidation(coorX+1,0,0);
			}
			if(horizontalfill[coorY] == 3 && win == -1){
				win = winvalidation(0,coorY+1,0);
			}
			if(diagonal[0] == 3 && win == -1){
				win = winvalidation(0,0,1);
			}else if(diagonal[1] == 3 && win == -1){
				win = winvalidation(0,0,2);
			}
			if(win != -1){
				printwin(win);
				return;
			}
		}
	}while(turn !=10);
	printwin(0);
}
int main(){
		newmap();
		play();
		system("cls");
	return 0;
}
