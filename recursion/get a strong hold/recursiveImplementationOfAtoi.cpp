#include "bits/stdc++.h"

using namespace std;

// int myAtoi(string s)
// {
//     int i = 0;
//     int sign = 1;
//     long ans = 0;
//     while (i < s.length() && s[i] == ' ')
//         i++;
//     if (s[i] == '-')
//     {
//         sign = -1;
//         i++;
//     }
//     else if (s[i] == '+')
//         i++;
//     while (i < s.length())
//     {
//         if (s[i] >= '0' && s[i] <= '9')
//         {
//             ans = ans * 10 + (s[i] - '0');
//             if (ans > INT_MAX && sign == -1)
//                 return INT_MIN;
//             else if (ans > INT_MAX && sign == 1)
//                 return INT_MAX;
//             i++;
//         }
//         else
//             return ans * sign;
//     }
//     return (ans * sign);
// }

// time complexity O(N) and space complexity O(N)

int helper(const string &s, int index, int sign, long long num){
    if(index >= s.size() || !isdigit(s[index])){
        return sign * num;
    }
    num = num*10 + (s[index]-'0');

    if(sign == -1 && num > INT_MAX) return INT_MIN;
    if(sign == 1 && num > INT_MAX) return INT_MAX;

    return helper(s,index+1,sign,num);
}

int myAtoi(string s)
{
    int i=0;
    while(i<s.size() && s[i]==' '){
        i++;
    }
    int sign = 1;
    while(i<s.size() && (s[i]=='+'||s[i]=='-')){
        sign = (s[i]=='-')?-1:1;
        i++;
        break;
    }
    return helper(s,i,sign,0);
}

int main()
{
    string s;
    getline(cin, s);
    int result = myAtoi(s);
    cout << result;
    return 0;
}