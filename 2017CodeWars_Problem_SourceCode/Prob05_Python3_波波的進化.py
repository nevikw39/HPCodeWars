my_input = input('')
my_input = my_input.split(' ')
# print(my_input)


my_list = list(map(int, my_input))
# print(my_list)

A = my_list[0]
B = my_list[1]
C = my_list[2]

ev_count = 0
bibi = 0
ev_exp = 0
ev_double_time = C * 30 * 60


while (B>0):
    while (A>=12):
        if B <= 0:
            print('break')
            break
        ev_count = ev_count + 1
        bibi = bibi + 1
        A = A - 12 + 1
        B = B - 1
#        print('A = ', A ,', B = ', B, ' ev_count = ', ev_count, ' time = ', ev_double_time)
        if ev_double_time > 0:
            ev_double_time = ev_double_time - 15
            ev_exp = ev_exp + 1000
        else:
            ev_exp = ev_exp + 500

    if B == 0:
        break
    if bibi > 0:
        bibi = bibi - 1
        A = A + 1
        # ev_double_time = ev_double_time - 3
    else:
        break
    
print (ev_count, ev_exp)

#print(A)
#print(B)
#print(ev_count)
#print(ev_exp)

    



