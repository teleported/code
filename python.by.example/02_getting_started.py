# Importing module
import math

# Import a specific function from a given namespace
from math import factorial

# You can also alias a function name while importing
from math import log as l

# Access functions inside module using dot operator
s = math.sqrt(81)
print("Square root of 81 is " + str(s))

# But if you have qualified the function, you can use the function directly
n = 5
k = 3
num = factorial(n)/(factorial(k) * factorial (n-k))
print ("Number of ways {0} items can be selected from {1} items is ".format(k, n) + str(int(num)))

print("Log of 100 base 10 is " + str(int(l(100, 10))))

# Decimal division
print("Decimal division: 10/9 is " + str(10/9))

# Integer division
print("Integer division: 10/9 is " + str(10//9))

# For loop. The colon suggests body to follow.
# Whitespaces signify body. Python uses indentation levels to demarcte code blocks.
# Convention: 4 spaces. (tabs or other # of spaces can be used, 
# but do not mix and match.
for i in range(3):
    x = i * 10
    print("Loop: {0} * 10 is ".format(i) + str(x));


