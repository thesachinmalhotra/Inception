class Solution {
   public:
    int maxProfit(const std::vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (const int price : prices) {
            minPrice = std::min(minPrice, price);

            const int profit = price - minPrice;
            maxProfit = std::max(maxProfit, profit);
        }
        return maxProfit;
    }
};
