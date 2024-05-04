#include <iostream>

void printToNReverse(int n)
{
    if (n < 1)
    {
        return;
    }

    std::cout << n << " ";
    printToNReverse(n - 1);
}

void printToN(int n)
{
    if (n < 1)
    {
        return;
    }

    printToN(n - 1);
    std::cout << n << " ";
}

int main(int argc, char const *argv[])
{
    // printToNReverse(10);
    printToN(10);

    return 0;
}