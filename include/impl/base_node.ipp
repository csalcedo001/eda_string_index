#ifndef TRIE_NODE_IPP_
#define TRIE_NODE_IPP_

#include "base_node.hpp"

#include "base_trie.hpp"

namespace eda {

namespace trie {

template <typename T, typename Node>
BaseNode<T, Node>::BaseNode(char key) : key_(key) {
	for (int i = 0; i < this->children_.size(); i++) {
		this->children_[i] = nullptr;
	}
}

} // namespace trie 

} // namespace eda

#endif // TRIE_NODE_IPP_
