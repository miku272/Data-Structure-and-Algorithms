#include <iostream>

int recursiveSumOfN(int *n)
{
    if (*n == 0)
    {
        return 0;
    }

    int prevNum = *n - 1;
    return *n + recursiveSumOfN(&prevNum);
}

int main(int argc, char const *argv[])
{
    int n = 5;

    std::cout << recursiveSumOfN(&n) << "\n";

    return 0;
}