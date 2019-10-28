"""
Given a string S that only contains "I" (increase) or "D" (decrease), let N = S.length.
Return any permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:

    If S[i] == "I", then A[i] < A[i+1]
    If S[i] == "D", then A[i] > A[i+1]

Example 1:
Input: "IDID"
Output: [0,4,1,3,2]

Example 2:
Input: "III"
Output: [0,1,2,3]

Example 3:
Input: "DDI"
Output: [3,2,0,1]
"""


class Solution:
    def diStringMatch(self, S: str) -> List[int]:
        L = []
        count = 0
        N = len(list(S))
        for x in list(S):
            if x == 'I':
                L.append(count)
                count += 1
            if x == 'D':
                L.append(N)
                N -=1     
        L.append(N)
        return L
                