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
 * @param first1 Ponteiro para o primeiro elemento do range
 * @param last1 Ponteiro para o último elemento do range
 * @param first2 Ponteiro para o primeiro elemento do range que deve ser levado em consideração para a comparação
 * @param last2 Ponteiro para o último elemento do range que deve ser levado em consideração para a comparação
 * @param eq Uma função que retorna true se o elemento é igual ao segundo, ou falso caso contrário
 * 
 * @return Verdadeiro se os ranges são iguais, falso caso contrário
 */
template<class InputIt1, class InputIt2, class Equal>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, Equal eq)
{
    while (first1 < last1) 
    {
        if(!eq(*first1, *first2)) 
        {
            return false;
        }
        first1 += 1;
        first2 += 1;
    }
    return true;
}

template<class InputIt1, class InputIt2, class Equal>
bool equal(InputIt1 first1, InputIt1 last1,
           InputIt2 first2, InputIt2 last2,
           Equal eq )
{
    while (first1 < last1) 
    {
        if(!eq(*first1, *first2)) 
        {
            return false;
        }
        first1 += 1;
        first2 += 1;
    }
    return true;
}

}
#endif
