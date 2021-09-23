/*
	编写一个程序，从标准输入设备读取一串整数，并将读入的整数依次放到array及vector，然后
	遍历两种容器，求取数值总和。将总和及平均值输出至标准输出设备。
*/

#include <iostream>
#include <vector>
using namespace std;

// vector实现方式
int main(int argc, char const* argv[])
{
	vector<int> ivec;
	int ival;
	while (cin >> ival) 
	{
		ivec.push_back(ival);
		// 终止循环
		if (cin.get() == '\n')
			break;
	}

	int sum = 0;
	for (int ix = 0; ix < ivec.size(); ++ix)
	{	// 遍历vector的元素，一一累加
		sum += ivec[ix];
	}

	double average = sum / ivec.size();

	cout << "Sum of " << ivec.size()
		<< " elements: " << sum
		<< ". Average: " << average << endl;

	return 0;
}


/*
// array实现方式
#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char const* argv[])
{
	const int array_size = 128;
	int ia[array_size];
	int ival, icnt = 0;

	while (cin >> ival && icnt < array_size)
	{
		ia[icnt++] = ival;
		if (cin.get() == '\n')
			break;
	}

	int sum = 0;
	for (int ix = 0; ix < icnt; ++ix)
		sum += ia[ix];

	double average = sum / icnt;

	cout << "Sum of " << icnt
		<< " elements: " << sum
		<< ". Average: " << average << endl;

	return 0;
}
*/
