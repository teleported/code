a = 10
b = 11
if a == b:
    print("a == b")
if a != b:
    print("a != b")

if a == b:
    print("a == b")
else:
    print("a != b")

if a > 10:
    print("a > 10")
elif a < 10:
    print("a < 10")
else:
    print("a == 10")

if True:
    print("It is True")
if False:
    print("It is True")
if bool("this"):
    print("this is True")
# This is better than above
if "this":
    print("this is True")

# While loop
c = 8
while c % 7 != 0:
    c = int(input())

l = ["Apple", "Banana", "Guava", "Pear", "Pinapple", ]
d = {1: "Apple", 2: "Banana", 3: "Guava", 4: "Pear", 5: "Pinapple"}
# For loop
for item in l:
    print (item)
for item in d:
    print (d[item], item)
