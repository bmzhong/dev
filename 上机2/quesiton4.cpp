#include<iostream>
#include<cstdlib>

using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
#define INFEASIBLE -2
#define INIT_SIZE 20
#define INCREAMENT 10
typedef int Status;
typedef int ElementType;
typedef struct Data {
	char ad;//Arrival or Departure 
	ElementType license;
	ElementType time;
	ElementType inTime;
	int pw;
	int site;
} Data, *PData;
typedef struct ParkStack {
	PData base;
	PData top;
	int size;
} ParkStack;
typedef struct Node {
	Data data;
	struct Node *next;
} Node, *PNode;
typedef struct WaitQueue {
	PNode front;
	PNode rear;
} WaitQueue;

Status createAndInit(ParkStack &P, ParkStack &R, WaitQueue &W);

Status push(ParkStack &P, Data &data);

Status pop(ParkStack &P, Data &data);

Status inQueue(WaitQueue &W, Data &data);

Status outQueue(WaitQueue &W, Data &data);

Status getTheSameCar(ParkStack &P, WaitQueue &W, Data data, Data &same);

Status processIn(ParkStack &P, WaitQueue &W, Data &data, int n);

Status deleteNode(WaitQueue &W, Data data);

Status resetStackSite(ParkStack &P);

Status resetQueueSite(WaitQueue &W);

Status processOut(ParkStack &P, ParkStack &R, WaitQueue &W, Data &data, int m);

Status process(ParkStack &P, ParkStack &R, WaitQueue &W);

Status countQueue(WaitQueue &W, int &count);

int main() {
	ParkStack P, R;
	WaitQueue W;
	createAndInit(P, R, W);
	process(P, R, W);
	return 0;
}

Status process(ParkStack &P, ParkStack &R, WaitQueue &W) {
	Data data;
	int n, m;
	cout << "请输入停车场的车位数：" << endl;
	cin >> n ;
	cout << "请输入每小时的停车费：" << endl;
	cin >> m ; 
	cout << "请输入车辆的停车信息：" << endl;
	while(true) {
		cin >> data.ad >> data.license >> data.time;
		if(data.ad=='E'){
			break;
		}
		if (data.ad == 'A') {
			processIn(P, W, data, n);
		} else if (data.ad == 'D') {
			processOut(P, R, W, data, m);
		}
	}
	return OK;
}

Status processIn(ParkStack &P, WaitQueue &W, Data &data, int n) {
	if (P.top - P.base < n) {
		push(P, data);
		cout << "此车停在停车场的" << data.site << "号位置" << endl;
	} else {
		inQueue(W, data);
		cout << "此车停在便道的" << data.site << "号位置" << endl;
	}
	return OK;
}

Status processOut(ParkStack &P, ParkStack &R, WaitQueue &W, Data &data, int m) {
	Data same, temp;
	int re, count;
	re = getTheSameCar(P, W, data, same);
	if (re == 1) {
		cout << "此车在停留的时间为" << data.time - same.inTime << endl;
		cout << "此车应收的停车费为" << m * (data.time - same.inTime) << endl;
		count = P.top - P.base;
		for (int i = 0; i < count - same.site; ++i) {
			pop(P, temp);
			push(R, temp);
		}
		pop(P, temp);
		for (int i = 0; i < count - same.site; ++i) {
			pop(R, temp);
			push(P, temp);
		}
		resetStackSite(P);
		if (W.rear != W.front) {
			outQueue(W, temp);
			resetQueueSite(W);
			temp.inTime = data.time;
			push(P, temp);
		}
	} else {
		cout << "此车没有在停车场停留" << endl;
		deleteNode(W, same);
		resetQueueSite(W);
	}
	return OK;
}

