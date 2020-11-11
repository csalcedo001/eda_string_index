#ifndef TRIE_BASE_NODE_IPP_
#define TRIE_BASE_NODE_IPP_

#include "trie/base_node.hpp"

#include <vector>

#include "trie/base_trie.hpp"

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
void BaseNode<T, Node>::recursive_values(std::vector<T> &result) {
	result.insert(result.end(), this->values_.begin(), this->values_.end());

	for (auto child : this->children_) {
		if (child != nullptr) {
			child->recursive_values(result);
		}
	}
}

template <typename T, typename Node>
bool BaseNode<T, Node>::is_terminal() {
	return !this->values_.empty();
}

} // namespace trie 

} // namespace eda

#endif // TRIE_BASE_NODE_IPP_
