#ifndef TERNARY_SEARCH_TREE_TERNARY_SEARCH_TREE_HPP_
#define TERNARY_SEARCH_TREE_TERNARY_SEARCH_TREE_HPP_

#include <vector>

#include "string_index/string_index.hpp"

namespace eda {

namespace ternary_search_tree {

template <typename T>
class TernarySearchTree : public string_index::StringIndex<T> {
public:
	void insert(std::string, T);
	std::vector<T> exact_match(std::string);
	std::vector<T> partial_match(std::string);
	long long size();
	void print();
};

} // namespace ternary_search_tree

} // namespace eda

#include "ternary_search_tree/impl/ternary_search_tree.ipp"

#endif // TERNARY_SEARCH_TREE_TERNARY_SEARCH_TREE_HPP_
