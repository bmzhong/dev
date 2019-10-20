
#include<cstdlib>

#include<iostream>

using namespace std;

typedef struct {	//���ڷ�װ��λ������ 

	int col,row,way;                 //0,1,2,3�ֱ�����ϡ��¡����� 

}Point;

 

typedef struct T{  //·������ڵ� 

	Point P;

	struct T *next;

}LStack;

 

void In(LStack *top,Point temp){  //��ջ 

	LStack *s=(LStack *)malloc(sizeof(LStack));

	s->P=temp;

	s->next=top->next;

	top->next=s;

} 

 

bool Out(LStack *top){       //��ջ 

	if(top->next==NULL)return false;

	else {

		LStack *p=top->next;

		top->next=p->next;

		free(p);

		return true;

	}

}

bool Query(LStack *top,Point temp){ //��ѯջ���Ƿ����tempֵ 

	LStack *p=top->next;

	while(p!=NULL){

		if(p->P.row==temp.row && p->P.col==temp.col)return true;

		p=p->next;

	}

	return false;

}

 

bool Found(LStack *top){

	int height,width;

	height=9;width=8;

	Point Home,End,temp;

	Home.row=1;Home.col=1;

	End.row=9;End.col=8;

	int map[][10]={

	{1,1,1,1,1,1,1,1,1,1},

	{1,0,0,1,0,0,0,1,0,1},

	{1,0,0,1,0,0,0,1,0,1},

	{1,0,0,0,0,1,1,0,1,1},

	{1,0,1,1,1,0,0,1,0,1},

	{1,0,0,0,1,0,0,0,0,1},

	{1,0,1,0,0,0,1,0,1,1},

	{1,0,1,1,1,1,0,0,1,1},

	{1,1,1,0,0,0,1,0,1,1},

	{1,1,1,0,0,0,0,0,0,1},

	{1,1,1,1,1,1,1,1,1,1}

	};

	temp.col=Home.col;temp.row=Home.row;

	do{

		for(temp.way=0;temp.way<=3;temp.way++){

			if(top->next!=NULL && ((top->next->P.way+2)%4==temp.way))continue;  //������£������ظ���ѭ������ 

			if(temp.way==0){

				if(map[--temp.row][temp.col]==0 && !Query(top,temp)){

					temp.row++;

					In(top,temp);

					temp.row--;

					break;

				}

				else{

					temp.row++;

					continue;

				}

			}

			if(temp.way==1){

				if(map[temp.row][++temp.col]==0 && !Query(top,temp)){

					temp.col--;

					In(top,temp);

					temp.col++;

					break;

				}

				else{

					temp.col--;

					continue;

				}

			}

			if(temp.way==2){

				if(map[++temp.row][temp.col]==0 && !Query(top,temp)){

					temp.row--;

					In(top,temp);

					temp.row++;

					break;

				}

				else{

					temp.row--;

					continue;

				}

			}

			if(temp.way==3){

				if(map[temp.row][--temp.col]==0 && !Query(top,temp)){

					temp.col++;

					In(top,temp);

					temp.col--;

					break;

				}

				else{

					temp.col++;

					continue;

				}

			}

		}

		if(temp.way>3){     //��·����ʱ�����-1����ջ 

			if(temp.row==Home.row && temp.col==Home.col)return false;

			map[temp.row][temp.col]=-1;

			Out(top);

			temp=top->next->P;

		} 

	}while(!(temp.row==End.row && temp.col==End.col));

	temp.way=4;        

	In(top,temp);           //������ڣ���ջ������Ϣ 

	return true; 

}

void Display(LStack *top){     //ͨ��ͷ�������ջʵ����������. 

	LStack *s,*p=top->next;

	top->next=NULL;

	while(p!=NULL){

		if(p->next!=NULL && p->P.col==p->next->P.col && p->P.row==p->next->P.row)p=p->next; //���ԭ·���л����һЩ�ж��˻�ʱ�����������������⡣ 

		s=p;

		p=p->next;

		s->next=top->next;

		top->next=s;

	} 

	while(s!=NULL){

		cout<<s->P.row<<" "<<s->P.col<<" "<<s->P.way<<endl; 

		s=s->next;

	}

}

int main(){

	LStack *top=(LStack *)malloc(sizeof(LStack));

	top->next=NULL;

	if(Found(top)){

		cout<<"������ȷ·��������(row,col,����0��,1��,2��,3��4���ڣ�)��"<<endl;

		Display(top);

	}

	else cout<<"�޷��������"<<endl; 

	return 0;

}

