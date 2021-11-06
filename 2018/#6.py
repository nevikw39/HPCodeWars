def rectangle():
    p1 = raw_input("").strip()
    p2 = raw_input("").strip()
    p3 = raw_input("").strip()
    p4 = raw_input("").strip()
    points = [p1.split(" "), p2.split(" "), p3.split(" "), p4.split(" ")]
    a = points[0]
    b = c = d = None

    result = False
    is_rectangle = False
    # verify if these points form a rectangle
    for p in points[1:]:
        if p[0] == a[0]:
            if not b:
                b = p
            else:
                break
        elif p[1] == a[1]:
            if not d:
                d = p
            else:
                break
        else:
            if not c:
                c = p
            else:
                break
    if a and b and c and d:
        is_rectangle = (c == [d[0], b[1]])

    # sort in sequence of A, B, C, D
    if is_rectangle:
        if c == [d[0], b[1]]:
            A, B, C, D = a, b, c, d
            if int(a[0]) > int(d[0]):
                A, B, C, D = d, c, b, a
            if int(B[1]) > int(A[1]):
                temp = A
                A = B
                B = temp
            if int(C[1]) > int(D[1]):
                temp = C
                C = D
                D = temp

            # verify if it a square
            h_dist = abs(int(C[0])-int(B[0]))
            v_dist = abs(int(C[1])-int(D[1]))
            result = (h_dist == v_dist)

    print result
    # sort in sequence of A, B, C, D
    if result:
        print " ".join(A)
        print " ".join(B)
        print " ".join(C)
        print " ".join(D)

# main
rectangle()
