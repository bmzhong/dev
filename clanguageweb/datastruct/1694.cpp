#include <iostream>
using namespace std;
struct A {
	int row;
	int data;
	int col;
};
struct B {
	A arr[10000];
	int cpot[1000] = {0};
	int mu, nu, tu = 0;
};
void multiply(B &m, B &t, B &rs);
void display(B &rs);
void createMatrix(B &m, B &t);
int main() {
	B m, t, rs;
	createMatrix(m, t);
	multiply(m, t, rs);
	display(rs);

	return 0;
}

void display(B &rs) {
	int p = 0;
	for (int i = 0; i < rs.mu; ++i) {
		for (int j = 0; j < rs.nu; ++j) {
			if (p<rs.tu&&rs.arr[p].row == i && rs.arr[p].col == j) {
				printf("%d ",rs.arr[p].data);
				++p;
			} else {
				printf("0 ");
			}
		}
		printf("\n");
	}
}

void createMatrix(B &m, B &t) {
	int r1, c1, r2, c2, b;
	scanf("%d %d", &r1, &c1);
	m.mu = r1;
	m.nu = c1;
	m.tu = 0;
	for (int i = 0; i < r1; ++i) {
		m.cpot[i] = m.tu;
		for (int j = 0; j < c1; ++j) {
			scanf("%d", &b);
			if (b != 0) {
				A a;
				a.data = b;
				a.col = j;
				a.row = i;
				m.arr[m.tu++] = a;
			}
		}
	}
	scanf("%d %d", &r2, &c2);
	t.mu = r2;
	t.nu = c2;

	for (int i = 0; i < r2; ++i) {
		t.cpot[i] = t.tu;
		for (int j = 0; j < c2; ++j) {
			scanf("%d", &b);
			if (b != 0) {
				A a;
				a.data = b;
				a.col = j;
				a.row = i;
				t.arr[t.tu++] = a;
			}
		}
	}
}

void multiply(B &m, B &t, B &rs) {
	rs.mu = m.mu;
	rs.nu = t.nu;
	int mnext, ccol, tnext;
	int ctemp[rs.nu];
	for (int i = 0; i < m.mu; ++i) {
		for (int j = 0; j < rs.nu; ++j) {
			ctemp[j] = 0;
		}
		rs.cpot[i] = rs.tu;
		if (i < m.mu - 1) {
			mnext = m.cpot[i + 1];
		} else {
			mnext = m.tu;
		}
		for (int k = m.cpot[i]; k < mnext; ++k) {
			int p = m.arr[k].col;
			if (p < t.mu - 1) {
				tnext = t.cpot[p + 1];
			} else {
				tnext = t.tu;
			}
			for (int q = t.cpot[p]; q < tnext; ++q) {
				ccol = t.arr[q].col;
				ctemp[ccol] += m.arr[k].data * t.arr[q].data;
			}
		}
		for (int j = 0; j < rs.nu; ++j) {
			if (ctemp[j] != 0) {
				rs.arr[rs.tu].row = i;
				rs.arr[rs.tu].col = j;
				rs.arr[rs.tu].data = ctemp[j];
				++rs.tu;
			}
		}
	}
}
