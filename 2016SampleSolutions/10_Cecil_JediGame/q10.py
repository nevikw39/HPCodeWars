
import sys

# function to calculate the draw times
def draw(rate, hit = 0.01):
    base_rate = 1 - rate # base hit rate
    miss = 1
    count = 0            
    while miss >= hit:
        count += 1
        miss *= base_rate

    return count

(l_rate, m_rate, k_rate, a_rate) = sys.stdin.readline().split()

print ("{0} {1} {2} {3}".format (draw(int(l_rate)/100), draw(int(m_rate)/100), draw(int(k_rate)/100), draw(int(a_rate)/100)))
