#!/usr/bin/python3
if __name__ == "__main__":
    import hidden_4
    module_names = dir(hidden_4)

    for x in module_names:
        if not x.startswith("__"):
            print(x)