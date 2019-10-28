"""
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements that appear twice in this array.
Could you do it without extra space and in O(n) runtime?

Example:
Input: [4,3,2,7,8,2,3,1]
Output: [2,3]
"""class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        myDict = {}
        final_L = []
        for x in nums:
            try:
                myDict[x] += 1
                if myDict[x] >= 2:
                    final_L.append(x)
            except KeyError:
                myDict[x] = 1
        return final_L
        