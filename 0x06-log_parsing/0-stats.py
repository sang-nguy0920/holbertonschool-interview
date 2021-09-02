#!/usr/bin/python3
"""Reads stdin line by line and computes metrics"""
import sys


def print_results(codes, fileS):
    print("File size: {:d}".format(fileS))
    for statusCode, times in sorted(codes.items()):
        if times:
            print("{:s}: {:d}".format(statusCode, times))

codes = {"200": 0,
         "301": 0,
         "400": 0,
         "401": 0,
         "403": 0,
         "404": 0,
         "405": 0,
         "500": 0
         }
fileS = 0
num = 0

try:
    for line in sys.stdin:
        if num != 0 and num % 10 == 0:
            print_results(codes, fileS)
        num += 1
        tmp = line.split()
        try:
            statusCode = tmp[-2]
            if statusCode in codes:
                codes[statusCode] += 1
            fileS += int(tmp[-1])
        except:
            pass
    print_results(codes, fileS)
except KeyboardInterrupt:
    print_results(codes, fileS)
    raise
