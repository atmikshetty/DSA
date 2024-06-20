class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // Traverse from behind
        vector<int> ans;

        if(amount == 0) return 0;
        if(amount<0) return -1;

        for(int i=n-1;i>=0;i--){
            if(amount >=coins[i]){
                amount = amount - coins[i];
                ans.push_back(coins[i]);
            }
        }
        return ans.size();
    }
};

// Partially correct, not executed