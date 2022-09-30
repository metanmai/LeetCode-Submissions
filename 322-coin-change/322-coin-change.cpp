class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> minCoins(amount + 1, amount + 1);
        minCoins[0] = 0;
        
        for(int i = 1; i < amount + 1; i++)
            for(auto coin : coins)
                if(i - coin >= 0)
                    minCoins[i] = min(minCoins[i], 1 + minCoins[i - coin]);
        
        return minCoins[amount] == amount + 1 ? -1 : minCoins[amount];
    }
};