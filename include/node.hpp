#ifndef TRIE_NODE_HPP_
#define TRIE_NODE_HPP_

#include "base_node.hpp"

namespace eda {

namespace trie {

template <typename T>
class Node : public BaseNode<T, Node<T> > {
public:
	Node(char);
};

} // namespace trie 

} // namespace eda

#include "impl/node.ipp"

#endif // TRIE_NODE_HPP_
