# take the string as input 
s = input()

# if we find a substring '1111111' or '0000000' in s, then print 'YES' otherwise 'NO'
# in otherwise if we don't find any of these, print 'NO' otherwise 'YES'
seven1 = '1111111'
seven0 = '0000000'
if(s.find(seven1) == -1 and s.find(seven0) == -1):
    print("NO")
else:
    print("YES")