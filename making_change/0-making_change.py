#!/usr/bin/python3
"""
Module for calculating the fewest number of coins needed to meet a given total
"""


def makeChange(coins, total):
    """
    Determine the fewest number of coins needed to meet a given total
    """
    if total <= 0:
        return 0

    # Sort coins in the descending order for greedy approach
    coins.sort(reverse=True)

    count = 0
    for coin in coins:
        if total <= 0:
            break
        count += total // coin
        total %= coin

    return count if total == 0 else -1
