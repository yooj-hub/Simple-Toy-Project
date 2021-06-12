/*
 * Word test
 * Description:
 *				Eng word test suggesting Korean then correting the answer(Eng)
 * Using : Linux gcc
 * Programmer: yooj
 * Date: 20.12.02
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int m=0;
int n=0;
int es=1;
int i=0;
int z=0;
typedef struct di{
	char eng[15];
	char kor[90];
}di;
typedef struct dic2{
	struct di dic;
	struct dic2 *next;
}dic2;
typedef struct dic2 ELEMENT;
typedef ELEMENT *LINK;
void test(LINK head){
	char  c[15];
	char w[15]=".quit";
	printf("%s\n",head->dic.kor);
	scanf("%s",c);
	es=0;
	
	if(strcmp(c,w)!=0){
	if(strcmp(c,head->dic.eng)==0){	
		n++;
		printf("correct!\n");
		m++;
		if(m==i){printf("average : %d .\n",(100*n)/m);es=0;}
		else {test(head->next);}
	}
	else if(strcmp(c,head->dic.eng)!=0){
		printf("incorrect!\n");
	m++;
		if(m==i){printf("average : %d \n",(100*n)/m);es=0;}
	else {test(head->next);}}
	}	
	else{printf("average : %d \n",(100*n)/m);
		es=0;
	}}

int main(void){
	FILE *fp;
	char * a;
	char * b;
	int o;
	fp=NULL;
	fp=fopen("dic.txt","r");
	LINK head;
	LINK temp;
	LINK k;
	head=NULL;
	LINK p;
	int l=0;
	int t=0;
	while(1){
		temp=malloc(sizeof(ELEMENT));
		l=fscanf(fp,"%s %s\n",temp->dic.eng,temp->dic.kor);
		temp->next=NULL;
		if(l!=EOF){
			i++;
		if(head==NULL){
			head=temp;
		}
		else{
			if(strcmp(temp->dic.eng,head->dic.eng)<0){
				temp->next=head;
				head=temp;}
			else{
				p=head;
				while(p!=NULL&&(strcmp(temp->dic.eng,p->dic.eng)>0))
						{
						k=p;
						p=p->next;}
				temp->next=k->next;
				k->next=temp;
			}
		}
		
		p=head;
		}
		else{
		break;}}
	printf("Menu \n 1)test Eng words\n 2)Exit\n");
	scanf("%d",&o);
	if(o==2){
		system("clear");
	exit(1);}
	if(o==1){
	while(es)
	{test(head);}}
	fclose(fp);
	return 0;}
