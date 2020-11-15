#ifndef RADIX_NODE_IPP_
#define RADIX_NODE_IPP_

#include "radix_tree/radix_node.hpp"

#include <vector>

#include "radix_tree/radix_tree.hpp"

namespace eda {
    namespace radix_tree {
        template <typename T, typename Node>
        BaseNode<T, Node>::BaseNode(const std::string& content, std::pair <int, int> pos) {
            this->content = content;
            this->prefix.resize(26);
            std::fill(this->prefix.begin(), this->prefix.end(), nullptr);
            this->isTerminal = true;
            this->posicion.push_back(pos);
        }
    }
}

#endif // RADIX_NODE_IPP_