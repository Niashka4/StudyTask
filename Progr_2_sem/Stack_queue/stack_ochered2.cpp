#include <iostream> 

using namespace std;

struct stack {  //  ��������� �����
	int Inf;  //  �������� ������
	stack* next;  //  ������ �� ��������� �������
};

void push(stack*& h, int x) {  //  ������� ������� �������� � ����
	stack* r = new stack;  //  ������ ����� ����
	r->Inf = x;  //  ��������� ����� �������
	r->next = h;  //  �� �������� ������
	h = r;
}

int pop(stack*& h) {  //  ������� �������� �� ������ ����� ��������
	int i = h->Inf;  //  ��������� �������� ������
	stack* r = h;  //  ������ ������ �� ������
	h = h->next;  //  ����� ������ - ��� ����� �������
	delete r;  //  ������� ������ �������
	return i;  //  ���������� ��������� �������
}

void reverse(stack*& h) {  //  ������� ��������� �����
	stack* head1 = NULL;  //  ������ �����
	while (h)  //  ���� ���� �� ����
		push(head1, pop(h));  //  ��������� ����
	h = head1;  //  ����� ������
}

stack* result(stack*& h, int min, int numb, int max) {  //  ������� �������� ��������������� �����
	stack* res = NULL;  //  �������������� ����� ����
	int fl = 0;  //  ����������-���� � ���, ��� �� ����� �� ������� ��� ���������� ������������
	while (h) {  //  ���� �� ����� �� ����� ������� �����
		int x = pop(h);  //  �������� ��� �������
		if (x == min) {  //  ���� �� �����������
			fl++;  //  ����������� ���������� �����������
			if (fl == 1 || fl == numb) {  //  ���� �� ������ ��� ���������, ��...
				push(res, max);  //  ��������� ���� ������������ ������� 
				push(res, x);  //  � ���� �������
			}
			else push(res, x);  //  ����� ������ ��������� �������
		}
		else push(res, x);  //  ��������� �������
	}
		reverse(res);  //  �������� �������������� ����
	return res;  //  ���������� �������������� ����
}

int main() {
	setlocale(LC_ALL, "Russian");  //  ���������� ������� ����
	int n;  //  ���������� ���������� �����
	cout << "������� ���������� �����:" << endl;  //  ������� ����� 
	cin >> n;  //  ������ �� ����������
	stack* head = NULL;  //  �������������� ����
	int x, max = 0, min = 0, numb = 1;  //  ������ ����������� ����������
	for (int i = 0; i < n; i++) {  //  ���� �� ���� ������� �����
		cin >> x;  //  ������ �����
		if (i == 0) {  //  ���� ��� ������ �����, ��...
			max = x;  //  ��� ���� ��� ������������
			min = x;  //  � �����������
		}
		if (x > max) max = x;  //  ���� ����� ������ �������������, �� ������ ��� ������������
		if (x <= min && i > 0) {  //  ���� ����� ������ ��� ����� �������������, �� ������ ��� ������������
			if (x < min) { min = x; numb = 1; }  //  ���� ��� ����� ����� ���������, �� ������� ����������� ������
			else numb++;  //  ����� ����������� ������� ������������
		}
		push(head, x);  //  ��������� ����� � ����
	}
	reverse(head);  //  �������������� ����
	stack* res = result(head, min, numb, max);  //  ������ ����� ���� �� �������  
	while (res)  //  ���� �� �� ������ �� ����� �����
		cout << pop(res) << " ";  //  ������� ������� �����
	cout << endl;  //  ���������� ������
	return 0;
}
