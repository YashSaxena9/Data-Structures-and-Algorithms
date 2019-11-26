#include<iostream>
#include<list>

using namespace std;

int main()
{
	list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	l.push_back(50);
	l.push_back(60);

	while(l.size() > 0) {
		int var = l.front();
		l.pop_front();
		cout << var << " ";
	}
	cout << endl;
}