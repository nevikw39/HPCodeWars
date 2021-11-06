import io
import os
import sys

def create_answer_base():
    # We skip the matches of '-' and '=' signs as they are always on in wahtever statements.
    # 這裡我們不去記錄 '-' 和 '=' 在運算式的線，因為不管是＋或－運算的數學式，它們都一直存在。
    ops = {'+': [1], '-': []}

    # Assign a line with a different number (2-8), and then a digit associate with a set of them.
    # 這邊我們定義每個數字或符號所需要顯示不同的線。
    symbols = {
        0:[2,3,4,6,7,8], 
        1:[4,7], 
        2:[2,4,5,6,8],
        3:[2,4,5,7,8],
        4:[3,4,5,7],
        5:[2,3,5,7,8],
        6:[2,3,5,6,7,8],
        7:[2,4,7],
        8:[2,3,4,5,6,7,8],
        9:[2,3,4,5,7,8],
        ' ':[]}


    # 這是準備存放０－２９條線所產生的數學式子用的，當然在６條線以下會是空的。 first element is valid, second is invalid
    results = [[] for i in xrange(30)]

    # 這是放答案用的，第一個放搬動１個的問題和對應的解答，第二個放搬動２個的問題和對應的解答。
    # quiz = [{},{}]

    # Define each line with different id (multiple by 10 for easier to understand).
    # 這是給每個在不同位置的數字裡的線（火柴棒）一個獨自的號碼；為了方便閱讀，我們直接乘１０而不是乘７。
    digits = {}
    for pos in xrange(4):
        digits[pos] = {}
        for symbol in symbols.keys():
            # 被加數、加數、被減數和減數（前２個數字）都不能是空白
            if symbol == ' ' and pos < 2:
                continue
                
            digits[pos][symbol] = [pos * 10 + line for line in symbols[symbol]]

    valids = [False for i in xrange(30)]        
            
            
    # Loop thru to find all valid and invalid statements, such as, '7+0= 7'.
    # 這裡我們運用電腦的計算能力，把每一個合法或不合法的數學式子都找出來。
    for op in ops:
        for d1 in digits[0].keys():
            for d2 in digits[1].keys():
                for d3 in digits[2].keys():
                    for d4 in digits[3].keys():
                        # 除非第４個是１（可以把１移走）或是空白，否則第３個數字不能為０，也就是我們不考慮 8-0=08 這種數學運算式。
                        if d3 == 0 and d4 not in [1, ' ']: # leading with 0
                            continue
                        # This is because we want to find the question, like '6+0=61'.
                        # 依照第３和第４個數字是否為空白來決定第３和第４個數字實際所代表的值。
                        if d3 == ' ' or d4 == ' ':
                            if d3 == ' ' and d4 == ' ':
                                continue
                            elif d3 == ' ':
                                result = d4
                            else:
                                result = d3
                        else:
                            result = d3 * 10 + d4
                        if d1 == 3 and d2 == 0 and d3 == 7 and d4 == 1:
                            pass


                        # Check the statement is valid or not by specified + or - operation.
                        # 實際做運算來檢查是否是合理的數學式。
                        if op == '+':
                            valid = ((d1 + d2) == result);
                        else:
                            valid = ((d1 - d2) == result);
                    
                        statement = str(d1) + op + str(d2) + \
                                '=' + str(d3) + str(d4)

                        # Count total lines of the statement.
                        # 把所有線都加起來去計算總共的線數（火柴棒數）。
                        lines = set(digits[0][d1] + ops[op] + \
                                 digits[1][d2] + \
                                 digits[2][d3] + digits[3][d4])
                        totallines = len(lines)

                        # add this statement
                        # statement - string, statement; eg. 3+0= 3
                        # valid - boolean, is the statement a valid one? eg. 3+0= 3 => True
                        # lines - the value list of each light segment in the statement
                        # [] - the container for fill-in the answer statement
                        results[totallines].append([statement, valid, lines, []])
                        
                        if (valid):
                            valids[totallines] = True;
                        
                        #else:
                        #    results[totallines][1].append([statement, lines, []])


    quiz = {}
    # Besides the minus and equal sign, the total of other matches is less than 30.
    # 可以移動的火柴棒最多有２９個
    for totallines in xrange(30):
        # skip all invalid or only 1 statement situations
        if not valids[totallines] or len(results[totallines]) < 2:
            continue
        
        # calculate the result
        for index1 in xrange(len(results[totallines])-1):
            for index2 in xrange(index1, len(results[totallines])):
                diff = results[totallines][index1][2] - results[totallines][index2][2]
                # if this is what we want to find 2 differences of the diff set
                if len(diff) == 2:
                    if results[totallines][index1][1]: # valid
                        results[totallines][index2][3].append(results[totallines][index1][0]);
                    if results[totallines][index2][1]: # valid
                        results[totallines][index1][3].append(results[totallines][index2][0]);
        
            if len(results[totallines][index1][3]) > 0:
                quiz[results[totallines][index1][0]] = str(len(results[totallines][index1][3])) #",".join(results[totallines][index1][3])
                
    return quiz
    
def load_quiz():
    answer_file = "answer_data.txt"
    if not os.path.isfile(answer_file):
        quiz = create_answer_base()
        with open(answer_file, "w+") as answer_handler:
            for prompt, answer in quiz.items():
                answer_handler.write(prompt + ":" + answer + "\n")
    
    quiz = {}
    with open(answer_file, "r") as answer_handler:
        for line in answer_handler.readlines():
            k,v = line.strip().split(":")
            quiz[k] = v
    
    return quiz


quiz = load_quiz()

equation = sys.stdin.readline().strip()[1:-1]
print(quiz[equation] if quiz.has_key(equation) else "0")
