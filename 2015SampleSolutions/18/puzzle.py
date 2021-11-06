
# is there already combo around (i, j) of the same color
def combo_around(rows, combo_map, i, j):
  c = rows[i][j]
  x_to_check = []
  y_to_check = []

  if i >= 0:
    y_to_check.append(i-1)

  if j > 0:
    x_to_check.append(j-1)

  for x in x_to_check:
    if rows[i][x] == c and combo_map[i][x] == True:
      return True
  for y in y_to_check:
    if rows[y][j] == c and combo_map[y][j] == True:
      return True

  return False
  

def scan_combo(rows, combo_map, combos):

  for i in range(5):
    for j in range(6):
      # horizontal combo
      c = rows[i][j]

      #ignore unknown color
      if not c in combos.keys():
        continue

      is_new_combo = True
      if j < 4 and c == rows[i][j+1] and c == rows[i][j+2]:
        x = 0
        while j + x < 6 and c == rows[i][j+x]:
          if is_new_combo and combo_map[i][j+x]:
            is_new_combo = False
          if is_new_combo and combo_around(rows, combo_map, i,j):
            is_new_combo = False
          combo_map[i][j+x] = True
          x += 1

        if is_new_combo:
          combos[c] += 1

      # vertical combo
      if i < 3 and c == rows[i+1][j] and rows[i][j] == rows[i+2][j]:
        y = 0
        is_new_combo = True

        while i + y < 5 and rows[i][j] == rows[i+y][j]:
          if is_new_combo and combo_map[i+y][j]:
            is_new_combo = False
          if is_new_combo and combo_around(rows, combo_map, i,j):
            is_new_combo = False
          combo_map[i+y][j] = True
          y += 1

        if is_new_combo:
          combos[c] += 1

 
def reduce_board(rows, combo_map):
  new_board = []
  reduced = False

  new_board.append(list("XXXXXX"))
  new_board.append(list("XXXXXX"))
  new_board.append(list("XXXXXX"))
  new_board.append(list("XXXXXX"))
  new_board.append(list("XXXXXX"))
  
  for i in range(5):
    for j in range(6):
      if combo_map[i][j]:
        combo_map[i][j] = False
        reduced = True
        rows[i][j] = 'X'

  if not reduced:
    return reduced

  for j in range(5,-1,-1):
    new_i = 4
    for i in range(4,-1, -1):
      if rows[i][j] != 'X':
        new_board[new_i][j] = rows[i][j]
        new_i -= 1

  for i in range(5):
    for j in range(6):
      rows[i][j] = new_board[i][j]

  return reduced
  
################################# main program #######################

rows = []
combo_map = [
 [False, False, False, False, False, False],
 [False, False, False, False, False, False],
 [False, False, False, False, False, False],
 [False, False, False, False, False, False],
 [False, False, False, False, False, False],
]

combos = {'R' : 0, 'U' : 0, 'G' : 0, 'Y' : 0, 'B': 0, 'P' : 0}


# read lines
for i in range(5):
  rows.append(list(input('')))

scan_combo(rows, combo_map, combos)
while reduce_board(rows, combo_map):
  scan_combo(rows, combo_map, combos)

print ('R {0}'.format(combos['R']))
print ('U {0}'.format(combos['U']))
print ('G {0}'.format(combos['G']))
print ('Y {0}'.format(combos['Y']))
print ('B {0}'.format(combos['B']))
print ('P {0}'.format(combos['P']))
