#include "sorting.h"

namespace sorting {

void swap(int target[], int i, int j) {
    int tmp = target[i];
    target[i] = target[j];
    target[j] = tmp;
}

}
