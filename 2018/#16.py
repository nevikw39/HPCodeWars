import sys

def exist(board, word):    
    def dfs(x, y, word):
        if len(word) == 0:
            return True
        # up
        if x > 0 and board[x - 1][y] == word[0]:
            tmp = board[x][y]
            board[x][y] = '#'
            if dfs(x - 1, y, word[1:]):
                return True
            board[x][y] = tmp

        # down
        if x < len(board) - 1 and board[x + 1][y] == word[0]:
            tmp = board[x][y]
            board[x][y] = '#'
            if dfs(x + 1, y, word[1:]):
                return True
            board[x][y] = tmp

        # left
        if y > 0 and board[x][y - 1] == word[0]:
            tmp = board[x][y]
            board[x][y] = '#'
            if dfs(x, y - 1, word[1:]):
                return True
            board[x][y] = tmp

        # right
        if y < len(board[0]) - 1 and board[x][y + 1] == word[0]:
            tmp = board[x][y]
            board[x][y] = '#'
            if dfs(x, y + 1, word[1:]):
                return True
            board[x][y] = tmp

        return False

    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == word[0]:
                if (dfs(i, j, word[1:])):
                    return True
    return False
    
if __name__ == '__main__':
    inputs = sys.stdin.readlines()

    word_length = int(inputs[0].strip('\n'))
    word = inputs[1].strip('\n').split(' ')[:word_length]

    splited_row_info = inputs[2].strip('\n').split(' ')
    board_row_count = int(splited_row_info[0])
    board_col_count = int(splited_row_info[1])

    board = []
    slice_head_index = 0
    slice_tail_index = board_col_count
    board_rowdata = inputs[3].strip('\n').split(' ')
    for i in range(0, board_row_count):
        board.append(board_rowdata[slice_head_index:slice_tail_index])
        slice_head_index = slice_head_index + board_col_count
        slice_tail_index = slice_tail_index + board_col_count
    
    print(exist(board, word))
