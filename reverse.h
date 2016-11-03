#pragma once

#include "node.h"

template <typename List, typename Prev>
struct reverse_impl
{
	typedef typename reverse_impl<typename List::next, node<List::data, Prev> >::result result;
};

template <typename Prev>
struct reverse_impl<nil, Prev>
{
	typedef Prev result;
};

template <typename List>
struct reverse
{
	typedef typename reverse_impl<List, nil>::result result;
};
