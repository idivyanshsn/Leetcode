class Solution {
public:
    int climbStairs(int n) {
        int prev=1;
        int prev2=0;
        int curr=0;
        for(int i=0;i<n;i++){
            curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};