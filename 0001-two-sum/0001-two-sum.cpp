class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n =nums.size();
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            int sum=nums[i];
            int rem=target-sum;
            if(mpp.find(rem)!=mpp.end()){
                return vector<int>{mpp[rem],i};
            } mpp[sum]=i;        }
        // for(int i =0;i<n;i++){
        //     for(int j =i+1;j<n;j++){
        //         // if (i==j){
        //         //     continue;
        //         // }
        //         if(nums[i]+nums[j]==target){
        //             return vector<int>{i,j};
        //         }
        //     }
        // }


        return {};
    }
};