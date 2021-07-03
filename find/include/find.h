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
 * @param value O valor a ser comparado na função
 * @param eq Uma função que retorna true se o elemento é igual ao segundo, ou falso caso contrário
 * 
 * @return Um iterator(ou ponteiro) para o primeiro elemento que satisfaz a função eq().
 */
template<class InputIt, class T, class Equal>
InputIt find(InputIt first, InputIt last, const T& value, Equal eq)
{
    while (first < last) {
        if (eq(value, *first)) {
            return first;
        }
        first += 1;
    }
    return last;
}

}
#endif
