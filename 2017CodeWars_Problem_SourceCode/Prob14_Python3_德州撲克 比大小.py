def check(cards):
    result = {
        'flush':True,
        'straight':0,
        'fourOfKing':0,
        'fullHouse':0,
        'threeOfKing':0,
        'twoPair':0,
        'onePair':0,
        'zitch':[]
    }
    number = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    color = None

    #sort
    for card in cards:
        num = card[:-1]
        if num == 'A':
            i = 14
        elif num == 'K':
            i = 13
        elif num == 'Q':
            i = 12
        elif num == 'J':
            i = 11
        else:
            i = int(num)
        
        number[i] = number[i] + 1

        #zitch
        if number[i] == 1:
            result['zitch'].insert(0,i)

        if color == None:
            color = card[-1]
        elif color != card[-1]:
            result['flush'] = False

    result['zitch'].sort(reverse=True)
    #straight
    for i in range(1,11):
        if number[i] == 1 and number[i+1] == 1 and number[i+2] == 1 and number[i+3] == 1 and number[i+4] == 1:
            result['straight'] = i+4

    for i in range(2,15):
        #four of kind
        if number[i] == 4:
            result['fourOfKing'] = i

        #three of kind
        if number[i] == 3:
            result['threeOfKing'] = i

        #two pair
        if number[i] == 2 and result['onePair'] != 0:
            result['twoPair'] = i

        #one pair
        if number[i] == 2 and result['onePair'] == 0:
            result['onePair'] = i
            


    #full house            
    if result['threeOfKing'] !=0 and result['onePair'] != 0:
        result['fullHouse'] = result['threeOfKing']

    return result
    
def compare(a, b):
    #print "flush straight"
    if (a['flush'] == True and a['straight'] != 0) or (b['flush'] == True and b['straight'] != 0):
        if (a['flush'] == True and a['straight'] != 0) and (b['flush'] == True and b['straight'] != 0):
            if a['straight'] > b['straight']:
                return 1
            elif a['straight'] < b['straight']:
                return -1
            else:
                return 0
        elif (a['flush'] == True and a['straight'] != 0) and (b['flush'] != True or b['straight'] == 0):
            return 1
        else:
            return -1

    #print "four of king"
    if (a['fourOfKing'] != 0) or (b['fourOfKing'] != 0):
        if(a['fourOfKing'] != 0) and (b['fourOfKing'] != 0):
            if a['fourOfKing'] > b['fourOfKing']:
                return 1
            else:
                return -1
        elif (a['fourOfKing'] != 0) and (b['fourOfKing'] == 0):
            return 1
        else:
            return -1
    
    #print "full house"
    if (a['fullHouse'] != 0) or (b['fullHouse'] != 0 ):
        if(a['fullHouse'] != 0) and (b['fullHouse'] != 0):
            if a['fullHouse'] > b['fullHouse']:
                return 1
            else:
                return -1
        elif (a['fullHouse'] != 0) and (b['fullHouse'] == 0):
            return 1
        else:
            return -1

    #print "flush"
    if (a['flush'] == True) or (b['flush'] == True ):
        if(a['flush'] == True) and (b['flush'] == True):
            for i in range(0,5):
                if(a['zitch'][i] > b['zitch'][i]):
                    return 1
                elif(a['zitch'][i] < b['zitch'][i]):
                    return -1
            return 0
        elif (a['flush'] == True) and (b['flush'] == False):
            return 1
        else:
            return -1

    #print "straight"    
    if (a['straight'] != 0) or (b['straight'] != 0 ):
        if(a['straight'] != 0) and (b['straight'] != 0):
            if a['straight'] == b['straight']:
                return 0
            elif a['straight'] > b['straight']:
                return 1
            else:
                return -1
        elif (a['straight'] != 0) and (b['straight'] == 0):
            return 1
        else:
            return -1

    #print "three of king"
    if (a['threeOfKing'] != 0) or (b['threeOfKing'] != 0 ):
        if(a['threeOfKing'] != 0) and (b['threeOfKing'] != 0):
            if a['threeOfKing'] > b['threeOfKing']:
                return 1
            else:
                return -1
        elif (a['threeOfKing'] != 0) and (b['threeOfKing'] == 0):
            return 1
        else:
            return -1

    #print "two pair"
    if (a['twoPair'] != 0) or (b['twoPair'] != 0 ):
        if(a['twoPair'] != 0) and (b['twoPair'] != 0):
            if a['twoPair'] > b['twoPair']:
                return 1
            elif a['twpPair'] < b['twoPair']:
                return -1
        elif (a['twoPair'] != 0) and (b['twoPair'] == 0):
            return 1
        else:
            return -1

    #print "one pair"
    if (a['onePair'] != 0) or (b['onePair'] != 0 ):
        if(a['onePair'] != 0) and (b['onePair'] != 0):
            if a['onePair'] > b['onePair']:
                return 1
            elif a['onePair'] < b['onePair']:
                return -1
        elif (a['onePair'] != 0) and (b['onePair'] == 0):
            return 1
        else:
            return -1

    #print "zitch"
    for i in range(0, 5):
        if(a['zitch'][i] > b['zitch'][i]):
            return 1
        elif(a['zitch'][i] < b['zitch'][i]):
            return -1

    return 0


line = input()
cards = line.split()
a = cards[0::2]
b = cards[1::2]
checked_a = check(a)
checked_b = check(b)
#print(a)
#print(b)
#print(checked_a)
#print(checked_b)
print(compare(checked_a, checked_b))