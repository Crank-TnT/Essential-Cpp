/*
	编写一个程序，能够询问用户的姓名，并读取用户所输入的内容。
	请确保用户输入的名称长度大于两个字符。如果用户的确输入了有效名称，就响应一些信息。
	请以两种方式实现：第一种使用C-style字符串，第二种使用string对象。
*/

#include <iostream>
#include <string>
using namespace std;


int main(int argc, char const* argv[])
{
	string user_name;

	cout << "Please enter your name: ";
	cin >> user_name;

	switch ( user_name.size() ) {
		case 0:
			cout << "Ah, the user with no name. " 
				<< "Well, ok, hi, user with no name\n";
			break;

		case 1:
			cout << "A 1-character name? Hmm, have you read Kafka?: "
				<< "hello, " << user_name << endl;
			break;

		default:
			cout << "Hello, " << user_name
				<< " -- happy to make your acquaintance!\n";
			break;
	}

	return 0;
}

/*
// 如果使用C_style字符串，写法就完全不同。
// Lippman特别建议初学者舍弃C-style字符串，改用string class。
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;


int main(int argc, char const* argv[])
{
	// 必须分配一个大小固定的空间
	const int nm_size = 128;
	char user_name[nm_size];

	cout << "Please enter your name: ";
	cin >> setw(nm_size) >> user_name;

	switch (strlen(user_name)) {
		case 0:
			cout << "Ah, the user with no name. " 
				<< "Well, ok, hi, user with no name\n";
			break;

		case 1:
			cout << "A 1-character name? Hmm, have you read Kafka?: "
				<< "hello, " << user_name << endl;
			break;

		case 127:
			// 也许所得的字符串已被setw()舍弃掉部分内容
			cout << "That is a very big name, indeed -- "
				<< "we may have needed to shorten it!\n"
				<< "In any case,\n";
			// 此处不加break， 向下继续执行

		default:
			cout << "Hello, " << user_name
				<< " -- happy to make your acquaintance!\n";
			break;
	}

	return 0;
}

*/