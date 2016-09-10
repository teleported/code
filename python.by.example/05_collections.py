# str - immutable sequence of Unicode codepoints
# str can be specified by delimiting with single quotes or double quotes

print("Python is beautiful")
print('Yes, I agree')
print("Don't you?")
print('"Yes!"')

s = """This is a 
multiline 
string 
with newlines intact"""
print (s)

# Raw strings do not support any escape sequences
# and pretty much what you see is what you get
m = r'C:\Program Files\Microsoft'
print(m)

# Strings are sequence types
# There are no 'characters' in Python. Everything is string.
n = "Anand Saha"
print("n is " + n)
print("type of n is " + str(type(n)))
print("n[0] is " + n[0])
print("type of n[0] is " + str(type(n[0])))

o = "this"
print("Capitalization of {0} is {1}".format(o, o.capitalize()))


# Bytes - immutable sequence of bytes
# byte literals are prefixed with b
print(b'Python')
print(b"Python")

p = b"This is\t a string";
print(p.split())

# str to b: encoding
# b to str: decoding


# lists - mutable sequence of heterogeneous objects
l = ['a', 1, 'Apple']
l[1] = 2
print(l)

# empty list
l1 = [] 
l1.append(42)
l1.append('Python')
print(l1)

# list constructor can take other collections and convert them to list
print(list('Alphabet'))


# dict - mutable mappings of keys to values
d = {1: "One",
     2: "Two",
     3: "Three"}
print(d)

#keys can be heterogenous
d1 = {1: "One", 
      "Two": 2 }

print(d1)

# Retrieving values using keys:
print(d[1])
print(d1["Two"])

# Empty dictionary
print({})

