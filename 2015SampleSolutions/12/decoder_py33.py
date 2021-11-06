import os
import sys
import pdb
    
def main():
    while 1:
        input_line = raw_input(">>Input:")
        
        (A, B, C, D, E, F, G, H) = bit_separater(input_line)
        
        (Outa, Outb, Outc, Outd) = circuit(A, B, C, D, E, F, G, H) 
        print ("%s%s%s%s" %(Outa, Outb, Outc, Outd))

def bit_separater(input_value):
    A = int(input_value[0])
    B = int(input_value[1])
    C = int(input_value[2])
    D = int(input_value[3])
    E = int(input_value[4])
    F = int(input_value[5])
    G = int(input_value[6])
    H = int(input_value[7])
    return (A, B, C, D, E, F, G, H)
        
def circuit(A, B, C, D, E, F, G, H):
    Outa = bit_checker((not A) and B)
    Outb = bit_checker(((not A) and B) or (not(C and D)))
    Outc = bit_checker(not (C and D))
    
    Outd = bit_checker((E or F) and ((not G) or H))

    return (Outa, Outb, Outc, Outd)

def bit_checker(input):
    input = str(input)
    if (input == "True") or (input == "1"):
        return "1"
    elif (input == "False") or (input == "0"):
        return "0"

if __name__=='__main__':
    main()