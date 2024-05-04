#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int num = 0, reverse = 0;

    cout << "Enter a number: ";
    cin >> num;

    while (num > 0)
    {
        reverse = (reverse * 10) + (num % 10);

        num /= 10;
    }

    cout << "\nThe reversed number is: " << reverse;

    return 0;
}
