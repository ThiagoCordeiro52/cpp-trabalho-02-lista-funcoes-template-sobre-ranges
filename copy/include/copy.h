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
 * @param last Ponteiro para a posição logo após o último elemento do range
 * @param d_first Ponteiro para o inicio do range onde os elementos devem ser copiados
 * 
 * @return Um iterator apontado para a posição logo após o último elemento do range cópia.
 */
template<class InputIt>
InputIt copy(InputIt first, InputIt last, InputIt d_first)
{
    while (first < last) {
        *d_first = *first;
        d_first += 1;
        first += 1;
    }
    return d_first;
}

}
#endif
