#include <stdio.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include<time.h>

int character[1000];
int length = 2;
int fruit;
int score;
clock_t t;
int s_e;
int vx;
int vy;
int speed=50;

enum state{
	MENU = 0, INGAME, SETTING, GUIDING, INFORMATION, GAMEOVER
} state;
int Random(int a, int b)
{
   return a + rand()%(b-a+1);
}

void gotoxy(int x, int y)
{
    static HANDLE  h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = {x,y};
    SetConsoleCursorPosition(h,c);
}
void SetColor(WORD color)
{ 
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0; wAttributes |= color;
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void setting(){
  system("cls");
  gotoxy(0,9);
  printf("An cac phim up down tren ban phim de tang giam toc do, nhan enter de tro ve menu");
  gotoxy(30,11);
  printf("toc do hien tai : %d",speed);
  int key;
  while(state==SETTING){
  	if(kbhit()){
  		key = getch();
  		switch (key){
  			//nut trai
  			case 75 :
  				if(speed>1){
				  
  				speed -=1;
  				gotoxy(30,11);
                printf("toc do hien tai : %d   ",speed);
                }
  				break;
  				//nut phai
  				case  77 :
  					if(speed<100){
					  
  					speed+=1;
  					gotoxy(30,11);
                    printf("toc do hien tai : %d   ",speed);
                    }
  					break;
  					case 13 :
  						state = MENU;
  						break;
		  }
	  }
  }	
}
void vekhung(){
	
	int i = 0;
	int j = 0;
	SetColor(3);
	for(i;i<79;i++){
		printf("#");
	}
	printf("\n");
    i = 0;
	for(i;i<23;i++){
	
	for(j;j<79;j++){
		if(j==0)printf("#");
		else if(j==78) printf("#\n");
		else printf(" ");
	}
	j=0;
} 
i = 0;
for(i;i<79;i++){
		printf("#");
	}
}
void gameover(){	
    SetColor(4);
    system("cls");
	gotoxy(30,9);
	printf("....Game over....");
	gotoxy(15,11);
	printf("Choi ngu duoc co %d diem/n An phim bat ki de ve menu",score);
	getchar();
	state = MENU;	
}
void menu(){
	SetColor(14);
	system("cls");
    gotoxy(25,3);
	printf("Game ran san moi");
	gotoxy(30,5);
	SetColor(4);
	printf("1. vao game");
	gotoxy(30,6);
	printf("2. tuy chinh");
	gotoxy(30,7);
	printf("3. thong tin");
	int choice = 1;
	int oldChoice = 1;
	int next = 1;
	int key;
	SetColor(14);
	gotoxy(29,5);
				printf("%c",16);
	while(state==MENU){
		if(kbhit()){
			key = getch();
			if(key==80) {
			choice++;
			if(choice ==4) choice = 1;
			}
			if(key==72) {
			choice --;
			if(choice == 0) choice = 3;
			}
		switch (choice) {
			case 1 :
				if(oldChoice!=choice){
				
				gotoxy(29,6);
				printf(" ");
				gotoxy(29,7);
				printf(" ");
				oldChoice = 1;
				
				gotoxy(29,5);
				SetColor(14);
				printf("%c",16);
				}
				break;
			case 2 :
				if(oldChoice!=choice){
			
				gotoxy(29,5);
				printf(" ");
				gotoxy(29,7);
				printf(" ");
		        gotoxy(29,6);
		        SetColor(14);
				printf("%c",16);
				oldChoice = 2;
				}
				break;
			case 3 :
				if(oldChoice!=choice){
				
				
				gotoxy(29,6);
				printf(" ");
				gotoxy(29,5);
				printf(" ");
				gotoxy(29,7);
				SetColor(14);
				printf("%c",16);
				
				oldChoice = 3;
				}
				break;
		}
		if(key==13){
		switch (choice){
		case 1:			
			state = INGAME;
			break;
			case 2:
				state = SETTING;
				break;
			case 3 :
				state = INFORMATION;
				break;
				
		}
		}
		
	}
	
	}
	
}


void initgame(){
	system("cls");
	s_e = 120-speed;
	t = 0;
	vx = 1;
	vy = 0;
	score = 0;
	length = 10;
	character[0] = 11510;
	character[1] = 11410;
	character[2] = 11310;
	character[3] = 11210;
	character[4] = 11110;
	character[5] = 11010;
	character[6] = 10910;
	character[7] = 10810;
	character[8] = 10710;
	character[9] = 10610;
	fruit = 15010;
}
void creatfruit(){
	int notok = 1;
	while(notok){
		notok = 0;
		fruit = 10000 + Random(1,77)*100 + Random(1,23);
		int i = 0;
		for(i;i<length;i++){
		if(character[i]	== fruit){
			notok = 1;
		}
		}
	}
}
int getx(int a){
	return (a-10000)/100;
}
int gety(int a){
	return a%100;
}
void drawscore(){

	gotoxy(79,3);
 	printf("s");
 	gotoxy(79,4);
 	printf("c");
 	gotoxy(79,5);
 	printf("o");
 	gotoxy(79,6);
 	printf("r");
 	gotoxy(79,7);
 	printf("e");
 	
 	gotoxy(79,9); 
 	printf("0");
 	gotoxy(79,10); 
 	printf("0");
 	gotoxy(79,11);
 	printf("0");
 	gotoxy(79,12); 
 	printf("0");
 	gotoxy(79,13);
 	printf("0");
}
void addscore(){
	SetColor(14);
	gotoxy(79,9); 
	printf("%d",(score%100000)/10000);
 	gotoxy(79,10);
 	printf("%d",(score%10000)/1000);
 	gotoxy(79,11);
 	printf("%d",(score%1000)/100);
 	gotoxy(79,12);
 	printf("%d",(score%100)/10);
 	gotoxy(79,13);
 	printf("%d",score%10);
}
void ingame(){
	int key;
	int i;
	initgame();
 	vekhung();
 	
 	drawscore();
 	state = INGAME;
 	SetColor(13);
 	gotoxy(getx(fruit),gety(fruit));
 	printf("O");
 	SetColor(12);
 	 gotoxy(getx(character[0]),gety(character[0]));
				printf("#");
	  i = 1;
	  SetColor(2);
 	for(i;i<length;i++){
				gotoxy(getx(character[i]),gety(character[i]));
				printf("o");
			}
	while(state == INGAME){
	if(kbhit()){
			key = getch();
			switch (key) {
				//nut len
				case 72:
					if(vy == 0){
						vx = 0;
						vy = -1;
					}
					break;
					//nut xuong
				case 80:
					if(vy == 0){
						vx = 0;
						vy = 1;
					}
					break;
					//nut trai
				case 75:
					if(vx == 0){
						vy = 0;
						vx = -1;
					}
					break;
					// nut phai
				case 77:
					if(vx == 0){
						vy = 0;
						vx = 1;
					}
					break;		
			}						     
	}	
	// bye ae
	
	if((clock()-t)>=s_e){
			if(character[length-1]!=0){			
			gotoxy(getx(character[length-1]),gety(character[length-1]));
			printf(" ");
		}
			i =length-1;
			for(i;i>0;i--){
			character[i]=character[i-1];
			}
			SetColor(2);
			gotoxy(getx(character[0]),gety(character[0]));
				printf("o");
		    character[0] += vx*100;
		    character[0] += vy;	
		    if(character[0] == fruit){
		    	length+= 1;
		    	score += (speed/10 + 5);
		    	addscore();
		    	creatfruit();
		    	SetColor(13);
		    	gotoxy(getx(fruit),gety(fruit));
 	            printf("O");
			}
			if((vx>0)&&(getx(character[0])==78)){
				character[0]-=7700;
			}    
			if((vx<0)&&(getx(character[0])==0)){
				character[0]+=7700;
			}  
			if((vy>0)&&(gety(character[0])==24)){
				character[0]-=23;
			}   
			if((vy<0)&&(gety(character[0])==0)){
				character[0]+=23;
			}   
			SetColor(12);
			gotoxy(getx(character[0]),gety(character[0]));
				printf("#");
			i = 1;
			for(i;i<length;i++){
				if(character[i]==character[0]){
					system("cls");					
					state = GAMEOVER;
				}
			}  
		   t = clock();  		    
		}
		
	}	
}
void main(){
	state = MENU;
    menu();
// moi chi thac mac vui long lien he https://www.facebook.com/nguoithichban.ghet.9
// all opinions and questions please give me by https://www.facebook.com/nguoithichban.ghet.9
// copyright 7/11/2018 anh's thanh
while(1){
	switch (state){
		case MENU : 
		menu();
		break;
		case INGAME :
			ingame();
			break;
		case GAMEOVER : 
		gameover();
		break;
		case INFORMATION :
			information();
			break;
			case  SETTING:
				setting();
				break;
	}
	
}

}
