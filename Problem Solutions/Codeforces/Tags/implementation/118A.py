# Take string input 
s = input()

# lowercase vowels to be deleted
# vowels = ['a', 'o', 'y', 'e', 'u', 'i']

# Append upper case in the same list using list comprehension technique 
# vowels[6:] = [v.upper() for v in vowels]

# make a transition table for the translate function
trans_table = str.maketrans('', '', 'aeiouyAEIOUY')

# delete all the vowels from string s
s = s.translate(trans_table)

# convert string to lower case 
s = s.lower()

# inset "." in between every character of s using join method 
s = ".".join(s)

# insert "." in the beginning of the string 
s = "." + s

print(s)