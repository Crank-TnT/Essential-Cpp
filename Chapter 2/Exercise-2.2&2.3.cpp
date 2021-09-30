/*
	Pentagonal数列的求值公式时P(n) = n (3n - 1) / 2，借此产生1,5,12,22,35等元素值。
	试定义一个函数，利用上述公式，将产生的元素放到用户传入的vector之中，元素个数由用户指定。
	接下来编写第二个函数，能够将给定的vector的所有元素一一打印出来。

	将2.2的Pentagonal数列求值函数拆分为两个函数，其中之一为inline，用来检测元素个数是否合理。
	如果的确合理，而且尚未被计算，便执行第二个函数，执行实际的求值工作
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool calc_elems(vector<int>& vec, int pos);
void display_elems(vector<int>& vec, const string& title, ostream& os = cout);
extern void really_calc_elems(vector<int>&, int);

int main(int argc, char const* argv[])
{
	vector<int> pent;
	const string title("Pentagonal Numeric Series");

	if (calc_elems(pent, 0))
		display_elems(pent, title);

	if (calc_elems(pent, 8))
		display_elems(pent, title);

	if (calc_elems(pent, 14))
		display_elems(pent, title);

	if (calc_elems(pent, 138))
		display_elems(pent, title);

}

inline bool calc_elems(vector<int>& vec, int pos)
{
	if (pos <= 0 || pos > 64)
	{
		cerr << "Sorry. Invalid position: " << pos << endl;
		return false;
	}

	if (vec.size() < pos)
		really_calc_elems(vec, pos);

	return true;
}

void really_calc_elems(vector<int>& vec, int pos)
{
	for (int ix = vec.size() + 1; ix <= pos; ++ix)
		vec.push_back((ix * (3 * ix - 1)) / 2);
}

void display_elems(vector<int>& vec, const string& title, ostream& os)
{
	os << "\n" << title << "\n\t";
	for (int ix = 0; ix < vec.size(); ++ix)
		os << vec[ix] << ' ';
	os << endl;
}

