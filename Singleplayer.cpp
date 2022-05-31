#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
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
void printmap(int turn, int playerturn){
	gotoxy(0,1);
	if(turn%2 == playerturn%2){
		puts("\033[0;32m					       _____  _                                  ");
		puts("					      |  __ \\| |                              ");
		puts("					      | |__) | | __ _ _   _  ___ _ __            ");
		puts("					      |  ___/| |/ _` | | | |/ _ \\ '__|        ");
		puts("					      | |    | | (_| | |_| |  __/ |            ");
		puts("					      |_|    |_|\\__,_|\\__, |\\___|_|           ");
		puts("					                       __/ |                      ");
		puts("					                      |___/                      ");
	}else{
		puts("\033[0;31m 					           ____   ____ _______         				   ");
		puts(" 					          |  _ \\ / __ \\__   __|       				   ");
		puts(" 					          | |_) | |  | | | |          				   ");
		puts(" 					          |  _ <| |  | | | |           				   ");
		puts(" 					          | |_) | |__| | | |          				   ");
		puts(" 					          |____/ \\____/  |_|          				   ");
		puts(" 					                                          ");
		puts(" 					                                          ");
	}
	puts("						  _____                 ");
	puts("						 |_   _|   _ _ __ _ __  ");
	puts("						   | || | | | '__| '_ \\ ");
	puts("						   | || |_| | |  | | | |");
	puts("						   |_| \\__,_|_|  |_| |_|");
	if(turn%2 != playerturn%2)Sleep(1000);
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
int botmove(int turn, int difficult, char BotKey, char PlayerKey){
	int cursorCoor[3] = {2,6,10};
	srand(time(0));
	int botX;
	int botY;
	int flag = 0;
	map[CursorY+1][CursorX] = ' ';
	if(difficult == 1){	
		do{
			botX = rand()%3;
			botY = rand()%3;
		}while(map[cursorCoor[botY]][cursorCoor[botX]*2] !=' ');
		map[cursorCoor[botY]][cursorCoor[botX]*2] = BotKey;
		coorX = botX;
		coorY = botY;
		CursorY= cursorCoor[botY];
		CursorX= cursorCoor[botX]*2;
		map[cursorCoor[botY]+1][cursorCoor[botX]*2] = '^';
		return turn+=1; 
	}
	else if(difficult == 2){
		for(int i = 0;i<3;i++){
			for(int j = 0;j<2;j++){
				if(map[cursorCoor[i]][cursorCoor[j]*2] == PlayerKey){
					if(j == 0 && map[cursorCoor[i]][cursorCoor[j+2]*2] == PlayerKey ){ // vertical
						if(map[cursorCoor[i]][cursorCoor[j+1]*2] == ' '){
							botX = j+1;
							botY = i;
							flag = 1;
							break;
						}
					} 
					else if(map[cursorCoor[i]][cursorCoor[j+1]*2] == PlayerKey){
						if(j == 0){
							if(map[cursorCoor[i]][cursorCoor[j+2]*2] == ' '){
								botX = j+2;
								botY = i;
								flag = 1;
							}
						}else{
							if(map[cursorCoor[i]][cursorCoor[j-1]*2] == ' '){
								botX = j-1;
								botY = i;
								flag = 1;
							}
						}
					}
				}
				if(map[cursorCoor[j]][cursorCoor[i]*2] == PlayerKey){
					if(j == 0 && map[cursorCoor[j+2]][cursorCoor[i]*2] == PlayerKey){ // horizontal
						if(map[cursorCoor[j+1]][cursorCoor[i]*2] == ' '){
							botX = i;
							botY =j+1;
							flag = 1;
						}
					}else if(map[cursorCoor[j+1]][cursorCoor[i]*2] == PlayerKey){
						if(j == 0){
							if(map[cursorCoor[j+2]][cursorCoor[i]*2] == ' '){
								botX = i;
								botY =j+2;
								flag = 1;
							}
						}else{
							if(map[cursorCoor[j-1]][cursorCoor[i]*2] == ' '){
								botX = i;
								botY =j-1;
								flag = 1;
							}
						}
					}
				}
				if(i == j && map[cursorCoor[i]][cursorCoor[j]*2] == PlayerKey){
					if(i == 1){
						if(map[cursorCoor[i-1]][cursorCoor[j-1]*2] == PlayerKey){
							if(map[cursorCoor[i+1]][cursorCoor[j+1]*2] == ' '){	
								botX = i+1;
								botY = j+1;
								flag = 1;
							}
						}else if(map[cursorCoor[i+1]][cursorCoor[j+1]*2] == PlayerKey){
							if(map[cursorCoor[i-1]][cursorCoor[j-1]*2] == ' '){
								botX = i-1;
								botY = j-1;
								flag = 1;
							}
						}else if(map[cursorCoor[0]][cursorCoor[2]*2] == PlayerKey){
							if(map[cursorCoor[2]][cursorCoor[0]*2] == ' '){
								botX = 0;
								botY = 2;
								flag = 1;
							}	
						}else if(map[cursorCoor[2]][cursorCoor[0]*2] == PlayerKey){
							if(map[cursorCoor[0]][cursorCoor[2]*2] == ' '){
								botX = 2;
								botY = 0;
								flag = 1;
							}
						}
					}else{
						if(map[cursorCoor[i+1]][cursorCoor[j+1]*2] == PlayerKey){
							if(map[cursorCoor[i+2]][cursorCoor[j+2]*2] == ' '){
								botX = j+2;
								botY = i+2;
								flag = 1;
							}
						}else if(map[cursorCoor[i+2]][cursorCoor[j+2]*2] == PlayerKey){
							if(map[cursorCoor[i+1]][cursorCoor[j+1]*2] == ' '){
								botX = j+1;
								botY = i+1;
								flag = 1;
							}
						}
					}
				}else if(i == 2 && j == 0 && map[cursorCoor[i]][cursorCoor[j]*2] == PlayerKey){
					if(map[cursorCoor[1]][cursorCoor[1]*2] == PlayerKey){
						if(map[cursorCoor[j]][cursorCoor[i]*2] == ' '){
							botX = i;
							botY = j;
							flag = 1;
						}
					}else if(map[cursorCoor[j]][cursorCoor[i]*2] == PlayerKey){
						if(map[cursorCoor[1]][cursorCoor[1]*2] == ' '){
							botX = 1;
							botY = 1;
							flag = 1;
						}
					}
				}
			}
			if(flag == 1){
				break;
			}
		}
		
		
		if(flag == 0){
			return turn = botmove(turn,1, BotKey, PlayerKey);
		}else{
			map[cursorCoor[botY]][cursorCoor[botX]*2] = BotKey;
			coorX = botX;
			coorY = botY;
			CursorY= cursorCoor[botY];
			CursorX= cursorCoor[botX]*2;
			map[cursorCoor[botY]+1][cursorCoor[botX]*2] = '^';
			return turn+=1; 
		}
	}
	else if(difficult == 3){
		if(turn != 1){
			for(int i = 0;i<3;i++){
				for(int j = 0;j<2;j++){
					if(map[cursorCoor[i]][cursorCoor[j]*2] == BotKey){
						if(j == 0 && map[cursorCoor[i]][cursorCoor[j+2]*2] == BotKey){ // vertical
							if(map[cursorCoor[i]][cursorCoor[j+1]*2] == ' '){
								botX = j+1;
								botY = i;
								flag = 1;
								break;
							}
						}
						else if(map[cursorCoor[i]][cursorCoor[j+1]*2] == BotKey){
							if(j == 0){
								if(map[cursorCoor[i]][cursorCoor[j+2]*2] == ' '){
									botX = j+2;
									botY = i;
									flag = 1;
								}
							}else{
								if(map[cursorCoor[i]][cursorCoor[j-1]*2] == ' '){
									botX = j-1;
									botY = i;
									flag = 1;
								}
							}
						}
					}
					if(map[cursorCoor[j]*2][cursorCoor[i]] == BotKey){
						if(j == 0 && map[cursorCoor[j+2]][cursorCoor[i]*2] == BotKey){ // horizontal
							if(map[cursorCoor[j+1]][cursorCoor[i]*2] == ' '){
								botX = i;
								botY =j+1;
								flag = 1;
							}
						}
						else if(map[cursorCoor[j+1]][cursorCoor[i]*2] == BotKey){
							if(j == 0){
								if(map[cursorCoor[j+2]][cursorCoor[i]*2] == ' '){
									botX = i;
									botY =j+2;
									flag = 1;
								}
							}else{
								if(map[cursorCoor[j-1]][cursorCoor[i]*2] == ' '){
									botX = i;
									botY =j-1;
									flag = 1;
								}
							}
						}
					}
					if(i == j && map[cursorCoor[i]][cursorCoor[j]*2] == BotKey){ // diagonal
						if(i == 1){
							if(map[cursorCoor[i-1]][cursorCoor[j-1]*2] == BotKey){
								if(map[cursorCoor[i+1]][cursorCoor[j+1]*2] == ' '){	
									botX = i+1;
									botY = j+1;
									flag = 1;
								}
							}else if(map[cursorCoor[i+1]][cursorCoor[j+1]*2] == BotKey){
								if(map[cursorCoor[i-1]][cursorCoor[j-1]*2] == ' '){
									botX = i-1;
									botY = j-1;
									flag = 1;
								}
							}else if(map[cursorCoor[0]][cursorCoor[2]*2] == BotKey){
								if(map[cursorCoor[2]][cursorCoor[0]*2] == ' '){
									botX = 0;
									botY = 2;
									flag = 1;
								}	
							}else if(map[cursorCoor[2]][cursorCoor[0]*2] == BotKey){
								if(map[cursorCoor[0]][cursorCoor[2]*2] == ' '){
									botX = 2;
									botY = 0;
									flag = 1;
								}
							}
						}else{
							if(map[cursorCoor[i+1]][cursorCoor[j+1]*2] == BotKey){
								if(map[cursorCoor[i+2]][cursorCoor[j+2]*2] == ' '){
									botX = j+2;
									botY = i+2;
									flag = 1;
								}
							}else if(map[cursorCoor[i+2]][cursorCoor[j+2]*2] == BotKey){
								if(map[cursorCoor[i+1]][cursorCoor[j+1]*2] == ' '){
									botX = j+1;
									botY = i+1;
									flag = 1;
								}
							}
						}
					}else if(i == 2 && j == 0 && map[cursorCoor[i]][cursorCoor[j]*2] == BotKey){
						if(map[cursorCoor[1]][cursorCoor[1]*2] == BotKey){
							if(map[cursorCoor[j]][cursorCoor[i]*2] == ' '){
								botX = i;
								botY = j;
								flag = 1;
							}
							
						}else if(map[cursorCoor[j]][cursorCoor[i]*2] == BotKey){
							if(map[cursorCoor[1]][cursorCoor[1]*2] == ' '){
								botX = 1;
								botY = 1;
								flag = 1;
							}
						}
					}
				}
				if(flag == 1){
					break;
				}
			}
		}else{
			botX = 1;
			botY = 1;
			flag = 1;
		}
		
		
		if(flag == 0){
			return turn = botmove(turn,2, BotKey, PlayerKey);
		}else{
			map[cursorCoor[botY]][cursorCoor[botX]*2] = BotKey;
			coorX = botX;
			coorY = botY;
			CursorY= cursorCoor[botY];
			CursorX= cursorCoor[botX]*2;
			map[cursorCoor[botY]+1][cursorCoor[botX]*2] = '^';
			return turn+=1; 	
		}
	}
}
int movefunc(int turn, int playerturn, int difficult, char BotKey, char PlayerKey){
	if(turn%2 == playerturn%2){
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
	}else{
			turn = botmove(turn, difficult, BotKey, PlayerKey);
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
void printwin(int win, int playerturn){
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
		if(win == playerturn){
			puts("\033[0;32m					       _____  _                                  ");
			puts("					      |  __ \\| |                              ");
			puts("					      | |__) | | __ _ _   _  ___ _ __            ");
			puts("					      |  ___/| |/ _` | | | |/ _ \\ '__|        ");
			puts("					      | |    | | (_| | |_| |  __/ |            ");
			puts("					      |_|    |_|\\__,_|\\__, |\\___|_|           ");
			puts("					                       __/ |                      ");
			puts("					                      |___/                      ");
		}else{
			puts("\033[0;31m 					           ____   ____ _______         				   ");
			puts(" 					          |  _ \\ / __ \\__   __|       				   ");
			puts(" 					          | |_) | |  | | | |          				   ");
			puts(" 					          |  _ <| |  | | | |           				   ");
			puts(" 					          | |_) | |__| | | |          				   ");
			puts(" 					          |____/ \\____/  |_|          				   ");
			puts(" 					                                          ");
			puts(" 					                                          ");
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
		if(win != playerturn)Sleep(1000);
		}
	getchar();
}
void play(int playerturn, int difficult, char BotKey, char PlayerKey){
	int verticalfill[3] = {0}, horizontalfill[3] = {0};
	int diagonal[2] = {0};
	system("cls");
	int turn = 1;
	int win = -1;
	do{
		Hide();
		int move = movefunc(turn, playerturn, difficult, BotKey, PlayerKey);
		printmap(turn,playerturn);
		if(move != turn){
			turn = move;
			verticalfill[coorX] ++;
			horizontalfill[coorY]++;
			system("cls");
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
			}
			if(diagonal[1] == 3 && win == -1){
				win = winvalidation(0,0,2);
			}
			if(win != -1){
				printwin(win,playerturn);
				return;
			}
		}
	}while(turn !=10);
	printwin(0,-1);
}
int main(){
	int difficult = 1;
	int playerturn = 0;
	int Movement = 0;
	char BotKey;
	char PlayerKey;
	char TurnSelect[4][20] = {"   1st Turn   ","              ", "   2nd Turn   ", "              "};
	char DiffSelect[6][20] = {"     Easy     ","              ","    Medium    ","              ","     Hard     ","              "};
	newmap();
	system("cls");
	while(true){
		Hide();
		gotoxy(0,6);
		puts("		    ____       _           _    __   __                 _____                 ");
		puts("		   / ___|  ___| | ___  ___| |_  \\ \\ / /__  _   _ _ __  |_   _|   _ _ __ _ __  ");
		puts("		   \\___ \\ / _ \\ |/ _ \\/ __| __|  \\ V / _ \\| | | | '__|   | || | | | '__| '_ \\ ");
		puts("		    ___) |  __/ |  __/ (__| |_    | | (_) | |_| | |      | || |_| | |  | | | |");
		puts("		   |____/ \\___|_|\\___|\\___|\\__|   |_|\\___/ \\__,_|_|      |_| \\__,_|_|  |_| |_|");
		puts("		   ===========================================================================");
		puts("");
		printf("\t\t\t\t\t%c", 201);
		for(int i = 0;i < 32; i++){
			printf("%c", 205);
		}
		printf("%c\n", 187);
		printf("\t\t\t\t\t%c",186);
		for(int i = 0;i<32;i++){
			printf(" ");
		}
		printf("%c\n",186);
		for(int i = 0;i<4;i++){
			printf("\t\t\t\t\t%c",186);
			if(Movement == i){
				printf("      >> %s <<      ", TurnSelect[i]);
			}else{
				printf("         %s         ", TurnSelect[i]);
			}
			printf("%c\n",186);
			}
		printf("\t\t\t\t\t%c", 200);
		for(int i = 0;i < 32; i++){
			printf("%c", 205);
		}
		char key;
		printf("%c\n", 188);
		if(kbhit()){
			key = getch();
			if(key == 72 && Movement != 0){
				Movement-=2;
			}else if(key == 80 && Movement != 2){
				Movement+=2;
			}else if(key == 13){
				if(Movement == 0){
					playerturn = 1;
					BotKey = 'O';
					PlayerKey = 'X';
					break;
				}else if(Movement == 2){
					playerturn = 2;
					BotKey = 'X';
					PlayerKey = 'O';
					break;
				}
			}
		}
	}
	system("cls");
	Movement = 0;
	while(true){
		Hide();
		gotoxy(0,6);
		puts("	           ____       _           _     ____        _     ____  _  __  __ _            _ _   ");
		puts("	          / ___|  ___| | ___  ___| |_  | __ )  ___ | |_  |  _ \\(_)/ _|/ _(_) ___ _   _| | |_ ");
		puts("	          \\___ \\ / _ \\ |/ _ \\/ __| __| |  _ \\ / _ \\| __| | | | | | |_| |_| |/ __| | | | | __|");
		puts("	           ___) |  __/ |  __/ (__| |_  | |_) | (_) | |_  | |_| | |  _|  _| | (__| |_| | | |_ ");
		puts("\t          |____/ \\___|_|\\___|\\___|\\__| |____/ \\___/ \\__| |____/|_|_| |_| |_|\\___|\\__,_|_|\\__|");
		puts("\t          ===================================================================================");
		puts("");
		printf("\t\t\t\t\t%c", 201);
		for(int i = 0;i < 32; i++){
			printf("%c", 205);
		}
		printf("%c\n", 187);
		printf("\t\t\t\t\t%c",186);
		for(int i = 0;i<32;i++){
			printf(" ");
		}
		printf("%c\n",186);
		for(int i = 0;i<6;i++){
			printf("\t\t\t\t\t%c",186);
			if(Movement == i){
				printf("      >> %s <<      ", DiffSelect[i]);
			}else{
				printf("         %s         ", DiffSelect[i]);
			}
			printf("%c\n",186);
			}
		printf("\t\t\t\t\t%c", 200);
		for(int i = 0;i < 32; i++){
			printf("%c", 205);
		}
		char key;
		printf("%c\n", 188);
		if(kbhit()){
			key = getch();
			if(key == 72 && Movement != 0){
				Movement-=2;
			}else if(key == 80 && Movement != 4){
				Movement+=2;
			}else if(key == 13){
				if(Movement == 0){
					difficult = 1;
					break;
				}else if(Movement == 2){
					difficult = 2;
					break;
				}else{
					difficult = 3;
					break;
				}
			}
		}
	}
	play(playerturn,difficult, BotKey, PlayerKey);
	system("cls");
	return 0;
}
