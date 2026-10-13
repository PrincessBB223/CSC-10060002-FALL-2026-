//
// Created by Princess B on 9/10/26.
//

#include <iostream>
#include <string>

using namespace std;
int main()
{
    string password;

    cout << "Enter your password: ";
    cin >> password;

    while (password != "PButterFly05")
    {
        cout << "Incorrect password. Try again: ";
        cin >> password;
    }

    cout << "Access granted!";

    return 0;
}
