#pragma once

#include "node.h"

template <typename List>
struct pop_front_impl
{
	typedef node<List::data, typename pop_front_impl <typename List::next>::result> result;
};

template <>
struct pop_front_impl <nil>
{
	typedef nil result;
};

template <typename List>
struct pop_front
{
	typedef typename pop_front_impl<typename List::next>::result result;
};
