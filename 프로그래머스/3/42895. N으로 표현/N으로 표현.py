from itertools import product

max_size = 8

def init_table(N):
    return [0] + [set([int(str(N)*i)]) for i in range(1, max_size + 1)]

def tabulate(table, i, j):
    products = list(product(table[i], table[j]))
    for p in products:
        table[i+j].update([p[0] + p[1], p[0] - p[1], p[0] * p[1]])
        if p[0] != 0:
            table[i+j].add(int(p[1] / p[0]))
        if p[1] != 0:
            table[i+j].add(int(p[0] / p[1]))

def combine(n, table):
    for i in range(1, int(n/2) + 1):
        tabulate(table, i, n-i)

def solution(N, number):
    table = init_table(N)
    for i in range(1, max_size + 1):
        combine(i, table)
        if number in table[i]:
            return i
    print(table)
    return -1