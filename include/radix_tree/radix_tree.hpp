#ifndef RADIX_TREE_RADIX_TREE_HPP_
#define RADIX_TREE_RADIX_TREE_HPP_

#include "string_index/string_index.hpp"

namespace eda {

namespace radix_tree {

template <typename T>
class RadixTree : public string_index::StringIndex<T> {
public:
	void insert(std::string, T);
	std::vector<T> exact_match(std::string);
	std::vector<T> partial_match(std::string);
	long long size();
	void print();
};

} // namespace radix_tree

} // namespace eda

#include "radix_tree/impl/radix_tree.ipp"

#endif // RADIX_TREE_RADIX_TREE_HPP_
