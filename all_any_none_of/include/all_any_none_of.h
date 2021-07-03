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
 */
template<class InputIt, class UnaryPredicate>
bool all_of(InputIt first, InputIt last, UnaryPredicate p)
{
    if (first == last)  {
        return false;
    }
    while (first < last) {
        if (!p(*first)) {
            return false;
        }
        first += 1;
    }
    return true;
}

/*! 
 * @param first Ponteiro para o primeiro elemento do range
 * @param last Ponteiro para o último elemento do range
 * @param p Uma função que retorna true quando uma determinada condição é satisfeita ou falso caso contrário
 */
template<class InputIt, class UnaryPredicate>
bool any_of(InputIt first, InputIt last, UnaryPredicate p)
{
    while (first < last) {
        if (p(*first)) {
            return true;
        }
        first += 1;
    }
    return false;
}

/*! 
 * @param first Ponteiro para o primeiro elemento do range
 * @param last Ponteiro para o último elemento do range
 * @param p Uma função que retorna true quando uma determinada condição é satisfeita ou falso caso contrário
 */
template<class InputIt, class UnaryPredicate>
bool none_of(InputIt first, InputIt last, UnaryPredicate p)
{
    while (first < last) {
        if (p(*first)) {
            return false;
        }
        first += 1;
    }
    return true;
}

}
#endif
