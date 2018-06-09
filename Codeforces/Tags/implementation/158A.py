# My first submission in Python on Codeforces

# take two integers as input separated by space 
n, k = map(int, input().split())

# stores the result to be printed 
count = 0

# list to store the n numbers 
nums = []

# take n numbers as input in the nums list 
nums[:] = map(int, input().split())

# score of the k-th place holder 
score = nums[k - 1]

# since numbers are sorted in non-increasing order 
# if it is 0 or less than the score, then break
# otherwise increment the count

for i in range(n):
    if(nums[i] == 0 or nums[i] < score):
        break
    count += 1  # count ++ doesn't work in Python
    
# print the result 
print(count)    