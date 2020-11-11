#ifndef TRIE_BASE_NODE_HPP_
#define TRIE_BASE_NODE_HPP_

#include <array>
#include <vector>

#define SIZE_ALPHABET 128 // All characters

namespace eda {

namespace trie {

template <typename T, typename Node>
class BaseNode {
public:
	char key_;
	std::array<Node *, SIZE_ALPHABET> children_;
	std::vector<T> values_;

public:
	BaseNode(char);

	Node *&child_get(char);
	Node *&child_set(char);
	void recursive_values(std::vector<T> &);
	bool is_terminal();
};

} // namespace trie 

} // namespace eda

#include "trie/impl/base_node.ipp"

#endif // TRIE_BASE_NODE_HPP_
