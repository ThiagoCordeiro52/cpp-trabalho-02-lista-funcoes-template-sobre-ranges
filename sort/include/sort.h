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
 * @param last Ponteiro para o último elemento do intervalo a ser considerado
 * @param cmp Uma função que retorna true se o elemento é menor do que o segundo, ou falso caso contrário
 * 
 */
template<class ForwardIt, class Comparison>
void sort(ForwardIt first, ForwardIt last, Comparison cmp)
{
    // The implemented algorithm was insertion sort!
    ForwardIt j;
    auto firstFake = first;
    // removed the j = first - 1 because of the entry in while, since you cannot do j >= first. 
    for (; first != last; first++){ // Cycles through all elements.
        auto value = *first;
        j = first;

        // Cycles through all elements before a value to the first element
        while(j != firstFake && cmp(value, *(j-1)))
        {
            *j = *(j-1); 
            j--;
        }
        *j = value;
    }
}
}
#endif
