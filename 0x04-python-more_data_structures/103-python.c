#include <stdio.h>
#include <Python.h>

/**
 * print_python_info - Prints Python object information
 *
 * @p: Python Object
 * Return: no return
 */
void print_python_info(PyObject *p)
{
	long int size, i, limit;
	PyObject *obj;

	if (PyBytes_Check(p))
	{
		printf("[.] bytes object info\n");
		size = PyBytes_Size(p);
		printf("  size: %ld\n", size);

		char *string = PyBytes_AsString(p);
		printf("  trying string: %s\n", string);

		limit = (size >= 10) ? 10 : size + 1;
		printf("  first %ld bytes:", limit);

		for (i = 0; i < limit; i++)
		{
			if (string[i] >= 0)
				printf(" %02x", (unsigned char)string[i]);
			else
				printf(" %02x", 256 + (unsigned char)string[i]);
		}
		printf("\n");
	}
	else if (PyList_Check(p))
	{
		size = PyList_Size(p);
		printf("[*] Python list info\n");
		printf("[*] Size of the Python List = %ld\n", size);

		PyListObject *list = (PyListObject *)p;
		printf("[*] Allocated = %ld\n", list->allocated);

		for (i = 0; i < size; i++)
		{
			obj = PyList_GetItem(p, i);
			printf("Element %ld: %s\n", i, Py_TYPE(obj)->tp_name);
			if (PyBytes_Check(obj))
				print_python_info(obj);
		}
	}
	else
	{
		printf("  [ERROR] Invalid Object Type\n");
	}
}
