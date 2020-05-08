[n, l, j] = input().split(" ")
n = int(n)
l = int(l)
j = int(j)

def fact(x):
    if x <= 1:
        return 1
    return x*fact(x-1)

def choose(x, k):
    return fact(x)/(fact(k)*fact(x-k))

def count(x, y):
    ans = 1
    for i in range (1, y+1):
        if (n-x < i):
            break
        ans += choose(n-x, i)
    return ans

x = ""
index = 0
popcount = 0
for i in range(n):
    if (count(len(x) + 1, l-popcount) < j - index):
        index += count(len(x) + 1, l-popcount)
        popcount += 1
        x += "1"
    else:
        x += "0"

print (x)
