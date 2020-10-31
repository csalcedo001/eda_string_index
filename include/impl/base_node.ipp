#ifndef TRIE_BASE_NODE_IPP_
#define TRIE_BASE_NODE_IPP_

#include "base_node.hpp"

#include "base_trie.hpp"

namespace eda {

namespace trie {

template <typename T, typename Node>
BaseNode<T, Node>::BaseNode(char key) :
	key_(key)
{
	for (int i = 0; i < this->children_.size(); i++) {
		this->children_[i] = nullptr;
	}
}

template <typename T, typename Node>
Node *&BaseNode<T, Node>::child_get(char key) {
	return this->children_[key];
}

template <typename T, typename Node>
Node *&BaseNode<T, Node>::child_set(char key) {
	return this->children_[key] = new Node(key);
}

template <typename T, typename Node>
bool BaseNode<T, Node>::is_terminal() {
	return !this->values_.empty();
}

} // namespace trie 

} // namespace eda

#endif // TRIE_BASE_NODE_IPP_
