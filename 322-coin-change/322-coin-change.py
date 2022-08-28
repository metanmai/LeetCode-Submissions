class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        minCoins = [amount + 1] * (amount + 1)
        minCoins[0] = 0
        
        for i in range(1, amount + 1):
            for j in coins:
                if i - j >= 0:
                    minCoins[i] = min(minCoins[i], 1 + minCoins[i - j])
        
        return minCoins[-1] if minCoins[-1] != amount + 1 else -1