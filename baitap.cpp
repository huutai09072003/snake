
#include <stdio.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include<time.h>
void inmap2();
int body[1000];
int length ;
int food;
int score;
clock_t t;
int a;
int vx;
int vy;
int i;
int speed=25;
void inputfile(){};//nhap vao file 
void getx(){};//lay toa do cua x
void gety(){};//lay toa do cua y
void gotoxy(short int x,short int y);
void SetColor(WORD color);
void back();
int getx(int x){
	return (x-10000)/100;
}
int gety(int y){
	return y%100;
}
enum state{
	MENU = 0, INGAME, SETTING, GUIDING, INFORMATION, GAMEOVER,HISTORY
} state;
typedef struct player{
	int sodiem;
	char ten[100];
}sv;
void inputfile(sv a){
	FILE *f;
	f=fopen("snakegame.txt","a");
	if(f==NULL){
		printf("\nLoi tao hay mo file");
	}
	fprintf(f,"\n%s ",a.ten);
	fprintf(f,"\t%d",a.sodiem);
	fclose(f);
}
void outputfile(sv a){
    FILE *f;
	f=fopen("snakegame.txt","r");
	printf("Danh sach nhung nguoi choi: ");
    if(f==NULL){
		printf("\n Loi tao hay mo file");
	}
	else{
	while(!feof(f)){
    fscanf(f,"%s %d",&a.ten,&a.sodiem);
	SetColor(2);
	printf("\n\tPlayer: %s",a.ten);
	SetColor(3);
	printf("\n\tSCORE : %d",a.sodiem);}
	fclose(f);}
	SetColor(5);
	printf("\nNhan enter de quay tro lai");
	getchar();
	state=MENU;
}
int Random(int a, int b)
{
   return a + rand()%(b-a+1);
}
void changemap(){
    int ct=0;
    int count=0;
    int a=1;
	gotoxy(40,12);
	SetColor(1);
	printf("chuyen man ");
	gotoxy(20,10);
    while(a==1){
    if(ct%20000000==0){
	SetColor(2);
    printf("#");
    count ++;
    }
     ct++;
     if(count ==60) break;
}	
}
void gotoxy(short int x,short int y)
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
void information(){
	system("cls");
	SetColor(4);
	gotoxy(10,8);
	printf("Moi su gop y cua ban la mon qua voi nhom toi: 6251071084@st.utc2.edu.vn");
	gotoxy(3,10);
	printf("An phim enter de tro lai menu");
	gotoxy(27,11);
	SetColor(14);
	printf("----Nhom 4 nguoi Hao Hung Tai Tin----");
	getchar();//nhan 1 ki tu bat ki de thoat ra khoi setting 
	state = MENU;
}
void setting(){
  system("cls");
  gotoxy(0,9);
  printf("An cac phim up down tren ban phim de tang giam toc do, Nhan enter de tro ve menu");
  gotoxy(30,11);
  printf("Speed hien tai : %d",speed);
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
                        printf("Speed hien tai : %d   ",speed);}
  			break;
  			//nut phai
  			case  77 :
  			if(speed<100){
  			speed+=1;
  			gotoxy(30,11);
                        printf("Speed hien tai : %d   ",speed);}
  			break;
  			case 13 :// nut enter
  			state = MENU;
  			break;}
	  }
      }	
}
void vekhung(){
	int i = 0;
	int j = 0;
	SetColor(3);
	for(i;i<79;i++){
		printf("#");}
	printf("\n");
        i = 0;
	for(i;i<23;i++){
	   for(j;j<79;j++){
		if(j==0)printf("#");
		else if(j==78) printf("#\n");
		else printf(" ");}
	    j=0;
		} 
         i = 0;
         for(i;i<79;i++){
		printf("#");}
}
void gameover(){	
	sv a;
    SetColor(5);
    system("cls");
    gotoxy(30,9);
    printf("....GAME OVER....");
    gotoxy(20,15);
    printf("Chuc mung ban duoc co %d diem",score);
	gotoxy(20,18);
	printf("Nhap ten cua ban:");
	fflush(stdin);
	gets(a.ten);//nhap ten thang choi
	a.sodiem=score;//luu diem cua nguoi choi vao struct player
	inputfile(a);//luu cái nhẹ vào file 
	gotoxy(20,20);
	printf("Nhan enter de tro ve menu ");
    getchar();
    state = MENU;	
}
void menu(){
	SetColor(14);
	system("cls");
    gotoxy(18,3);
	printf("===============MENU===============");
	gotoxy(30,5);
	SetColor(4);
	printf("1.Vao Game");
	gotoxy(30,6);
	SetColor(5);
	printf("2.Tuy Chinh");
	gotoxy(30,7);
	SetColor(6);
	printf("3.Thong Tin");
	gotoxy(30,8);
	SetColor(2);
	printf("4.Lich su");
	int choice = 1;
	int oldChoice = 1;
	int next = 1;
	int key;
	SetColor(14);
	gotoxy(29,5);
	while(state==MENU){
		if(kbhit()){// kiem tra nguoi dung co nhap vao ban phim hay khong
			key = getch();
			if(key==80) {//nut xuong 
			choice++;
			if(choice ==5) choice = 1;
			}
			if(key==72) {//mui ten len 
			choice --;
			if(choice == 0) choice = 4;
			}
		switch (choice){
			case 1 :
				if(oldChoice!=choice){
				 oldChoice = 1;
				 gotoxy(29,5);
		     }
            	break;
			case 2 :
				if(oldChoice!=choice){
			
		                 gotoxy(29,6);
				 oldChoice = 2;}
				break;
			case 3 :
				if(oldChoice!=choice){
			     gotoxy(29,7);
				 oldChoice = 3;}
				 break;
			case 4 :
				if(oldChoice!=choice){
			     gotoxy(29,8);
				 oldChoice = 4;}
				 break;
				 }
		if(key==13){//enter 
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
				case 4:
				state=HISTORY;
				}
		  }
	      }
	}	
}
int v[1000],at[100];//khai bao toa do cua hai thanh chắn ở map 3 
int dd=7;// do dai cua chuong ngai vật 
void inputmap3(){//ham nay dung de  ve khung va in chuong ngai vat o map 3 
	vekhung();
	for(int i=0;i<7;i++){
		v[i]=12515+i;
		gotoxy(getx(v[i]),gety(v[i]));
		printf("#");
		at[i]=16001+i;
		gotoxy(getx(at[i]),gety(at[i]));
	    printf("#");
	}
}
void inmap3(){
	inputmap3();
		 if(v[dd-1]!=0){			
			gotoxy(getx(v[dd-1]),gety(v[dd-1]));
			printf(" ");
	}
		int i =dd-1;
			for(i;i>0;i--){
			v[i]=v[i-1];
			}
		gotoxy(getx(v[0]),gety(v[0]));
			printf("#");
		        v[0] += 0;
		        v[0] += -1;	
			if(gety(v[0])==0) {// neu thang chan  dat 
				v[0]+=23;
			}
		if(at[dd-1]!=0){			
			gotoxy(getx(at[dd-1]),gety(at[dd-1]));
			printf(" ");
	}
		 i =dd-1;
			for(i;i>0;i--){
			at[i]=at[i-1];
			}
		gotoxy(getx(at[0]),gety(at[0]));
			printf("#");
		        at[0] += 0;
		        at[0] += -1;	
			if(gety(at[0])==0) {
				at[0]+=23;
			}	
}
void initgame(){
	system("cls");
	a = 120-speed;
	t = 0;
	vx = 1;
	vy = 0;
	score = 0;
	length = 2;
	body[0] = 11511;
	body[1] = 11411;
	body[2] = 11311;
	food = 15010;
}
void creatfruit(){
	int tiktok = 1;
	while(tiktok==1){
		tiktok = 0;
		
		food= 10000 + Random(1,77)*100 + Random(1,22);
		int i = 0;
		for(i;i<length;i++){
		if(body[i]	== food){
			tiktok = 1;}
		}
	}
}
void removefruit(){
	food=food+100+1;//ham này để dời thức ăn cho map 2 map 2 lỗi quá dm
}
void drawscore(){
    gotoxy(79,3);
    SetColor(3);
    printf("score");
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
void move(){
	int key;
	if(kbhit()){
			key = getch();
			switch (key) {
				//nut len
				case 72:
					if(vy == 0){
					vx = 0;
					vy = -1;}
					break;
					//nut xuong
				case 80:
					if(vy == 0){
					vx = 0;
					vy = 1;}
					break;
					//nut trai
				case 75:
					if(vx == 0){
					vy = 0;
					vx = -1;}
					break;
					// nut phai
				case 77:
					if(vx == 0){
					vy = 0;
					vx = 1;}
					break;}						     
}		if((clock()-t)>a){
		  if(body[length-1]!=0){			
			gotoxy(getx(body[length-1]),gety(body[length-1]));
			printf(" ");
			}// chuyen vi tri cuoi cung thanh  khoang trong
			i =length-1;
			for(i;i>0;i--){
			body[i]=body[i-1];
			}
			SetColor(2);
			gotoxy(getx(body[0]),gety(body[0]));
			printf("o");
		        body[0] += vx*100;
		        body[0] += vy;	
		    if(body[0] == food){
		    	length+= 1;
		    	score += (speed/10 + 5);
		    	addscore();
		    	creatfruit();// tao thuc an trong vong lap 
		    	SetColor(13);
		    	gotoxy(getx(food),gety(food));
 	            printf("O");}
			if((getx(body[0])==78)){//neu ran dung vao tuong thi cong cho no quay lai 
				body[0]-=7700;}    
			if((getx(body[0])==0)){
				body[0]+=7700;}  
			if((gety(body[0])==24)){
				body[0]-=23;}   
			if((gety(body[0])==0)){
				body[0]+=23;}   
			SetColor(12);
			gotoxy(getx(body[0]),gety(body[0]));
				printf("#");
			i = 1;
			for(i;i<length;i++){
				if(body[i]==body[0]){
					system("cls");					
					state = GAMEOVER;}
			}  
		        t = clock(); 		
		}	
}
void ingame(){
	int key;
	int i;
	//drawscore();
	if(length<=4){
    initgame();
	vekhung();
 	drawscore();
 	state = INGAME;
 	SetColor(13);
 	gotoxy(getx(food),gety(food));
 	printf("O");
 	SetColor(12);
 	gotoxy(getx(body[0]),gety(body[0]));
	printf("#");
	i = 1;
	SetColor(2);
 	for(i;i<length;i++){
		gotoxy(getx(body[i]),gety(body[i]));
		printf("o");}
	while(state == INGAME){
	move();
	if(length>=4) break;// di?u ki?n ? trên thì dúng nhung mà n?u length >=5 thi nó v?n chua th? thoát kh?i vòng l?p while nên là ph?i thêm di?u ki?n d? thoát kh?i th?ng while 
	}
	}
	if(length>=4 && length<=24) {
	system("cls");
    changemap();
	initgame();
	inmap2();
 	drawscore();
 	state = INGAME;
	SetColor(13);
 	gotoxy(getx(food),gety(food));
 	printf("O");
 	SetColor(12);
 	gotoxy(getx(body[0]),gety(body[0]));
	printf("#");
	//i = 1;
	///SetColor(2);
 	//for(i;i<length;i++){
	//	gotoxy(getx(body[i]),gety(body[i]));
	//	printf("o");}
	while(state == INGAME){
	move();
	for(int i=13;i<23;i++){
        if(12500+i==body[0]) {//dau con ran roi vao toa do cua x=25 y tu 13 -23 thi se chêt
            state=GAMEOVER;
        } 
         if(16000+i==body[0]){//nay cung tuong tu tren 
            state=GAMEOVER;
        }
        while (food==12500+i || food==16000+i) {// neu food trung với  dungf while lỡ nó trùng 2 3 4 lần thì sao 
			SetColor(3);
			gotoxy(getx(food),gety(food));
		    printf("%c",219);
			removefruit();
			gotoxy(getx(food),gety(food));
			printf("0");
        }
    }
    for(int i=14;i<=70;i++){//neu ran dung thanh nganh toa do tu y=10 x tu 14-70 thi chết
        if(10008+i*100==body[0]){
            state=GAMEOVER;
        }
        while (food==10008+i*100) {//neu moi cua con ran trung vs vat cản thì bắt nó in lại dungf while ms được dm dùng if fix gần chết
            gotoxy(getx(food),gety(food));
			SetColor(3);
			printf("%c",219);
			removefruit();
			gotoxy(getx(food),gety(food));
			printf("0");

        	}
    	}
		if(length==14) break;
	}	
}
		if(length>=14){
			system("cls");
    changemap();//su dung ham doi map 
	initgame();//khoi tao con ran voi do dai = length trong ran 
    length=5;
	inputmap3();//in map so 3
 	drawscore();//ve ham score 
 	state = INGAME;
	SetColor(13);
 	gotoxy(getx(food),gety(food));//in thuc an cho con ran dop
 	printf("O");
 	SetColor(12);
 	gotoxy(getx(body[0]),gety(body[0]));//in dau ran
	printf("#");
	i = 1;
	SetColor(2);
 	for(i;i<length;i++){
		gotoxy(getx(body[i]),gety(body[i]));//vong lap nay dung de in than con ran 
		printf("o");}
	while(state == INGAME){
	//move();
	int key;
	if(kbhit()){//kiem tra  1 ki tu nhap vao 
			key = getch();
			switch (key) {
				//nut len
				case 72:
					if(vy == 0){
					vx = 0;
					vy = -1;}
					break;
					//nut xuong
				case 80:
					if(vy == 0){
					vx = 0;
					vy = 1;}
					break;
					//nut trai
				case 75:
					if(vx == 0){
					vy = 0;
					vx = -1;}
					break;
					// nut phai
				case 77:
					if(vx == 0){
					vy = 0;
					vx = 1;}
					break;}
	}if((clock()-t)>a){//day co the xem nhu la 1 vong lap cham 
		  if(body[length-1]!=0){			
			gotoxy(getx(body[length-1]),gety(body[length-1]));
			printf(" ");
			}// chuyen vi tri cuoi cung thanh  khoang trong
			i =length-1;
			for(i;i>0;i--){
			body[i]=body[i-1];
			}
			SetColor(2);
			gotoxy(getx(body[0]),gety(body[0]));
			printf("o");
		        body[0] += vx*100;
		        body[0] += vy;	
		    if(body[0] == food){
		    	length+= 1;
		    	score += (speed/10 + 5);
		    	addscore();
		    	creatfruit();// tao thuc an trong vong lap 
		    	SetColor(13);
		    	gotoxy(getx(food),gety(food));
 	            printf("O");}
			if((getx(body[0])==78)){//neu ran dung vao tuong thi cong cho no quay lai 
				body[0]-=7700;}    
			if((getx(body[0])==0)){
				body[0]+=7700;}  
			if((gety(body[0])==24)){
				body[0]-=23;}   
			if((gety(body[0])==0)){
				body[0]+=23;}   
			SetColor(12);
			gotoxy(getx(body[0]),gety(body[0]));
				printf("#");
			i = 1;
			for(i;i<length;i++){
				if(body[i]==body[0]){
					system("cls");					
					state = GAMEOVER;}
			}         		
		//toàn bộ phần code này là để xử lí các chướng ngại vật tạo ra no va cho nó di chuyển 	
	if(v[dd-1]!=0){			
			gotoxy(getx(v[dd-1]),gety(v[dd-1]));//hàm này dùng để xóa các khi tiến tới thì nó sẽ xóa phần sau
			printf(" ");
	}
		int i =dd-1;
			for(i;i>0;i--){// dung de cho các thanh di chuyển nó sẽ tăng lên 
			v[i]=v[i-1];
			}
		gotoxy(getx(v[0]),gety(v[0]));
			printf("#");
		        v[0] += 0;
		        v[0] += -1;	
			if(gety(v[0])==0) {
				v[0]+=23;
			}
		if(at[dd-1]!=0){			
			gotoxy(getx(at[dd-1]),gety(at[dd-1]));
			printf(" ");
	}
		 i =dd-1;
			for(i;i>0;i--){
			at[i]=at[i-1];
			}
		gotoxy(getx(at[0]),gety(at[0]));
			printf("#");
		        at[0] += 0;
		        at[0] += -1;	
			if(gety(at[0])==0) {
				at[0]+=23;
			}
			for(int i=0;i<length;i++){
				for(int j=0;j<dd;j++)
				if(body[i]==at[j] || body[i]==v[j]){
					state=GAMEOVER;
				}
			}
			 t = clock(); } 
	}
		}
}
void inmap2(){
	vekhung();
	gotoxy(13,25);
	for(int i=13;i<23;i++){
		gotoxy(25,i);
		printf("%c",219);
		gotoxy(60,i);
		printf(" %c",219);
	}
	for(int j=14;j<=70;j++){
		gotoxy(j,8);
		printf("%c",219);
	}	
}
int main(){
	sv a;
    state = MENU;
    menu();
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
		case SETTING:
		     setting();
		     break;
		case HISTORY:
			system("cls");
		    outputfile(a);
			break;
			 } 
   }
}
