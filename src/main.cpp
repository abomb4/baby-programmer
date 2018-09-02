#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting/sort.h"

using namespace std;
using namespace sorting;

Sorting *chooseSorter(const int i) {
    switch(i) {
    case 1:
    default:
        return new Select();
    }
}

template<typename Functor>
void run(Functor functor) {
    clock_t start_s = clock();
    functor();
    clock_t stop_s = clock();
    cout << "Duration millseconds: " << (stop_s-start_s) / double(CLOCKS_PER_SEC) * 1000 << endl;
}

int main() {
    cout << "Hello World, I'm a baby!" << endl;

    cout << "Enter 1 and enter" << endl;
    int number = 1;
    cout << "Choose " << number << endl;
    Sorting *sort = chooseSorter(number);

    const int size_of_array = 100000;
    int a[size_of_array];
    for (int i = 0; i < size_of_array; ++i) {
        a[i] = rand() % size_of_array + 1;
    }

    run([&a, &sort]() { sort->sort(a, size_of_array); });

    cout << "Done" << endl;
    return 0;
}
