f = open('pg27780.txt', 'r')
for line in f:
    line = line.strip()
    words = line.split(' ')
    for w in words:
        if(w.strip() != ''):
            print(w.strip())
