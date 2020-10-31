#ifndef TRIE_BASE_TRIE_IPP_
#define TRIE_BASE_TRIE_IPP_

#include "base_trie.hpp"

#include "base_node.hpp"

namespace eda {

namespace trie {

template <typename T, class Node>
BaseTrie<T, Node>::BaseTrie () : head_(nullptr) { }

template <typename T, class Node>
BaseTrie<T, Node>::~BaseTrie () {
	this->kill(this->head_);
}

template <typename T, class Node>
void BaseTrie<T, Node>::insert(std::string index, T value) {
	if (index.length() == 0) return;

	Node *prev, *current;

	current = &this->head_;

	for (char c : index) {
		if (*current == nullptr) {
			*current = new Node(c);
		}

		current = &(*current)->get_node(c);
	}

	(*current)->values_.push_back(value);
}

template <typename T, class Node>
void BaseTrie<T, Node>::kill(Node *node) {
	if (node != nullptr) {
		for (auto child : node->children_) {
			this->kill(child);
		}
	}
}

} // namespace trie 

} // namespace eda

#endif // TRIE_BASE_TRIE_IPP_
