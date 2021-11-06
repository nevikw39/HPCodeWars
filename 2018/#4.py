# Python 2
#input = raw_input("Input: ")
# Python 3
inputStr = input("")

# input = "25 zshnmzkmzx zhvzmszx mhudqrhsxtzx"
shift, words = int(inputStr.split(" ")[0]), inputStr.split(" ")[1:]

for index, word in enumerate(words):
    temp = []

    for letterIndex, l in enumerate(word):
        shiftedLetter = (ord(l) - 97 + 26 - shift) % 26
        temp += chr(shiftedLetter + 97)

    newWord = "".join(temp)
    words[index] = newWord[-3] + newWord[:-3]

output = " ".join(words)
print(output)

'''
words = ["".join([chr((ord(l)-97+26-shift)%26 + 97) for l in word]) for word in words]
output = " ".join([word[-3]+word[:-3] for word in words])
print(output)
'''
