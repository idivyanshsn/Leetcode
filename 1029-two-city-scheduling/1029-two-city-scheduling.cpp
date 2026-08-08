class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b){
        int diffA=a[0]-a[1];
        int diffB=b[0]-b[1];
        return diffA<diffB;
;    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        sort(costs.begin(), costs.end(),compare);
        int sum=0;
        for(int i=0;i<n/2;i++){
            sum+=costs[i][0];
        }
        for(int i=n/2;i<n;i++){
            sum+=costs[i][1];
        }
        return sum;
    }
};