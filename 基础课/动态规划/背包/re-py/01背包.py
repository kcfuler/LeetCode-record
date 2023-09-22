def knapsack(weights, values, capacity):
    n = len(weights)
    # 初始化二维数组
    dp = [[0 for _ in range(capacity + 1)] for _ in range(n + 1)]

    for i in range(1, n + 1):
        for j in range(1, capacity + 1):
            if weights[i - 1] > j:
                dp[i][j] = dp[i - 1][j]
            else:
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j])
    
    return dp[n][capacity]

# 生产单元测试, 使用 assert 语法
# 1. 成功用例 
weights = [1, 3, 4, 5]
values = [1, 4, 5, 7]
capacity = 7

assert knapsack(weights, values, capacity) == 9

# 2. 失败用例
weights = [1, 3, 4, 5]
values = [1, 4, 5, 7]
capacity = 6

assert knapsack(weights, values, capacity) == 9
