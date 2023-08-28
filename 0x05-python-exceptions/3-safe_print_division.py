#!/usr/bin/python3
def safe_print_division(a, b):
    """Returns the division of a by b."""
    div = None 
    
    try:
        div = a / b
    except (TypeError, ZeroDivisionError):
        pass
    finally:
        print("Inside result: {}".format(div))
    
    return div  