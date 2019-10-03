#MergeSort is a time-efficient divide & conquer sorting algorithm following a pretty simple idea.
# - it divides the input in 2 halves - let them be L and R.
# - it recurses for the halves
# - it merges the sorted halves.
#
# This works, because when looking at the recursion stack, we can see that it reaches a point where it will merge 2 lists containing 1 element or at most 2 elements each.
# So, when returning from recursion, the sub-arrays will each be sorted.
# The compare function can be modified in order for the algorithm to support other criteria.

def compare(a, b):
    return a < b

def merge_sort(a):
    if len(a) > 1:
        mid = len(a)//2
        L = a[:mid]
        R = a[mid:]

        merge_sort(L)
        merge_sort(R)

        l = r = k = 0

        while l < len(L) and r < len(R):
            if compare(L[l], R[r]):
                a[k] = L[l]
                l += 1
            else:
                a[k] = R[r]
                r += 1
            k += 1
        while l < len(L):
            a[k] = L[l]
            l += 1
            k += 1
        while r < len(R):
            a[k] = R[r]
            r += 1
            k += 1

print('Give the array:')
A = [int(x) for x in input().split()]

merge_sort(A)
print(A)
