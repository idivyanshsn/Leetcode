class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = *max_element(nums.begin(), nums.end());
        vector<long long> cnt(max_val + 1, 0);
        for (int x : nums) {
            cnt[x]++;
        }
        vector<long long> exact(max_val + 1, 0);
        for (int g = max_val; g >= 1; --g) {
            long long total_multiples = 0;
            for (int multiple = g; multiple <= max_val; multiple += g) {
                total_multiples += cnt[multiple];
            }
            long long pairs_with_divisor =
                total_multiples * (total_multiples - 1) / 2;
            for (int multiple = 2 * g; multiple <= max_val; multiple += g) {
                pairs_with_divisor -= exact[multiple];
            }
            exact[g] = pairs_with_divisor;
        }
        vector<long long> prefix_sums(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            prefix_sums[i] = prefix_sums[i - 1] + exact[i];
        }
        vector<int> answer;
        answer.reserve(queries.size());
        for (long long q : queries) {
            auto it = upper_bound(prefix_sums.begin(), prefix_sums.end(), q);
            int gcd_val = distance(prefix_sums.begin(), it);
            answer.push_back(gcd_val);
        }
        return answer;
    }
};