#include <iostream>
using namespace std;

int main()
{
	float decpound, decfrac;
	int pound, sh, p;
	cout << "Enter quantity of decpound: ";
	cin >> decpound;
	pound = static_cast<int>(decpound);
	decfrac = decpound - pound;
	sh = decfrac / (1 / 20.0); //������ ���������
	p = round((decfrac - sh * (1 / 20.0)) / (1 / 20.0 / 12.0)); //������� ���������
	cout << "Pound " << pound << '.' << sh << '.' << p;
}