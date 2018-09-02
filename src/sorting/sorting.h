#ifndef SORTING_H
#define SORTING_H

namespace sorting {

class Sorting {
public:
    virtual void sort(int target[], const int size) const = 0;
    virtual ~Sorting() {}
};

void swap(int target[], int i, int j);

}

#endif

