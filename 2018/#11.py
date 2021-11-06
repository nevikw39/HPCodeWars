
import sys
# import time

def search(n, bs):
    result = []

    if n == 0:
        return [[]]
    elif len(bs) == 0 or n < bs[0]:
        return []
    
    for i in range(0, len(bs)):
        if n >= bs[i]:
            rest = search(n - bs[i], bs[i:])
            for j in range(0, len(rest)):
                rest[j].append(bs[i])
                result.append(rest[j])
    
    return result

if __name__ == "__main__":
    # start_time = time.time()

    input_data = sys.stdin.readlines()
    kind_count = int(input_data[0])
    target = int(input_data[2])
    boxes = map(lambda s: int(s), input_data[1].split())
    boxes = boxes[:kind_count]
    boxes.sort()

    # print 'question:', kind_count, boxes, target

    r = search(target, boxes)
    r.sort(key=lambda a: len(a))
    
    # print 'total: %d, cost: %f seconds' % (len(r), time.time() - start_time)
    answer = len(r[0]) if len(r) > 0 else 0
    # print 'answer: %d' % answer

    print answer