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
 * @param first Ponteiro para o primeiro elemento do intervalo a ser considerado
 * @param last Ponteiro para o elemento logo após o último elemento do intervalo a ser considerado.
 * @param p Uma função que retorna true quando uma determinada condição é satisfeita ou falso caso contrário
 * 
 * @return Um iterator apontando para o elemento logo após o último elemento no range reordenado que satisfaz o predicado
 */
template<class ForwardIt, class UnaryPredicate>
ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPredicate p)
{
    // To resolve the issue, three intervals were created:
    // 1. [first, slow): in this range we have the values ​​that were approved in processing
    // 2. [slow, fast): in this range we have the values ​​that were rejected in processing
    // 3. [fast, last): in this range we have the values ​​that will be processed/evaluated
    
    auto slow = first;
    auto fast = first;
    while (fast != last) 
    {
        // If the value passes the predicate, we place it within the pass range, otherwise we place it in the fail range
        if (p(*fast)) {
            std::swap(*slow, *fast);
            slow++;
        }
        fast++;
    }
    return slow;
}

}
#endif
