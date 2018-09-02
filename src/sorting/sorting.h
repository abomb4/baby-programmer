#ifndef SORTING_H
#define SORTING_H

namespace sorting {

// Currently only int values are supported for sorting.
class Sorting {
public:
    virtual ~Sorting();
    virtual const char* name() const = 0;
    virtual void sort(int target[], const int size) const = 0;
};

// Currently this value must manage manually.
static const int SORTERS_TOTAL = 2;

// This function can use like:
// for (int i = 0; i < SORTER_TOTAL; i++) { const Sorting* sort = chooseSorter(i); }
const Sorting *chooseSorter(const int number);

// Swap two elements in array
template<typename T>
void swap(T array[], int i, int j);

// -=-=-=-==- Sorting algorighms =-=--==-=--=

class Select : public virtual Sorting {
public:
    virtual const char* name() const;
    virtual void sort(int target[], const int size) const;
};

class Insert : public virtual Sorting {
public:
    virtual const char* name() const;
    virtual void sort(int target[], const int size) const;
};

}
#endif

