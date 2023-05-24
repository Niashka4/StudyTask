#include <iostream> 

using namespace std;

struct queue {  //  ��������� �������
	int Inf;  //  �������� ������
	queue* next;  //  ������ �� ��������� �������
};

void push(queue*& h, queue*& t, int x) {  //  ������� ������� � ����� ������� ������ ��������
	queue* r = new queue;  //  ������ ����� �������
	r->Inf = x;  //  ��������� ����� �������
	r->next = NULL;  //  �� �������� ���������
	if (!h && !t) {  //  ���� ������� �����
		h = t = r;  //  ����� ������� �������� � ������� � �������
	}
	else {  //  �����
		t->next = r;  //  ����� ������� ����� ����� ������
		t = r;  //  � �������� ���������
	}
}

int pop(queue*& h, queue*& t) {  //  ������� �������� �� ������ ������� ��������
	queue* r = h;  //  ������ ������ �� ������
	int i = h->Inf;  //  ��������� �������� ������
	h = h->next;  //  ����� ������ - ��� ����� �������
	if (!h) t = NULL;  //  ���� ��� ��������� �������, �� ����� - ����
	delete r;  //  ������� ������ �������
	return i;  //  ���������� ��������� �������
}

void reverse(queue*& h, queue*& t) {  //  ������� ��������� �������
	queue* head1 = NULL;  //  ������ � ����� �����
	queue* tail1 = NULL;
	while (h)  //  ���� ������� �� �����
		push(head1, tail1, pop(h, t));  //  ��������� �������
	h = head1;  //  ����� ������
	t = tail1;  //  ����� �����
}

queue* result(queue*& h, queue*& t, int max) {  //  ������� �������� �������������� �������
	queue* res = NULL;  //  �������������� ����� �������
	queue* t1 = NULL;
	queue* h1 = NULL;  //  � ��� ���� ���������������
	queue* t2 = NULL;
	int fl = 0;  //  ����������-���� � ���, ��� �� ����� � ������� �������������
	while (h) {  //  ���� �� ����� �� ����� ������ �������
		int x = pop(h, t);  //  �������� � �������
		if (x == max && fl == 0) {  //  ���� �� ������������ � ������ ������������
			push(res, t1, x);  //  ��������� ���� ������� � �������������� �������
			fl = 1;  //  �� ����� � ����
		}
		else if (fl == 0) push(h1, t2, x);  //  ���� �� ��� �� ����� �� ������� �������������, �� ��������� ���� ������� �� ��������������� �������
		else push(res, t1, x);  //  �����, ���������� �� ���������� � �������������� �������
	}
	while (h1) {  //  ���� �� ����� �� ����� ��������������� �������
		int x = pop(h1, t2);  //  �������� �������
		push(res, t1, x);  //  ��������� ��� � �������������� �������
	}
	t = t1;  //  �������������� �����
	return res;  //  ���������� �������������� �������
}

int main() {
	setlocale(LC_ALL, "Russian");  //  ���������� ������� ����
	int n;  //  ���������� ���������� �����
	cout << "������� ���������� �����:" << endl;  //  ������� ����� 
	cin >> n;  //  ������ �� ����������
	queue* head = NULL; queue* tail = NULL;  //  �������������� �������
	int x, max = 0;  //  ������ ����������� ����������
	for (int i = 0; i < n; i++) {  //  ���� �� ���� ������� �����
		cin >> x;  //  ������ �����
		if (i == 0) {  //  ���� ��� ������ �����, ��...
			max = x;  //  ��� ���� ��� ������������
		}
		if (x > max) max = x;  //  ���� ����� ������ �������������, �� ������ ��� ������������
		push(head, tail, x);  //  ��������� ����� � ������
	}
	reverse(head, tail);  //  �������������� �������
	queue* res = result(head, tail, max);  //  ������ ����� ������� �� �������  
	while (res)  //  ���� �� �� ������ �� ����� �������
		cout << pop(res, tail) << " ";  //  ������� ������� �������
	cout << endl;  //  ���������� ������
	return 0;
}
