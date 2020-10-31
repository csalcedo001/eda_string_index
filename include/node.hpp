#ifndef TRIE_NODE_HPP_
#define TRIE_NODE_HPP_

#include <array>

#include "base_node.hpp"

namespace eda {

namespace trie {

template <typename T>
class Node : public BaseNode<T, Node<T> > { };

} // namespace trie 

} // namespace eda

#endif // TRIE_NODE_HPP_
