#ifndef TERNARY_SEARCH_TREE_TERNARY_SEARCH_TREE_IPP_
#define TERNARY_SEARCH_TREE_TERNARY_SEARCH_TREE_IPP_

#include "ternary_search_tree/ternary_search_tree.hpp"

#include <vector>

namespace eda {

namespace ternary_search_tree {

template <typename T>
void TernarySearchTree<T>::insert(std::string& val, int& index, ts_node<T>*& temp, T& data) {
	if (index == val.length()) {
            if (temp == nullptr) {
                temp = new ts_node<T>(true, data);
            }
            else {
                temp->is_Final = true;
                temp->disk_pos.push_back(data);
            }
            return;
        }
        if (temp == nullptr) {
            temp = new ts_node<T>(val[index]);
        }

        if (temp->no_val) {
            temp->val = val[index];
            temp->no_val = false;
            index++;
            insert(val, index, temp->middle, data);
        }
        else if (val[index] < temp->val) {
            insert(val, index, temp->left, data);
        }
        else if (val[index] == temp->val) {
            index++;
            insert(val, index, temp->middle, data);
        }
        else {
            insert(val, index, temp->right, data);
        }
}

template <typename T>
void TernarySearchTree<T>::insert(std::string val, T data) {
	if (root == nullptr) {
            root = new ts_node<T>(val[0]);
        }
        int index = 0;
        insert(val, index, root, data);
}

template <typename T>
std::vector<T> TernarySearchTree<T>::exact_match(std::string& serachval, int& index, ts_node<T>*& tsn) {
	vector <T> result;
        if (!tsn) { return result; }

        if (index == searchval.length()) {
            if (tsn->is_Final) {
                return tsn->disk_pos;
            }
            else {
                return result;
            }
        }

        if (searchval[index] < tsn->val) {
            return exact_match(searchval, index, tsn->left);
        }
        else if (searchval[index] == tsn->val) {
            index++;
            return exact_match(searchval, index, tsn->middle);
        }
        else {
            return exact_match(searchval, index, tsn->right);
        }
}

template <typename T>
std::vector<T> TernarySearchTree<T>::exact_match(std::string searchval) {
	int index = 0;
    return exact_match(searchval, index, root);
}

template <typename T>
std::vector<T> TernarySearchTree<T>::partial_match(ts_node<T>*& tsm, std::string partialword) {
	vector<T> result;
	if (tsn == nullptr) { return result; }
	vector<T> vec0 = partial_match_find_words(tsn->left, partialword);
	vector<T> vec2 = partial_match_find_words(tsn->right, partialword);

	if (tsn->is_Final) {
		result.insert(result.end(), tsn->disk_pos.begin(), tsn->disk_pos.end());
	}
	partialword.push_back(tsn->val);

	vector<T> vec1 = partial_match_find_words(tsn->middle, partialword);
	result.insert(result.end(), vec0.begin(), vec0.end());
	result.insert(result.end(), vec1.begin(), vec1.end());
	result.insert(result.end(), vec2.begin(), vec2.end());

	return result;
}

template <typename T>
std::vector<T> TernarySearchTree<T>::partial_match(std::string searchval) {
	ts_node<T>* temp = root;
	string searchword = {};
	vector <string> result;
	for (int i = 0; i < searchval.length(); i++) {
		if (temp == nullptr) { return result; }
		if (searchval[i] < temp->val) {
			temp = temp->left;
		}
		else if (searchval[i] == temp->val) {
			searchword.push_back(temp->val);
			temp  = temp->middle;
		}
		else {
			temp = temp->right;
		}
	}
	return partial_match_find_words(temp, searchword);
}

template <typename T>
long long TernarySearchTree<T>::size(ts_node<T>* tsn) {
	if (!tsn) { return 0; }
	int currval = 0;
	currval += size(tsn->left);
	currval += size(tsn->middle);
	currval += size(tsn->right);

	return currval + 1;
}

template <typename T>
long long TernarySearchTree<T>::size() {
	ts_node<T>* temp = root;
    return size(temp);
}

template <typename T>
void TernarySearchTree<T>::print(ts_node<T>* tsn, std::string partialword) {
	if (!tsn) { return; }

	print(tsn->left, partialword);

	string prev = partialword;
	if (tsn->is_Final) cout << partialword << endl;
	if (!tsn->no_val) partialword.push_back(tsn->val);
	print(tsn->middle, partialword);

	print(tsn->right, prev);
}

template <typename T>
void TernarySearchTree<T>::print() {
	ts_node<T>* temp = root;
	string partialword = {};
	print(temp, partialword);
}

} // namespace ternary_search_tree

} // namespace eda

#endif // TERNARY_SEARCH_TREE_TERNARY_SEARCH_TREE_IPP_
