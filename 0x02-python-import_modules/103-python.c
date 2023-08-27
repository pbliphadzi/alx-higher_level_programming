#include <Python.h>
#include <listobject.h>
#include <object.h>
#include <bytesobject.h>

/**
 * print_python_bytes - prints python bytes
 *
 * Description: prints python bytes
 *
 * @p: PyObject pointer
 *
 * Return: void
 */
void print_python_bytes(PyObject *p)
{
    long int size_of_bytes, i;

    printf("[.] bytes object info\n");
    if (PyBytes_CheckExact(p))
    {
        size_of_bytes = ((PyVarObject *)p)->ob_size; // Using ob_size instead of PyBytes_GET_SIZE
        printf("  size: %ld\n", size_of_bytes);
        printf("  trying string: %s\n", PyBytes_AsString(p));
        if (size_of_bytes >= 10)
            size_of_bytes = 10;
        else
            size_of_bytes++;
        printf("  first %ld bytes:", size_of_bytes);
        for (i = 0; i < size_of_bytes; i++)
            printf(" %02x", (unsigned char) PyBytes_AsString(p)[i]);
        printf("\n");
    }
    else
        printf("  [ERROR] Invalid Bytes Object\n");
}

/**
 * print_python_list - prints some basic info about Python lists
 *
 * Description: function that prints some basic info about Python lists
 *
 * @p: PyObject pointer
 *
 * Return: void
 */
void print_python_list(PyObject *p)
{
    long int size_of_list, list_index;
    PyObject *temp;
    PyObject *list_items = NULL;
    PyObject *list_items_iterator = NULL;

    printf("[*] Python list info\n");

    if (PyList_Check(p))
    {
        size_of_list = ((PyVarObject *)p)->ob_size; // Using ob_size instead of PyList_GET_SIZE
        printf("[*] Size of the Python List = %ld\n", size_of_list);

        list_items = PyObject_GetIter(p);
        if (list_items != NULL)
        {
            list_index = 0;
            while ((temp = PyIter_Next(list_items)) != NULL)
            {
                printf("Element %ld: %s\n", list_index, temp->ob_type->tp_name);
                if (PyBytes_CheckExact(temp))
                    print_python_bytes(temp);

                Py_DECREF(temp);
                list_index++;
            }

            Py_DECREF(list_items);
        }
        else
        {
            printf("[ERROR] Failed to retrieve list items.\n");
        }
    }
    else
    {
        printf("  [ERROR] Invalid List Object\n");
    }
}
