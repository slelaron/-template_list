#pragma once

#include "node.h"

template <typename List>
struct size
{
	static const size_t result = size <typename List::next>::result + 1;
};

template <>
struct size <nil>
{
	static const size_t result = 0;
};
