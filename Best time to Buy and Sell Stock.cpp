class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0; // Edge case: no prices
        
        int minPrice = prices[0]; // Initialize minPrice to the first price
        int maxProfit = 0; // Initialize maxProfit to 0
        
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i]; // Update minPrice if current price is lower
            } else {
                int currentProfit = prices[i] - minPrice; // Calculate profit
                if (currentProfit > maxProfit) {
                    maxProfit = currentProfit; // Update maxProfit if currentProfit is greater
                }
            }
        }
        
        return maxProfit;
    }
};
