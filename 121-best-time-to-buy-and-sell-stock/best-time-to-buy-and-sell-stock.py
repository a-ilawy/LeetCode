class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        min_price = prices[0]
        max_profit = 0

        for price in prices[1:]:
            min_price = min(min_price, price) 
            max_profit = max(max_profit, price - min_price)  

        return max_profit

        # n = len(prices)
        # if n == 0:
        #     return 0

        # dp = [0] * n  # dp[i] = max profit if we sell on day i
        # min_price = prices[0]

        # for i in range(1, n):
        #     min_price = min(min_price, prices[i])
        #     dp[i] = max(dp[i - 1], prices[i] - min_price)

        # return dp[-1]