#ifndef TRIE_BASE_TRIE_IPP_
#define TRIE_BASE_TRIE_IPP_

#include "trie/base_trie.hpp"

#include <iostream>
#include <optional>

#include "trie/base_node.hpp"

namespace eda {

namespace trie {

template <typename T, class Node>
BaseTrie<T, Node>::BaseTrie () :
	head_(new Node('\0')),
	size_(0)
{ }

template <typename T, class Node>
BaseTrie<T, Node>::~BaseTrie () {
	this->kill(this->head_);
}

template <typename T, class Node>
void BaseTrie<T, Node>::insert(std::string index, T value) {
	if (index.length() == 0) return;

	Node *curr = this->head_, *prev;

	int i = 0;

	while (true) {
		prev = curr;
		curr = prev->child_get(index[i]);

		if (i >= index.size()) break;

		if (curr == nullptr) {
			curr = prev->child_set(index[i]);
		}

		i++;
	}

	prev->values_.push_back(value);
	this->size_++;
}

template <typename T, class Node>
long long BaseTrie<T, Node>::size() {
	return this->size_;
}

template <typename T, class Node>
std::vector<T> BaseTrie<T, Node>::exact_match(std::string index) {
	Node *curr = this->head_, *prev;

	int i = 0;

	while (true) {
		prev = curr;
		curr = prev->child_get(index[i]);

		if (i >= index.size()) break;

		if (curr == nullptr) return {};

		i++;
	}

	return prev->values_;
}

template <typename T, class Node>
std::vector<T> BaseTrie<T, Node>::partial_match(std::string index) {
	Node *curr = this->head_, *prev;

	int i = 0;

	while (true) {
		prev = curr;
		curr = prev->child_get(index[i]);

		if (i >= index.size()) break;

		if (curr == nullptr) return {};

		i++;
	}

	return prev->values_;
}

template <typename T, class Node>
void BaseTrie<T, Node>::print() {
	std::cout << "Element count: " << this->size_ << std::endl;

	for (auto child : this->head_->children_) {
		this->print(child, 0);
	}
}

template <typename T, class Node>
void BaseTrie<T, Node>::print(Node *node, int level) {
	if (node != nullptr) {
		for (int i = 0; i < level; i++) {
			std::cout << "    ";
		}
		std::cout << node->key_;

		if (node->is_terminal()) {
			std::cout << "*" << std::endl;

			for (auto value : node->values_) {
				for (int i = 0; i < level; i++) {
					std::cout << "    ";
				}

				std::cout << value << std::endl;
			}

			std::cout << std::endl;
		}
		else {
			std::cout << std::endl;
		}
		
		for (auto child : node->children_) {
			this->print(child, level + 1);
		}
	}
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
