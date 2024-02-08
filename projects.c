#include <stdio.h>
#include <stdlib.h>

struct arrayElements {
    int size;
    int index;
    int *data;
};
typedef struct arrayElements Array;

// Function to create array
void createArray(Array *arr, int size) {
    arr->size = size;
    arr->data = (int*)malloc(size * sizeof(int));
    arr->index = 0;
}

// Function to extend array
void extend(Array *arr, int addedSize) {
    arr->size += addedSize;
    arr->data = (int*)realloc(arr->data, arr->size * sizeof(int));
}

// Function to add element to array
void addElementToArray(Array *arr, int value) {
    if (arr->index == arr->size - 1) {
        printf("Would you like to extend the size of the array? (Exit -1): ");
        int addedSize;
        scanf("%d", &addedSize);
        if (addedSize == -1) {
            return;
        }
        extend(arr, addedSize);
    }
    arr->data[arr->index] = value;
    arr->index++;
}

int main() {
    int size;
    printf("How many elements will be in your array: ");
    scanf("%d", &size);

    Array array;
    createArray(&array, size);

    for (int i = 0; i < size; i++) {
        printf("\nEnter the %dth element of the array: ", i + 1);
        int element;
        scanf("%d", &element);
        addElementToArray(&array, element);
    }

    printf("\nElements of the array:\n");
    for (int i = 0; i < array.index; i++) {
        printf("%d ", array.data[i]);
    }
    printf("\n");

    free(array.data);

    return 0;
}
