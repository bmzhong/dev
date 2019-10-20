
#include<cstdlib>

#include<iostream>

using namespace std;

typedef struct {	//用于封装方位及方向 

	int col,row,way;                 //0,1,2,3分别代表上、下、左、右 

}Point;

 

typedef struct T{  //路径链表节点 

	Point P;

	struct T *next;

}LStack;

 

void In(LStack *top,Point temp){  //入栈 

	LStack *s=(LStack *)malloc(sizeof(LStack));

	s->P=temp;

	s->next=top->next;

	top->next=s;

} 

 

bool Out(LStack *top){       //出栈 

	if(top->next==NULL)return false;

	else {

		LStack *p=top->next;

		top->next=p->next;

		free(p);

		return true;

	}

}

bool Query(LStack *top,Point temp){ //查询栈中是否存在temp值 

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

			if(top->next!=NULL && ((top->next->P.way+2)%4==temp.way))continue;  //解决上下，左右重复死循环问题 

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

		if(temp.way>3){     //无路可走时将点标-1并退栈 

			if(temp.row==Home.row && temp.col==Home.col)return false;

			map[temp.row][temp.col]=-1;

			Out(top);

			temp=top->next->P;

		} 

	}while(!(temp.row==End.row && temp.col==End.col));

	temp.way=4;        

	In(top,temp);           //到达出口，入栈出口信息 

	return true; 

}

void Display(LStack *top){     //通过头插二次入栈实现逆序链表. 

	LStack *s,*p=top->next;

	top->next=NULL;

	while(p!=NULL){

		if(p->next!=NULL && p->P.col==p->next->P.col && p->P.row==p->next->P.row)p=p->next; //解决原路径中会存在一些判断退回时产生的数据冗余问题。 

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

		cout<<"存在正确路径，如下(row,col,方向（0上,1右,2下,3左，4出口）)："<<endl;

		Display(top);

	}

	else cout<<"无法到达出口"<<endl; 

	return 0;

}

