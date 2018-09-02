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

int main() {
    cout << "Hello World, I'm a baby!" << endl;

    // Generate random int array
    const int size_of_array = 100000;
    int a[size_of_array];
    for (int i = 0; i < size_of_array; ++i) {
        a[i] = rand() % size_of_array + 1;
    }

    // Select sorting algorithm and run
    for (int i = 0; i < SORTERS_TOTAL; i++) {
        const Sorting *sort = chooseSorter(i);
        cout << "Choose '" << sort->name() << "' algorithm to sort [" << size_of_array << "] elements." << endl;
        const double duration = run([&a, &sort]() { sort->sort(a, size_of_array); });
        cout << "Duration millseconds: " << duration << endl;
    }

    cout << "Done" << endl;
    return 0;
}
