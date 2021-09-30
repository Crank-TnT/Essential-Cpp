/*
	读取文本文件内容，并将内容储存于vector。以字符串长度为依据，对vector排序。定义一个
	function object并传给sort();这一function object接受两个字符串，当第一字符串的
	长度小于第二字符串的长度时，就返回true。最后，打印排序后的vector内容。
*/

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

class LessThan {
public:
	bool operator()(const string& s1, const string& s2)
	{
		return s1.size() < s2.size();
	}
};

template <typename elemType>
void display_vector(const vector<elemType>& vec,
	ostream& os = cout, int len = 8);

int main(int argc, char const* argv[])
{
	ifstream ifile("column.txt");
	ofstream ofile("MooCat.map");
	if (!ifile || !ofile)
	{
		cerr << "Unable to open file -- bailing out!\n";
		return -1;
	}

	vector<string> text;
	string word;
	
	while (ifile >> word)
		text.push_back(word);

	sort(text.begin(), text.end(), LessThan());
	display_vector(text, ofile);

	return 0;
}

template <typename elemType>
void display_vector(const vector<elemType>& vec,
	ostream& os, int len)
{
	typename vector<elemType>::const_iterator iter = vec.begin(), end_it = vec.end();
	// 这里typename一定要写上因为时代变了！！！

	int elem_cnt = 1;
	while (iter != end_it)
		os << *iter++
		<< (!(elem_cnt++ % len) ? '\n' : ' ');
	os << endl;
}