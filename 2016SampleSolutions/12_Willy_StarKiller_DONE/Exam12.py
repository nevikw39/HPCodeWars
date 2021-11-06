import sys
from itertools import permutations

stars = sys.argv[1:4]
planets = sys.argv[4:7]

stars_combination = list(permutations(stars))
platnets_combination = list(permutations(planets))

def time (star, end):
    angle = abs(int(star) - int(end))
    complement_angle = 360 - angle
    if angle < complement_angle:
        return angle * 2
    else:
        return complement_angle * 2

def timeSum (obj) :
    s = obj['star']
    p = obj['planet']
    step1 = time(0, s[0]) + 60 + time(s[0], p[0]) + 5
    step2 = time(p[0], s[1]) + 60 + time(s[1], p[1]) + 5
    step3 = time(p[1], s[2]) + 60 + time(s[2], p[2]) + 5
    sum = step1 + step2 + step3
    return sum

minimum = -1
for p_combination in platnets_combination:
    for s_combination in stars_combination:
        obj = dict()
        obj['star'] = s_combination
        obj['planet'] = p_combination
        total_time = timeSum(obj)
        if minimum == -1:
            minimum = total_time
        elif minimum and total_time < minimum:
            minimum = total_time

print minimum
