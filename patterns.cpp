#include <iostream>

using namespace std;

// Inverted Pattern
// int main(int argc, char const *argv[])
// {
//     int no_of_rows = 0;

//     cout << "Enter number of rows: ";
//     cin >> no_of_rows;

//     for (int i = no_of_rows; i >= 1; i--)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             cout << j << ' ';
//         }
//         cout << '\n';
//     }
    
//     return 0;
// }

// Inverted 0 and 1 pattern
// int main(int argc, char const *argv[])
// {
//     int no_of_rows = 0;

//     cout << "Enter number of rows: ";
//     cin >> no_of_rows;

//     for (int i = 1; i <= no_of_rows; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {

//             if ((i + j) % 2 == 0)
//             {
//                 cout << 1 << ' ';
//             }
//             else
//             {
//                 cout << 0 << ' ';
//             }
//         }
//         cout << '\n';
//     }
    
//     return 0;
// }


// Right aligned pattern
// int main(int argc, char const *argv[])
// {
//     int no_of_rows;

//     cout << "Enter number of rows: ";
//     cin >> no_of_rows;

//     for (int i = 1; i <= no_of_rows; i++)
//     {
//         for (int j = 1; j <= no_of_rows - i; j++)
//         {
//             cout << "  ";
//         }
//         for (int j = 1; j <= no_of_rows; j++)
//         {
//             cout << "* ";
//         }
        
        
//         cout << '\n';
//     }
    
//     return 0;
// }

// Number's pyramid
// int main(int argc, char const *argv[])
// {
//     int no_of_rows = 0;

//     cout << "Enter number of rows: ";
//     cin >> no_of_rows;

//     for (int i = 1; i <= no_of_rows; i++)
//     {
//         for (int j = 1; j <= no_of_rows - i; j++)
//         {
//             cout << ' ';
//         }

//         for(int j = 1; j <= i; j++)
//         {
//             cout << j << ' ';
//         }
//         cout <<'\n';
//     }
    
//     return 0;
// }

// Palindromic Pattern
// int main(int argc, char const *argv[])
// {
//     int no_of_rows = 0;

//     cout << "Enter number of rows: ";
//     cin >> no_of_rows;

//     for(int i = 1; i <= no_of_rows; i++)
//     {
//         int j;
//         for(j = 1; j <= no_of_rows - i; j++)
//         {
//             cout << ' ';
//         }

//         int k = i;
//         for(; j <= no_of_rows; j++)
//         {
//             cout << k-- << ' ';
//         }

//         k = 2;
//         for(; j <= no_of_rows + i - 1; j++)
//         {
//             cout << k++ << ' ';
//         }

//         cout << '\n';
//     }
//     return 0;
// }

// 