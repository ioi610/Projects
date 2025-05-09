
#include <iostream>

using namespace std;

const int N = 100010;

int head, e[N], ne[N], idx;

void init()
{
	head = -1;
	idx = 0;
}

void add_to_head(int x)
{
	e[idx] = x ,ne[idx] = head ,head = idx ++;
}

void add(int x, int k)
{
	e[idx] = x, ne[idx] = ne[k], ne[k] = idx ++;
}

void remove(int k)
{
	ne[k] = ne[ne[k]];	
}

int main()
{
	int m;
	cin >> m;
	while (m -- )
	{
		int k, x;
		cahr op;

		cin >> op;
		if (op == 'M')
		{
			cin >> x;
			add_to_head(x);
		}	
		else if (op == 'D')
		{
			cin >> k;
			remove(k);
		}
		else
		{
			cin >> k >> x;
			add(k, x);
		}	
	}

	for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
	cout << endl;

	return 0;
}
