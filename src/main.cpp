#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting/sorting.h"

using namespace std;
using namespace sorting;

template<typename Functor>
double run(Functor functor) {
    clock_t start_s = clock();
    functor();
    clock_t stop_s = clock();
    const double duration = (stop_s-start_s) / double(CLOCKS_PER_SEC) * 1000;
    return duration;
}


template<typename T>
bool validate_sort(const T array[], const int size) {
    if (size <= 1) {
        return true;
    }
    int previous = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < array[previous]) {
            return false;
        }
    }
    return true;
}

void print(int a[], const int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}


int main() {
    cout << "Hello World, I'm a baby!" << endl;

    // Generate random int array
    const int size_of_array = 10;
    int a[size_of_array];

    // Select sorting algorithm and run
    for (int i = 0; i < SORTERS_TOTAL; i++) {
        for (int i = 0; i < size_of_array; ++i) {
            a[i] = rand() % size_of_array + 1;
        }
        const Sorting *sort = chooseSorter(i);
        cout << "Choose '" << sort->name() << "' algorithm to sort [" << size_of_array << "] elements." << endl;
        const double duration = run([&a, &sort]() { sort->sort(a, size_of_array); });
        cout << "Duration millseconds: " << duration << endl;
        const bool valid = validate_sort(a, size_of_array);
        cout << "Valid: " << valid << endl;
        print(a, size_of_array);
    }

    cout << "Done" << endl;
    return 0;
}
