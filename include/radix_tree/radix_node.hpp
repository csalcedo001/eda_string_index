#ifndef RADIX_NODE_HPP_
#define RADIX_NODE_HPP_

namespace eda {
    namespace radix_tree {
        template <typename T, typename Node>
        class BaseNode {
        public:
            std::string content;
            std::vector <Node<T>*> prefix;
            bool isTerminal{};
            std::vector <std::pair <int, int>> posicion;

            explicit Node(const std::string& content, std::pair <int, int> pos);
        };
    }
}

#endif // TRIE_BASE_NODE_HPP_