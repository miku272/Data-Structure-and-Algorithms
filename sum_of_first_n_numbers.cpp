#include <iostream>

int recursiveSumOfN(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return n + recursiveSumOfN(n - 1);
}

int main(int argc, char const *argv[])
{
    std::cout << recursiveSumOfN(5) << "\n";

    return 0;
}
