#ifndef TRIE_BASE_TRIE_HPP_
#define TRIE_BASE_TRIE_HPP_

#include <vector>
#include <optional>

#include "base_node.hpp"

namespace eda {

namespace trie {

template <typename T, typename Node>
class BaseTrie {
protected:
	Node *head_;
	int size_;

public:
	BaseTrie();
	~BaseTrie();

	void insert(std::string, T);
	std::vector<T> get(std::string);
	void remove(std::string);

	long long size();
	void print();

protected:
	void print(Node *, int level);
	void kill(Node *);
};

} // namespace trie

} // namespace eda

#include "impl/base_trie.ipp"

#endif // TRIE_TRIE_HPP_
