#ifndef RADIX_TREE_RADIX_TREE_IPP_
#define RADIX_TREE_RADIX_TREE_IPP_

#include "string_index/string_index.hpp"

namespace eda {

namespace radix_tree {

template <typename T>
void RadixTree<T>::insert(std::string, T) {
	// TODO: implement insertion method
}

template <typename T>
std::vector<T> RadixTree<T>::exact_match(std::string) {
	// TODO: implement exact match search

	return {};
}

template <typename T>
std::vector<T> RadixTree<T>::partial_match(std::string) {
	// TODO: implement partial match search

	return {};
}

template <typename T>
long long RadixTree<T>::size() {
	// TODO: implement size retrieval

	return 0;
}

template <typename T>
void RadixTree<T>::print() {
	// TODO: implement print method
}

} // namespace radix_tree

} // namespace eda

#endif // RADIX_TREE_RADIX_TREE_IPP_
