#! /usr/bin/env python2.7


class People(object):
    def __init__(self, num):
        super(People, self).__init__()
        self.num = num
        self.friends = list()


class Node(object):
    def __init__(self, num, depth, parent, prob):
        super(Node, self).__init__()
        self.num = num
        self.ancestor = list()
        self.depth = depth
        self.prob = prob
        self.parent = parent
        self.leaf = False
        if parent:
            self.ancestor.extend(parent.ancestor)
            self.ancestor.append(parent.num)


def count_expected(_peoples):
    n = len(_peoples)
    tree = list()
    leaves = list()
    root = Node(1, 1, None, 1.0)
    expected = 0
    stack = [root]

    while stack:
        n = stack.pop()
        tree.append(n)
        child_set = set(_peoples[n.num].friends) - set(n.ancestor)
        count = len(child_set)
        if count == 0:
            n.leaf = True
            leaves.append(n)
        else:
            for c in child_set:
                prob = 1.0 / count
                p = Node(c, n.depth + 1, n, prob * n.prob)
                stack.append(p)

    for l in leaves:
        expected += l.prob * l.depth

    return expected

if __name__ == '__main__':
    people_count = int(raw_input())
    rel = list()
    peoples = dict()

    for i in range(1, people_count + 1):
        peoples.update({
            i: People(i)
        })

    for i in range(1, people_count+1):
        r = list(raw_input())
        for idx, x in enumerate(r):
            if x == 'Y':
                peoples[i].friends.append(idx + 1)

        rel.append(r)

    #print people_count
    #print rel
    #print peoples

    print int(count_expected(peoples) * 1000) / 1000.0
