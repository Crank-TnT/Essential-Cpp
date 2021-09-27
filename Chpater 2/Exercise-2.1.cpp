
#include <iostream>
using namespace std;

bool fibon_elem(int, int&);

int main(int argc, char const* argv[])
{
	int pos, elem;
	char ch;
	bool more = true;

	while (more)
	{
		cout << "Please enter a position: ";
		cin >> pos;

		if (fibon_elem(pos, elem))
			cout << "element # " << pos
			<< " is " << elem << endl;
		else
			cout << "Sorry. Could not calculate element # "
			<< pos << endl;

		cout << "Would you like to try again? (y/n) ";
		cin >> ch;
		if (ch != 'y' && ch != 'Y')
			more = false;
	}
}

bool fibon_elem(int pos, int& elem)
{
	// 检查位置值是否合理
	if (pos <= 0 || pos > 1024)
	{
		elem = 0; 
		return false;
	}

	// 位置为1和2时，elem的值为1
	elem = 1;
	int n_2 = 1, n_1 = 1;

	for (int ix = 3; ix <= pos; ix++)
	{
		elem = n_2 + n_1;
		n_2 = n_1;
		n_1 = elem;
	}

	return true;
}
