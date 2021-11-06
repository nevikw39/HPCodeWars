import sys, datetime

def count_bits(n):
    n = n-((n>>1)&0x555)
    n = (n&0x333)+((n>>2)&0x333)
    return ((((n+(n>>4))&0x0f0f)*0x0101)&0x0FFFF)>>8
        
def evaluate(v, mask, sumweight, advweights, base):
    if v == 0:
        return sumweight
    elif v == mask:
        return advweights[base+3]
    elif v&(v-1) == 0:
        return advweights[base+1]
    else:
        return advweights[base+2]
        
def load_file(file):
    bits = [1<<n for n in xrange(9)]
    masks = [bits[s[0]]|bits[s[1]]|bits[s[2]] for s in [(0,1,2),(3,4,5),(6,7,8),(0,3,6),(1,4,7),(2,5,8),(0,4,8),(2,4,6)]]
    total = 0

    try:
        with open(file, "r") as fh:
            basicweights = [int(i) for i in fh.readline().strip().split(",")]
            advweights = [int(i) for i in fh.readline().strip().split(",")]
            sumweights = [basicweights[s[0]]+basicweights[s[1]]+basicweights[s[2]] for s in [(0,1,2),(3,4,5),(6,7,8),(0,3,6),(1,4,7),(2,5,8),(0,4,8),(2,4,6)]]
        
            # read each line
            for line in fh.readlines():
                line = line.strip()
                
                # exception occurrs if digits < 9, then it ends
                
                # counts the board status for 2 players, values[0]=>player1, values[1]=>player2
                values=[sum([bits[i] if (line[i]==c) else 0 for i in xrange(9)]) for c in 'OX']
                
                # counts the bits for the status to set the parameters
                counts=[count_bits(v) for v in values]
                if counts[0] == counts[1]: # the amount of "O" equals to "X"
                    pl = 0
                    base = 0
                elif counts[0] == counts[1]+1: # the amount of "O" has 1 more than "X"
                    pl = 1
                    base = 0
                else: # invalid board
                    continue
                
                
                evaluation = 0
                # stats = []
                
                # count 8 lines 
                for i in xrange(8):
                    mask = masks[i]
                    rr = [v & mask for v in values]
                    # rr is the masked value
                    if rr[0]*rr[1]==0:
                        if rr[1-pl]==0: # enemy is empty
                            score = evaluate(rr[pl], mask, sumweights[i], advweights, base)
                        elif rr[pl]==0: # mine is empty
                            score = evaluate(rr[1-pl], mask, 0, advweights, base+4)
                            
                    #    stats.append(str(score))
                        evaluation += score
                    #else:
                    #    stats.append("0")

                #print ",".join(stats) + " => " + str(evaluation) + "\n"
                total += evaluation
    
    except:
        pass
            
    fh.close()
                
    return total            


# print str(datetime.datetime.now())

print load_file(sys.stdin.readline().strip());
# print str(datetime.datetime.now())
    
