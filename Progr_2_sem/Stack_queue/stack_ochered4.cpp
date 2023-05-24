#include <iostream> 
#include <fstream>

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

stack* result(stack*& h, int el) {  //  ������� �������� ��������������� �����
	stack* res = NULL;  //  �������������� ����� ����
	int fl = 0;  //  ����������-���� � ���, ��� �� ����� �� ������� �������
	while (h) {  //  ���� �� ����� �� ����� ������� �����
		int x = pop(h);  //  �������� ��� �������
		if (x % 2 == 0 && fl == 0) {  //  ���� �� ������ ������
			fl = 1;  //  �� ������ ����� ������ ������
			push(res, x);  //  ��������� � ���� ���� �������
			push(res, el);  //  ��������� � ���� �������� �������
		}
		else push(res, x);  //  ��������� �������
	}
	reverse(res);  //  �������� �������������� ����
	return res;  //  ���������� �������������� ����
}

int main() {
	setlocale(LC_ALL, "Russian");  //  ���������� ������� ����
	ifstream in("text.txt");  //  ���������� ����
	int n;  //  ���������� ���������� �����
	cout << "������� ���������� �����:" << endl;  //  ������� ����� 
	cin >> n;  //  ������ �� ����������
	stack* head = NULL;  //  �������������� ����
	int x, el = 0, numb = 0;  //  ������ ����������� ����������
	cout << "������� 1, ���� ������ ������ ����� ����, ��� 2, ���� �� �����: "; cin >> numb;  //  ������� ����� � ����� ����, ��� �������� �����
	cout << "������� ����� �����: "; cin >> el;  //  ������� ����� � ������ ����� �����
	if (numb == 1) {  //  ������ ����� ����
		for (int i = 0; i < n; i++) {  //  ���� �� ���� ������� �����
			cin >> x;  //  ������ �����
			push(head, x);  //  ��������� ����� � ����
		}
	}
	if (numb == 2) {  //  ������ �� �����
		while (in.peek() != EOF) {  //  ���� �� ����� �� ����� �����
			in >> x;  //  ������ �������
			push(head, x);  //  ��������� ��� � ����
		}
	}
	reverse(head);  //  �������������� ����
	stack* res = result(head, el);  //  ������ ����� ���� �� �������  
	while (res)  //  ���� �� �� ������ �� ����� �����
		cout << pop(res) << " ";  //  ������� ������� �����
	cout << endl;  //  ���������� ������
	return 0;
}