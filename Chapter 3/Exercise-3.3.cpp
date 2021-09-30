/*
	定义一个map，以家庭姓氏为key，value则是家庭所有小孩的名字。令此map至少容纳六笔数据。
	允许用户根据姓氏来查询，并得以打印map内的每一笔数据。
*/

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

typedef vector<string> vstring;
map<string, vstring> families;

// 按行读取文件，并处理字符串内容
void populate_map(ifstream& nameFile, map<string, vstring>& families)
{
	string textline;
	while (getline(nameFile, textline))
	{	// getline()是标准库提供的函数，从文件中读取一行内容，
		// 第三个参数用来指定行末字符，如 getline( nameFile, textline, '\n')。
		string fam_name;
		vector<string> child;
		string::size_type
			pos = 0, prev_pos = 0,
			text_size = textline.size();

		while ((pos = textline.find_first_of(' ', pos))
			!= string::npos)
		{
			// string::size_type 整数型，相当于int，用来描述对象的长度
			string::size_type end_pos = pos - prev_pos;

			if (!prev_pos)
				fam_name = textline.substr(prev_pos, end_pos);
			else
				child.push_back(textline.substr(prev_pos, end_pos));
			prev_pos = ++pos;
		}

		if (prev_pos < text_size)
			child.push_back(textline.substr(prev_pos, pos - prev_pos));

		if (!families.count(fam_name))
			families[fam_name] = child;
		else
			cerr << "Oops! We already have a "
			<< fam_name << " family in our map!\n";
	}
}

void display_map(const map<string, vstring>& families, ostream& os)
{
	map<string, vstring>::const_iterator
		it = families.begin(),
		end_it = families.end();

	while (it != end_it)
	{
		os << "The " << it->first << " family ";
		if (it->second.empty())
			os << "has no children\n";
		else
		{
			os << "has " << it->second.size() << " children: ";
			vector<string>::const_iterator
				iter = it->second.begin(),
				end_iter = it->second.end();

			while (iter != end_iter)
			{
				os << *iter << " ";
				++iter;
			}
			os << endl;
		}
		++it;
	}
}

void query_map(const string& family, const map<string, vstring>& families)
{
	map<string, vstring>::const_iterator
		it = families.find(family);

	if (it == families.end())
	{
		cout << "Sorry. The " << family
			<< " is not currently entered.\n";
		return;
	}

	cout << "The " << family;
	if (!it->second.size())
		cout << " has no children\n";
	else
	{
		cout << " has " << it->second.size() << " children: ";
		vector<string>::const_iterator
			iter = it->second.begin(),
			end_iter = it->second.end();

		while (iter != end_iter)
		{
			cout << *iter << " ";
			++iter;
		}
		cout << endl;
	}
}

int main(int argc, char const* argv[])
{
	map<string, vstring> families;
	ifstream nameFile("families.txt");

	if (!nameFile)
	{
		cerr << "Unable to find families.txt file. Bailing Out!\n";
		return -1;
	}

	populate_map(nameFile, families);
	string family_name;
	while (1) {
		cout << "Please enter a family name or q to quit ";
		cin >> family_name;

		if (family_name == "q")
			break;
		query_map(family_name, families);
	}
	display_map(families, cout);

	return 0;
}
