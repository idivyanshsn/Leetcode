class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0, product=1;
        for(int x=n; x>0; x/=10){
            const int r=x%10;
            sum+=r;
            product*=r;
        }
        return n%(sum+product)==0;
    }
};