class Gray:
    def __init__(self, code, isOdd):
        self.code = code
        self.isOdd = isOdd
        
    def lastIndexOf(self, elem):
        return len(self.code) - 1 - self.code[::-1].index(elem)
    
    def next(self):
        i = (len(self.code) if self.isOdd 
                            else self.lastIndexOf(1)) - 1
        return Gray([] if i == -1 else self.code[0:i] + [1 - self.code[i]] + self.code[i + 1:], not self.isOdd)
    
    def isEmpty(self):
        return len(self.code) == 0
               
    def __str__(self):
        return str(self.code) + (' odd' if self.isOdd else ' even')
        
def gray(length):
    def successors(gray):
        nx = gray.next()
        return [] if nx.isEmpty() else [nx] + successors(nx)
            
    init = Gray([0] * length, True)
    return [init] + successors(init)
    
for code in gray(9):
    print(code)
    