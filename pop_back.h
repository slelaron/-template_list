#pragma once

#include "node.h"

template <typename List, typename Child>
struct pop_back_impl
{
	typedef node<List::data, typename pop_back_impl <typename List::next, typename List::next::next>::result> result;
};

template <typename List>
struct pop_back_impl<List, nil>
{
	typedef nil result;
};

template <typename List>
struct pop_back
{
	typedef typename pop_back_impl <List, typename List::next>::result result;
};
