class Node(object):
	def __init__ (self, x):
		self.value = x
		self.left = None
		self.right = None
		self.level = -1
	def insertRight(self, Object):
		if self.right == None:
			self.right = Object
		else:
			return False

	def insertLeft(self, Object):
		if self.left == None:
			self.left = Object
		else:
			return False

def Tree(leaves, num4lastlevel, depth4tree):
	current = []
	index = -1
	for i in range(0,len(leaves),1):
		if i == 0:
			index = index + 1
			current.append(i)
			leaves[i].level = leaves[i].level + 1
		else:
			while True:
				if depth4tree > leaves[current[index]].level:
					if (depth4tree - 1) == leaves[current[index]].level:
						if num4lastlevel > 0:	
							if leaves[current[index]].left == None:
								leaves[i].level = leaves[current[index]].level + 1
								leaves[current[index]].insertLeft(leaves[i])
								current.append(i)
								index = len(current) - 1
								num4lastlevel = num4lastlevel - 1
								break
							elif leaves[current[index]].right == None:
								leaves[i].level = leaves[current[index]].level + 1
								leaves[current[index]].insertRight(leaves[i])
								current.append(i)
								index = len(current) - 1
								num4lastlevel = num4lastlevel - 1
								break
							else:
								index = index - 1
						else:
							index = index - 1
					else:
						if leaves[current[index]].left == None:
							leaves[i].level = leaves[current[index]].level + 1
							leaves[current[index]].insertLeft(leaves[i])
							current.append(i)
							index = len(current) - 1
							break
						elif leaves[current[index]].right == None:
							leaves[i].level = leaves[current[index]].level + 1
							leaves[current[index]].insertRight(leaves[i])
							current.append(i)
							index = len(current) - 1
							break
						else:
							index = index - 1
				else:
					index = index - 1		
	
	Final = []
	Answer = ""
	for i in range(0,len(leaves),1):
		if leaves[i].left == None and leaves[i].right == None:
			Final.append(leaves[i])	
	
	for i in range(0,(depth4tree+1),1):
		for j in range(0,len(Final),1):
			if Final[j].level == i:
				Answer+=str(Final[j].value + ", ")
	Answer = Answer[0:len(Answer)-2]	
	print Answer
	return Answer			

def GrowLeave(Input):
	Leave = []
	for item in Input:
		Leave.append(Node(item))
	return Leave

### Calculate the depth of the tree and the max number of last level
def Depth(Count4Leave):
	count = 0
	total = 1
	while Count4Leave > total:
		count = count + 1
		total = total + 2**count
	total = total - 2**(count)
	Num4LastLevel = Count4Leave - total
	return (Num4LastLevel, count)	

if __name__ == '__main__':
	### Could customize your input
	with open('Q3.txt', 'r') as myfile:
    		Input=myfile.read().replace(',','').replace(' ','').strip()
		Input.split()

	file = open('A3.txt', 'w')
	
	Num4LastLevel, Depth4Tree = Depth(len(Input))
	Leaves = GrowLeave(Input)	
	Answer = Tree(Leaves, Num4LastLevel, Depth4Tree)	
	file.write(Answer)
	file.close()
	myfile.close()
