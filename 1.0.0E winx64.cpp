#include<iostream>
#include<windows.h>
#include<unistd.h> 
using namespace std;

int main (){
	system("color F0");
	cout << endl << endl << endl << endl << "                " <<"Maze Game";
	sleep (1.5);
	system ("cls");
	char use = 23;
	cout << "rules:";
	cout << endl;
	cout << "e for up, s for left, d for down, f for right.";
	cout << endl;
	cout << "# is wall, if you crash on it, you lose.";
	cout << endl;
	cout << "@ if a machine to go to another @.";
	cout << endl;
	cout << "! is a key to open the doors.";
	cout << endl;
	cout << use << " is a wepon, if you have a wepon, you can break a #.";
	cout << endl;
	system ("pause");
	system ("cls");
	cout << "__________________________start__________________________";
	cout << endl;
	system ("pause");
	system("cls");
	char a;
	cout << "Choose a difficulty ('e' for easy, 'm' for middel, 'h' for hard)" << endl;
	cin >> a;
	bool flag = false;
	int countbreak = 0;
	system("cls");
	if (a == 'e'){
		int level;
		cout << "Choose a level (1,2,3,4,5)" << endl;
		cin >> level;
		system("cls");
		if (level == 1){
			
			char MiGong[6][6] = {{'#','O','#','#',' ','#'},{'#',' ',' ','#',' ','#'},
			{'#','#',' ',' ',' ','#'},{'#','#','#',' ','#','#'},{'#',' ',' ',' ',' ','#'},
			{'#','#','#','#','#','#'}};
			/*
			#O## #
			#  # #
			##   #
			### ##
			#    #
			######
			*/
			// output
			
			for (int i = 0; i < 6 ; i ++){
				for (int j = 0 ; j < 6 ; j ++){
					cout << MiGong[i][j] ;
				}
				cout << endl;
			}
			cout << endl;
			
			int  i = 0 , j = 1;
			cout << "press 'e' to go up,'s' to go left,'f' to go right,'d' to go down.ps : dont't forget to press Enter after you press.'";
			for (int A = 0 ; true ; A ++){
				
				
				cout << endl;
				char d;
				cin >> d;
				if (d == 'e'){
					
					i --;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i + 1][j] = ' ';
					    
					    system("cls");
					    for (int n = 0 ; n < 6 ; n ++){
					    	for (int m = 0 ; m < 6 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else {
						system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 's'){
					
					j --;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i][j + 1] = ' ';
					    
					    system("cls");
					    for (int n = 0 ; n < 6 ; n ++){
					    	for (int m = 0 ; m < 6 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
					} else {
						system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 'f'){
					
					j ++;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i][j - 1] = ' ';
					    
					    system("cls");
					    for (int n = 0 ; n < 6 ; n ++){
					    	for (int m = 0 ; m < 6 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else {
						system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 'd'){
					
					i ++;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i - 1][j] = ' ';
					    
					    system("cls");
					    for (int n = 0 ; n < 6 ; n ++){
					    	for (int m = 0 ; m < 6 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else {
						system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				}
				if (MiGong[0][4] == 'O'){
					system ("cls");
					cout << endl;
					cout << "You win !!! " << "Thanks for playing! this game was developed by Tony.";
					cout << endl;
					system ("pause");
					return 0;
				}	
			}
		//_____________________________________________________level 2 
		} else if (level == 2){
			
			
			char MiGong[7][7] = {{'#','#','O','#','#','#','#'},{'#',' ',' ','#',' ',' ','#'},{'#',' ','@',' ',' ','#','#'},{'#',' ',' ',' ','#',' ','#'},{'#','#','#',' ',' ',' ','#'},{'#','@','#','#',' ','#','#'},{'#',' ','#','#',' ','#','#'}};
			/*
			##O####					
			#  #  #					
			# @  ##					
			#   # #					
			###   #					
			#@## ##					
			# ## ##					
			*/
			// output
			
			for (int i = 0; i < 7 ; i ++){
				for (int j = 0 ; j < 7 ; j ++){
					cout << MiGong[i][j] ;
				}
				cout << endl;
			}
			cout << endl;
			
			int  i = 0 , j = 2;
			cout << "press 'e' to go up,'s' to go left,'f' to go right,'d' to go down.ps : dont't forget to press Enter after you press.'";
			cout << endl;
			cout << "Try going to @!";
			cout << endl;
			for (int A = 0 ; true ; A ++){
				
				char d;
				cin >> d;
				if (d == 'e'){
					
					i --;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i + 1][j] = ' ';
						system("cls");
					    
					    for (int n = 0 ; n < 7 ; n ++){
					    	for (int m = 0 ; m < 7 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
			 		} else if (MiGong [i][j] == '@'){
			 			
			 		    MiGong [i + 1][j] = ' ';
						i = 5;
						j = 1;
			 			MiGong [5][1] = 'O';
			 			system("cls");
			 			
			 			for (int n = 0 ; n < 7 ; n ++){
					    	for (int m = 0 ; m < 7 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else {
						system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 's'){
					
					j --;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i][j + 1] = ' ';
					    system("cls");
					    for (int n = 0 ; n < 7 ; n ++){
					    	for (int m = 0 ; m < 7 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else if (MiGong [i][j] == '@'){
						
			 		    MiGong [i][j + 1] = ' ';
			 		    i = 5;
						j = 1;
			 			MiGong [5][1] = 'O';
			 			system("cls");
			 			for (int n = 0 ; n < 7 ; n ++){
					    	for (int m = 0 ; m < 7 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else {
						system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 'f'){
					
					j ++;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i][j - 1] = ' ';
					    system("cls");
					    for (int n = 0 ; n < 7 ; n ++){
					    	for (int m = 0 ; m < 7 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else if (MiGong [i][j] == '@'){
						
			 		    MiGong [i][j - 1] = ' ';
			 		    i = 5;
						j = 1;
			 			MiGong [5][1] = 'O';
			 			system("cls");
			 			for (int n = 0 ; n < 7 ; n ++){
					    	for (int m = 0 ; m < 7 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else {
						system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 'd'){
					
					i ++;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i - 1][j] = ' ';
					    system("cls");
					    for (int n = 0 ; n < 7 ; n ++){
					    	for (int m = 0 ; m < 7 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else if (MiGong [i][j] == '@'){
						
			 		    MiGong [i - 1][j] = ' ';
			 		    i = 5;
						j = 1;
			 			MiGong [5][1] = 'O';
			 			system("cls");
			 			for (int n = 0 ; n < 7 ; n ++){
					    	for (int m = 0 ; m < 7 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else {
						system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				}
				if (MiGong[6][1] == 'O' || MiGong[6][4] == 'O'){
					system ("cls");
					cout << endl;
					cout << "You win !!! " << "Thanks for playing ! this game was developed by Tony.";
					cout << endl;
					system ("pause");
					return 0;
				}	
			}
		
		//_______________________________________________________level 3	
			
		} else if (level == 3){
			
			char MiGong[10][10] = {{'#','#','#','#','#','O','#','#','#','#'},{'#','#','#',' ',' ',' ',' ','#','@','#',},
			{'#','#','#',' ','#','#',' ','#',' ','#'},{'#',' ',' ',' ','#','#',' ',' ',' ','#'},
			{'#',' ','#',' ','#',' ','#',' ','#','#'},{'#',' ',' ',' ',' ',' ','#',' ','#','#'},
			{'#','#','#','#','#',' ','#',' ','#','#'},{'#','#','@',' ','#',' ','#',' ',' ',' '},
			{'#','#','#',' ','#',' ','#','#','#','#'},{'#','#','#',' ','#',' ','#','#','#','#'}}; 
			/*
			#####O####
			###    #@#
			### ## # #
			#   ##   #
			# # # # ##
			#     # ##
			##### # ##
			##@ # #   
			### # ####
			### # #### 
							
			*/
			// output
			
			for (int i = 0; i < 10 ; i ++){
				for (int j = 0 ; j < 10 ; j ++){
					cout << MiGong[i][j] ;
				}
				cout << endl;
			}
			cout << endl;
			
			int  i = 0 , j = 5;
			cout << "press 'e' to go up,'s' to go left,'f' to go right,'d' to go down.ps : dont't forget to press Enter after you press.'";
			cout << endl;
			cout << "Try going to @!";
			cout << endl;
			for (int A = 0 ; true ; A ++){
				
				
				char d;
				cin >> d;
				if (d == 'e'){
					
					i --;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i + 1][j] = ' ';
						system("cls");
					    
					    for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
			 		} else if (MiGong [i][j] == '@'){
			 			
			 		    MiGong [i + 1][j] = ' ';
						i = 7;
						j = 2;
			 			MiGong [7][2] = 'O';
			 			system("cls");
			 			
			 			for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else {
						system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 's'){
					
					j --;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i][j + 1] = ' ';
					    system("cls");
					    for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else {
						system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 'f'){
					
					j ++;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i][j - 1] = ' ';
					    system("cls");
					    for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else {
						system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 'd'){
					
					i ++;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i - 1][j] = ' ';
					    system("cls");
					    for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else {
						system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				}
				if (MiGong[9][3] == 'O' || MiGong[9][5] == 'O'|| MiGong[7][9] == 'O'){
					system ("cls");
					cout << endl;
					cout << "You win !!! " << "Thanks for playing ! this game was developed by Tony.";
					cout << endl;
					system ("pause");
					return 0;
				}	
			}
	//___________________________________________________________________________________level 4
		} else if (level == 4){
			
			char MiGong[10][10] = {{'#','#','#','#','#','#','#','#','#','#'},{'#',' ',' ',' ',' ',' ',' ','#','@','#'},
			{'#','O','#','-','#','#','-','#',' ','#'},{'#',' ',' ',' ','#','#',' ',' ',' ','#'},
			{'#',' ','!',' ','#',' ',' ',' ','#','#'},{'#',' ',' ',' ','#',' ','#',' ','#','#'},
			{'#','#','#','#','#',' ','#',' ','#','#'},{'#','#','@',' ','#',' ','#',' ',' ',' '},
			{'#','#','#',' ','#',' ','#','#','#','#'},{'#','#','#',' ','#',' ','#','#','#','#'}}; 
			/*
			##########
			#      #@#
			#O#-##-# #
			#   ##   #
			# ! #   ##
			#   # # ##
			##### # ##
			##@ # #   
			### # ####
			### # #### 
							
			*/
			// output
			
			for (int i = 0; i < 10 ; i ++){
				for (int j = 0 ; j < 10 ; j ++){
					cout << MiGong[i][j] ;
				}
				cout << endl;
			}
			cout << endl;
			
			int  i = 2 , j = 1;
			cout << "press 'e' to go up,'s' to go left,'f' to go right,'d' to go down.ps : dont't forget to press Enter after you press.'";
			cout << endl;
			cout << "Try going to @!";
            cout << endl;
            cout << "There are doors which needs to be open by a key.";
			cout << endl;
			for (int A = 0 ; true ; A ++){
				
				
				char d;
				cin >> d;
				if (d == 'e'){
					
					i --;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i + 1][j] = ' ';
						system("cls");
					    
					    for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
			 		} else if (MiGong [i][j] == '@'){
			 			
			 		    MiGong [i + 1][j] = ' ';
						i = 7;
						j = 2;
			 			MiGong [7][2] = 'O';
			 			system("cls");
			 			
			 			for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else if (MiGong [i][j] == '!'){
                        MiGong [2][3] = ' ';
						MiGong [2][6] = ' ';
						MiGong [4][2] = 'O';
						MiGong [i + 1][j] = ' ';
						system("cls");

						for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}

                    } else {
                    	system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 's'){
					
					j --;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i][j + 1] = ' ';
					    system("cls");
					    for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else if (MiGong [i][j] == '!'){
                        MiGong [2][3] = ' ';
						MiGong [2][6] = ' ';
						MiGong [i][j] = 'O';
						MiGong [i - 1][j] = ' ';
						system("cls");

						for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
                    } else {
                    	system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 'f'){
					j ++;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i][j - 1] = ' ';
					    system("cls");
					    for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else if (MiGong [i][j] == '!'){
                        MiGong [2][3] = ' ';
						MiGong [2][6] = ' ';
						MiGong [i][j] = 'O';
						MiGong [i][j - 1] = ' ';
						system("cls");

						for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
                    } else {
                    	system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 'd'){
					
					i ++;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i - 1][j] = ' ';
					    system("cls");
					    for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else if (MiGong [i][j] == '!'){
                        MiGong [2][3] = ' ';
						MiGong [2][6] = ' ';
						MiGong [i][j] = 'O';
						MiGong [i - 1][j] = ' ';
						system("cls");
						
						for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
					} else if (MiGong [i][j] == '-'){
						MiGong [i-1][j] = 'O';
						i --;
						cout << "This is a door, please get the key.";
	
                    } else {
                    	system ("cls");
						cout << "Your choice is not correct!"; 
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else {
					system ("cls");
					cout << "Your choice is not correct!"; 
					cout << endl;
                    system ("pause");
					return 0;
				}
				if (MiGong[9][3] == 'O' || MiGong[9][5] == 'O'|| MiGong[7][9] == 'O'){
					system ("cls");
					cout << endl;
					cout << "You win !!! " << "Thanks for playing ! this game was developed by Tony.";
					cout << endl;
					system ("pause");
					return 0;
				}	
			}
			// __________________________________________________________________________________level 5
		} else if (level == 5){
		char we = 23;
		char MiGong[10][10] = {{'#','#','#','#','#','#','#','#','#','#'},{'#',' ',' ',' ',' ',' ',' ','#','@','#'},
			{'#','O','#','-','#','#','-','#',' ','#'},{'#',' ',' ',' ','#','#',' ',' ',' ','#'},
			{'#',' ','!',' ','#',' ','#',' ','#','#'},{'#',' ',' ',' ','#',' ','#',' ','#','#'},
			{'#',we,'#','#','#',' ','#',' ','#','#'},{'#','#','@',' ','#',' ','#',' ',' ',' '},
			{'#','#','#',' ','#',' ','#','#','#','#'},{'#','#','#',' ','#',' ','#','#','#','#'}}; 
			/*
			##########
			#      #@#
			#O#-##-# #
			#   ##   #
			# ! #   ##
			#   # # ##
			#|### # ##
			##@ # #   
			### # ####
			### # #### 
							
			*/
			// output
			
			for (int i = 0; i < 10 ; i ++){
				for (int j = 0 ; j < 10 ; j ++){
					cout << MiGong[i][j] ;
				}
				cout << endl;
			}
			cout << endl;
			int  i = 2 , j = 1;
			cout << "press 'e' to go up,'s' to go left,'f' to go right,'d' to go down.ps : dont't forget to press Enter after you press.'";
			cout << endl;
			cout << "Try going to @!";
            cout << endl;
            cout << "There are doors which needs to be open by a key.";
			cout << endl;
			cout << "Try get '" << we << "' !";
			cout << endl;
			for (int A = 0 ; true ; A ++){
				
				char d;
				cin >> d;
				if (d == 'e'){
					
					i --;
					if (MiGong [i][j] == '#'){
						if (flag){
							if (countbreak == 5){
								flag = false;
								MiGong [i][j] = 'O';
								MiGong [i + 1][j] = ' ';
								system ("cls");
								cout << "Your wepon is not allowed any more!";
								cout << endl;
								for (int n = 0 ; n < 10 ; n ++){
					    			for (int m = 0 ; m < 10 ; m ++){
					    				cout << MiGong [n][m];
									}
									cout << endl;
								}
							} else {
								MiGong [i][j] = 'O';
								MiGong [i + 1][j] = ' ';
								countbreak ++;
								system("cls");
								for (int n = 0 ; n < 10 ; n ++){
					    			for (int m = 0 ; m < 10 ; m ++){
					    				cout << MiGong [n][m];
									}
									cout << endl;
								}
							}
						} else{
							cout << "You lose! Try again next time!";
							cout << endl;
                        	system ("pause");
							return 0;
						}
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i + 1][j] = ' ';
						system("cls");
					    
					    for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
			 		} else if (MiGong [i][j] == '@'){
			 			
			 		    MiGong [i + 1][j] = ' ';
						i = 7;
						j = 2;
			 			MiGong [7][2] = 'O';
			 			system("cls");
			 			
			 			for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else if (MiGong [i][j] == '!'){
                        MiGong [2][3] = ' ';
						MiGong [2][6] = ' ';
						MiGong [4][2] = 'O';
						MiGong [i + 1][j] = ' ';
						system("cls");

						for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}

                    } else {
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 's'){
					
					j --;
					if (MiGong [i][j] == '#'){
						if (flag){
							if (countbreak == 5){
								flag = false;
								MiGong [i][j] = 'O';
								MiGong [i][j + 1] = ' ';
								system ("cls");
								cout << "Your wepon is not allowed any more!";
								cout << endl;
								for (int n = 0 ; n < 10 ; n ++){
					    			for (int m = 0 ; m < 10 ; m ++){
					    					cout << MiGong [n][m];
									}
									cout << endl;
									}
							} else {
								MiGong [i][j] = 'O';
								MiGong [i][j + 1] = ' ';
								countbreak ++;
								system("cls");
								for (int n = 0 ; n < 10 ; n ++){
					    			for (int m = 0 ; m < 10 ; m ++){
					    				cout << MiGong [n][m];
									}
									cout << endl;
								}
							}
						} else{
							cout << "You lose! Try again next time!";
							cout << endl;
                        	system ("pause");
							return 0;
						}
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i][j + 1] = ' ';
					    system("cls");
					    for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else if (MiGong [i][j] == '!'){
                        MiGong [2][3] = ' ';
						MiGong [2][6] = ' ';
						MiGong [i][j] = 'O';
						MiGong [i][j + 1] = ' ';
						system("cls");

						for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
                    } else {
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 'f'){
					
					j ++;
					if (MiGong [i][j] == '#'){
						if (flag){
							if (countbreak == 5){
								flag = false;
								MiGong [i][j] = 'O';
								MiGong [i][j - 1] = ' ';
								system ("cls");
								cout << "Your wepon is not allowed any more!";
								cout << endl;
								for (int n = 0 ; n < 10 ; n ++){
					    			for (int m = 0 ; m < 10 ; m ++){
					    				cout << MiGong [n][m];
									}
									cout << endl;
								}
							} else {
								MiGong [i][j] = 'O';
								MiGong [i][j - 1] = ' ';
								countbreak ++;
								system("cls");
								for (int n = 0 ; n < 10 ; n ++){
					    			for (int m = 0 ; m < 10 ; m ++){
					    				cout << MiGong [n][m];
									}
									cout << endl;
								}
							}
						} else{
							cout << "You lose! Try again next time!";
							cout << endl;
                        	system ("pause");
							return 0;
						}
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i][j - 1] = ' ';
					    system("cls");
					    for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else if (MiGong [i][j] == '!'){
                        MiGong [2][3] = ' ';
						MiGong [2][6] = ' ';
						MiGong [i][j] = 'O';
						MiGong [i][j - 1] = ' ';
						system("cls");

						for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
                    } else {
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 'd'){
				
					i ++;
					if (MiGong [i][j] == '#'){
						if (flag){
							if (countbreak == 5){
								flag = false;
								MiGong [i][j] = 'O';
								MiGong [i - 1][j] = ' ';
								system ("cls");
								cout << "Your wepon is not allowed any more!";
								cout << endl;
								for (int n = 0 ; n < 10 ; n ++){
					    			for (int m = 0 ; m < 10 ; m ++){
					    					cout << MiGong [n][m];
									}
									cout << endl;
									}
							} else {
								MiGong [i][j] = 'O';
								MiGong [i - 1][j] = ' ';
								countbreak ++;
								system("cls");
								for (int n = 0 ; n < 10 ; n ++){
					    			for (int m = 0 ; m < 10 ; m ++){
					    				cout << MiGong [n][m];
									}
									cout << endl;
								}
							}
						} else{
							cout << "You lose! Try again next time!";
							cout << endl;
                        	system ("pause");
							return 0;
						}
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i - 1][j] = ' ';
					    system("cls");
					    for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else if (MiGong [i][j] == '!'){
                        MiGong [2][3] = ' ';
						MiGong [2][6] = ' ';
						MiGong [i][j] = 'O';
						MiGong [i - 1][j] = ' ';
						system("cls");
						
						for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
					} else if (MiGong [i][j] == '-'){
						MiGong [i-1][j] = 'O';
						i --;
						cout << "This is a door, please get the key.";
                    } else if (MiGong [i][j] == we){
                    	MiGong [i][j] = 'O';
                    	MiGong [i - 1][j] = ' ';
                    	flag = true;
                    	system("cls");
                    	for (int i = 0; i < 10; i++){
                    		for (int j = 0; j < 10; j ++){
                    			cout << MiGong [i][j];
							}
							cout << endl;
						}
					}else {
						cout << "Your choice is not correct!"; 
						cout << endl;
                        system ("pause");
						return 0;
					}
				}
				if (MiGong[9][3] == 'O' || MiGong[9][5] == 'O'|| MiGong[7][9] == 'O'){
					system ("cls");
					cout << endl;
					cout << "You win !!! " << "Thanks for playing ! this game was developed by Tony.";
					cout << endl;
					system ("pause");
					return 0;
				}	
			}	
			
		} else {
			system ("cls");
			cout << "Your choice is not correct!" << endl;
			cout << endl;
            system ("pause");
			return 0;
		}
	//______________________________________________________
	//______________________________________________________
	//______________________________________________________
	//middle
	} else if (a == 'm'){
		
		int level;
		cout << "Choose a level (1,2,3,4,5)" << endl;
		cin >> level;
		system("cls");
		if (level == 1){
			
			char MiGong[10][13] = {{'#','#','#','#','#','#','#','#','#','#','#','#','#'},
			{'#','#','O','#','#',' ',' ',' ','#','#',' ','#','#'},
			{'#','#',' ',' ','#',' ','#',' ',' ','#',' ',' ','#'},
			{'#',' ','#',' ',' ',' ','#','#',' ',' ','#',' ','#'},
			{'#',' ','#','#',' ','#',' ','#',' ',' ','#','#','#'},
			{'#','#',' ',' ','#','#',' ','#',' ','#',' ',' ','#'},
			{'#','#','#',' ','#',' ','#',' ',' ','#','#',' ','#'},
			{'#','#',' ','#',' ','#','#','#',' ',' ','#',' ','#'},
			{'#','#','#','#','#',' ',' ',' ','#',' ',' ','#','#'},
			{'#','#','#','#','#','#','#','#','#',' ','#','#','#'}};
			
			// output
			
			for (int i = 0; i < 10 ; i ++){
				for (int j = 0 ; j < 13 ; j ++){
					cout << MiGong[i][j] ;
				}
				cout << endl;
			}
			cout << endl;
			
			int  i =  1, j = 2;
			cout << "press 'e' to go up,'s' to go left,'f' to go right,'d' to go down.ps : dont't forget to press Enter after you press.'";
			for (int A = 0 ; true ; A ++){
				
				
				cout << endl;
				char d;
				cin >> d;
				if (d == 'e'){
					
					i --;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i + 1][j] = ' ';
					    
					    system("cls");
					    for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 13 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else {
						system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 's'){
					
					j --;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i][j + 1] = ' ';
					    
					    system("cls");
					    for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 13 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
					} else {
						system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 'f'){
					
					j ++;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i][j - 1] = ' ';
					    
					    system("cls");
					    for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 13 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else {
						system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 'd'){
					
					i ++;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i - 1][j] = ' ';
					    
					    system("cls");
					    for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 13 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else {
						system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				}
				if (MiGong[9][9] == 'O'){
					system ("cls");
					cout << endl;
					cout << "You win !!! " << "Thanks for playing! this game was developed by Tony.";
					cout << endl;
					system ("pause");
					return 0;
				}	
			}
		//_____________________________________________________level 2 
		} else if (level == 2){
			
			
			char MiGong[15][15] = {{'#','#','#','#','#','O','#','#','#','#','#','#','#','#','#'},
			{'#',' ','#',' ',' ',' ','#','#',' ',' ',' ',' ','#',' ','#'},
			{'#','#','#','#','#',' ','#',' ',' ','#','#',' ',' ',' ','#'},
			{'#','@',' ',' ',' ',' ','#','#',' ','#','#',' ','#','@','#'},
			{'#','#','#','#','#',' ','#','#',' ','#','#','#','#','#','#'},
			{'#',' ','#','#','#','#','#',' ',' ',' ',' ',' ',' ','#','#'},
			{'#',' ',' ',' ',' ',' ','#','#','#',' ','#','#',' ','#','#'},
			{'#',' ',' ','#',' ','#',' ','#',' ',' ','#',' ',' ',' ','#'},
			{'#','#',' ','#','#','#',' ','#',' ','#',' ','#','#',' ','#'},
			{'#','#','#','#',' ','#','#',' ',' ',' ',' ','#','#',' ','#'},
			{'#',' ',' ','#','#',' ','#','#',' ','#',' ','#',' ',' ','#'},
			{'#',' ','#','#',' ',' ','#',' ',' ','#',' ',' ',' ',' ','#'},
			{'#','#',' ','#',' ','#',' ','#','#',' ','#',' ',' ','#','#'},
			{'#','#','#','#',' ','#','#',' ','#','#','#','#',' ',' ','#'},
			{'#','#','#','#',' ','#','#',' ','#','#','#','#',' ','#','#'}};
			/*
			#####O#########
			# #   ##    # #
			##### #  ##   #
			#@    ## ## #@#
			##### ## ######
			# #####      ##
			#     ### ## ##
			#  # # #  #   #
			## ### # # ## #
			#### ##    ## #
			#  ## ## #  ###
			# ##  #  #    #
			## # # ## #  ##
			#### ## ####  #
			#### ## #### ##				
			*/
			// output
			
			for (int i = 0; i < 15 ; i ++){
				for (int j = 0 ; j < 15 ; j ++){
					cout << MiGong[i][j] ;
				}
				cout << endl;
			}
			cout << endl;
			
			int  i = 0 , j = 5;
			cout << "press 'e' to go up,'s' to go left,'f' to go right,'d' to go down.ps : dont't forget to press Enter after you press.'";
			cout << endl;
			cout << "Try going to @!";
			cout << endl;
			for (int A = 0 ; true ; A ++){
				
				char d;
				cin >> d;
				if (d == 'e'){
					
					i --;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i + 1][j] = ' ';
						system("cls");
					    
					    for (int n = 0 ; n < 15 ; n ++){
					    	for (int m = 0 ; m < 15 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
			 		} else if (MiGong [i][j] == '@'){
			 			
			 		    MiGong [i + 1][j] = ' ';
						i = 3;
						j = 13;
			 			MiGong [3][13] = 'O';
			 			system("cls");
			 			
			 			for (int n = 0 ; n < 15 ; n ++){
					    	for (int m = 0 ; m < 15 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else {
						system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 's'){
					
					j --;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i][j + 1] = ' ';
					    system("cls");
					    for (int n = 0 ; n < 15 ; n ++){
					    	for (int m = 0 ; m < 15 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else if (MiGong [i][j] == '@'){
						
			 		    MiGong [i][j + 1] = ' ';
			 		    i = 3;
						j = 13;
			 			MiGong [3][13] = 'O';
			 			system("cls");
			 			for (int n = 0 ; n < 15 ; n ++){
					    	for (int m = 0 ; m < 15 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else {
						system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 'f'){
					
					j ++;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i][j - 1] = ' ';
					    system("cls");
					    for (int n = 0 ; n < 15 ; n ++){
					    	for (int m = 0 ; m < 15 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else if (MiGong [i][j] == '@'){
						
			 		    MiGong [i][j - 1] = ' ';
			 		    i = 3;
						j = 13;
			 			MiGong [3][13] = 'O';
			 			system("cls");
			 			for (int n = 0 ; n < 15 ; n ++){
					    	for (int m = 0 ; m < 15 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else {
						system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 'd'){
					
					i ++;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i - 1][j] = ' ';
					    system("cls");
					    for (int n = 0 ; n < 15 ; n ++){
					    	for (int m = 0 ; m < 15 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else if (MiGong [i][j] == '@'){
						
			 		    MiGong [i - 1][j] = ' ';
			 		    i = 3;
						j = 13;
			 			MiGong [3][13] = 'O';
			 			system("cls");
			 			for (int n = 0 ; n < 15 ; n ++){
					    	for (int m = 0 ; m < 15 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else {
						system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				}
				if (MiGong[14][12] == 'O'){
					system ("cls");
					cout << endl;
					cout << "You win !!! " << "Thanks for playing ! this game was developed by Tony.";
					cout << endl;
					system ("pause");
					return 0;
				}	
			}
		
		//_______________________________________________________level 3	
			
		} else if (level == 3){
			
			char MiGong[15][15] = {{'#','#','O','#','#','#','#','#','-','#','#','#','#','#','#'},
				       {'#',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ','#',' ','#'},
					   {'#','#','#','#','#',' ','#',' ',' ','#','#',' ',' ',' ','#'},
					   {'#','@',' ',' ',' ',' ','#','#',' ','#','#',' ','#','@','#'},
					   {'#','#','#','#','#',' ','#','#',' ','#','#','#','#','#','#'},
					   {'#',' ','#','#','#','#','#',' ',' ',' ',' ',' ',' ','#','#'},
					   {'#',' ',' ',' ',' ',' ','#','#','#',' ','#','#',' ','#','#'},
					   {'#',' ',' ','#',' ','#',' ','#',' ',' ','#',' ',' ',' ','#'},
					   {'#','#',' ','#','#','#',' ','#',' ','#',' ','#','#',' ','#'},
					   {'#','#','#','#',' ','#','#',' ',' ',' ',' ','#','#',' ','#'},
					   {'#',' ',' ','#','#',' ','#','#',' ','#',' ','#',' ',' ','#'},
					   {'#',' ','#','#',' ',' ','#',' ',' ','#',' ',' ',' ',' ','#'},
					   {'#','#',' ','#',' ','#',' ','#','#',' ','#',' ',' ','#','#'},
					   {'#','#','#','#',' ','#','#',' ','#','#','#','#',' ',' ','#'},
					   {'#','#','#','#',' ','#','#',' ','#','#','#','#',' ','#','#'}}; 
			/*
			##O#####-######
			#   # #     !##
			###   ##@ ## ##
			#  # ###-### ##
			## #  ## ### ##
			#### #-#-#-#--#
			## # # #     ##
			###   #   # # #
			# #   # #@# # #
			## #     # # ##
			# # # # # # # #
			## # # # # # ##
			# # # # # # # #
			## # # # # # ##
			### ### ## ####
							
			*/
			// output
			
			for (int i = 0; i < 10 ; i ++){
				for (int j = 0 ; j < 10 ; j ++){
					cout << MiGong[i][j] ;
				}
				cout << endl;
			}
			cout << endl;
			
			int  i = 0 , j = 5;
			cout << "press 'e' to go up,'s' to go left,'f' to go right,'d' to go down.ps : dont't forget to press Enter after you press.'";
			cout << endl;
			cout << "Try going to @!";
			cout << endl;
			for (int A = 0 ; true ; A ++){
				
				
				char d;
				cin >> d;
				if (d == 'e'){
					
					i --;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i + 1][j] = ' ';
						system("cls");
					    
					    for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
			 		} else if (MiGong [i][j] == '@'){
			 			
			 		    MiGong [i + 1][j] = ' ';
						i = 7;
						j = 2;
			 			MiGong [7][2] = 'O';
			 			system("cls");
			 			
			 			for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else {
						system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 's'){
					
					j --;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i][j + 1] = ' ';
					    system("cls");
					    for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else {
						system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 'f'){
					
					j ++;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i][j - 1] = ' ';
					    system("cls");
					    for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else {
						system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 'd'){
					
					i ++;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i - 1][j] = ' ';
					    system("cls");
					    for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else {
						system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				}
				if (MiGong[9][3] == 'O' || MiGong[9][5] == 'O'|| MiGong[7][9] == 'O'){
					system ("cls");
					cout << endl;
					cout << "You win !!! " << "Thanks for playing ! this game was developed by Tony.";
					cout << endl;
					system ("pause");
					return 0;
				}	
			}
	//___________________________________________________________________________________level 4
		} else if (level == 4){
			
			char MiGong[10][10] = {{'#','#','#','#','#','#','#','#','#','#'},{'#',' ',' ',' ',' ',' ',' ','#','@','#'},
			{'#','O','#','-','#','#','-','#',' ','#'},{'#',' ',' ',' ','#','#',' ',' ',' ','#'},
			{'#',' ','!',' ','#',' ',' ',' ','#','#'},{'#',' ',' ',' ','#',' ','#',' ','#','#'},
			{'#','#','#','#','#',' ','#',' ','#','#'},{'#','#','@',' ','#',' ','#',' ',' ',' '},
			{'#','#','#',' ','#',' ','#','#','#','#'},{'#','#','#',' ','#',' ','#','#','#','#'}}; 
			/*
			##########
			#      #@#
			#O#-##-# #
			#   ##   #
			# ! #   ##
			#   # # ##
			##### # ##
			##@ # #   
			### # ####
			### # #### 
							
			*/
			// output
			
			for (int i = 0; i < 10 ; i ++){
				for (int j = 0 ; j < 10 ; j ++){
					cout << MiGong[i][j] ;
				}
				cout << endl;
			}
			cout << endl;
			
			int  i = 2 , j = 1;
			cout << "press 'e' to go up,'s' to go left,'f' to go right,'d' to go down.ps : dont't forget to press Enter after you press.'";
			cout << endl;
			cout << "Try going to @!";
            cout << endl;
            cout << "There are doors which needs to be open by a key.";
			cout << endl;
			for (int A = 0 ; true ; A ++){
				
				
				char d;
				cin >> d;
				if (d == 'e'){
					
					i --;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i + 1][j] = ' ';
						system("cls");
					    
					    for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
			 		} else if (MiGong [i][j] == '@'){
			 			
			 		    MiGong [i + 1][j] = ' ';
						i = 7;
						j = 2;
			 			MiGong [7][2] = 'O';
			 			system("cls");
			 			
			 			for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else if (MiGong [i][j] == '!'){
                        MiGong [2][3] = ' ';
						MiGong [2][6] = ' ';
						MiGong [4][2] = 'O';
						MiGong [i + 1][j] = ' ';
						system("cls");

						for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}

                    } else {
                    	system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 's'){
					
					j --;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i][j + 1] = ' ';
					    system("cls");
					    for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else if (MiGong [i][j] == '!'){
                        MiGong [2][3] = ' ';
						MiGong [2][6] = ' ';
						MiGong [i][j] = 'O';
						MiGong [i - 1][j] = ' ';
						system("cls");

						for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
                    } else {
                    	system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 'f'){
					
					j ++;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i][j - 1] = ' ';
					    system("cls");
					    for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else if (MiGong [i][j] == '!'){
                        MiGong [2][3] = ' ';
						MiGong [2][6] = ' ';
						MiGong [i][j] = 'O';
						MiGong [i][j - 1] = ' ';
						system("cls");

						for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
                    } else {
                    	system ("cls");
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 'd'){
					
					i ++;
					if (MiGong [i][j] == '#'){
						system ("cls");
						cout << "You lose! Try again next time!";
						cout << endl;
                        system ("pause");
						return 0;
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i - 1][j] = ' ';
					    system("cls");
					    for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else if (MiGong [i][j] == '!'){
                        MiGong [2][3] = ' ';
						MiGong [2][6] = ' ';
						MiGong [i][j] = 'O';
						MiGong [i - 1][j] = ' ';
						system("cls");
						
						for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
					} else if (MiGong [i][j] == '-'){
						MiGong [i-1][j] = 'O';
						i --;
						cout << "This is a door, please get the key.";
	
                    } else {
                    	system ("cls");
						cout << "Your choice is not correct!"; 
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else {
					system ("cls");
					cout << "Your choice is not correct!"; 
					cout << endl;
                    system ("pause");
					return 0;
				}
				if (MiGong[9][3] == 'O' || MiGong[9][5] == 'O'|| MiGong[7][9] == 'O'){
					system ("cls");
					cout << endl;
					cout << "You win !!! " << "Thanks for playing ! this game was developed by Tony.";
					cout << endl;
					system ("pause");
					return 0;
				}	
			}
			// __________________________________________________________________________________level 5
		} else if (level == 5){
		char we = 23;
		char MiGong[10][10] = {{'#','#','#','#','#','#','#','#','#','#'},{'#',' ',' ',' ',' ',' ',' ','#','@','#'},
			{'#','O','#','-','#','#','-','#',' ','#'},{'#',' ',' ',' ','#','#',' ',' ',' ','#'},
			{'#',' ','!',' ','#',' ','#',' ','#','#'},{'#',' ',' ',' ','#',' ','#',' ','#','#'},
			{'#',we,'#','#','#',' ','#',' ','#','#'},{'#','#','@',' ','#',' ','#',' ',' ',' '},
			{'#','#','#',' ','#',' ','#','#','#','#'},{'#','#','#',' ','#',' ','#','#','#','#'}}; 
			/*
			##########
			#      #@#
			#O#-##-# #
			#   ##   #
			# ! #   ##
			#   # # ##
			#|### # ##
			##@ # #   
			### # ####
			### # #### 
							
			*/
			// output
			
			for (int i = 0; i < 10 ; i ++){
				for (int j = 0 ; j < 10 ; j ++){
					cout << MiGong[i][j] ;
				}
				cout << endl;
			}
			cout << endl;
			int  i = 2 , j = 1;
			cout << "press 'e' to go up,'s' to go left,'f' to go right,'d' to go down.ps : dont't forget to press Enter after you press.'";
			cout << endl;
			cout << "Try going to @!";
            cout << endl;
            cout << "There are doors which needs to be open by a key.";
			cout << endl;
			cout << "Try get '" << we << "' !";
			cout << endl;
			for (int A = 0 ; true ; A ++){
				
				char d;
				cin >> d;
				if (d == 'e'){
					
					i --;
					if (MiGong [i][j] == '#'){
						if (flag){
							if (countbreak == 5){
								flag = false;
								MiGong [i][j] = 'O';
								MiGong [i + 1][j] = ' ';
								system ("cls");
								cout << "Your wepon is not allowed any more!";
								cout << endl;
								for (int n = 0 ; n < 10 ; n ++){
					    			for (int m = 0 ; m < 10 ; m ++){
					    				cout << MiGong [n][m];
									}
									cout << endl;
								}
							} else {
								MiGong [i][j] = 'O';
								MiGong [i + 1][j] = ' ';
								countbreak ++;
								system("cls");
								for (int n = 0 ; n < 10 ; n ++){
					    			for (int m = 0 ; m < 10 ; m ++){
					    				cout << MiGong [n][m];
									}
									cout << endl;
								}
							}
						} else{
							cout << "You lose! Try again next time!";
						    cout << endl;
                        	system ("pause");
							return 0;
						}
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i + 1][j] = ' ';
						system("cls");
					    
					    for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
			 		} else if (MiGong [i][j] == '@'){
			 			
			 		    MiGong [i + 1][j] = ' ';
						i = 7;
						j = 2;
			 			MiGong [7][2] = 'O';
			 			system("cls");
			 			
			 			for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else if (MiGong [i][j] == '!'){
                        MiGong [2][3] = ' ';
						MiGong [2][6] = ' ';
						MiGong [4][2] = 'O';
						MiGong [i + 1][j] = ' ';
						system("cls");

						for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}

                    } else {
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 's'){
					
					j --;
					if (MiGong [i][j] == '#'){
						if (flag){
							if (countbreak == 5){
								flag = false;
								MiGong [i][j] = 'O';
								MiGong [i][j + 1] = ' ';
								system ("cls");
								cout << "Your wepon is not allowed any more!";
								cout << endl;
								for (int n = 0 ; n < 10 ; n ++){
					    			for (int m = 0 ; m < 10 ; m ++){
					    					cout << MiGong [n][m];
									}
									cout << endl;
									}
							} else {
								MiGong [i][j] = 'O';
								MiGong [i][j + 1] = ' ';
								countbreak ++;
								system("cls");
								for (int n = 0 ; n < 10 ; n ++){
					    			for (int m = 0 ; m < 10 ; m ++){
					    				cout << MiGong [n][m];
									}
									cout << endl;
								}
							}
						} else{
							cout << "You lose! Try again next time!";
					    	cout << endl;
                        	system ("pause");
							return 0;
						}
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i][j + 1] = ' ';
					    system("cls");
					    for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else if (MiGong [i][j] == '!'){
                        MiGong [2][3] = ' ';
						MiGong [2][6] = ' ';
						MiGong [i][j] = 'O';
						MiGong [i][j + 1] = ' ';
						system("cls");

						for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
                    } else {
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 'f'){
					
					j ++;
					if (MiGong [i][j] == '#'){
						if (flag){
							if (countbreak == 5){
								flag = false;
								MiGong [i][j] = 'O';
								MiGong [i][j - 1] = ' ';
								system ("cls");
								cout << "Your wepon is not allowed any more!";
								cout << endl;
								for (int n = 0 ; n < 10 ; n ++){
					    			for (int m = 0 ; m < 10 ; m ++){
					    				cout << MiGong [n][m];
									}
									cout << endl;
								}
							} else {
								MiGong [i][j] = 'O';
								MiGong [i][j - 1] = ' ';
								countbreak ++;
								system("cls");
								for (int n = 0 ; n < 10 ; n ++){
					    			for (int m = 0 ; m < 10 ; m ++){
					    				cout << MiGong [n][m];
									}
									cout << endl;
								}
							}
						} else{
							cout << "You lose! Try again next time!";
						    cout << endl;
                        	system ("pause");
							return 0;
						}
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i][j - 1] = ' ';
					    system("cls");
					    for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else if (MiGong [i][j] == '!'){
                        MiGong [2][3] = ' ';
						MiGong [2][6] = ' ';
						MiGong [i][j] = 'O';
						MiGong [i][j - 1] = ' ';
						system("cls");

						for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
                    } else {
						cout << "Your choice is not correct!";
						cout << endl;
                        system ("pause");
						return 0;
					}
				} else if (d == 'd'){
					i ++;
					if (MiGong [i][j] == '#'){
						if (flag){
							if (countbreak == 5){
								flag = false;
								MiGong [i][j] = 'O';
								MiGong [i - 1][j] = ' ';
								system ("cls");
								cout << "Your wepon is not allowed any more!";
								cout << endl;
								for (int n = 0 ; n < 10 ; n ++){
					    			for (int m = 0 ; m < 10 ; m ++){
					    					cout << MiGong [n][m];
									}
									cout << endl;
									}
							} else {
								MiGong [i][j] = 'O';
								MiGong [i - 1][j] = ' ';
								countbreak ++;
								system("cls");
								for (int n = 0 ; n < 10 ; n ++){
					    			for (int m = 0 ; m < 10 ; m ++){
					    				cout << MiGong [n][m];
									}
									cout << endl;
								}
							}
						} else{
							cout << "You lose! Try again next time!";
						    cout << endl;
                        	system ("pause");
							return 0;
						}
					} else if (MiGong [i][j] == ' '){
						MiGong [i][j] = 'O';
						MiGong [i - 1][j] = ' ';
					    system("cls");
					    for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
						
					} else if (MiGong [i][j] == '!'){
                        MiGong [2][3] = ' ';
						MiGong [2][6] = ' ';
						MiGong [i][j] = 'O';
						MiGong [i - 1][j] = ' ';
						system("cls");
						
						for (int n = 0 ; n < 10 ; n ++){
					    	for (int m = 0 ; m < 10 ; m ++){
					    		cout << MiGong [n][m];
							}
							cout << endl;
						}
					} else if (MiGong [i][j] == '-'){
						MiGong [i-1][j] = 'O';
						i --;
						cout << "This is a door, please get the key.";
                    } else if (MiGong [i][j] == we){
                    	MiGong [i][j] = 'O';
                    	MiGong [i - 1][j] = ' ';
                    	flag = true;
                    	system("cls");
                    	for (int i = 0; i < 10; i++){
                    		for (int j = 0; j < 10; j ++){
                    			cout << MiGong [i][j];
							}
							cout << endl;
						}
					}else {
						cout << "Your choice is not correct!"; 
						cout << endl;
                        system ("pause");
						return 0;
					}
				}
				if (MiGong[9][3] == 'O' || MiGong[9][5] == 'O'|| MiGong[7][9] == 'O'){
					system ("cls");
					cout << endl;
					cout << "You win !!! " << "Thanks for playing ! this game was developed by Tony.";
					cout << endl;
					system ("pause");
					return 0;
				}	
			}	
			
		} else {
			system ("cls");
			cout << "Your choice is not correct!" << endl;
			cout << endl;
            system ("pause");
			return 0;
		}
		
	} else if (a == 'h'){
		
		
		
	} else {
		system ("cls");
	    cout << "Your choice is not correct!" << endl;
		cout << endl;
        system ("pause");
	    return 0;
	}
	
	return 0;
}
