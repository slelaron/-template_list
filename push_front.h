#pragma once

#include "node.h"

template <typename List, int Value>
struct push_front
{
	typedef node<Value, typename push_front <typename List::next, List::data>::result> result;
};

template <int Value>
struct push_front <nil, Value> 
{
	typedef node <Value, nil> result;
};
