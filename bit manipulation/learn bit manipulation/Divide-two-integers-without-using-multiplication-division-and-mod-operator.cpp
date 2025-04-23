#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // O(logN) 
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if(dividend == INT_MAX && divisor == 1){
            return INT_MAX;
        }
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }
        if(dividend == INT_MAX && divisor == -1){
            return INT_MAX*-1;
        }
        long long sign = 1;
        if (dividend < 0 ^ divisor < 0) {
            sign = -1;
        }
        
        long long dividend_abs = abs((long long)dividend);
        long long divisor_abs = abs((long long)divisor);

        long long ans = 0;
        while (dividend_abs >= divisor_abs) {
            long long count = 0;
            while (dividend_abs >= (divisor_abs << (count + 1))) {
                count++;
            }
            ans += (1 << count);
            dividend_abs -= (divisor_abs << count);
        }

        ans = sign * ans;

        if (ans < INT_MIN) return INT_MIN;
        if (ans > INT_MAX) return INT_MAX;

        return (int)ans;
    }
};

int main() {
    int a, b;
    cin >> a >> b;
    Solution s;
    int result = s.divide(a, b);
    cout << result;
    return 0;
}
