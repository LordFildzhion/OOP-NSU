/*
*    Implementing a program that supports the following commands:
*
*    Add line:
*    The user enters a string that is appended to the end of an array of strings.
*
*    Delete line:
*    The user enters the index of the row to delete. The program frees up memory for this line and shifts all remaining lines one position to the left.
*
*    Display all lines:
*    The program prints all the rows in the array.
*
*    Exit:
*    The program terminates by terminating its work gracefully.
*/



#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct array_of_strings {
    uint64_t count;
    uint64_t buffer;
    char **strings;
} array_of_strings;

#define MIN_ARRAY_BUFFER_SIZE 16

array_of_strings *create_array()
{
    array_of_strings *array = (array_of_strings *) malloc(sizeof(array_of_strings));

    if (array == NULL)
    {
        printf("Memory allocation error when creating a string array\n");
        exit(EXIT_FAILURE);
    }

    array->count = 0;
    array->buffer = MIN_ARRAY_BUFFER_SIZE;
    array->strings = (char **) malloc(sizeof(char *) * array->buffer);

    if (array->strings == NULL)
    {
        printf("Memory allocation error when creating a string array\n");
        exit(EXIT_FAILURE);
    }

    for (uint64_t i = 0; i < array->buffer; i++)
        array->strings[i] = NULL;

    return array;
}

#undef MIN_ARRAY_BUFFER_SIZE

void delete_array(array_of_strings *array)
{
    for (uint64_t i = 0; i < array->buffer; i++)
        if (array->strings[i] != NULL)
        {
            free(array->strings[i]);
            array->strings[i] = NULL;
        }

    if (array->strings != NULL)
    {
        free(array->strings);
        array->strings = NULL;
    }

    if (array != NULL)
    {
        free(array);
        array = NULL;
    }
}

#define MIN_STRING_BUFFER_SIZE 256

char *add_string(array_of_strings *array)
{
    uint64_t string_length = 0,
    length_buffer = MIN_STRING_BUFFER_SIZE;
    char *string = (char *) malloc(length_buffer * sizeof(char));

    for (uint64_t i = 0; i < length_buffer; i++)
        string[i] = '\0';

    printf("Please, print your string:\n");

    getchar();
    while (true)
    {
        int16_t end_of_string = getchar();

        if (end_of_string == '\n')
            break;

        if (string_length + 1 == length_buffer)
        {
            length_buffer *= 2;

            if ((string = (char *)realloc(string, length_buffer * sizeof(char))) == NULL)
                return "Memory allocation error when reading a string\n";
        }

        string[string_length++] = (char)end_of_string;
    }

    if (array->count + 1 == array->buffer)
    {
        array->buffer *= 2;
        if ((array->strings = (char **)realloc(array->strings, array->buffer * sizeof(char *))) == NULL)
            return "Error when allocating memory to add a readable line\n";
    }
    array->strings[array->count++] = string;

    return NULL;
}

#undef MIN_STRING_BUFFER_SIZE

void swap_strings(char **str1, char **str2)
{
    char *buffer = *str1;
    *str1 = *str2;
    *str2 = *str1;
}

char *delete_str(array_of_strings *array, uint64_t index)
{
    if (index >= array->count)
        return "Incorrectly entered index. Array haven't string with that index\n";

    for (uint64_t i = index; i < array->count; i++)
        swap_strings(&array->strings[i], &array->strings[i + 1]);

    array->count--;

    if (array->strings[array->count])
        free(array->strings[array->count]);
    array->strings[array->count] = NULL;

    return NULL;
}

void print_str(array_of_strings *array)
{
    printf("Count strings in array: %lld\nStrings in array:\n", (int64_t)array->count);

    for (uint64_t i = 0; i < array->count; i++)
        if (array->strings[i] != NULL)
            printf("%s\n", array->strings[i]);

}

bool menu(array_of_strings *array)
{
    printf("Hello, this is program can:\n1. Add string to array\n2. Delete string from array\n3. Print all array\nOr you can leave if input 4\n\n");
    while(true)
    {
        int command = -1;
        char *res = "Can't read command. Please try again                                 \n";

        printf("Please input number of the command:");
        _flushall();
        if (scanf("%i", &command) <= 0)
        {
            printf("%s", res);
            continue;
        }

        if (command == 1)
        {
            res = add_string(array);
            printf("%s", (res == NULL ? "String adding accepted\n" : res));
        }

        else if (command == 2)
        {
            if (array->count == 0)
            {
                printf("Array is empty\n");
                continue;
            }

            int64_t index = -1;
            while (true)
            {
                printf("Please enter the index of the string to be deleted: ");

                if ((scanf("%lld", &index) <= 0))
                    printf("Can't input index. Please try again\n");
                else if (index < 0)
                    printf("Incorrectly entered index. Please try again\n");
                else
                    break;
            }

            res = delete_str(array, (uint64_t)index);
            printf("%s", (res == NULL ? "String deleting accepted\n" : res));
        }

        else if (command == 3)
        {
            print_str(array);
            printf("\n");
        }

        else if (command == 4)
        {
            printf("Goodbye!\n");
            delete_array(array);
            return false;
        }

        else
            printf("%s", res);

    }
}

int main(int argc, char **argv)
{
    array_of_strings *array = create_array();
    return menu(array);
}
