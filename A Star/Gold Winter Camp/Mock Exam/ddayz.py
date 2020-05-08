n = input().split(" ")
n[0] = int(n[0])
n[1] = int(n[1])
dp = [[]]
for i in range(n[0]+1):
    temp = []
    for j in range(n[1]):
        temp.append(0)
    #print(temp)
    dp.append(temp)
#print (dp)
dp.pop(0)
dp[0][0] = 1
for i in range(1, n[0]+1):
    for j in range(n[1]):
        for l in range(j+1):
            if i - j - 1 >= 0:
                dp[i][j] += dp[i - j - 1][l];
ans = 0
for i in range(n[1]):
    ans += dp[n[0]][i]
print(ans)
