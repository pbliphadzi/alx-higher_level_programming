#include <stdio.h>
#include <Python.h>
#include <bytesobject.h>

/**
 * print_python_bytes - Prints bytes information
 *
 * @p: Python Object
 * Return: no return
 */
void print_python_bytes(PyObject *p)
{
	PyBytesObject *bytes_obj = (PyBytesObject *)p;

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	long int size = ((PyVarObject *)(p))->ob_size;
	printf("  size: %ld\n", size);

	char *string = (char *)(bytes_obj->ob_sval);
	printf("  trying string: %s\n", string);

	long int limit = (size >= 10) ? 10 : size + 1;
	printf("  first %ld bytes:", limit);

	for (long int i = 0; i < limit; i++)
	{
		if (string[i] >= 0)
			printf(" %02x", (unsigned char)string[i]);
		else
			printf(" %02x", 256 + (unsigned char)string[i]);
	}

	printf("\n");
}

/**
 * print_python_list - Prints list information
 *
 * @p: Python Object
 * Return: no return
 */
void print_python_list(PyObject *p)
{
	if (!PyList_Check(p))
	{
		printf("  [ERROR] Invalid List Object\n");
		return;
	}

	long int size = PyList_Size(p);
	PyListObject *list = (PyListObject *)p;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", list->allocated);

	for (long int i = 0; i < size; i++)
	{
		PyObject *obj = PyList_GetItem(p, i);
		printf("Element %ld: %s\n", i, Py_TYPE(obj)->tp_name);
		if (PyBytes_Check(obj))
			print_python_bytes(obj);
	}
}

int main(void)
{
	PyObject *list = PyList_New(0);
	PyObject *str = PyUnicode_DecodeUTF8("Hello", 5, "strict");
	PyObject *bytes = PyBytes_FromStringAndSize("world", 5);

	PyList_Append(list, str);
	PyList_Append(list, bytes);

	print_python_list(list);

	Py_DECREF(list);
	Py_DECREF(str);
	Py_DECREF(bytes);

	return 0;
}
