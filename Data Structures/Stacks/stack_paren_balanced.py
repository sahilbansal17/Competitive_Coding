s=input()
l=[]
def is_match(a,b):
  if a=="(" and b==")":
    return True
  if a=="{" and b=="}":
    return True 
  if a=="[" and b=="]":
    return True
flag=True
for i in range(0,len(s)):
  if s[i] in "({[" and flag==True:
    l.append(s[i])
  else:
    if len(l)==0:
      flag=False
    else:
      top=l.pop()
      if not is_match(top,s[i]):
        flag=False
if len(l)==0 and flag:
  print(True)
else:
  print(False)
