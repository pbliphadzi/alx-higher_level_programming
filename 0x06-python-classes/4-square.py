#!/usr/bin/python3

"""Defines a square"""

class Square:
    """Square class with properties and methods."""
    def __init__(self, size=0):
        self.size = size  # Using the property setter to validate size

    @property
    def size(self):
        """Getter method for size"""
        return self.__size

    @size.setter
    def size(self, value):
        """Setter method for size"""
        if not isinstance(value, int):
            raise TypeError("size must be an integer")
        if value < 0:
            raise ValueError("size must be >= 0")
        self.__size = value

    def area(self):
        """Returns the current square area"""
        return self.__size ** 2
