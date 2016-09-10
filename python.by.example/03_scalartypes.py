# int: signed, unlimited signed precision integer
#      specified in decimal by default
print("Decimal 10: " + str(10))
print("Binary 10: "  + str(0b10))
print("Octal 10: "   + str(0o10))
print("Hex 10: "     + str(0x10))

# Conversation from float (rounded off to nearest int towards 0)
print("3.5 in int is " + str(int(3.5)))
print("3.6 in int is " + str(int(3.6)))
print("-3.6 in int is " + str(int(-3.6)))

# int constructor can take in string with numbers
print("String ""456"" to int: " + str(int("456")))

# float can be specified in dot or scientific notation
print("A floating point number: " + str(float(4.97)));
print("A floating point number in scieitific notation: " + str(float(1.2e-8)))

print("Int 7 to float: " + str(float(7)))
print("String ""78.9"" to float: " + str(float("78.9")))

print("Not a number float: " + str(float("nan")))
print("Positive infinity: " + str(float("inf")))
print("Negative infinity: " + str(float("-inf")))

# None type
# None represents absense of a value
# N is capital in None keyword
a = None
if a is None:
    print("a does not have any value")

# Bool type represents logical state of True or False
# B, T and F are capital 
# Bool constructure can take in various data types and maps their state to True or False
print("Bool of 0 is " + str(bool(0)))
print("Bool of 1 is " + str(bool(1)))
print("Bool of -1 is " + str(bool(-1)))
print("Bool of 0.0 is " + str(bool(0.0)))
print("Bool of 0.001 is " + str(bool(0.001)))
print("Bool of -0.001 is " + str(bool(-0.001)))

# For collections, only empty collections are treated as False
print("Bool of \"\" is " + str(bool("")) ) 
print("Bool of \"a\" is " + str(bool("a")) ) 
print("Bool of [] is " + str(bool([])) ) 
print("Bool of [1, 2, 3] is " + str(bool([1, 2, 3])) ) 

