#include "bits/stdc++.h"

using namespace std;

void bitManipulation(int num, int i)
{
    vector<int> bits;
    int temp = num, valI = 0, setI = 0, clearI = 0;
    while (temp != 0)
    {
        bits.push_back(temp % 2);
        temp = temp / 2;
    }
    while (bits.size() != 32)
    {
        bits.push_back(0);
    }
    valI = bits[i - 1];
    if (bits[i - 1] == 1)
    {
        setI = num;
        clearI = num - (int)pow(2, i - 1);
    }
    else
    {
        setI = (int)pow(2, i - 1) + num;
        clearI = num;
    }
    cout << valI << " " << setI << " " << clearI;
}

int main()
{
    int num, i;
    cin >> num >> i;
    bitManipulation(num, i);
    return 0;
}