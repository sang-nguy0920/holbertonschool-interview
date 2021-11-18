#!/usr/bin/python3
"""rain"""


def rain(walls):
    """rain"""
    if type(walls) is not list:
        return 0

    if len(walls) is 0:
        return 0

    w = 0
    for i, mid in enumerate(walls):
        if i is not 0 and i is not (len(walls) - 1):
            left = max(walls[0:i])
            right = max(walls[i + 1:len(walls)])
            if mid < left and mid < right:
                w += min([left, right]) - mid
    return w
