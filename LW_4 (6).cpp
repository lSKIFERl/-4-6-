#include <iostream>
using namespace std;
struct list
{
	int info;
	list* pred;
	list* next;
};
bool elementary(list* p)
{
	for (int i = 2; i < p->info; i++)
		if (p->info % 2 == 0)
			return 0;
	return 1;
}
void main()
{
	int x;
	bool boolka = 1;
	list* p, *r, *beg;
	beg = new(list);
	cin >> x;
	beg->info = x;
	beg->next = 0;
	beg->pred = 0;
	p = beg;
	cin >> x;
	while (x != 0)
	{
		if (x != 0)
		{
			r = new(list);
			r->info = x;
			r->pred = p;
			r->next = 0;
			p->next = r;
			p = r;
		}
		cin >> x;
	}
	r = p;
	p = beg;
	while (p != r && boolka)
	{
		if (p->info != r->info)
			boolka = 0;
		r = r->pred;
		p = p->next;
	}
	p = beg;
	if (boolka == 0)
	{
		while (p->next->next!= 0)
			if (p->next->info > 0)
			{
				p->next = p->next->next;
				p->next->pred = p;
			}
			else p = p->next;
		if (p->next->info > 0)
			p->next = 0;
		if (beg->info > 0)
			beg = beg->next;
	}
	else
	{
		while (p->next->next!=0)
			if (elementary(p->next))
			{
				p->next = p->next->next;
				p->next->pred = p;
			}
			else p = p->next;
		if (elementary(p->next))
			p->next = 0;
		if (elementary(beg))
			beg = beg->next;
	}
	p = beg;
	while (p != 0)
	{
		cout << p->info << " ";
		p = p->next;
	}
	system("Pause");
}
