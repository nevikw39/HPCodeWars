#2.3 ml % kg
aaa = raw_input("").split()
number = aaa[0]
ml = int(aaa[1])
percent = int(aaa[2])
kg = float(aaa[3])
cans = int(number.split(".")[0])*6 + int(number.split(".")[1]);

alcohol_ml = cans*ml*percent/100.0
#print alcohol_ml
threshold_ml = kg*1000*0.08*0.05/100
#print(alcohol_ml)
#print(threshold_ml)
minu = int((alcohol_ml-threshold_ml)/(10.0/60)+0.999)

print "{0:d}:{1:02d}".format(minu/60, minu%60)
