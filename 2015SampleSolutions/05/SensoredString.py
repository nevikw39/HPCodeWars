#! python

data = input()
inlist = data.split(" ")
FilenameArray = inlist[0].split(".txt")

f_origin = open(inlist[0], "r")
string = f_origin.read()

Hidden_num = int(inlist[1])

for num in range(2, Hidden_num + 2):
    string = string.replace(inlist[num],"***")

NewName = FilenameArray[0]+"_mod"
f_new = open(NewName + ".txt", "w")
f_new.write(string)

f_origin.close()
f_new.close()

print ("Success: " + NewName + ".txt\n")
