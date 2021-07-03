#ifndef GRAAL_H
#define GRAAL_H

#include <utility>
using std::pair;
#include <iterator>
using std::distance;
#include <algorithm>
using std::sort;

namespace graal {

/*! 
 * @param first Ponteiro para o primeiro elemento do range
 * @param last Ponteiro para o último elemento do range
 */
template<class BidirIt>
void reverse(BidirIt first, BidirIt last)
{
    last -= 1; // Get the last valid value from the array
    while (first < last) 
    {
        std::swap(*first, *last); // Swap the values ​​that are within the respective variable addresses
        first += 1;
        last -= 1;
    }
}

}
#endif
