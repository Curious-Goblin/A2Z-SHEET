#include "iostream"
#include "string"

using namespace std;

string largestOddNumber(string num)
{
    int number = 0;
    for (int i = 0; i < num.size(); i++)
    {
        if ((num[i] - '0') % 2 != 0)
        {
            if (number < (num[i] - '0'))
            {
                number = num[i] - '0';
            }
        }
    }
    if (number == 0)
    {
        return "";
    }
    return to_string(number);
}

int main()
{
    string s;
    cin >> s;
    string result = largestOddNumber(s);
    cout<<result;
    return 0;
}