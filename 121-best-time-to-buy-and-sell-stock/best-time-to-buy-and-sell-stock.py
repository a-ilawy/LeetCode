class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        buyPrice = prices[0]
        maxProfit = 0

        for price in prices:
            if price < buyPrice:
                buyPrice = price 
            else:
                maxProfit = max(maxProfit, price - buyPrice)

        return maxProfit

        # n = len(prices)
        # if n == 0:
        #     return 0

        # dp = [0] * n  # dp[i] = max profit if we sell on day i
        # min_price = prices[0]

        # for i in range(1, n):
        #     min_price = min(min_price, prices[i])
        #     dp[i] = max(dp[i - 1], prices[i] - min_price)

        # return dp[-1]