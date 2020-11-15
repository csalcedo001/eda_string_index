#ifndef RADIX_TREE_RADIX_TREE_HPP_
#define RADIX_TREE_RADIX_TREE_HPP_

#include "string_index/string_index.hpp"

namespace eda {

namespace radix_tree {

template <typename T>
class RadixTree : public string_index::StringIndex<T> {
protected:
    std::vector <Node<T>*> prefix;

    void recorrerRecursivo(Node<T>* temp, const std::string& word);

public:
	void insert(const std::string& content, std::pair <int, int> posicion);
	void exact_match(std::string);
	void partial_match(const std::string& word);
	long long size();
	void print();
};

} // namespace radix_tree

} // namespace eda

#include "radix_tree/impl/radix_tree.ipp"

#endif // RADIX_TREE_RADIX_TREE_HPP_
