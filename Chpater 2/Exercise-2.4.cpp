/*
	写一个函数，以局部静态（local static）的vector储存Pentagonal数列元素。此函数返回一个const
	指针，指向该vector。如果vector的大小小于指定的元素个数，就扩充vector的大小。
	接下来再实现第二个函数，接受一个位置值，返回该位置上的元素。
	最后编写main()测试这些函数。
*/

#include <vector>
#include <iostream>
using namespace std;

inline bool check_validity(int pos)
{
	return (pos <= 0 || pos > 64) ? false : true;
}

const vector<int>* Pentagonal_Series(int pos)	
{
	static vector<int> _elems;			// 局部静态vector

	if (check_validity(pos) && (pos > _elems.size()))
		for (int ix = _elems.size() + 1; ix <= pos; ++ix)
			_elems.push_back((ix * (3 * ix - 1)) / 2);
	return &_elems;		// 返回const指针
}

bool pentagonal_elem(int pos, int &elem)
{
	if (!check_validity(pos))
	{
		cout << "Sorry. Invalid position: " << pos << endl;
		elem = 0;
		return false;
	}

	const vector<int> *pent = Pentagonal_Series(pos);
	elem = (*pent)[pos - 1];
	return true;
}

int main(int argc, char const *argv[])
{
	int elem;

	if (pentagonal_elem(8, elem))
		cout << "element 8 is " << elem << '\n';
	if (pentagonal_elem(88, elem))
		cout << "element 88 is " << elem << '\n';
	if (pentagonal_elem(12, elem))
		cout << "element 12 is " << elem << '\n';
	if (pentagonal_elem(64, elem))
		cout << "element 64 is " << elem << '\n';

	return 0;
}