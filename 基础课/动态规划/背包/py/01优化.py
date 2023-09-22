def knapsack(weights, values, capacity):
    n = len(weights)
    dp = [0 for _ in range(capacity + 1)]
    for i in range(n):
        for j in range(capacity, weights[i] - 1, -1):
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i])
    
    return dp[capacity]

# 生产单元测试, 使用 assert 语法
# 1. 成功用例
weights = [1, 3, 4, 5]
values = [1, 4, 5, 7]
capacity = 7

assert knapsack(weights, values, capacity) == 9