Status createAndInit(ParkStack &P, ParkStack &R, WaitQueue &W) {
	P.base = (PData) malloc(INIT_SIZE * sizeof(Data));
	P.top = P.base;
	P.size = INIT_SIZE;
	R.base = (PData) malloc(INIT_SIZE * sizeof(Data));
	R.top = R.base;
	R.size = INIT_SIZE;
	W.front = (PNode) malloc(sizeof(PNode));
	W.front->next = NULL;
	W.rear = W.front;
	if (!P.base || !R.base || !W.front) {
		exit(OVERFLOW);
	}
	return OK;
}

Status push(ParkStack &P, Data &data) {
	if ((P.top - P.base) >= P.size) {
		P.base = (PData) malloc((P.size + INCREAMENT) * sizeof(Data));
		P.top = P.base + P.size;
		P.size = P.size + INCREAMENT;
	}
	if (!P.base) {
		exit(OVERFLOW);
	}
	data.pw = 0;
	data.site = P.top - P.base + 1;
	data.inTime = data.time;
	*P.top++ = data;
	return OK;
}

Status pop(ParkStack &P, Data &data) {
	if (P.top == P.base) return INFEASIBLE;
	data = *--P.top;
	return OK;
}

Status inQueue(WaitQueue &W, Data &data) {
	PNode p;
	int count;
	p = (PNode) malloc(sizeof(Node));
	if (!p) {
		exit(OVERFLOW);
	}
	countQueue(W, count);
	data.site = count + 1;
	p->data = data;
	p->next = NULL;
	W.rear->next = p;
	W.rear = p;
	return OK;
}

Status outQueue(WaitQueue &W, Data &data) {
	if (W.front == W.rear) {
		return ERROR;
	}
	PNode p;
	p = W.front->next;
	W.front->next = p->next;
	if (W.rear == p) {
		W.rear = W.front;
	}
	data = p->data;
	free(p);
	return OK;
}

Status getTheSameCar(ParkStack &P, WaitQueue &W, Data data, Data &same) {
	ElementType license;
	license = data.license;
	PNode j = W.front->next;
	PData i = P.base;
	for (i; i < P.top; ++i) {
		if (data.license == i->license) {
			break;
		}
	}
	if (i < P.top) {
		same = *i;
		return 1;
	} else {
		same.inTime = data.time;
		return 0;
	}
}

Status deleteNode(WaitQueue &W, Data data) {
	PNode p = W.front->next, t;
	while (p->next->data.license != data.license) {
		p = p->next;
	}
	t = p->next;
	p->next = t->next;
	free(t);
	return OK;
}

Status resetStackSite(ParkStack &P) {
	PData q = P.base;
	int i = 1;
	while (q < P.top) {
		q->site = i;
		q++;
	}
	return OK;
}

Status resetQueueSite(WaitQueue &W) {
	PNode p = W.front->next;
	int i = 1;
	if (!p) {
		return OK;
	}
	while (p <= W.rear) {
		p->data.site = i;
		p++;
	}
	return OK;
}

Status countQueue(WaitQueue &W, int &count) {
	PNode p = W.front;
	count = 0;
	while (p != W.rear) {
		p = p->next;
		++count;
	}
	return OK;
}
/*
  1.将data传入函数后，对data的数据进行了处理，然后又在原函数中处理了和输出了data的值， 
但是由于data没有用引用传递，导致在原函数中的data数据没有发生改变，从而产生了错误的结果。
  2.将代码从devc++中赋值到clion中，调试和运行的编码不同，调试的时候功能正常，而运行不正常
  3.在节点出队列的时候，没有做if (W.rear == p) {W.rear = W.front;}的判断，并且W.rear=W.front
不要写成W.rear==W.front,虽然在Clion中有提示。 
  4.在出栈和出队列的时候，应改变其中每辆车的位置信息。
  5.在计算队列的节点个数时，一开始用W.rear-W.front，出现了错误，另外写了一个countQueue函数。
链式结构用W.top-W.base或者W.rear-W.front没有意义。
  6.do while{}循环改成了while(true){if break}循环，判断的是当前的data.ad而不是上一次的data.ad
     
*/
