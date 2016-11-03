#include <iostream>
#include "node.h"
#include "is_nil.h"
#include "print.h"
#include "push_back.h"
#include "reverse.h"
#include "insert.h"
#include "erase.h"
#include "pop_back.h"
#include "push_front.h"
#include "pop_front.h"
#include "size.h"

typedef node<1, nil> list_1;
typedef node<1, node<2, nil>> list_12;
typedef node<1, node<2, node<3, nil>>> list_123;
typedef node<3, node<2, node<1, nil>>> list_321;
typedef node<1, node<2, node<3, node <4, nil>>>> list_1234;


#if defined(_MSC_VER)                                                 
 || defined(__GNUC__) && __GNUC__ < 6
// MSVC and GCC (pre 6.x) don't support C++17 terse static assert
#define static_assert(x) static_assert(x, #x)
#endif

//static_assert(list_1::data == 1   && is_nil<list_1::next>::value);
//static_assert(list_12::data == 1  && list_12::next::data == 2  && is_nil<list_12::next::next>::value);
//static_assert(list_123::data == 1 && list_123::next::data == 2 && list_123::next::next::data == 3 && is_nil<list_123::next::next::next>::value);

//static_assert((std::is_same<list_12, push_back<list_1, 2>::result>::value));
//static_assert((std::is_same<list_123, push_back<list_12, 3>::result>::value));

int main()
{
    using std::endl;
    using std::cout;
    //cout << list_123() << endl;
    
    typedef typename push_front < list_123, 0 >::result list_0123;    
    typedef typename insert < list_0123, 1, 4 >::result list_04123;              
    typedef typename reverse < list_1234 >::result list_4321;
    typedef typename erase < list_04123, 2 >::result list_0423;
    typedef typename pop_front < list_321 >::result list_21;
    typedef typename pop_back < list_04123 >::result list_0412;
    typedef typename insert < list_123, 3, 7 >::result list_1237;

    /*
    typedef typename pop_back < nil >::result err_pop_back;
    typedef typename pop_front < nil >::result err_pop_front;
    typedef typename insert < list_123, 4, 9 >::result err::out_of_bound_insert;
    typedef typename erase < list_123, 3 >::result err::out_of_bound_erase;
    */
    
    cout << list_1237() << " expected [1, 2, 3, 7]" << endl;
    std::cout << list_0123() << " expected [0, 1, 2, 3]" << std::endl;
    cout << list_4321() << " expected [4, 3, 2, 1]" << endl;
    cout << list_04123() << " expected [0, 4, 1, 2, 3]" << endl;
    cout << list_0423() << " expected [0, 4, 2, 3]" << endl;
    cout << size < list_04123 >::result << " expected 5" << endl;
    cout << list_21() << " expected [2, 1]" << endl;
    cout << list_0412() << " expected [0, 4, 1, 2]" << endl;
}
