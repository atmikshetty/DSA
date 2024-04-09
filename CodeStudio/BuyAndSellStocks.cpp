int bestTimeToBuyAndSellStock(vector<int>&prices) {
    // Write your code here.
    // O(N)
    int mini = prices[0];
    int profit = 0;
    int n= prices.size();
    for(int i=1;i<n;i++){
        int cost = prices[i] - mini;
        profit = max(profit, cost);
        mini = min(mini, prices[i]);
    }
    return profit;
}
