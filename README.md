<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Multi-Purpose Dynamic Array Implementation</title>
</head>
<body>
    <h1>Multi-Purpose Dynamic Array Implementation</h1>
    <p>This program demonstrates a multi-purpose dynamic array implementation in C. It provides functionalities to create an array, extend its size dynamically, and add elements to it. The array dynamically adjusts its size as needed to accommodate additional elements.</p>
    <h2>Features:</h2>
    <ol>
        <li><strong>Create Array:</strong> Allows the creation of an array with a specified initial size.</li>
        <li><strong>Extend Array:</strong> Provides the capability to extend the size of the array dynamically when needed.</li>
        <li><strong>Add Element to Array:</strong> Enables the addition of elements to the array. If the array is full, it prompts the user to extend its size before adding more elements.</li>
    </ol>
    <h2>Usage:</h2>
    <ol>
        <li><strong>Creating an Array:</strong> Use the <code>createArray</code> function to create an array with a specified initial size.</li>
        <li><strong>Extending Array Size:</strong> If the array is full and more elements need to be added, the <code>extend</code> function can be used to increase the array size dynamically.</li>
        <li><strong>Adding Elements to Array:</strong> The <code>addElementToArray</code> function adds elements to the array. If the array is full, it prompts the user to extend its size before adding more elements.</li>
    </ol>
    <h2>Example:</h2>
    <pre><code>
#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

// Structure to represent the dynamic array
struct arrayElements {
    int size;
    int index;
    int *data;
};
typedef struct arrayElements Array;

// Function to create array
void createArray(Array *arr, int size) {
    arr-&gt;size = size;
    arr-&gt;data = (int*)malloc(size * sizeof(int));
    arr-&gt;index = 0;
}

// Function to extend array
void extend(Array *arr, int addedSize) {
    arr-&gt;size += addedSize;
    arr-&gt;data = (int*)realloc(arr-&gt;data, arr-&gt;size * sizeof(int));
}

// Function to add element to array
void addElementToArray(Array *arr, int value) {
    if (arr-&gt;index == arr-&gt;size - 1) {
        printf("Would you like to extend the size of the array? (Exit -1): ");
        int addedSize;
        scanf("%d", &addedSize);
        if (addedSize == -1) {
            return;
        }
        extend(arr, addedSize);
    }
    arr-&gt;data[arr-&gt;index] = value;
    arr-&gt;index++;
}

int main() {
    // Usage example
    int size;
    printf("How many elements will be in your array: ");
    scanf("%d", &size);

    Array array;
    createArray(&array, size);

    for (int i = 0; i &lt; size; i++) {
        printf("\nEnter the %dth element of the array: ", i + 1);
        int element;
        scanf("%d", &element);
        addElementToArray(&array, element);
    }

    printf("\nElements of the array:\n");
    for (int i = 0; i &lt; array.index; i++) {
        printf("%d ", array.data[i]);
    }
    printf("\n");

    free(array.data);

    return 0;
}
    </code></pre>
    <p>This program demonstrates the flexibility and functionality of dynamic arrays in C, allowing for efficient storage and manipulation of data with dynamic sizing capabilities.</p>
</body>
</html>
