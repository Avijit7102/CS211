#include <iostream>
#include <string>
using namespace std;

string addBigInteger(string a, string b)
{
    string result = "";
    int lenA = a.length();
    int lenB = b.length();

    if(lenA > lenB)
    {
        for(int i = 0; i < lenA - lenB; i++)
        {
            b = '0' + b;
        }
    }
    else
    {
        for(int i = 0; i < lenB - lenA; i++)
        {
            a = '0' + a;
        }
    }

    int carry = 0, digit;
    char c;
    for(int i = lenA-1; i >= 0; i--)
    {
        int sum = (a[i] - 48) + (b[i] - 48) + carry;
        if(sum > 9)
        {
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        digit = sum % 10 + '0';
        result = char(digit) + result;
    }

    if(carry == 1)
    {
        result = '1' + result;
    }

    return result;
}
int main()
{
    string a, b;

    cout << "Enter a number : ";
    cin >> a;
    cout << endl;
    cout << "Enter second number : ";
    cin >> b;
    cout << endl;
    string result = addBigInteger(a,b);
    cout << "Adding result is : " << result << endl;
}
