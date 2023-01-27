#include <iostream>

template <typename T>
void iter(T* arr, int len, void (*func)(T)) {
    for (int i = 0; i < len; i++) {
        func(arr[i]);
    }
}

void printInt(int x) {
    std::cout << x << " ";
}

void printString(std::string x) {
    std::cout << x << " ";
}

int main() {
    int intArr[] = {1, 2, 3, 4, 5};
    std::string stringArr[] = {"Hello", "World", "!"};

    iter(intArr, 5, printInt);
    std::cout << std::endl;
    iter(stringArr, 3, printString);

    return 0;
}
/*In this example, the iter function template takes a pointer to an array of type T, the length of the array, and a function pointer that takes a single argument of type T. The function iterates over the array and calls the provided function on each element of the array.

The main function demonstrates how to use the iter function template with both an array of integers and an array of strings, passing the appropriate function for printing each type.*/