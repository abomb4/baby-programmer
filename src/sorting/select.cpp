#include "select.h"

using namespace sorting;

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
