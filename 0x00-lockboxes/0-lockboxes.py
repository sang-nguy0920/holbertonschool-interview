#!/usr/bin/python3
"""
You have n number of locked boxes in front of you:
Each box is numbered sequentially from 0 to n - 1 and each box
may contain keys to the other boxes.
"""


def canUnlockAll(boxes):
    """ Check if boxes can be open, starting at 0 """
    keysDict = {
        0: True
    }
    loopIterations = 0
    for i in range(1, len(boxes)):
        keysDict[i] = False
    try:
        while False in keysDict.values() and loopIterations < len(boxes):
            for i in list(keysDict):
                if keysDict[i] is True:
                    for k in boxes[i]:
                        keysDict[k] = True
                    loopIterations += 1
    except IndexError:
        return False
    if False in keysDict.values():
        return False
    return True
