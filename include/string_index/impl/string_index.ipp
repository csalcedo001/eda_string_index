#ifndef STRING_INDEX_STRING_INDEX_IPP_
#define STRING_INDEX_STRING_INDEX_IPP_

#include "string_index/string_index.hpp"

#include <iostream>
#include <vector>

namespace eda {

namespace string_index {

// template <typename T, class Node>
// void StringIndex<T, Node>::print() {
// 	std::cout << "Element count: " << this->size() << std::endl;
// 
// 	for (auto child : this->head_->children()) {
// 		this->print(child, 0);
// 	}
// }
// 
// template <typename T, class Node>
// void StringIndex<T, Node>::print(Node *node, int level) {
// 	if (node != nullptr) {
// 		for (int i = 0; i < level; i++) {
// 			std::cout << "    ";
// 		}
// 		std::cout << node->key();
// 
// 		if (node->is_terminal()) {
// 			std::cout << "*" << std::endl;
// 
// 			for (auto value : node->values()) {
// 				for (int i = 0; i < level; i++) {
// 					std::cout << "    ";
// 				}
// 
// 				std::cout << value << std::endl;
// 			}
// 
// 			std::cout << std::endl;
// 		}
// 		else {
// 			std::cout << std::endl;
// 		}
// 		
// 		for (auto child : node->children()) {
// 			this->print(child, level + 1);
// 		}
// 	}
// }
// 
// template <typename T, class Node>
// void StringIndex<T, Node>::kill(Node *node) {
// 	if (node != nullptr) {
// 		for (auto child : node->children()) {
// 			this->kill(child);
// 		}
// 	}
// }

} // namespace string_index

} // namespace eda

#endif // STRING_INDEX_STRING_INDEX_IPP_
