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
 * Exemplo de documentação seguindo o formato Doxygen
 *
 * @tparam Itr iterator para o range.
 * @tparam Compare o tipo de uma função bool(const T &a, const T &b)
 *
 * @param first Ponteiro para o primeiro elemento do range
 * @param last Ponteiro para a posição logo após o último elemento do range
 * @param cmp A função de comparação que retorna true quando o primeiro parâmetro é menor do que o segundo
 *
 * @return Um std::pair contendo o menor e maior elemento, nesta ordem
 *
 */
template <typename Itr, typename Compare >
std::pair<Itr, Itr> minmax( Itr first, Itr last, Compare cmp )
{
    // TODO
    // Already initialize the variable with the first element of the array.
    Itr bigger = first; // The biggest element.
    Itr smaller = first; // The smallest element.

    while(first != last) {
        if( cmp(*first, *smaller) ) // Compare if the first element is smaller than the second
        {
            smaller = first;
        }
        if(cmp(*bigger, *first)) // Compare if the first element is smaller than the second
        {
            bigger = first;
        } 
        if (*first == *bigger) { // Get the last position of the biggest element.
            bigger = first;
        }
        first += 1;
    }
    if (last == first + 1) {
        return std::make_pair( first, first );
    } else {
        return std::make_pair( smaller, bigger );
    }
}

}
#endif
