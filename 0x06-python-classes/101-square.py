#!/usr/bin/python3

"""Defines a square"""

class Square:
    """Square class with properties and methods."""
    def __init__(self, size=0, position=(0, 0)):
        self.size = size  # Using the property setter to validate size
        self.position = position  # Using the property setter to validate position

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

    @property
    def position(self):
        """Getter method for position"""
        return self.__position

    @position.setter
    def position(self, value):
        """Setter method for position"""
        if not isinstance(value, tuple) or len(value) != 2:
            raise TypeError("position must be a tuple of 2 positive integers")
        if not all(isinstance(num, int) and num >= 0 for num in value):
            raise TypeError("position must be a tuple of 2 positive integers")
        self.__position = value

    def area(self):
        """Returns the current square area"""
        return self.__size ** 2

    def my_print(self):
        """Prints the square with '#' characters and position handling"""
        if self.__size == 0:
            print()
        else:
            for _ in range(self.__position[1]):
                print()
            for _ in range(self.__size):
                print(" " * self.__position[0] + "#" * self.__size)

    def __str__(self):
        """Returns the square as a string"""
        square_str = ""
        if self.__size == 0:
            return square_str
        for _ in range(self.__position[1]):
            square_str += '\n'
        for _ in range(self.__size):
            square_str += ' ' * self.__position[0] + '#' * self.__size
            square_str += '\n'
        return square_str.rstrip()