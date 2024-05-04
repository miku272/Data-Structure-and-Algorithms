#include <iostream>
#include <cmath>
using namespace std;

int bin_to_dec(int binary)
{
    int dec = 0, digit = 0, power = 0;
    bool bin_check = true;

    while (binary > 0)
    {
        digit = binary % 10;

        if (digit != 0 && digit != 1)
        {
            bin_check = false;
            break;
        }

        dec += digit * pow(2, power);
        binary /= 10;
        power++;
    }

    if (bin_check == true)
    {
        return dec;
    }
    else
    {
        return -1;
    }
}

int main(int argc, char const *argv[])
{
    int binary = 0, dec = 0;

    cout << "Enter a binary number: ";
    cin >> binary;

    dec = bin_to_dec(binary);

    if (dec == -1)
    {
        cout << "Something went wrong. Please try again";
    }
    else
    {
        cout << "The binary representation of " << binary << " is: " << dec;
    }

    return 0;
}
