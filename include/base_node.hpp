#ifndef TRIE_BASE_NODE_HPP_
#define TRIE_BASE_NODE_HPP_

#include <array>
#include <vector>

#define NUM_LETTERS 26

namespace eda {

namespace trie {

template <typename T, typename Node>
class BaseNode {
public:
	char key_;
	std::array<Node *, 2 * NUM_LETTERS> children_;
	std::vector<T> values_;

public:
	BaseNode(char);

	Node *get_node(char);
};

} // namespace trie 

} // namespace eda

#include "impl/base_node.ipp"

#endif // TRIE_BASE_NODE_HPP_
