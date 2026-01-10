import sys
input = sys.stdin.readline

n, k = map(int, input().split())
dp = [[0 for _ in range(k + 1)] for _ in range(n + 1)]
for i in range(0, n + 1):
  dp[i][1] = 1
  for j in range(1, k + 1):
    for l in range(0, i+1):
      dp[i][j] += dp[i-l][j-1]
      dp[i][j] %= 1000000000

print(dp[n][k])