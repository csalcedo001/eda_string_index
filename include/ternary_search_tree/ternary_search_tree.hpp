#ifndef TERNARY_SEARCH_TREE_TERNARY_SEARCH_TREE_HPP_
#define TERNARY_SEARCH_TREE_TERNARY_SEARCH_TREE_HPP_

#include <vector>

#include "string_index/string_index.hpp"

namespace eda {

namespace ternary_search_tree {

template <typename T>
class TernarySearchTree : public string_index::StringIndex<T> {

private:
    template <typename T>
    struct ts_node {
        char val;
        bool is_Final;
        bool no_val;
        ts_node<T>* left;
        ts_node<T>* middle;
        ts_node<T>* right;
        vector<T> disk_pos;

        ts_node(bool Final, T& data) {
            this->is_Final = Final;
            this->no_val = true;
            disk_pos.push_back(data);
            this->left = nullptr; this->right = nullptr; this->middle = nullptr;
        }
        ts_node(char val) {
            this->val = val;
            this->is_Final = false;
            this->no_val = false;
            this->left = nullptr; this->right = nullptr; this->middle = nullptr;
        }
    };

    ts_node<T>* root;

public:
    TernarySearchTree() {
        this->root = nullptr;
    }

    void insert(std::string&, int&, ts_node<T>*&, T&);
	void insert(std::string, T);
    std::vector<T> exact_match(std::string&, int&, ts_node<T>*&);
	std::vector<T> exact_match(std::string);
    std::vector<T> partial_match(ts_node<T>*&, std::string);
	std::vector<T> partial_match(std::string);
    long long size(ts_node<T>*);
	long long size();
    void print(ts_node<T>*, std::string);
	void print();
};

} // namespace ternary_search_tree

} // namespace eda

#include "ternary_search_tree/impl/ternary_search_tree.ipp"

#endif // TERNARY_SEARCH_TREE_TERNARY_SEARCH_TREE_HPP_
