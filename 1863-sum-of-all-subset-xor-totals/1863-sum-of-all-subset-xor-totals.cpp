class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<(1<<n);i++){
            int xorr=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j))
                    xorr^=nums[j];
            }
            ans+=xorr;
        }
        return ans;
    }
};