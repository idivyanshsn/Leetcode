class Solution {
    private:
    int product(int n){
        long long ans=1;
        while(n>0){
            int last=n%10;
            ans*=last;
            n/=10;
        }
        return ans;
    }
public:
    int smallestNumber(int n, int t) {
        for(int i=n; ;i++){
            if(product(i)%t==0)
                return i;
        }
        return -1;
    }
};