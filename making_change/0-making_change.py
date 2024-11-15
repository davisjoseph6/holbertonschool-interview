#!/usr/bin/python3
"""
Module for calculating the fewest number of coins needed to meet a given total.
"""


def makeChange(coins, total):
    """
    Determine the fewest number of coins needed to meet a given total.
    """
    if total <= 0:
        return 0

    # Initialize a DP array to store the minimum coins needed for each amount
    dp = [float('inf')] * (total + 1)
    dp[0] = 0  # Base case: 0 coins are needed to make a total 0

    # Iterate through each coin and update DP table
    for coin in coins:
        for i in range(coin, total + 1):
            dp[i] = min(dp[i], dp[i - coin] + 1)

    # if dp[total] is still infinity, the total cannot be reached
    return dp[total] if dp[total] != float('inf') else -1
