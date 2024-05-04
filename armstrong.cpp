#include<iostream>
#include<cmath>
using namespace std;

int count_num(int num)
{
    int count = 0;

    while (num > 0)
    {
        num /= 10;
        count++;
    }

    return count; 
}

int armstrong(int num, int count)
{
    int digit = 0, sum = 0;

    while(num > 0)
    {
        digit = num % 10;

        sum += pow(digit, count);

        num /= 10;
    }

    return sum;
}

int main(int argc, char const *argv[])
{
    int num = 0, count = 0, sum = 0;

    cout << "Enter any number: ";
    cin >> num;

    count = count_num(num);

    sum = armstrong(num, count);

    if (sum == num)
    {
        cout << "The given number is armstrong number";
    }
    else
    {
        cout << "The given number is not armstrong number";
    }

    return 0;
}
