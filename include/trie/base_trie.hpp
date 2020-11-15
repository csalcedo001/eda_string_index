#ifndef TRIE_BASE_TRIE_HPP_
#define TRIE_BASE_TRIE_HPP_

#include <vector>
#include <optional>

#include "string_index/string_index.hpp"
#include "trie/base_node.hpp"

namespace eda {

namespace trie {

template <typename T, class Node>
class BaseTrie : public string_index::StringIndex<T> {
protected:
	Node *head_;
	int size_;

public:
	BaseTrie();
	~BaseTrie();

	void insert(std::string, T);
	std::vector<T> exact_match(std::string);
	std::vector<T> partial_match(std::string);
	long long size();
	void print();

protected:
	void print(Node *, int level);
	void kill(Node *);
	long long size(Node *);
};

} // namespace trie

} // namespace eda

#include "trie/impl/base_trie.ipp"

#endif // TRIE_BASE_TRIE_HPP_
