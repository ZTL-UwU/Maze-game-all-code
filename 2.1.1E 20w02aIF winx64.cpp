#include<iostream>
#include<iomanip>
#include<cstdio>
#include<windows.h>
#include<unistd.h>
#include<conio.h>
#include<fstream>
#include<cstdlib>
#include<time.h>
using namespace std;

struct s {
	int x;
	int y;
};
s _mcheck;
s _dcheck;
int coins; // vis in the shop
short shortest = 0;
short last = 6; // check if the game is end
short x = 1; // where the charactor is
short y = 1; // where the charactor is
short chang; // the length of the map
short over = 3;
char temp_char;
short temp_int;
char temp_move;
char hard;
short level;
char temp[200][200];
bool showrecord = true;

//_______________________________________________________________________________________________________________________________________________________________
//_______________________________________________________________________________________________________________________________________________________________
// map __________________________________________________________________________________________________________________________________________________________
char e1[5][5] = {{'#','#','#','#','#'},{'#',' ','#','#','#'},{'#',' ',' ',' ','#'},{'#','#','#',' ','#'},{'#',' ','#',' ','#'}};
char e2[5][5] = {{'#','#','#',' ','#'},{'#',' ',' ','#','#'},{'#','#',' ',' ','#'},{'#','#','#',' ','#'},{'#',' ',' ',' ','#'}};
char e3[5][5] = {{'#','#',' ',' ','#'},{'#',' ','#',' ','#'},{'#',' ','#','#','#'},{'#',' ',' ',' ','#'},{'#',' ','#','#','#'}};
char e4[5][5] = {{'#','#',' ',' ',' '},{'#',' ',' ',' ','#'},{' ','#',' ','#',' '},{'#',' ','#',' ','#'},{' ','#',' ','#',' '}};
char e5[5][5] = {{'#','#','#','#','#'},{'#',' ','#',' ','#'},{'#','@','#','#','#'},{'#','#','#','#','#'},{' ','@',' ',' ',' '}};
char e6[5][5] = {{'#','#',' ','#','#'},{'#',' ',' ',' ','#'},{'#','@','#','#','#'},{'#','#',' ','@','#'},{'#','#','#','#','#'}};
char e7[5][5] = {{'#','#','#','#','#'},{'#',' ','#',' ',' '},{'#',' ',' ',' ','#'},{'#',' ','@','#','#'},{'#','#','@',' ',' '}};
char e8[5][5] = {{'#','#','#','#','#'},{'#',' ','@','#',' '},{'#',' ',' ','@',' '},{'#',' ',' ',' ',' '},{'#','#','#','#','#'}};
char e9[5][5] = {{'#','#','#','#','#'},{'#',' ','!','#','#'},{'#','-','#',' ',' '},{'#',' ',' ',' ','#'},{'#','#','#','#','#'}};
char m1[10][10] = {{'#','#','#','#','#','#','#','#','#','#'},{'#',' ','#','#','#','#','#','#','#','#'},{'#',' ','#','#','#','#',' ',' ',' ',' '},{'#',' ',' ',' ',' ',' ',' ','#','#','#'},{'#',' ','#','#','#','#','#',' ',' ',' '},{'#',' ',' ',' ',' ',' ',' ',' ','#','#'},{'#',' ','#','#','#','#','#',' ','#','#'},{'#',' ','#','#','#','#','#',' ',' ',' '},{'#',' ','#','#','#','#','#','#','#','#'},{'#',' ','#','#','#','#','#','#','#','#'}};
char m2[10][10] = {{'#','#','#','#','#','#','#','#','#','#'},{'#',' ',' ','#','#',' ',' ','#','!','#'},{'#','#',' ',' ',' ','#',' ',' ',' ','#'},{'#',' ','#','@','#',' ',' ','#','@','#'},{'#',' ',' ','#',' ','#','-','#','#','#'},{'#',' ','#',' ','#',' ',' ','#',' ','#'},{'#',' ','#',' ',' ','#',' ',' ','#','#'},{'#',' ',' ','#',' ',' ','#',' ',' ','#'},{'#',' ',' ',' ',' ','#',' ','#',' ',' '},{'#','#','#','#','#','#','#','#','#','#'}};
char m3[10][10] = {{'#','#','#',' ','#','#','#','#','#','#'},{'#',' ','#',' ','#',' ',' ',' ',' ',' '},{'#',' ','#','-','#',' ','#','#','#','#'},{'#',' ','#',' ','#',' ',' ','#','@',' '},{'#',' ','#',' ','#',' ','@','#','#',' '},{'#',' ','#',' ','#',' ',' ','#','#',' '},{'#',' ','#',' ',' ','#',' ','#','#','#'},{'#',' ','!','#',' ',' ',' ','#','#','#'},{'#',' ',' ',' ',' ',' ','#','#','#','#'},{'#','#','#','#','#','#','#','#','#','#'}};
char m4[10][10] = {{'#','#',' ','#',' ','#',' ','#',' ','#'},{'#',' ','#',' ','#',' ','#',' ','#',' '},{'#',' ',' ','#',' ','#',' ','#',' ','#'},{'#',' ',' ',' ','#',' ','#',' ','#',' '},{'#',' ','#',' ',' ','#',' ',' ',' ','#'},{'#','#',' ','#',' ',' ',' ',' ','#','#'},{'#',' ','#',' ','#','#',' ','#',' ',' '},{'#','#',' ','#',' ',' ',' ',' ','#',' '},{'#',' ',' ',' ',' ','#','#',' ',' ',' '},{'#','#','#','#','#','#','#','#','#','#'}};
char m5[10][10] = {{'#','#','#','#','#','#','#','#','#','#'},{'#',' ','#',' ',' ',' ',' ',' ','#',' '},{'#',' ','#',' ',' ','#','#',' ',' ','#'},{'#',' ','#','#',' ','#','#',' ',' ',' '},{'#',' ','#',' ',' ',' ',' ',' ',' ','#'},{'#',' ','#',' ','#','#','#','#','#','#'},{'#',' ','#',' ',' ',' ',' ',' ',' ','#'},{'#',' ','#','#','#','#','#','#',' ','#'},{'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},{'#','#','#','#','#','#','#','#','#','#'}};
char m6[10][10] = {{'#','#','#','#','#','#','#','#','#','#'},{'#',' ','#','@','#',' ',' ',' ','#','#'},{'#',' ',' ',' ','#',' ','#',' ',' ','#'},{'#','#','#',' ',' ',' ',' ','#',' ','#'},{'#',' ',' ',' ','#','#','#',' ',' ','#'},{'#',' ','#','#','#','#',' ',' ','#','#'},{'#',' ','#','!','#',' ',' ','#','#','#'},{'#',' ','#',' ','#',' ','#','#','@','#'},{'#',' ',' ',' ','#',' ',' ','#','-','#'},{'#','#','#','#','#','#',' ','#',' ','#'}};
char m7[10][10] = {{'#','#','#','#','#','#','#','#','#','#'},{'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},{'#',' ','#','#','#','#','#','!',' ','#'},{'#',' ','#',' ',' ',' ','#','#',' ','#'},{'#',' ','#',' ','#',' ','#','#',' ','#'},{'#',' ',' ',' ','#','@','#','#','-','#'},{'#',' ','#','#','#','#','#','@',' ','#'},{'#','#','#',' ',' ',' ','#','#',' ','#'},{'#',' ',' ',' ','#',' ',' ',' ',' ','#'},{'#',' ','#','#','#','#','#','#','#','#'}};
char m8[10][10] = {{'#','#','#','#','#','#','#','#','#','#'},{'#',' ',' ',' ',' ',' ',' ',' ','#','#'},{'#','#','#','#',' ','#','#',' ',' ','#'},{'#',' ',' ',' ',' ','#',' ',' ',' ','#'},{'#',' ','#','#','#','@',' ',' ',' ','#'},{'#',' ',' ',' ',' ','#','#','!',' ','#'},{'#','#','#','#',' ','#',' ',' ',' ','#'},{' ',' ','#','#',' ','#','-','#','#','#'},{'#',' ',' ',' ',' ',' ',' ',' ','@','#'},{'#','#','#','#','#','#','#','#','#','#'}};
char m9[10][10] = {{'#','#','#','#','#','#','#','#','#','#'},{'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},{'#','#','#','#','#',' ','#','#',' ','#'},{'#',' ',' ',' ',' ',' ',' ','#',' ','#'},{'#',' ','#','#',' ','#',' ','#',' ','#'},{'#',' ',' ','#',' ','#',' ','#',' ','#'},{'#','#',' ','#',' ','#','@','#',' ','#'},{'#',' ',' ',' ',' ',' ','#','@',' ','#'},{'#','!','#',' ',' ','#','#','#','-','#'},{'#','#','#','#','#','#','#','#',' ','#'}};
char h1[15][15] = {{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},{'#',' ','#',' ','@','#','!',' ',' ','#',' ',' ','#',' ','#'},{'#',' ','#',' ','#','#','#','#',' ','#',' ',' ',' ',' ',' '},{'#',' ','#',' ',' ',' ',' ','#',' ','#','-','#','#',' ','#'},{'#',' ','#','#','#','#',' ','#',' ','#',' ','#',' ',' ','#'},{'#',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ','#','#'},{'#',' ','#',' ','#','#','#','#',' ','#',' ','#',' ',' ','#'},{'#',' ','#',' ',' ',' ','#',' ',' ','#',' ','#','#',' ','#'},{'#',' ','#','#','#',' ','#',' ',' ','#',' ','#',' ',' ','#'},{'#',' ',' ',' ','#',' ','#','#',' ','#',' ','#',' ','#','#'},{'#','#','#',' ','#',' ',' ',' ',' ',' ',' ','#',' ',' ','#'},{'#',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ','#'},{'#',' ','#','#','@',' ',' ',' ','#',' ',' ',' ','#',' ','#'},{'#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#'},{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}};
char h2[15][15] = {{'#','#','#','#','#','#','#','#','-','#','#','#','#','#','#'},{'#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},{'#',' ','#',' ','#','#','#','#','#','#','#','#','#',' ','#'},{'#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#'},{'#',' ','#',' ','#',' ','#','#','#','#',' ',' ','#',' ','#'},{'#',' ','#',' ','#',' ','#',' ','!','#',' ',' ','#',' ','#'},{'#',' ','#',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#'},{'#',' ','#',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#'},{'#',' ','#',' ','#',' ','#',' ',' ','#',' ',' ','#',' ','#'},{'#',' ','#',' ','#',' ',' ',' ',' ','#',' ',' ','#',' ','#'},{'#',' ','#',' ','#','#','#','#','#','#',' ',' ','#',' ','#'},{'#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#'},{'#',' ','#','#','#','#','#','#','#','#','#','#','#',' ','#'},{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}};
char h3[15][15] = {{'#','-','#','#','#','#','#','#','#','#','#','#','#','#','#'},{'#',' ','#','#','#','#','#','#','#','#','#','#','#','#','#'},{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#'},{'#','#','#','#','#','#','#',' ',' ','#','#','#',' ','#','#'},{'#','#','#','#',' ',' ',' ',' ','#','#','#',' ',' ',' ','#'},{'#','#',' ',' ',' ','#','#','#','#','#','#',' ','#','#','#'},{'#','#','#',' ',' ','#',' ','!','#','#','#',' ','#','#','#'},{'#','#',' ',' ','#',' ',' ','#',' ','#',' ',' ','#','#','#'},{'#',' ',' ','#','#','#',' ','#',' ',' ',' ',' ','#','#','#'},{'#','#',' ',' ','#','#',' ','#',' ',' ','#','#','#','#','#'},{'#','#',' ',' ','#','#',' ','#',' ','#','#','#','#','#','#'},{'#',' ',' ','#','#','#',' ',' ',' ','#','#','#','#','#','#'},{'#',' ',' ',' ','#',' ',' ',' ','#','#','#','#','#','#','#'},{'#','#',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#'},{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}};
char h4[15][15] = {{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},{'#',' ','#',' ',' ',' ','#','#',' ',' ',' ',' ','#',' ','#'},{'#',' ','#','#','#',' ','#',' ',' ','#','#',' ',' ',' ','#'},{'#',' ',' ',' ',' ',' ','#','#',' ','#','#',' ','#','@','#'},{'#','#','#','#','#','@','#','#',' ','#','#','#','#','#','#'},{'#',' ','#','#','#','#','#',' ',' ',' ',' ',' ',' ','#','#'},{'#',' ',' ',' ',' ',' ','#','#','#',' ','#','#',' ','#','#'},{'#',' ',' ','#',' ','#',' ','#',' ',' ','#',' ',' ',' ','#'},{'#','#',' ','#','#','#',' ','#',' ','#',' ','#','#',' ','#'},{'#','#','#','#',' ','#','#',' ',' ',' ',' ','#','#',' ','#'},{'#',' ',' ','#','#',' ','#','#',' ','#',' ','#',' ',' ','#'},{'#',' ','#','#',' ',' ','#',' ',' ','#',' ',' ',' ',' ','#'},{'#','#',' ','#',' ','#',' ','#','#',' ','#',' ',' ','#','#'},{'#','#','#','#',' ','#','#',' ','#','#','#','#',' ',' ','#'},{'#','#','#','#',' ','#','#',' ','#','#','#','#',' ','#','#'}};
char h5[15][15];
char h6[15][15];
char h7[15][15];
char h8[15][15];
char h9[15][15];
char c1[20][20] = {{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},{'#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','@',' ','#'},{'#',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#',' ','#','#',' ','#'},{'#',' ',' ','#','#','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#'},{'#',' ','#',' ',' ',' ','#','#',' ','#','#','#','#','#',' ','#','#',' ','#','#'},{'#',' ','#',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#'},{'#',' ','@',' ',' ',' ',' ',' ','#','!','#','#','#','#','#','#','#','#',' ','#'},{'#',' ','#','-','#','#','#','#','#','#','#',' ',' ','#',' ',' ',' ',' ',' ','#'},{'#',' ','#',' ','#','#','#','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ','#','#'},{'#',' ','#',' ',' ',' ',' ','#',' ','#','#','#','#','#','#','#','#','#','#','#'},{'#',' ','#',' ','#','#',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' '},{'#',' ','#',' ','#',' ',' ','#',' ','#',' ','#',' ','#','#',' ','#','#','#','#'},{'#',' ','#','#','#','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#'},{'#',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#','#','#'},{'#',' ','#',' ',' ',' ',' ','#','#',' ','#',' ',' ',' ',' ','#',' ',' ',' ','#'},{'#',' ','#',' ','#','#',' ','#',' ',' ','#',' ','#',' ','#',' ',' ','#',' ','#'},{'#',' ','#',' ',' ','#',' ','#',' ',' ',' ',' ','#',' ',' ','#','#',' ',' ','#'},{'#',' ','#',' ','#','#',' ','#',' ','#',' ','#','#',' ','#',' ','#','#',' ','#'},{'#',' ',' ',' ',' ','#',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','#'},{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}};
char c2[20][20] = {{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','@','#'},{'#','#','#','#','#','#',' ','#','#','#','#','#',' ','#','#','#','#',' ','#','#'},{'#','@','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},{'#',' ','#',' ','#','#','#','#',' ','#','#','#','#','#',' ','#','#','#',' ','#'},{'#',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#'},{'#',' ','#','#','#','#',' ','#','#','#','#','#',' ','#',' ','#',' ','#','#','#'},{'#',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#'},{'#',' ','#',' ','#','#','#','#',' ','#','#','#','!','#',' ','#','#','#','-','#'},{'#',' ','#',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ',' '},{'#',' ','#','#','#','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#'},{'#',' ','#',' ',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ','#',' ','#',' ','#'},{'#',' ','#',' ','#','#','#','#','#','#','#',' ',' ','#',' ','#',' ','#',' ','#'},{'#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','#','#',' ','#',' ','#',' ','#'},{'#',' ','#','#','#',' ','#',' ','#',' ','#',' ',' ',' ',' ','#',' ','#',' ','#'},{'#',' ','#',' ','#',' ','#',' ','#',' ','#','#','#','#','#','#',' ','#',' ','#'},{'#',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#'},{'#',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#'},{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}};
char c3[20][20];
char c4[20][20];
char c5[20][20];
char c6[20][20];
char c7[20][20];
char c8[20][20];
char c9[20][20];
//_______________________________________________________________________________________________________________________________________________________________
//_______________________________________________________________________________________________________________________________________________________________
//_______________________________________________________________________________________________________________________________________________________________


string skintruefalse;
bool skintruefalsebool[5] = {false};
short c = 0;
string wenjian;
short target;
char skin = 'O'; // skin
short playerlevel_short;

void feedback (){
	system("cls");
	printf("Any questions?\n");
	printf("Please contact Tianli Zhang");
	sleep (3);
	return;
}

void print (int t, string st)
{
	for (int i = 0; i < st.size(); i ++)
	{
		printf("%c",st[i]);
		Sleep(t);
	}
}

void pause (){
	printf("Press any key to continue ...");
	getch();
	return;
}

void findsize (char a){
    if (a == 'e') chang = 5;
    else if (a == 'm') chang = 10;
    else if (a == 'h') chang = 15;
    else chang = 20;
}

void playerlevel_show (){
	system("cls");
	system("color A0");
	printf("<now level>: %d\n",playerlevel_short);
	if (playerlevel_short == 1){
		printf("1\n");
		printf("# 2 3 4 5\n\n");
		printf("<back> (b)");
		getch();
		return;
	} else if (playerlevel_short == 2){
		printf("  2\n");
		printf("1 # 3 4 5\n\n");
		printf("<back> (b)");
		getch();
		return;
	} else if (playerlevel_short == 3){
		printf("    3\n");
		printf("1 2 # 4 5\n\n");
		printf("<back> (b)");
		getch();
		return;
	} else if (playerlevel_short == 4){
		printf("      4\n");
		printf("1 2 3 # 5\n\n");
		printf("<back> (b)");
		getch();
		return;
	} else if (playerlevel_short == 5){
		printf("        5\n");
		printf("1 2 3 4 #\n\n");
		printf("<back> (b)");
		getch();
		return;
	}
}

void lucky_draw (){
	srand((int)time(0));
	system("color 0F");
	system("cls");
	printf("sure to use 30 coins to have a go of lucky draw?\n");
	printf("<back> (b) , <yes> (y)");
	temp_char = getch();
	if (temp_char == 'y'){
		if (coins < 30){
			MessageBox(GetForegroundWindow(),"No enough coins!","",1);
			system("cls");
			return;
		}
		temp_int = MessageBox(GetForegroundWindow(),"sure?","",1);
		if (temp_int == 1){
			coins -= 30;
			short tmp_int = rand();
			cout << "-----------------\n";
			cout << "| - | 0 | 2 | 0 |\n";
			cout << "-----------------\n";
			Sleep(30);
			system("cls");
			cout << "-----------------\n";
			cout << "| + | 0 | 2 | 0 |\n";
			cout << "-----------------\n";
			Sleep(30);
			system("cls");
			cout << "-----------------\n";
			cout << "| + | 1 | 0 | 0 |\n";
			cout << "-----------------\n";
			Sleep(30);
			system("cls");
			cout << "-----------------\n";
			cout << "| - | 0 | 5 | 0 |\n";
			cout << "-----------------\n";
			Sleep(35);
			system("cls");
			cout << "-----------------\n";
			cout << "| + | 3 | 0 | 0 |\n";
			cout << "-----------------\n";
			Sleep(35);
			system("cls");
			cout << "-----------------\n";
			cout << "| - | 0 | 1 | 0 |\n";
			cout << "-----------------\n";
			Sleep(40);
			system("cls");
			cout << "-----------------\n";
			cout << "| + | 0 | 5 | 0 |\n";
			cout << "-----------------\n";
			Sleep(40);
			system("cls");
			cout << "-----------------\n";
			cout << "| - | 0 | 2 | 0 |\n";
			cout << "-----------------\n";
			Sleep(50);
			system("cls");
			cout << "-----------------\n";
			cout << "| - | 0 | 4 | 0 |\n";
			cout << "-----------------\n";
			Sleep(60);
			system("cls");
			cout << "-----------------\n";
			cout << "| - | 0 | 7 | 0 |\n";
			cout << "-----------------\n";
			Sleep(90);
			system("cls");
			cout << "-----------------\n";
			cout << "| + | 0 | 1 | 0 |\n";
			cout << "-----------------\n";
			Sleep(200);
			system("cls");
			cout << "-----------------\n";
			cout << "| - | 0 | 2 | 0 |\n";
			cout << "-----------------\n";
			Sleep(500);
			system("cls");
			if (tmp_int % 5 == 0){
				cout << "-----------------\n";
				cout << "| + | 3 | 5 | 0 |\n";
				cout << "-----------------\n";
				Sleep(800);
				system("cls");
			} else {
				cout << "-----------------\n";
				cout << "| - | 0 | 5 | 0 |\n";
				cout << "-----------------\n";
				Sleep(800);
				system("cls");
			}
			if (tmp_int % 6 == 0){
				cout << "-----------------\n";
				cout << "| + | 2 | 0 | 0 |\n";
				cout << "-----------------\n";
				sleep (1);
				system("cls");
				cout << "Congratulations!\n";
				cout << "You get 200 coins!\n";
				coins += 200;
				cout << "<now coins>: " << coins << "\n";
				ofstream luckydrawend ("coins.txt");
				luckydrawend << coins;
				sleep (2);
			}
			if (tmp_int % 6 == 1){
				cout << "-----------------\n";
				cout << "| + | 0 | 2 | 0 |\n";
				cout << "-----------------\n";
				sleep (1);
				system("cls");
				cout << "Congratulations!\n";
				cout << "You get 20 coins!\n";
				coins += 20;
				cout << "<now coins>: " << coins << "\n";
				ofstream luckydrawend ("coins.txt");
				luckydrawend << coins;
				sleep (2);
			}
			if (tmp_int % 6 == 2){
				cout << "-----------------\n";
				cout << "| - | 0 | 5 | 0 |\n";
				cout << "-----------------\n";
				sleep (1);
				system("cls");
				cout << "Sorry!\n";
				cout << "You lose 50 coins!\n";
				coins -= 50;
				cout << "<now coins>: " << coins << "\n";
				ofstream luckydrawend ("coins.txt");
				luckydrawend << coins;
				sleep (2);
			}
			if (tmp_int % 6 == 3){
				cout << "-----------------\n";
				cout << "| - | 1 | 0 | 0 |\n";
				cout << "-----------------\n";
				sleep (1);
				system("cls");
				cout << "Sorry!\n";
				cout << "You lose 100 coins!\n";
				coins -= 100;
				cout << "<now coins>: " << coins << "\n";
				ofstream luckydrawend ("coins.txt");
				luckydrawend << coins;
				sleep (2);
			}
			if (tmp_int % 6 == 4){
				cout << "-----------------\n";
				cout << "| + | 0 | 5 | 0 |\n";
				cout << "-----------------\n";
				sleep (1);
				system("cls");
				cout << "Congratulations!\n";
				cout << "You get 50 coins!\n";
				coins += 50;
				cout << "<now coins>: " << coins << "\n";
				ofstream luckydrawend ("coins.txt");
				luckydrawend << coins;
				sleep (2);
			}
			if (tmp_int % 6 == 5){
				cout << "-----------------\n";
				cout << "| + | 1 | 5 | 0 |\n";
				cout << "-----------------\n";
				sleep (1);
				system("cls");
				cout << "Congratulations!\n";
				cout << "You get 150 coins!\n";
				coins += 150;
				cout << "<now coins>: " << coins << "\n";
				ofstream luckydrawend ("coins.txt");
				luckydrawend << coins;
				sleep (2);
			}
		} else if (temp_char == 'n'){
			system("cls");
			return;
		} else
		{
   	 		MessageBox(GetForegroundWindow(),"Your choise is not correct!","",1);
   	        system("cls");
		}
		if (coins < 0){
			system("cls");
			printf("You lose all your coins!\n");
			sleep (2);
			system("cls");
			if (playerlevel_short > 1){
				printf("Your level minus 1");
				playerlevel_short -= 1;
				ofstream levelminus ("level.txt");
				levelminus << playerlevel_short;
				sleep (2);
			} else {
				printf("Be careful next time! Don't lose you level and coins!");
				sleep (2);
				system("cls");
			}
		}
	} else {
		system("cls"); 
		return;
	}
}

void shop (){
	system ("cls");
	while (true){
		system("color 90");
		cout << "<coins now>: " << coins << endl;
		cout << "skins: " << endl;
		cout << "--------------------------------------" << endl;
		cout << "|  O  |  ~  |  A  |  %  |  &   |  *  |" << endl;
		cout << "--------------------------------------" << endl;
		cout << "|  0$ | 30$ | 50$ | 80$ | 100$ | 1k$ |" << endl;
		cout << "--------------------------------------" << endl;
		cout << "|  1  |  2  |  3  |  4  |  5   |  6  |" << endl;
		cout << "--------------------------------------" << endl;
		cout << endl;
		cout << "<lucky draw> (l) , <back> (b)";
		temp_char = getch();
		if (temp_char == '1'){
			skin = 'O';
			system("cls");
		} else if (temp_char == '2'){
			if (skintruefalsebool[0] == true){
				skin = '~';
			    system("cls");
			    return;
			}
			if (coins < 30){
				MessageBox(GetForegroundWindow(),"Not enough coins","",1);
				system("cls");
			} else {
				temp_int = MessageBox(GetForegroundWindow(),"Sure to buy ~ ?","",1);
				if (temp_int == 1){
					coins -= 30;
					ofstream buy("coins.txt");
					buy << coins;
					skin = '~';
					skintruefalsebool[0] = true;
				}
			}
			system("cls");
		} else if (temp_char == '3'){
			if (skintruefalsebool[1] == true){
				skin = 'A';
			    system("cls");
			    return;
			}
			if (coins < 50){
				MessageBox(GetForegroundWindow(),"Not enough coins","",1);
				system("cls"); 
			} else {
				temp_int = MessageBox(GetForegroundWindow(),"Sure to buy A ?","",1);
				if (temp_int == 1){
					coins -= 50;
					ofstream buy("coins.txt");
					buy << coins;
					skin = 'A';
					skintruefalsebool[1] = true;
				}
			}
			system("cls");
		} else if (temp_char == '4'){
			if (skintruefalsebool[2] == true){
				skin = '%';
			    system("cls");
			    return;
			}
			if (coins < 80){
				MessageBox(GetForegroundWindow(),"Not enough coins","",1);
				system("cls"); 
			} else {
				temp_int = MessageBox(GetForegroundWindow(),"Sure to buy % ?","",1);
				if (temp_int == 1){
					coins -= 80;
					ofstream buy("coins.txt");
					buy << coins;
					skin = '%';
					skintruefalsebool[2] = true;
				}
			}
			system("cls");
		} else if (temp_char == '5'){
			if (skintruefalsebool[3] == true){
				skin = '&';
			    system("cls");
			    return;
			}
			if (coins < 100){
				MessageBox(GetForegroundWindow(),"Not enough coins","",1);
				system("cls"); 
			} else {
				temp_int = MessageBox(GetForegroundWindow(),"Sure to buy & ?","",1);
				if (temp_int == 1){
					coins -= 100;
					ofstream buy("coins.txt");
					buy << coins;
					skin = '&';
					skintruefalsebool[3] = true;
				}
			}
			system("cls");
		} else if (temp_char == '6'){
			if (skintruefalsebool[4] == true){
				skin = '*';
			    system("cls");
			    return;
			}
			if (coins < 1000){
				MessageBox(GetForegroundWindow(),"Not enough coins","",1);
				system("cls"); 
			} else {
				temp_int = MessageBox(GetForegroundWindow(),"Sure to buy * ?","",1);
				if (temp_int == 1){
					coins -= 1000;
					ofstream buy("coins.txt");
					buy << coins;
					skin = '*';
					skintruefalsebool[4] = true;
				}
			}
			system("cls");
		} else if (temp_char == 'b'){
			system("cls");
			ofstream endskin("skin.txt");
			endskin << skintruefalse;
			return;
		} else if (temp_char == 'l'){
			lucky_draw();
			system("cls");
		} else {
//   	 		MessageBox(GetForegroundWindow(),"Your choise is not correct!","",1);
   	        system("cls");
		}
	}
}

void rule (){
	system("color D0");
    system("cls");
	printf("rules:\n");
	printf("w or ^ for up, a or < for left, s or \\/ for down, d or > for right.\n");
	printf("# is wall, if you crash on it, you lose.\n");
	printf("@ if a machine to go to another @.\n");
	printf("! is a key to open the doors.\n");
	printf("} is a wepon, if you have a wepon, you can break 5#.\n\n");
	printf("If you win,brake your own record or reach the target can get coins\n");
	printf("If you lose,you lose coins\n");
	printf("If you have no more coins,you will lose level\n");
	printf("Use your coins to buy skins\n");
	printf("Play crazy mode and reach the target can make your level higher\n\n");
	pause();
	system ("color F0");
    system ("cls");
}

int check (short xtmp, short ytmp){
    if (temp[xtmp][ytmp] == '#' || temp[xtmp][ytmp] == '-'){
    	return 2; //dead
    } else if (temp[xtmp][ytmp] == '@'){
    	x = _mcheck.x;
    	y = _mcheck.y;
    	return 3; //alive
	} else if (temp[xtmp][ytmp] == '!'){
		temp[_dcheck.x][_dcheck.y] = ' ';
		return 3; //alive
	} else if (xtmp == 0 || ytmp == 0){
        return 4; //win
    } else if (xtmp == chang-1 || ytmp == chang-1){
    	return 4; //win
	} else {
    	return 3; //alive
	}
}

void move (char a){
    if (a == 'w' || a == 72){
        temp[x][y] = ' ';
        x --;
        over = check(x,y);
        temp[x][y] = skin;
    } else if (a == 'a' || a == 75){
        temp[x][y] = ' ';
        y --;
        over = check(x,y);
        temp[x][y] = skin;
    } else if (a == 's' || a == 80) {
        temp[x][y] = ' ';
        x ++;
        over = check(x,y);
        temp[x][y] = skin;
    } else if (a == 'd' || a == 77) {
        temp[x][y] = ' ';
        y ++;
        over = check(x,y);
        temp[x][y] = skin;
    }
    if (a != 72 && a != 75 && a != 80 && a != 77){
    	c ++;
	}
	return;
}

void change (char h,short l){
    if (h == 'e'){
        if (l == 1){
            for (int i = 0; i < 5; i ++){
                for (int j = 0; j < 5; j ++){
                    temp[i][j] = e1[i][j];
                    wenjian = "e1.txt";
                    target = 5;
                }
            }
        } else if (l == 2){
            for (int i = 0; i < 5; i ++){
                for (int j = 0; j < 5; j ++){
                    temp[i][j] = e2[i][j];
                    wenjian = "e2.txt";
                    target = 5;
                }
            }
        } else if (l == 3){
            for (int i = 0; i < 5; i ++){
                for (int j = 0; j < 5; j ++){
                    temp[i][j] = e3[i][j];
                    wenjian = "e3.txt";
                    target = 3;
                }
            }
        } else if (l == 4){
            for (int i = 0; i < 5; i ++){
                for (int j = 0; j < 5; j ++){
                    temp[i][j] = e4[i][j];
                    wenjian = "e4.txt";
                    target = 2;
                }
            }
        } else if (l == 5){
            for (int i = 0; i < 5; i ++){
                for (int j = 0; j < 5; j ++){
                    temp[i][j] = e5[i][j];
                    wenjian = "e5.txt";
                    _mcheck.x = 4;
                    _mcheck.y = 1;
                    target = 2;
                }
            }
        } else if (l == 6){
            for (int i = 0; i < 5; i ++){
                for (int j = 0; j < 5; j ++){
                    temp[i][j] = e6[i][j];
                    wenjian = "e6.txt";
                    _mcheck.x = 3;
                    _mcheck.y = 3;
                    target = 2;
                }
            }
        } else if (l == 7){
            for (int i = 0; i < 5; i ++){
                for (int j = 0; j < 5; j ++){
                    temp[i][j] = e7[i][j];
                    _mcheck.x = 4;
                    _mcheck.y = 2;
                    wenjian = "e7.txt";
                    target = 4;
                }
            }
        } else if (l == 8){
            for (int i = 0; i < 5; i ++){
                for (int j = 0; j < 5; j ++){
                    temp[i][j] = e8[i][j];
                    wenjian = "e8.txt";
					_mcheck.x = 2;
					_mcheck.y = 3;
					target = 2;
                }
            }
        } else if (l == 9){
            for (int i = 0; i < 5; i ++){
                for (int j = 0; j < 5; j ++){
                    temp[i][j] = e9[i][j];
                    wenjian = "e9.txt";
					_dcheck.x = 2;
					_dcheck.y = 1;
					target = 8;
                }
            }
        }
    } else if (h == 'm'){
        if (l == 1){
            for (int i = 0; i < 10; i ++){
                for (int j = 0; j < 10; j ++){
                    temp[i][j] = m1[i][j];
                    wenjian = "m1.txt";
                    target = 8;
                }
            }
        } else if (l == 2){
            for (int i = 0; i < 10; i ++){
                for (int j = 0; j < 10; j ++){
                    temp[i][j] = m2[i][j];
                    wenjian = "m2.txt";
					_mcheck.x = 3;
					_mcheck.y = 8;
					_dcheck.x = 4;
					_dcheck.y = 6;
					target = 18;
                }
            }
        } else if (l == 3){
            for (int i = 0; i < 10; i ++){
                for (int j = 0; j < 10; j ++){
                    temp[i][j] = m3[i][j];
                    wenjian = "m3.txt";
					_mcheck.x = 3;
					_mcheck.y = 8;
					_dcheck.x = 2;
					_dcheck.y = 3;
					target = 17;
                }
            }
        } else if (l == 4){
            for (int i = 0; i < 10; i ++){
                for (int j = 0; j < 10; j ++){
                    temp[i][j] = m4[i][j];
                    wenjian = "m4.txt";
                    target = 15;
                }
            }
        } else if (l == 5){
            for (int i = 0; i < 10; i ++){
                for (int j = 0; j < 10; j ++){
                    temp[i][j] = m5[i][j];
                    wenjian = "m5.txt";
                    target = 30;
                }
            }
        } else if (l == 6){
            for (int i = 0; i < 10; i ++){
                for (int j = 0; j < 10; j ++){
                    temp[i][j] = m6[i][j];
                    wenjian = "m6.txt";
                    _mcheck.x = 7;
                    _mcheck.y = 8;
                    _dcheck.x = 8;
                    _dcheck.y = 8;
                    target = 23;
                }
            }
        } else if (l == 7){
            for (int i = 0; i < 10; i ++){
                for (int j = 0; j < 10; j ++){
                    temp[i][j] = m7[i][j];
                    wenjian = "m7.txt";
                    target = 24;
                    _mcheck.x = 6;
                    _mcheck.y = 7;
                    _dcheck.x = 5;
                    _dcheck.y = 8;
                }
            }
        } else if (l == 8){
            for (int i = 0; i < 10; i ++){
                for (int j = 0; j < 10; j ++){
                    temp[i][j] = m8[i][j];
                    wenjian = "m8.txt";
                    target = 20;
                    _mcheck.x = 8;
                    _mcheck.y = 8;
                    _dcheck.x = 7;
                    _dcheck.y = 6;
                }
            }
        } else if (l == 9){
            for (int i = 0; i < 10; i ++){
                for (int j = 0; j < 10; j ++){
                    temp[i][j] = m9[i][j];
                    wenjian = "m9.txt";
                    target = 31;
                    _mcheck.x = 7;
                    _mcheck.y = 7;
                    _dcheck.x = 8;
                    _dcheck.y = 8;
                }
            }
        }
    } else if (h == 'h'){
        if (l == 1){
            for (int i = 0; i < 15; i ++){
                for (int j = 0; j < 15; j ++){
                    temp[i][j] = h1[i][j];
                    wenjian = "h1.txt";
                    target = 45;
                    _mcheck.x = 12;
                    _mcheck.y = 4;
                    _dcheck.x = 3;
                    _dcheck.y = 10;
                }
            }
        } else if (l == 2){
            for (int i = 0; i < 15; i ++){
                for (int j = 0; j < 15; j ++){
                    temp[i][j] = h2[i][j];
                    wenjian = "h2.txt";
                    _dcheck.x = 0;
                    _dcheck.y = 8;
                    target = 138;
                }
            }
        } else if (l == 3){
            for (int i = 0; i < 15; i ++){
                for (int j = 0; j < 15; j ++){
                    temp[i][j] = h3[i][j];
                    wenjian = "h3.txt";
                    _dcheck.x = 0;
                    _dcheck.y = 1;
                    target = 67;
                }
            }
        } else if (l == 4){
            for (int i = 0; i < 15; i ++){
                for (int j = 0; j < 15; j ++){
                    temp[i][j] = h4[i][j];
                    wenjian = "h4.txt";
                    _mcheck.x = 3;
                    _mcheck.y = 13;
                    target = 33;
                }
            }
        } else if (l == 5){
            for (int i = 0; i < 15; i ++){
                for (int j = 0; j < 15; j ++){
                    temp[i][j] = h5[i][j];
                    wenjian = "h5.txt";
                }
            }
        } else if (l == 6){
            for (int i = 0; i < 15; i ++){
                for (int j = 0; j < 15; j ++){
                    temp[i][j] = h6[i][j];
                    wenjian = "h6.txt";
                }
            }
        } else if (l == 7){
            for (int i = 0; i < 15; i ++){
                for (int j = 0; j < 15; j ++){
                    temp[i][j] = h7[i][j];
                    wenjian = "h7.txt";
                }
            }
        } else if (l == 8){
            for (int i = 0; i < 15; i ++){
                for (int j = 0; j < 15; j ++){
                    temp[i][j] = h8[i][j];
                    wenjian = "h8.txt";
                }
            }
        } else if (l == 9){
            for (int i = 0; i < 15; i ++){
                for (int j = 0; j < 15; j ++){
                    temp[i][j] = h9[i][j];
                    wenjian = "h9.txt";
                }
            }
        }
    } else if (h == 'c'){
        if (l == 1){
            for (int i = 0; i < 20; i ++){
                for (int j = 0; j < 20; j ++){
                    temp[i][j] = c1[i][j];
                    wenjian = "c1.txt";
                    _dcheck.x = 7;
                    _dcheck.y = 3;
                    _mcheck.x = 1;
                    _mcheck.y = 17;
                    target = 63;
                }
            }
        } else if (l == 2){
            for (int i = 0; i < 20; i ++){
                for (int j = 0; j < 20; j ++){
                    temp[i][j] = c2[i][j];
                    wenjian = "c2.txt";
                    target = 59;
                    _dcheck.x = 8;
                    _dcheck.y = 18;
                    _mcheck.x = 3;
                    _mcheck.y = 1;
                }
            }
        } else if (l == 3){
            for (int i = 0; i < 20; i ++){
                for (int j = 0; j < 20; j ++){
                    temp[i][j] = c3[i][j];
                    wenjian = "c3.txt";
                }
            }
        } else if (l == 4){
            for (int i = 0; i < 20; i ++){
                for (int j = 0; j < 20; j ++){
                    temp[i][j] = c4[i][j];
                    wenjian = "c4.txt";
                }
            }
        } else if (l == 5){
            for (int i = 0; i < 20; i ++){
                for (int j = 0; j < 20; j ++){
                    temp[i][j] = c5[i][j];
                    wenjian = "c5.txt";
                }
            }
        } else if (l == 6){
            for (int i = 0; i < 20; i ++){
                for (int j = 0; j < 20; j ++){
                    temp[i][j] = c6[i][j];
                    wenjian = "c6.txt";
                }
            }
        } else if (l == 7){
            for (int i = 0; i < 20; i ++){
                for (int j = 0; j < 20; j ++){
                    temp[i][j] = c7[i][j];
                    wenjian = "c7.txt";
                }
            }
        } else if (l == 8){
            for (int i = 0; i < 20; i ++){
                for (int j = 0; j < 20; j ++){
                    temp[i][j] = c8[i][j];
                    wenjian = "c8.txt";
                }
            }
        } else if (l == 9){
            for (int i = 0; i < 20; i ++){
                for (int j = 0; j < 20; j ++){
                    temp[i][j] = c9[i][j];
                    wenjian = "c9.txt";
                }
            }
        }
    }
}

void draw (){
    system("cls");
    for (int i = 0; i < chang; i ++){
        for (int j = 0; j < chang; j ++){
            printf("%c",temp[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    printf("<target>: %d\n", target);
    if (shortest == 1000 && showrecord){
    	printf("<best>: No record\n");
	} else if (showrecord){
		printf("<best>: %d\n", shortest);
    }
    printf("<now>: %d",c);
}

bool vis[100][100];
int shortestpath;
int minpath = 0x7fffffff;
double persent = 0;

void walkableDFS(int nowx, int nowy)
{
	if (shortestpath >= minpath)
	{
		return;
	}
	if (nowx == 0 || nowy == 0 || nowx == chang - 1 || nowy == chang - 1)
	{		
		if (shortestpath < minpath)
		{
			minpath = shortestpath;
		}
		return;
	}
	if (!vis[nowx + 1][nowy] && temp[nowx + 1][nowy] != '#')
	{
		shortestpath ++;
		vis[nowx + 1][nowy] = true;
		walkableDFS(nowx + 1, nowy);
		vis[nowx + 1][nowy] = false;
		shortestpath --;	
	}
	if (!vis[nowx][nowy + 1] && temp[nowx][nowy + 1] != '#')
	{
		shortestpath ++;
		vis[nowx][nowy + 1] = true;
		walkableDFS(nowx, nowy + 1);
		vis[nowx][nowy + 1] = false;
		shortestpath --;	
	}
	if (!vis[nowx - 1][nowy] && temp[nowx - 1][nowy] != '#')
	{
		shortestpath ++;
		vis[nowx - 1][nowy] = true;
		walkableDFS(nowx - 1, nowy);
		vis[nowx - 1][nowy] = false;
		shortestpath --;	
	}
	if (!vis[nowx][nowy - 1] && temp[nowx][nowy - 1] != '#')
	{
		shortestpath ++;
		vis[nowx][nowy - 1] = true;
		walkableDFS(nowx, nowy - 1);
		vis[nowx][nowy - 1] = false;
		shortestpath --;	
	}
}

void random (){
	system("cls");
	cout << "<small map> (s) , <large map> (l) , <huge size map> (h) , <custom size map> (c)";
	temp_char = getch();
	c = 0;
	srand((int)time(0));
	int widerand = rand() % 3;
	if (temp_char == 'c')
	{
		system("cls");
		cout << "input map size: ";
		cin >> temp_int;
		chang = temp_int;
		system("mode con cols=120 lines=40");
	}
	else if (temp_char == 'h')
	{
		system("cls");
		system("mode con cols=100 lines=40");
		Sleep (1000);
		chang = 30;
	}
	else
	{
		if (temp_char == 'l')
		{
			widerand += 2;
		}
		if (widerand == 0)
		{
			chang = 8;
		}
		else if (widerand == 1)
		{
			chang = 10;
		}
		else if (widerand == 2)
		{
			chang = 15;
		}
		else if (widerand == 3)
		{
			chang = 20;
		}
		else if (widerand == 4)
		{
			chang = 25;
		}
	}
	system("cls");
	printf("loading...");
	while (true)
	{
		shortestpath = 0;
//		if (persent <= 100)
//		{
//			system("cls");
//			cout << persent << "%";
//			persent += 1;
//			Sleep(10);
//		}
		for (int i = 0; i < chang; i ++)
		{
			for (int j = 0; j < chang; j ++)
			{
				temp_int = rand() % 2;
				if (temp_int == 0)
					temp[i][j] = ' ';
				else
					temp[i][j] = '#';
			}
		}
		temp [1][1] = skin;
		for (int i = 0; i < chang; i ++)
		{
			temp[0][i] = '#';
		}
		for (int i = 0; i < chang; i ++)
		{
			temp[i][0] = '#';
		}
		walkableDFS(1, 1);
		if (minpath != 0x7fffffff)
		{
			target = minpath;
			break;
		}
	}
	x = 1;
	y = 1;
	minpath = 0x7fffffff;
	showrecord = false;
	system("cls");
	char read;
	while (over == 3)
	{
		draw();
		read = getch();
        if (read == 224){
            read = getch();
		}
		move(read);
		system("cls");
	}
	system("mode con cols=100 lines=30");
	if (over == 2 || over == 1){
        system ("cls");
        print(200,"You lose!\n");
        cout << "coins - 15!\n";
        cout << "<now coins>: " << coins;
        coins -= 15;
        Sleep(1000);
        system("cls");
        printf("You lose!\n");
        cout << "coins - 15!\n";
        cout << "<now coins>: " << coins;
        if (coins < 0){
			system("cls");
			cout << "You lose all your coins!\n";
			sleep (2);
			system("cls");
			if (playerlevel_short > 1){
				printf("Your level minus 1");
				sleep(2);
				playerlevel_short -= 1;
				ofstream levelminus ("level.txt");
				levelminus << playerlevel_short;
			} else {
				cout << "Be careful next time! Don't lose you level and coins!";
				sleep (2);
				system("cls");
			}
		}
       	sleep (2);
       	system("cls");
    } else {
        system ("cls");
        print(200,"You win!\n");
        cout << "coins + 20!" << endl;
        cout << "<now coins>: " << coins;
        coins += 20;
        Sleep(1000);
        system("cls");
        printf("You win!\n");
        cout << "coins + 20!\n";
        cout << "<now coins>: " << coins;
        sleep (2);
        system ("cls");
		if (c == target)
		{
			cout << "Reach the target!\n";
			cout << "coins + 20!\n";
			cout << "<now coins>: " << coins;
			coins += 20;
        	Sleep(1000);
        	system("cls");
        	printf("Reach the target!\n");
        	cout << "coins + 20!\n";
        	cout << "<now coins>: " << coins;
			sleep (2);
			system("cls");
		}
	}
	
	showrecord = true;
	c = 0;
	over = 3;
}

//_______________________________________________________________________________________________________________________________________________________________
//_______________________________________________________________________________________________________________________________________________________________
//_______________________________________________________________________________________________________________________________________________________________
//_______________________________________________________________________________________________________________________________________________________________
int main (){
	
	system("mode con cols=100 lines=30");
	srand((int)time(0));
	system ("color F0");
	printf("\n\n\n\n\n\n\n\n\n\n                Maze Game");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nversion:2.1.1E 20w02aIF winx64");
	sleep(2);
	system("cls");
	ifstream skintruefalsewenjian("skin.txt");
	skintruefalsewenjian >> skintruefalse;
	ifstream playerlevel("level.txt");
	playerlevel >> playerlevel_short;
	ifstream shopcoins("coins.txt");
    shopcoins >> coins;
    for (int i = 0; i < 4; i ++){
    	if (skintruefalse[i] == '1'){
    		skintruefalsebool[i] = true;
		}
	}
	while (true){
		cout << "<start> (s) , <rule> (r)" << endl;
		temp_char = getch();
    	if (temp_char == 's'){
        	system ("cls");
        	break;
    	} else if (temp_char == 'r'){
        	rule();
   		} else {
//   	 		MessageBox(GetForegroundWindow(),"Your choise is not correct!","",1);
   	        system("cls");
		}
	}
	
	Main:

	system("color F0");
	while (last == 6){
		while (true){
			system("cls");
			system("color F0");
			cout << "<shop> (s) , <player level> (p) , <continue> (c) , <leave> (l) , <rule> (r) , <feedback> (f)" << endl;
			char temp_char = getch();
			if (temp_char == 'f'){
				feedback();
				goto Main;
			}
			if (temp_char == 's'){
				shop();
			} else if (temp_char == 'l'){
				goto Leave;
			} else if (temp_char == 'p'){
				playerlevel_show();
			} else if (temp_char == 'r'){
				rule();
			} else if (temp_char == 'c'){
				break;
			} else {
//   	 			MessageBox(GetForegroundWindow(),"Your choise is not correct!","",1);
   	        	system("cls");
			}
		}
		system("cls");
		system("color F0");
		while (true){
			printf("<easy> (e) , <middle> (m) , <hard> (h) , <crazy> (c) , <random> (r) , <back> (b)");
       		hard = getch();
        	system("cls");
        	if (hard != 'e' && hard != 'm' && hard != 'h' && hard != 'c' && hard != 'b' && hard != 'r'){
//        		MessageBox(GetForegroundWindow(),"Your choise is not correct!","Error",1);
        		system("cls");
			} else if (hard == 'b'){
				goto Main;
			} else {
				break;
			}
		}
		if (hard == 'e'){
			system("color E0");
		} else if (hard == 'm'){
			system("color 60");
		} else if (hard == 'h'){
			system("color C0");
		} else if (hard == 'c'){
			system("color 40");
		} else if (hard == 'r'){
			system("color F0");
		}
		if (hard == 'r'){
			random();
			goto Main;
		}
		while (true){
			printf("Choose a level: 1,2,3,4,5,6,7,8,9\n<back> (b)\n");
        	temp_char = getch();
			if (temp_char == 'b'){
				goto Main;
			}
        	level = temp_char - '0';
        	system("cls");
        	if (level < 1 || level >= 10){
//        		MessageBox(GetForegroundWindow(),"Your choise is not correct!","",1);
        		system("cls");
			} else {
				break;
			}
		}
    	change(hard,level);
    	temp[1][1] = skin;
    	char a[1000];
    	strcpy(a,wenjian.c_str());
    	ifstream open(a);
    	open >> shortest;
        findsize(hard);
        while (over == 3){
            draw();
            temp_move = getch();
            if (temp_move == 224){
            	temp_move = getch();
			}
            move(temp_move);
            system("cls");
        }
        if (over == 2 || over == 1){
        	system ("cls");
        	print(200,"You lose!\n");
        	if (hard == 'e'){
				cout << "coins - 10!";
				cout << endl << "<now coins>: " << coins;
				Sleep (1000);
				system("cls");
				coins -= 10;
				printf("You lose!\n");
				cout << "coins - 10!";
				cout << endl << "<now coins>: " << coins;
			} else if (hard == 'm'){
				cout << "coins - 15!";
				cout << endl << "<now coins>: " << coins;
				sleep (1);
				system("cls");
				printf("You lose!\n");
				coins -= 15;
				cout << "coins - 15!";
				cout << endl << "<now coins>: " << coins;
			} else if (hard == 'h'){
				cout << "coins - 20!";
				cout << endl << "<now coins>: " << coins;
				sleep (1);
				system("cls");
				printf("You lose!\n");
				coins -= 20;
				cout << "coins - 20!";
				cout << endl << "<now coins>: " << coins;
			} else if (hard == 'c'){
				cout << "coins - 30!";
				cout << endl << "<now coins>: " << coins;
				Sleep (1000);
				system("cls");
				printf("You lose!\n");
				coins -= 30;
				cout << "coins - 30!";
				cout << endl << "<now coins>: " << coins;
			}
			if (coins < 0){
				system("cls");
				cout << "You lose all your coins!\n";
				sleep (2);
				system("cls");
				if (playerlevel_short > 1){
					cout << "Your level minus 1";
					playerlevel_short -= 1;
					ofstream levelminus ("level.txt");
					levelminus << playerlevel_short;
					sleep(2);
				} else {
					cout << "Be careful next time! Don't lose you level and coins!";
					sleep (2);
					system("cls");
				}
			}
        	sleep (2);
        	system("cls");
        } else {
        	system ("cls");
        	print(200,"You win!\n");
			cout << "coins + 10!";
			cout << endl << "<now coins>: " << coins;
			sleep(1);
			system("cls");
			printf("You win!\n");
        	coins += 10;
        	cout << "coins + 10!" << endl;
        	cout << "<now coins>: " << coins;
        	sleep (2);
        	system ("cls");
		}
		if (c < shortest && over != 2 && over != 1){
			ofstream record(a);
			record << c;
			cout << "New record!" << endl;
			if (hard == 'e'){
				cout << "coins + 10!";
				cout << endl << "<now coins>: " << coins;
				sleep (1);
				system("cls");
				cout << "New record!" << endl;
				coins += 10;
				cout << "coins + 10!";
				cout << endl << "<now coins>: " << coins;
			} else if (hard == 'm'){
				cout << "coins + 15!";
				cout << endl << "<now coins>: " << coins;
				sleep(1);
				system("cls");
				cout << "New record!" << endl;
				coins += 15;
				cout << "coins + 15!";
				cout << endl << "<now coins>: " << coins;
			} else if (hard == 'h'){
				cout << "coins + 20!";
				cout << endl << "<now coins>: " << coins;
				sleep(1);
				system("cls");
				cout << "New record!" << endl;
				coins += 20;
				cout << "coins + 20!";
				cout << endl << "<now coins>: " << coins;
			} else if (hard == 'c'){
				cout << "coins + 30!";
				cout << endl << "<now coins>: " << coins;
				sleep(1);
				system("cls");
				cout << "New record!" << endl;
				coins += 30;
				cout << "coins + 30!";
				cout << endl << "<now coins>: " << coins;
			}
			sleep(2);
			system("cls");
		}
		if (c == target && over != 2 && over != 1){
			cout << "Reach the target!" << endl;
			if (hard == 'e'){
				cout << "coins + 20!";
				cout << endl << "<now coins>: " << coins;
				sleep(1);
				system("cls");
				cout << "Reach the target!" << endl;
				coins += 20;
				cout << "coins + 20!";
				cout << endl << "<now coins>: " << coins;
			} else if (hard == 'm'){
				cout << "coins + 25!";
				cout << endl << "<now coins>: " << coins;
				sleep(1);
				system("cls");
				cout << "Reach the target!" << endl;
				coins += 25;
				cout << "coins + 25!";
				cout << endl << "<now coins>: " << coins;
			} else if (hard == 'h'){
				cout << "coins + 30!";
				cout << endl << "<now coins>: " << coins;
				sleep(1);
				system("cls");
				cout << "Reach the target!" << endl;
				coins += 30;
				cout << "coins + 30!";
				cout << endl << "<now coins>: " << coins;
			} else if (hard == 'c'){
				cout << "coins + 35!";
				cout << endl << "<now coins>: " << coins;
				sleep(1);
				system("cls");
				cout << "Reach the target!" << endl;
				coins += 35;
				cout << "coins + 35!";
				cout << endl << "<now coins>: " << coins;
				sleep(2);
				system("cls");
				cout << "Reach crazy mode's target!" << endl;
				cout << "level + 1!" << endl;
				playerlevel_short ++;
				cout << "<now level>: " << playerlevel_short;
			}
			sleep(2);
			system("cls");
		}
		for (int i = 0; i < 4; i ++){
			if (skintruefalsebool[i] == true){
				skintruefalse[i] = '1';
			} else {
				skintruefalse[i] = '0';
			}
		}
       	last = MessageBox(GetForegroundWindow(),"Play again?","",4);
        system ("cls");
    	x = 1;
    	y = 1;
    	over = 3;
    	change(hard,level);
    	shortest = 0;
    	c = 0;
    	target = 0;
    	system ("color F0");
	}
	
	Leave:
	
	system("cls");
	ofstream endcoins("coins.txt");
	endcoins << coins;
	ofstream endskin("skin.txt");
	endskin << skintruefalse;
	ofstream endlevel("level.txt");
	endlevel << playerlevel_short;
    cout << "Thanks for playing :)";
    sleep (2);
	
	return 0;
}
