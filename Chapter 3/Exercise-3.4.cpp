/*

*/

#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

// 以普通函数的方式定义partition()的筛选规则
// bool m_even_elem(int i) { return i % 2 ? false : true; };

int main(int argc, char const* argv[])
{
	ifstream ifile("int_input.txt");
	if (!ifile )
	{
		cerr << "arghh!! unable to open the output files. bailing out!\n";
		return -1;
	}

	vector<int> input;
	istream_iterator<int> in(ifile), eof;
	
	// 从文件而不是控制台读取int数列
	copy(in, eof, back_inserter(input));
	// back_inserter()是必要的，因为copy()会采用assignment运算符来复制每个元素。
	// 由于input vector是空的，第一个元素赋值操作就会导致溢出错误。
	// 使用back_inserter()可以避免assignment运算符，改以push_back()函数来插入所有元素。

	// 以函数对象的形式定义筛选规则
	class even_elem {
	public:
		bool operator()(int elem)
		{
			return elem % 2 ? false : true;
		}
	};

	vector<int>::iterator division =
		stable_partition(input.begin(), input.end(), even_elem());

	ofstream even_file("even_file"),
		odd_file("odd_file");
	
	ostream_iterator<int> even_iter(even_file, "\n"),
		odd_iter(odd_file, " ");

	if (!even_file || !odd_file)
	{
		cerr << "arghh!! unable to open the output files. bailing out!";
		return -1;
	}

	copy(input.begin(), division, even_iter);
	copy(division, input.end(), odd_iter);

	return 0;
}
