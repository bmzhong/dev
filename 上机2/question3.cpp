#include<iostream>
#include<cstdlib>
using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
#define INFEASIBLE -2
#define ROW 11
#define COL 10
typedef int Status;
typedef struct {
	int map[ROW][COL];
} Map;
typedef struct Site {
	int row;
	int col;
	int dir; //1 下；2 右；3 上；4 左；
} Site;
typedef struct Node {
	Site site;
	struct Node *next;
} Node, *LinkStack;
Status initMap(Map &M);
Status create(LinkStack &L);
bool stackEmpty(LinkStack &L);
Status push(LinkStack &L, Site site);
Status pop(LinkStack &L);
bool isSame(LinkStack &L, int row, int col);
Status maze(LinkStack &L, Map &M);
Status traverse(LinkStack &L);
int main() {
	LinkStack L;
	create(L);
	Map M;
	initMap(M);
	int result;
	result = maze(L, M);
	if (result == 1) {
		traverse(L);
	} else {
		cout << "没有通路" << endl;
	}
	return 0;
}
Status initMap(Map &M) {
	//map全部初始化为0 ,再赋值,注意map的第一行和第一列是墙
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			M.map[i][j] = 1;
		}
	}
	int map1[11][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
		{1, 1, 0, 1, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 1, 1, 0, 1, 1},
		{1, 0, 1, 1, 1, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 1, 1, 0, 0, 0, 1, 0, 1, 1},
		{1, 0, 1, 1, 1, 1, 0, 0, 1, 1},
		{1, 1, 1, 0, 0, 0, 1, 0, 1, 1},
		{1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
//	给map赋值，墙不允许赋值,1表示该位置是通路，0表示该位置是障碍。
	for (int i = 1; i < ROW - 1; ++i) {
		for (int j = 1; j < COL - 1; ++j) {
//			cin>>M.map[i][j];
			M.map[i][j] = map1[i][j];
		}
	}
	return OK;
}
Status create(LinkStack &L) {
	L = (LinkStack) malloc(sizeof(Node));
	if (!L) {
		exit(OVERFLOW);
	}
	L->next = NULL;
	return OK;
}
bool stackEmpty(LinkStack &L) {
	return L->next == NULL ? true : false;
}
Status push(LinkStack &L, Site site) {
	LinkStack p;
	p = (LinkStack) malloc(sizeof(Node));
	p->site = site;
	p->next = L->next;
	L->next = p;
	return OK;
}
Status pop(LinkStack &L) {
	LinkStack t;
	t = L->next;
	L->next = t->next;
	free(t);
	return OK;
}
bool isSame(LinkStack &L, int row, int col) {
	LinkStack p = L->next;
	while (p) {
		if (p->site.row == row && p->site.col == col) {
			return true;
		}
		p = p->next;
	}
	if (!p) {
		return false;
	}
}
Status maze(LinkStack &L, Map &M) {
	Site start, end, temp;
	start.col = 1;
	start.row = 1;
	end.col = COL - 2;
	end.row = ROW - 2;
	temp = start;
	do {
		for (temp.dir = 1; temp.dir <= 4; ++temp.dir) {
			if (temp.dir == 1) {
				if (M.map[temp.row + 1][temp.col] == 0 && (!isSame(L, temp.row + 1, temp.col))) {
					push(L, temp);
					temp.row++;
					break;
				}
			}
			if (temp.dir == 2) {
				if (M.map[temp.row][temp.col + 1] == 0 && (!isSame(L, temp.row, temp.col + 1))) {
					push(L, temp);
					temp.col++;
					break;
				}
			}
			if (temp.dir == 3) {
				if (M.map[temp.row - 1][temp.col] == 0 && (!isSame(L, temp.row - 1, temp.col))) {
					push(L, temp);
					temp.row--;
					break;
				}
			}
			if (temp.dir == 4) {
				if (M.map[temp.row][temp.col - 1] == 0 && (!isSame(L, temp.row, temp.col - 1))) {
					push(L, temp);
					temp.col--;
					break;
				}
			}
		}
		if (temp.dir > 4) {
			if (temp.row==start.row&&temp.col==start.col) {
				return ERROR;
			}
			M.map[temp.row][temp.col] = -1;
			pop(L);
			temp = L->next->site;
		}
	} while (!(temp.row == end.row && temp.col == end.col));
	temp.dir = 0;
	push(L, temp);
	return OK;
}
Status traverse(LinkStack &L) {
	LinkStack p,q, t;
	p = L->next;
	q=NULL;
	while (p) {
		t = p;
		p = p->next;
		t->next = q;
		q = t;
	}
	L->next=t;
	while (t) {
		if(t->next!=NULL&&t->site.row==t->next->site.row&&t->site.col==t->next->site.col) {
			t=t->next;
		}
		cout <<"("<< t->site.row << "," << t->site.col << "," << t->site.dir<<")" << endl;
		t=t->next;
	}
	return OK;
}
