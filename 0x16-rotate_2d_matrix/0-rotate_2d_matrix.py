#!/usr/bin/python3
""" Given an n x n 2D matrix, rotate it 90 degrees clockwise """


def rotate_2d_matrix(matrix):
    n = len(matrix)
    for layer in range(n // 2):
        first, last = layer, n - 1 - layer
        for i in range(first, last):
            off = i - first
            top = matrix[first][i]
            matrix[first][i] = matrix[last - off][first]
            matrix[last - off][first] = matrix[last][last - off]
            matrix[last][last - off] = matrix[i][last]
            matrix[i][last] = top
