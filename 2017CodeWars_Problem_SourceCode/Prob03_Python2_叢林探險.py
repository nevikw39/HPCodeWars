import math
import sys

def generate_map( source_map ):
    target_map = []    

    with source_map as new_map:
        row_count = source_map.readline()
        for new_row in new_map:
            row_list = []
            for item in new_row.strip().split(' '):
                if item:
                    row_list.append(item)
            target_map.append(row_list)
    return target_map

def IsPrime( number ):
    if float(number) % 2 == 0 and float(number) > 2:
        return False
    return all(float(number) % i for i in range(3, int(math.sqrt(float(number))) + 1, 2))    

def walk_map( target_map ):
    current_loc = [0,0]
    current_loc_num = target_map[0][0]
    path_tracker = []
    path_count = 0
    path_tracker.append(current_loc_num)
    target_loc = target_map[len(target_map)-1][len(target_map)-1]
    while current_loc_num != target_loc and path_count < len(target_map)*len(target_map):
        path_count = path_count + 1
        right_path = down_path = upper

        if current_loc[0] < len(target_map) and current_loc[1]+1 < len(target_map):
            right_path_loc = [current_loc[0], current_loc[1]+1]
            right_path = int(target_map[current_loc[0]][current_loc[1]+1])
            if not IsPrime(right_path):
                right_path = upper
        if current_loc[0]+1 < len(target_map) and current_loc[1] < len(target_map):
            down_path_loc = [current_loc[0]+1, current_loc[1]]
            down_path = int(target_map[current_loc[0]+1][current_loc[1]])
            if not IsPrime(down_path):
                down_path = upper
        
        if right_path > down_path:
            current_loc[0] = current_loc[0]+1
            current_loc_num = down_path
            path_tracker.append(current_loc_num)
        elif right_path < down_path:
            current_loc[1] = current_loc[1]+1
            current_loc_num = right_path
            path_tracker.append(current_loc_num)

    return path_tracker

def calc_fuel(path_tracker):
    return reduce(lambda x, y: int(x) + int(y), path_tracker)

if __name__ == '__main__':
    target_map = []
    upper = 1000
    target_map = generate_map(sys.stdin)
    path_tracker = walk_map(target_map)
    print calc_fuel(path_tracker)

