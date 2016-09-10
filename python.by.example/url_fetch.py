# Import specific function from module
# Module code is executed only once on first import
# Module name is nothing but the filename without the .py
from urllib.request import urlopen

# Declare a function
def fetch(url):
    # Use the with syntax to ensure resources are released automatically 
    with urlopen(url) as story:
        for line in story:
            print(line.decode('utf-8'), end="")

# Special attributes are delimited by double underscore
# __name__ equates to __main__ if it is executed outside REPL
# Inside REPL, it equates to the module name
print("__name__ is " + __name__)
if __name__ == "__main__":
    fetch("http://teleported.in")
