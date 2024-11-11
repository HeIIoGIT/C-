#include <iostream>
using namespace std;




int main()
{
	setlocale(0, "");

	int a, b;
	char operation;
	cout << "Введите два числа <int>\n";
	cout << "первое число <a> : ";
	cin >> a;
	cout << "второе число <b> : ";
	cin >> b;
	cout << "\nВведите знак операции <+-*/>: ";
	cin >> operation;
	cout << endl;

	switch (operation)
	{
	case '+':
		cout << a << " + " << b << " = " << a + b << endl;
		break;
	case '-':
		cout << a << " - " << b << " = " << a - b << endl;
		break;
	case '*':
		cout << a << " * " << b << " = " << a * b << endl;
		break;
	case '/':
		if (b != 0)
		{
			cout << a << " / " << b << " = " << a / b << endl;
			cout << a << " % " << b << " = " << a % b << endl;
		}
		else
		{
			cerr << "НА НОЛЬ ДЕЛИТЬ НЕЛЬЗЯ!";
		}
		break;
	default:
		cout << "Я вообще без понятия!" << endl;
		break;
	}

	return 0;
}
