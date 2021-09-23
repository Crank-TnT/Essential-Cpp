/*
	使用你最趁手的编辑工具，输入两行（或更多）文字并存盘。然后编写一个程序，打开该文本
	文件，将其中每个字都读取到一个vector<string>对象中。遍历该vector，将内容显示到cout。
	然后利用泛型算法sort()，对所有文字排序，再将排序后的结果输出到另一个文件。
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


int main(int argc, char const* argv[])
{	
	ifstream in_file("text.txt");
	if (!in_file)
	{
		cerr << "Oops! unable to open input file\n";
		return -1;
	}

	ofstream out_file("text.sort");
	if (!out_file)
	{
		cerr << "Oops! unable to open output file\n";
		return -2;
	}

	string word;
	vector<string> text;
	while (in_file >> word)
		text.push_back(word);

	cout << "unsorted text: \n";
	for (int ix = 0; ix < text.size(); ++ix)
		cout << text[ix] << ' ';
	cout << endl;

	sort(text.begin(), text.end());

	out_file << "sorted text: \n";
	for (int ix = 0; ix < text.size(); ++ix)
		out_file << text[ix] << ' ';
	out_file << endl;

	return 0;
}