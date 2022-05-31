#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<math.h>
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
void Tutorial(){
	system("cls");
	puts("=======================================================");
	puts("      _         __  _         _  _    _                ");
	puts("     | |       / _|(_)       (_)| |  (_)               ");
	puts("   __| |  ___ | |_  _  _ __   _ | |_  _   ___   _ __   ");
	puts("  / _` | / _ \\|  _|| || '_ \\ | || __|| | / _ \\ | '_ \\  ");
	puts(" | (_| ||  __/| |  | || | | || || |_ | || (_) || | | | ");
	puts("  \\__,_| \\___||_|  |_||_| |_||_| \\__||_| \\___/ |_| |_| ");
	puts("=======================================================");
	char Tutortext[500] = 
	"Tic-tac-toe is a fun game that you can play any time and anywhere as long as you have a piece of paper,\na pencil, and an opponent. Tic-tac-toe is a zero-sum game, which means that if both players are playing\ntheir best, then neither player will win. However, if you learn how to play tic-tac-toe and master some\nsimple strategies, then you'll be able to not only play but win the majority of the time.";
	char Rules [5][255] = {"The game is played on a grid that's 3 squares by 3 squares", "You are X, your friend or the computer is O. Players take turns putting their marks in empty squares.","The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner.", "When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie."};	
	int len = strlen(Tutortext);
	for(int i = 0;i<len;i++){
		printf("%c", Tutortext[i]);
		Sleep(15);
	}
	puts("");
	puts("");
	puts("=======================================================");
	puts("              _____         _            ");
	puts("             |  __ \\       | |           ");
	puts("             | |__) |_   _ | |  ___  ___ ");
	puts("             |  _  /| | | || | / _ \\/ __|");
	puts("             | | \\ \\| |_| || ||  __/\\__ \\");
	puts("             |_|  \\_\\\\__,_||_| \\___||___/");
	puts("=======================================================");
	for(int i = 0;i<4;i++){
		printf("%d. ", i+1);
		Sleep(300);
		int len = strlen(Rules[i]);
		for(int j = 0;j<len;j++){
			printf("%c", Rules[i][j]);
		Sleep(1);
		}
		puts("");
	}
	puts("Press Any button to continue... ");
	getchar();
	system("cls");
}
int main(){
	int Movement = 0;
	char Selection[8][50] = {"!=Singleplayer","              ", " Singleplayer "
	,"              ", "   Tutorial   ","              ", "     Exit     ","              "};
	char key;
	for(int i =0; i<=11;i++){
		if(i>7){
			gotoxy(0,i-7);
		}else{
			gotoxy(0,0);
		}
		if(i>6)puts("\t /$$$$$$$$ /$$$$$$  /$$$$$$        /$$$$$$$$ /$$$$$$   /$$$$$$        /$$$$$$$$ /$$$$$$  /$$$$$$$$");
		if(i>5)puts("\t|__  $$__/|_  $$_/ /$$__  $$      |__  $$__//$$__  $$ /$$__  $$      |__  $$__//$$__  $$| $$_____/");
		if(i>4)puts("\t   | $$     | $$  | $$  \\__/         | $$  | $$  \\ $$| $$  \\__/         | $$  | $$  \\ $$| $$      ");
		if(i>3)puts("\t   | $$     | $$  | $$               | $$  | $$$$$$$$| $$               | $$  | $$  | $$| $$$$$   ");
		if(i>2)puts("\t   | $$     | $$  | $$               | $$  | $$__  $$| $$               | $$  | $$  | $$| $$__/   ");
		if(i>1) puts("\t   | $$     | $$  | $$    $$         | $$  | $$  | $$| $$    $$         | $$  | $$  | $$| $$      ");
		if(i>0) puts("\t   | $$    /$$$$$$|  $$$$$$/         | $$  | $$  | $$|  $$$$$$/         | $$  |  $$$$$$/| $$$$$$$$");
		puts("\t   |__/   |______/ \\______/          |__/  |__/  |__/ \\______/          |__/   \\______/ |________/");
		Sleep(200);
		system("cls");
	}
	system("cls");
	while(true){
		Hide();
		gotoxy(0,5);
		puts("\t /$$$$$$$$ /$$$$$$  /$$$$$$        /$$$$$$$$ /$$$$$$   /$$$$$$        /$$$$$$$$ /$$$$$$  /$$$$$$$$");
		puts("\t|__  $$__/|_  $$_/ /$$__  $$      |__  $$__//$$__  $$ /$$__  $$      |__  $$__//$$__  $$| $$_____/");
		puts("\t   | $$     | $$  | $$  \\__/         | $$  | $$  \\ $$| $$  \\__/         | $$  | $$  \\ $$| $$      ");
		puts("\t   | $$     | $$  | $$               | $$  | $$$$$$$$| $$               | $$  | $$  | $$| $$$$$   ");
		puts("\t   | $$     | $$  | $$               | $$  | $$__  $$| $$               | $$  | $$  | $$| $$__/   ");
		puts("\t   | $$     | $$  | $$    $$         | $$  | $$  | $$| $$    $$         | $$  | $$  | $$| $$      ");
		puts("\t   | $$    /$$$$$$|  $$$$$$/         | $$  | $$  | $$|  $$$$$$/         | $$  |  $$$$$$/| $$$$$$$$");
		puts("\t   |__/   |______/ \\______/          |__/  |__/  |__/ \\______/          |__/   \\______/ |________/");
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
		for(int i = 0;i<8;i++){
			printf("\t\t\t\t\t%c",186);
			if(Movement == i){
				printf("      >> %s <<      ", Selection[i]);
			}else{
				printf("         %s         ", Selection[i]);
			}
			printf("%c\n",186);
		}
		printf("\t\t\t\t\t%c", 200);
		for(int i = 0;i < 32; i++){
			printf("%c", 205);
		}
		printf("%c\n", 188);
		if(kbhit()){
			key = getch();
			if(key == 72 && Movement != 0){
				Movement-=2;
			}else if(key == 80 && Movement != 6){
				Movement+=2;
			}else if(key == 13){
				if(Movement == 0){
					system("Multiplayer.exe");
				}else if(Movement == 2){
					system("Singleplayer.exe");
				}else if(Movement == 4){
					Tutorial();
				}else if(Movement == 6){
					return 0;
				}
			}
		}
	}
	
	return 0;
}

