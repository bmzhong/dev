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
	cout << "������ͣ�����ĳ�λ����" << endl;
	cin >> n ;
	cout << "������ÿСʱ��ͣ���ѣ�" << endl;
	cin >> m ; 
	cout << "�����복����ͣ����Ϣ��" << endl;
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
		cout << "�˳�ͣ��ͣ������" << data.site << "��λ��" << endl;
	} else {
		inQueue(W, data);
		cout << "�˳�ͣ�ڱ����" << data.site << "��λ��" << endl;
	}
	return OK;
}

Status processOut(ParkStack &P, ParkStack &R, WaitQueue &W, Data &data, int m) {
	Data same, temp;
	int re, count;
	re = getTheSameCar(P, W, data, same);
	if (re == 1) {
		cout << "�˳���ͣ����ʱ��Ϊ" << data.time - same.inTime << endl;
		cout << "�˳�Ӧ�յ�ͣ����Ϊ" << m * (data.time - same.inTime) << endl;
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
		cout << "�˳�û����ͣ����ͣ��" << endl;
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
  1.��data���뺯���󣬶�data�����ݽ����˴���Ȼ������ԭ�����д����˺������data��ֵ�� 
��������dataû�������ô��ݣ�������ԭ�����е�data����û�з����ı䣬�Ӷ������˴���Ľ����
  2.�������devc++�и�ֵ��clion�У����Ժ����еı��벻ͬ�����Ե�ʱ���������������в�����
  3.�ڽڵ�����е�ʱ��û����if (W.rear == p) {W.rear = W.front;}���жϣ�����W.rear=W.front
��Ҫд��W.rear==W.front,��Ȼ��Clion������ʾ�� 
  4.�ڳ�ջ�ͳ����е�ʱ��Ӧ�ı�����ÿ������λ����Ϣ��
  5.�ڼ�����еĽڵ����ʱ��һ��ʼ��W.rear-W.front�������˴�������д��һ��countQueue������
��ʽ�ṹ��W.top-W.base����W.rear-W.frontû�����塣
  6.do while{}ѭ���ĳ���while(true){if break}ѭ�����жϵ��ǵ�ǰ��data.ad��������һ�ε�data.ad
     
*/
