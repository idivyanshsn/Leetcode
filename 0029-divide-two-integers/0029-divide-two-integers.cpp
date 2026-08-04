class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor)
            return 1;
        bool sign = true;
        if ((dividend > 0 && divisor < 0) || (divisor > 0 && dividend < 0))
            sign = false;
        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);
        long long ans = 0;
        while (n >= d) {
            int count = 0;
            while (n >= (d << (count + 1))) {
                count++;
            }
            ans += 1 << count;
            n  -= (d  << count);
        }
        if((ans==1<<31)&&sign) return INT_MAX;
        if((ans==1<<31)&&!sign) return INT_MIN;
        return sign?ans:-ans;
    }
};