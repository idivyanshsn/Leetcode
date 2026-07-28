class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum_price = prices[0];
        int max_profit = 0;
        for (int i = 1;i<prices.size();i++) {
            int profit = prices[i] - minimum_price;
            max_profit = max(max_profit, profit);
            minimum_price = min(prices[i], minimum_price);
        }
        return max_profit;
    }
};