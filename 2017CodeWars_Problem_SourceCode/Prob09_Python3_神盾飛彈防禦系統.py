import sys
def climbStairs(stairs):
	global results
	if stairs in results:
		return results[stairs]
	else:
		temp=climbStairs(stairs-1)+climbStairs(stairs-2)
		results[stairs]=temp
		return temp
if __name__ == '__main__':
    
    results={}
    results[1]=1
    results[2]=2
    
    text = input()
    i = int(text)
    print(climbStairs(i))


