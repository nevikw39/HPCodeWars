import math
import sys

plan_A = [0.3, 550, 50, 20, 300]
plan_B = [0.1, 1000, 100, 15, 500]
plan_C = [0.05, 2000, 150, 5, 800]


def calc_cost( usage, plan ):
    base_cost = plan[4]
    voice_cost = float(usage[0])*plan[0]
    overflow = int(usage[1]) - int(plan[1])
    if overflow <= 0 :
        data_cost = 0
    elif overflow > 0 :
        overflow_count = math.ceil((float(usage[1]) - float(plan[1]))/float(plan[2]))
        data_cost = overflow_count * plan[3]

    total = base_cost + voice_cost + data_cost
    
    return total


if __name__ == '__main__':
    #with open(input_filename, 'r') as person:
    for person in sys.stdin:
        usage = []
        for item in person.strip().split(' '):
            if item:
                usage.append(item)
        cost_A = calc_cost(usage, plan_A)
        cost_B = calc_cost(usage, plan_B)
        cost_C = calc_cost(usage, plan_C)
        suggest_plan = 'A'
        if cost_B < cost_A:
            suggest_plan = 'B'
        if cost_C < cost_B:
            suggest_plan = 'C'

        print suggest_plan

