import sys

MAX_X = 8
MAX_Y = 5
gems = [[], [], [], [], []]
selected = []

def select_same(gem, x, y):
    global gems
    global selected

    if [x, y] in selected:
        return

    selected.append([x, y])

    
    if gems[y][x] == gem:
        gems[y][x] = ' '
        if x > 0:
            select_same(gem, x - 1, y)
        if x < (len(gems[0]) - 1):
            select_same(gem, x + 1, y)
        if y > 0:
            select_same(gem, x, y - 1)
        if y < MAX_Y - 1:
            select_same(gem, x, y + 1)


def clean_board():
    global gems
    x = 0
    #
    # collect non-empty gems in each column
    # and then place them from bottom to top
    #
    while x < len(gems[0]):
        l = []
        for y in range(MAX_Y):
            if gems[y][x] != ' ':
                l.append(gems[y][x])

        if len(l) == 0: # empty column, delete it
            for l in gems:
                del l[x]
            continue
        else:
            n = 0
            while n < len(l):
                gems[n][x] = l[n]
                n += 1

            while n < MAX_Y:
                gems[n][x] = ' '
                n += 1
                
        x += 1





def select(x, y):
    global gems
    global selected
    gem = gems[y][x]
    select_same(gem, x, y)
    clean_board()
    selected = []


# debug function
def print_gems():
    global gems
    print (gems[4])
    print (gems[3])
    print (gems[2])
    print (gems[1])
    print (gems[0])


def print_count_gems():
    global gems
    
    for gem in ('R', 'G', 'B', 'Y'):
        count = 0
        for l in gems:
            count += l.count(gem)
        if gem == 'Y':
            print (count)
        else:
            print (count, end=' ')
    



for i in range(MAX_Y):
    gems[MAX_Y - i - 1] = list(sys.stdin.readline().strip())


print_gems()
(x, y) = sys.stdin.readline().split()
while int(x) != MAX_X and int(y) != MAX_Y:
    select(int(x), int(y))
    print ("after {0} {1}".format(x, y))
    print_gems()
    (x, y) = sys.stdin.readline().split()

print_count_gems()
