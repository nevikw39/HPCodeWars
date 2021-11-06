#!/usr/bin/env python
'''

CodeWars 2013

Triangle Area
'''
import sys
import math


class Point(object):
    def __init__(self, x, y):
        self.x = float(x)
        self.y = float(y)

    def __eq__(self, point):
        return self.x == point.x and self.y == point.y

    def origin(self):
        return self.x == self.y == 0

    def __str__(self):
        return '(%.2f, %.2f)' % (self.x, self.y)

    def coords(self):
        return self.x, self.y


class Triangle(object):
    def __init__(self, points):
        self.points = points

    def __str__(self):
        return '[%s, %s, %s]' % (self.points[0], self.points[1], self.points[2])

    def len_sides(self):
        retval = []
        for p0, p1 in self.point_combinations():
            size = self.len_points(p0, p1)
            retval.append(size)
        retval.sort()
        return retval

    def point_combinations(self):
        size = len(self.points)
        for i in range(size):
            yield (self.points[i], self.points[(i + 1) % size])

    def len_points(self, p0, p1):
        x0, y0 = p0.coords()
        x1, y1 = p1.coords()
        d = math.sqrt(pow((x0 - x1), 2) + pow((y0 - y1), 2))
        return d

    def angle(self, sides):
        a = sides[0]
        b = sides[1]
        c = sides[2]
        cos_w = (pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b)
        return math.acos(cos_w)

    def area(self):
        sides = self.len_sides()
        w = self.angle(sides)
        a = sides[0]
        b = sides[1]
        return (a * b * math.sin(w)) / 2


if __name__ == '__main__':
    for line in sys.stdin:
        coords = line.rstrip().split()
        points = []
        for x, y in zip(coords[0::2], coords[1::2]):  # [x y x y x y]
#        for x, y in zip(coords[:3], coords[3:]):  # [x x x y y y]
            point = Point(x, y)
            points.append(point)
        if points[0].origin() and points[1].origin() and points[2].origin():
            break
        tri = Triangle(points)
#        print tri,
        print (tri.area())
