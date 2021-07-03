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
 * @param first Ponteiro para o primeiro elemento do intervalo 
 * @param last Ponteiro para a posição após o último elemento do intervalo
 * @param eq Uma função que retorna true se o elemento é igual ao segundo, ou falso caso contrário
 * 
 * @return Um iterator para o elemento logo após o último elemento do range após o processamento
 */
template<class InputIt, class Equal>
InputIt unique( InputIt first, InputIt last, Equal eq )
{
    // To resolve the issue, three intervals were created:
    // 1. [first, slow): in this range we have the values ​​that were approved in processing
    // 2. [slow, fast): in this range we have the values ​​that were rejected in processing
    // 3. [fast, last): in this range we have the values ​​that will be processed/evaluated
    
    auto slow = first;
    auto fast = first;
    InputIt auxiliary;
    bool repeated; // logical value that indicates whether the value is repeated.
    while (fast != last) 
    {
        auxiliary = first;
        repeated = false;
        // We go through the entire range of approved values ​​to check if the value sought is not in there or if it is
        while(auxiliary != slow) {
            if (eq(*fast, *auxiliary))
            {
                repeated = true;
            }
            auxiliary++;
        }
        // If it is not repeated, we pass the value to the approved range. And we update the range,
        // increasing the size and adding the new element
        if (repeated == false) {
            *slow = *fast;
            slow++;
        }
        fast++;
    }
    return slow;
}

}
#endif
