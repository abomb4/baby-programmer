#include "sorting.h"
#include <algorithm>

namespace sorting {

static const Sorting* const SORTERS_OBJECT[SORTERS_TOTAL] = { new Select(), new Insert(), new Shell() };

template<typename T>
void swap(T array[], int i, int j) {
    T tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

Sorting::~Sorting() {}

const Sorting *chooseSorter(const int number) {
    if (number >= 0 && number < SORTERS_TOTAL) {
        return SORTERS_OBJECT[number];
    } else {
        return SORTERS_OBJECT[0];
    }
}

// -=================== Basic sorting ===================-
// Select sorting
const char* Select::name() const { return "Select"; };
void Select::sort(int target[], const int size) const {

    for (int i = 0; i < size; i++) {
        int min = 2147483647;
        int mini = -1;
        for (int j = i + 1; j < size; j++) {
            if (target[j] < min) {
                min = target[j];
                mini = j;
            }
        }

        if (mini > -1) {
            swap(target, i, min);
        }
    }
}

// Insert sorting
const char* Insert::name() const { return "Insert"; };
void Insert::sort(int a[], const int size) const {

    for (int i = 0; i < size; i++) {
        for (int j = i; j > 0 && a[j] < a[j - 1]; j--) {
            swap(a, j, j - 1);
        }
    }
}

// Shell sorting
const char* Shell::name() const { return "Shell"; };
void Shell::sort(int a[], const int size) const {

    int h = 1;
    while (h < size / 3) {
        h = 3 * h + 1; // 1, 4, 13, 40, 121, 364, 1093
    }
    while (h > 1) {
        for (int i = h; i < size; i++) {
            // insert a[i] to a[i - h], a[i - 2 * h], a[i - 3 * h]...
            for (int j = i; j >= h && a[j] < a[j - h]; j -= h) {
                swap(a, j, j - h);
            }
        }
        h = h / 3;
    }
}


}
