#include <iostream>
#include <string>
using namespace std;


void temp()
{
    string first_name, last_name;

    cout << "Please enter your first name: ";
    cin >> first_name;

    cout << "Hi, " << first_name
        << " Please enter your last name: ";
    cin >> last_name;

    cout << "\n" << "Hello, "
        << first_name << " " << last_name
        << " ... and goodbye!\n";

}

int main()
{
    temp();

    return 0;
}

