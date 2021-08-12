#!/usr/bin/python3
"""
0. Minimum Operations
"""


def prime_factor(n):
    """ prime factorization """
    i = 2
    f = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            f.append(i)
    if n > 1:
        f.append(n)
    return f


def minOperations(n):
    """ method that calculates the fewest number of operations needed """
    if n == 0 or n == 1:
        return 0
    else:
        new_list = prime_factor(n)
        return sum(new_list)
