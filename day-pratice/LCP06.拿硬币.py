from typing import List


class Solution:
    @staticmethod
    def minCount(coins: List[int]) -> int:
        cnt = 0
        for coin in coins:
            cnt += (coin // 2)
            if coin % 2 == 1:
                cnt += 1
        return cnt


solution = Solution()
arr = input('input the list').split(',')
print('coins', isinstance(arr, list), arr)
