"""
https://leetcode-cn.com/problems/shortest-subarray-with-sum-at-least-k/
"""

from typing import List

class Solution:
    def shortestSubarray(self, A: List[int], K: int) -> int:
        sums = [0] * (len(A)+1)
        sums[0] = 0

        for i in range(0, len(A)): sums[i+1] = sums[i] + A[i]

        queue = []
        res = len(A) + 1
        for i, p in enumerate(sums):
            while len(queue)>0 and p<=sums[queue[-1]]:
                queue = queue[:-1]

            while len(queue)>0 and p-sums[queue[0]]>=K:
                res = min(res, i-queue[0])
                queue = queue[1:]

            queue += [i]
        if res == len(A) + 1: res = -1
        return res

if __name__ == "__main__":
    s = Solution()
    A = [2,-1,2]
    K = 3
    min_len = s.shortestSubarray(A, K)
    print(min_len)


