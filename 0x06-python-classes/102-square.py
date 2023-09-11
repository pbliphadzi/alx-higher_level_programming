#!/usr/bin/python3

"""Defines a square"""

class Square:
    """Square class with properties and methods."""
    def __init__(self, size=0):
        self.size = size  

    @property
    def size(self):
        """Getter method for size"""
        return self.__size

    @size.setter
    def size(self, value):
        """Setter method for size"""
        if not isinstance(value, (int, float)):
            raise TypeError("size must be a number")
        if value < 0:
            raise ValueError("size must be >= 0")
        self.__size = value

    def area(self):
        """Returns the current square area"""
        return self.__size ** 2

    def __eq__(self, other):
        """Equal operator overload"""
        return self.area() == other.area()

    def __ne__(self, other):
        """Not equal operator overload"""
        return self.area() != other.area()

    def __gt__(self, other):
        """Greater than operator overload"""
        return self.area() > other.area()

    def __ge__(self, other):
        """Greater than or equal operator overload"""
        return self.area() >= other.area()

    def __lt__(self, other):
        """Less than operator overload"""
        return self.area() < other.area()

    def __le__(self, other):
        """Less than or equal operator overload"""
        return self.area() <= other.area()