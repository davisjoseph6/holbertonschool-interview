#!/usr/bin/python3
"""
Determines if all boxes can be opened
"""


def canUnlockAll(boxes):
    """
    Determines if all boxes can be opened.
    """
    if not boxes:
        return False

    n = len(boxes)
    unlocked = [False] * n
    unlocked[0] = True
    keys = [0]

    while keys:
        current_key = keys.pop()
        for key in boxes[current_key]:
            if key < n and not unlocked[key]:
                unlocked[key] = True
                keys.append(key)

    return all(unlocked)
