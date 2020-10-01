# Equilibrium point refers to the index at which 
# sum of elements on its left is equal to the 
# sum of elements on its right.

def equilibriumPoint(a, n):
    t = sum(a)
    prefix = [0]
    
    # prefix sum array
    for e in a:
        prefix.append(prefix[-1] + e)

    j = 1
    while j <= n:
        if prefix[j - 1] == t - prefix[j]:
            return j
        j += 1
    return -1
