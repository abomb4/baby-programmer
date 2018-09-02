#ifndef SELECT_H
#define SELECT_H
#include "sorting.h"

namespace sorting {

class Select : public virtual Sorting {
public:
    // Sorting interface
    virtual void sort(int target[], const int size) const;
};

}
#endif // SELECT_H
