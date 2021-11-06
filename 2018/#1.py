# Python3 implementation of left rotation of an array K number of times 
 
# Function to left rotate
# an array k times
def leftRotate(arr, n, k):
    # Print array after k rotations
    new_arr = []
    for i in range(k, k + n):
        new_arr.append(arr[i%n])
    
    return new_arr

# Function to right rotate arr of size n by d 
def RotateToLeftAndRight(arr, n, k):
    k = int(k)
    if (k<0):
    	k=abs(k)
    elif(k>0):
    	k = n - (k % n)
   
    new_arr = []
    for i in range(k, k + n):
        new_arr.append(arr[i%n])
    
    return new_arr

# Driver Code

#data = "5\n23 77 129 14 232\n3\n-82 -72 12" 
#data = "9\n48 62 76 209 235 54 13 255 243\n5\n42 38 -68 -73 60"
#data = "14\n172 55 22 204 114 117 255 239 232 141 232 242 211 118\n10\n-100 36 28 8 -88 -24 45 -90 -46 -91"

data1=raw_input("")
data2=raw_input("")
data3=raw_input("")
data4=raw_input("")

# datafile = data.split("\n")

a = data1
arr = data2
b = data3
step = data4


n = len(arr.split(" "))
steps = len(step.split(" "))

arr = arr.split(" ")
step = step.split(" ")

for i in range(0,steps):
    arr = RotateToLeftAndRight(arr, n, step[i])

print ' '.join(arr), "\n"
    
    


 