#include <iostream>

void printToNReverse(int n)
{
    if (n == 1)
    {
        std::cout << n << "\n";
        return;
    }

    std::cout << n << "\n";
    printToNReverse(n - 1);
}

int main(int argc, char const *argv[])
{
    printToNReverse(10);

    return 0;
}