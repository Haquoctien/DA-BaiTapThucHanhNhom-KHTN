#include <iostream>
using namespace std;

// struct DonThuc la node, DaThuc la dslk don bieu dien da thuc
struct DonThuc {
	int expo; // so mu
	int coef; // he so
	DonThuc *next;
};
struct DaThuc {
	DonThuc *head;
	DonThuc *tail;
};
// cac thao tac tren DaThuc
void nhap(DaThuc &f);
void xuat(DaThuc f);
DaThuc &cong(DaThuc f, DaThuc g);
void destroy(DaThuc &f);
void sort(DaThuc &f);
int main()
{
	DaThuc f, g;
	nhap(f);
	xuat(f);
	nhap(g);
	xuat(g);
	DaThuc h = cong(f, g);
	cout << "Ket qua phep cong: ";
	xuat(h);
	destroy(f);
	destroy(g);
	destroy(h);
	system("pause");
	return 0;
}

void nhap(DaThuc & f)
{
	f.head = new DonThuc;
	DonThuc *p = f.head;
	bool respond;
	while (true)
	{
		cout << "Nhap lan luot so mu va he so cua don thuc can nhap: ";
		cin >> p->expo >> p->coef;
		cout << "Nhap 1 de nhap tiep, nhap 0 de dung: ";
		cin >> respond;
		if (respond)
		{
			p->next = new DonThuc;
			p = p->next;
		}
		else
			break;
		respond = 0;
		cin.ignore();
	}
	p->next = NULL;
	f.tail = p;
}

void xuat(DaThuc f)
{
	DonThuc *p = f.head;
	while (p)
	{
		cout << p->coef << "x^" << p->expo;
		p = p->next;
		if (p)
			cout << " + ";
	}
	cout << endl;
}

DaThuc &cong(DaThuc f, DaThuc g)
{
	sort(f);
	sort(g);
	DonThuc *pf = f.head, *pg = g.head, *ans = new DonThuc;
	DaThuc answer;
	answer.head = ans;
	while (pf && pg)
	{
		if (pg->expo > pf->expo)
		{
			ans->coef = pg->coef;
			ans->expo = pg->expo;
			pg = pg->next;
		}
		else if (pf->expo > pg->expo)
		{
			ans->coef = pf->coef;
			ans->expo = pf->expo;
			pf = pf->next;
		}
		else
		{
			ans->coef = pf->coef + pg->coef;
			ans->expo = pf->expo;
			pf = pf->next;
			pg = pg->next;
		}
		if (pf && pg)
		{
			ans->next = new DonThuc;
			ans = ans->next;
		}
	}
	while (pf)
	{
		ans->next = new DonThuc;
		ans = ans->next;
		ans->coef = pf->coef;
		ans->expo = pf->expo;
		pf = pf->next;

	}
	while (pg)
	{
		ans->next = new DonThuc;
		ans = ans->next;
		ans->coef = pg->coef;
		ans->expo = pg->expo;
		pg = pg->next;
	}
	ans->next = NULL;
	answer.tail = ans;
	return answer;
}

DonThuc *popHead(DaThuc &f)
{
	DonThuc *temp;
	if (f.head == NULL)
		return NULL;
	else if (f.head == f.tail)
	{
		temp = f.head;
		f.head = f.tail = NULL;
		return temp;
	}
	temp = f.head;
	f.head = f.head->next;
	temp->next = NULL;
	return temp;
	
}
void destroy(DaThuc & f)
{
	while (f.head)
	{
		delete popHead(f);
	}
}

void swap(DonThuc *a, DonThuc *b)
{
	if (a == b)
		return;
	swap(a->coef, b->coef);
	swap(a->expo, b->expo);
}
void sort(DaThuc & f)
{
	for (DonThuc *i = f.head; i; i = i->next)
	{
		DonThuc *max = i;
		for (DonThuc *j = i->next; j; j = j->next)
		{
			if (max->expo < j->expo)
				max = j;
		}
		swap(max, i);
	}
}
