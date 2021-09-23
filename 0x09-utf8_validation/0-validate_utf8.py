#!/usr/bin/python3
""" Method that determines if a given data set is  a valid UTF-8 encoding """


def validUTF8(data):
    """ validUTF8 method """
    data = iter(data)
    for leader in data:
        ones = counter(leader)
        if ones in [1, 7, 8]:
            return False
        for _ in range(ones - 1):
            trails = next(data, None)
            if trails is None or trails >> 6 != 0b10:
                return False
    return True


def counter(byte):
    """counter"""
    for x in range(8):
        if byte >> (7 - x) == 0b11111111 >> (7 - x) & ~1:
            return x
    return 8
