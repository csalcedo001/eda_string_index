#ifndef TRIE_TRIE_HPP_
#define TRIE_TRIE_HPP_

#include "base_trie.hpp"
#include "base_node.hpp"
#include "node.hpp"

namespace eda {

namespace trie {

template <typename T>
class Trie : public BaseTrie<T, Node<T> > { };

} // namespace trie 

} // namespace eda

#endif // TRIE_TRIE_HPP_
