#!/usr/bin/python3
def safe_print_list_integers(my_list=[], x=0):
    count = 0

    for item in my_list:
        try:
            if isinstance(item, int):
                print("{:d}".format(item), end=" ")
                count += 1
        except ValueError:
            pass

        if count == x:
            break

    print()
    return count