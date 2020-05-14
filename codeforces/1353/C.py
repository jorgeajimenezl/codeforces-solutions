from sys import stdin, stdout

t = int(stdin.readline())
while t > 0:
    n = int(stdin.readline())
    sum = 0
    for i in range(n, 1, -2):
        sum += 4 * (i - 1) * (i // 2)
    stdout.write(str(sum) + '\n')
    t-= 1