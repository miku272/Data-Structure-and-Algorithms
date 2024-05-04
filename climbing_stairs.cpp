/*
Given a number of stairs. Starting from the 0th stair we need to climb to the “Nth” stair. At a time we can climb either one or two steps. We need to return the total number of distinct ways to reach from 0th to Nth stair.

Time Complexity: O(N)
Space Complexity: O(1) (After Space Optimization)
*/

#include <iostream>

int main(int argc, char const *argv[])
{
    int n = 3;

    int prev2 = 1;
    int prev = 1;

    for (int i = 2; i <= n; i++)
    {
        int cur_1 = prev + prev2;

        prev2 = prev;

        prev = cur_1;
    }

    std::cout << prev << "\n";

    return 0;
}
