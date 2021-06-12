/*
 * Sliding puzzle(4*4)
 * Description:
 *				This is just Sliding puzzle (4 * 4)
 *				./a.out 1 ==> 4*4 Printing
 *				./a.out 2 ==> Game Start(j = left, k= down, l = right, i = up)
 * Using : Linux gcc
 * Programmer: yooj
 * Date: 20.11.08
 */
#include<stdio.h>
#include<stdlib.h>
#include<termio.h>
#include<unistd.h>
#include<time.h>
#include<string.h>
void printscreen(char* a[16]){
    system("clear");
    for(int i=0;i<16;i++){
        printf("%20s",a[i]);
    if(i%4==3)
    printf("\n");}
}

int getch(void){
    struct termios buf;
    struct termios save;
    int ch;
    tcgetattr(0,&save);
    buf=save;
    buf.c_lflag &= ~(ICANON | ECHO);
    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;
    tcsetattr(0,TCSAFLUSH,&buf);
    ch=getchar();
	tcsetattr(0,TCSAFLUSH,&save);
	return ch;}

int main(int argc, char *argv[])
{
	char* num[16]={"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"," "};
	char* num2[16]={"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"," "};
	int  a=0;

	int game=1;
	system("clear");
	if(1==(atoi(argv[1]))){
		printscreen(num);}
	else if(2==(atoi(argv[1]))){
		int c[16]={0,};
		int temp=0;
		char *change="0";
		srand(time(NULL));
		for(int i=0;i<16;i++){


			c[i]= rand()+1;
		
		}
		for(int i=15;i>0;i--){
			for(int j=0;j<i;j++){
				if(c[j]<c[j+1]){

					temp=c[j];
					c[j]=c[j+1];
					c[j+1]=temp;
					change=num[j];
					num[j]=num[j+1];
					num[j+1]=change;
				}}}
		for(int i=0;i<16;i++){
        printf("%20s",num[i]);
        if(i%4==3)
            printf("\n");
		}
		while(game){
			int b=0;
			int d=0;
			for(int i=0;i<16;i++){
				d=strcmp(num[i],num2[i]);
				if(d>0){
					b+=d;}
			else if(d<0){
				b-=d;}}


				
			if(b==0){
				printf("축하합니다.");
				sleep(3);
				game=0;
			}
			else{
			for(int i=0;i<16;i++){
				if(*num[i]==32){
					if(i==0){
						a=getch();
						if(a==27)
							game=0;
						else if(a==105){
							printf("이동 할 수 없습니다.");}
						else if(a==106){
							printf("이동 할 수 없습니다.");
						}
						else if(a==107){
							change=num[i];	
							num[i]=num[i+4];
							num[i+4]=change;
							system("clear");
							printscreen(num);
						}
						else if(a==108){
							change=num[i];
							num[i]=num[i+1];
							num[i+1]=change;
							system("clear");
							printscreen(num);
						}
					}
					else if(i==1||i==2){
						a=getch();
						
						if(a==27)
                            game=0;

						else if(a==105){
							printf("이동 할 수 없습니다.");}
						else if(a==106){
							change=num[i];
							num[i]=num[i-1];
							num[i-1]=change;
							system("clear");
							printscreen(num);
						}
						else if(a==107){
							change=num[i];
							num[i]=num[i+4];
							num[i+4]=change;
							system("clear");
							printscreen(num);
						}
						else if(a==108){
							change=num[i];
							num[i]=num[i+1];
							num[i+1]=change;
							system("clear");
							printscreen(num);
						}}
						else if(i==3){
                        a=getch();
						 if(a==27)
                            game=0;

						 else if(a==105){
							printf("이동 할 수 없습니다.");

                        }
						 else if(a==106){
                            change=num[i];
                            num[i]=num[i-1];
                            num[i-1]=change;
                            system("clear");
                            printscreen(num);
                        }
						 else if(a==107){
                            change=num[i];
                            num[i]=num[i+4];
                            num[i+4]=change;
                            system("clear");
                            printscreen(num);
                        }
						 else if(a==108){
							printf("이동 할 수 없습니다.");}}
						 else if(i==4||i==8){
                        	a=getch();
							 if(a==27){
                            game=0;}
 							else if(a==105){	
                            change=num[i];
                            num[i]=num[i-4];
                            num[i-4]=change;
							system("clear");
							printscreen(num);

                        }
							 else if(a==106){
							printf("이동 할 수 없습니다.");
                        }
							 else if(a==107){
                            change=num[i];
                            num[i]=num[i+4];
                            num[i+4]=change;
                            system("clear");
                            printscreen(num);
                        }
							 else if(a==108){
                            change=num[i];
                            num[i]=num[i+1];
                            num[i+1]=change;
                            system("clear");
                            printscreen(num);}}
						 	else if(i==7||i==11){
                        	a=getch();
							 if(a==27){
                            	game=0;}
 							else if(a==105){	
                            change=num[i];
                            num[i]=num[i-4];
                            num[i-4]=change;
							system("clear");
							printscreen(num);
						   	}
							 else if(a==106){
                            change=num[i];
                            num[i]=num[i-1];
                            num[i-1]=change;
                            system("clear");
                            printscreen(num); }
							 else if(a==107){
                            change=num[i];
                            num[i]=num[i+4];
                            num[i+4]=change;
                            system("clear");
                            printscreen(num);
                        	}
							 else if(a==108){
							printf("이동할 수 없습니다.");
								}}
							  else if(i==12){
								  a=getch();
								   if(a==27){
                            game=0;}
							else if(a==105){
                            change=num[i];
                            num[i]=num[i-4];
                            num[i-4]=change;
							system("clear");
							printscreen(num);

                        }
						else if(a==106){
							printf("이동 할 수 없습니다.");

                        }
						else if(a==107){
							printf("이동 할 수 없습니다.");
                        }
						else if(a==108){
                            change=num[i];
                            num[i]=num[i+1];
                            num[i+1]=change;
                            system("clear");
                            printscreen(num);}}
							    else if(i==13||i==14){
									a=getch();
 if(a==27){
                            game=0;}


						else if(a==105){
                            change=num[i];
                            num[i]=num[i-4];
                            num[i-4]=change;
							system("clear");
							printscreen(num);

                        }
						else if(a==106){
                            change=num[i];
                            num[i]=num[i-1];
                            num[i-1]=change;
                            system("clear");
                            printscreen(num);
                        }
						else if(a==107){
							printf("이동할 수 없습니다.");
                        }
						else if(a==108){
                            change=num[i];
                            num[i]=num[i+1];
                            num[i+1]=change;
                            system("clear");
                            printscreen(num);}
								}



						 else if(i==15){
                        	a=getch();
						 if(a==27){
                            game=0;
						 }
						 else if(a==105){
                            change=num[i];
                            num[i]=num[i-4];
                            num[i-4]=change;
							system("clear");
							printscreen(num);

                        }
						 else if(a==106){
                            change=num[i];
                            num[i]=num[i-1];
                            num[i-1]=change;
                            system("clear");
                            printscreen(num);
                        }
						 else if(a==107){
							printf("이동할 수 없습니다.");
                        }
						 else if(a==108){
							printf("이동할 수 없습니다.");
						}
						 }






						 else{
                        a=getch();
						 if(a==27)
                            game=0;
						 else if(a==105){
                            change=num[i];
                            num[i]=num[i-4];
                            num[i-4]=change;
							system("clear");
							printscreen(num);

                        }
						 else if(a==106){
                            change=num[i];
                            num[i]=num[i-1];
                            num[i-1]=change;
                            system("clear");
                            printscreen(num);
                        }
						 else if(a==107){
                            change=num[i];
                            num[i]=num[i+4];
                            num[i+4]=change;
                            system("clear");
                            printscreen(num);
                        }
						 else if(a==108){
                            change=num[i];
                            num[i]=num[i+1];
                            num[i+1]=change;
                            system("clear");
                            printscreen(num);}}

	}
				}
			}
		}
	}

	return 0;
}
