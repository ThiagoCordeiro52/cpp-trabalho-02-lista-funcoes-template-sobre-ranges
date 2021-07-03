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
 * @param p Uma função que retorna true quando uma determinada condição é satisfeita ou falso caso contrário
 * 
 * @return Um iterator apontando para o primeiro elemento do range que satisfaz p
 */
template<class InputIt, class UnaryPredicate>
InputIt find_if(InputIt first, InputIt last, UnaryPredicate p)
{
    while(first < last) {
        if (p(*first)) {
            return first;
        }
        first += 1;
    }
    return last;
}

}
#endif
