#ifndef TRIE_NODE_IPP_
#define TRIE_NODE_IPP_

#include "node.hpp"

namespace eda {

namespace trie {

template <typename T>
Node<T>::Node(char key) : BaseNode<T, Node<T> >(key) { }

} // namespace trie 

} // namespace eda

#endif // TRIE_NODE_IPP_
