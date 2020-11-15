#ifndef TERNARY_SEARCH_TREE_TERNARY_SEARCH_TREE_HPP_
#define TERNARY_SEARCH_TREE_TERNARY_SEARCH_TREE_HPP_

#include <vector>

#include "string_index/string_index.hpp"

namespace eda {

namespace ternary_search_tree {

#include <iostream>
#include <fstream>

using namespace std;

class ternary_serach_tree {

private:

    struct ts_node {
        char val;
        bool is_Final;
        bool no_val;
        ts_node* left;
        ts_node* middle;
        ts_node* right;
        vector <long long> disk_pos;

        ts_node(bool Final, long long& data) {
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

    ts_node* root;
    string datafilename;

public:

    ternary_serach_tree(const string& datafilename) {
        this->root = nullptr;
        this->datafilename = datafilename;
    }

    void insert(const string& val, int& index, ts_node*& temp, long long& data) {

        if (index == val.length()) {
            if (temp == nullptr) {
                temp = new ts_node(true, data);
            }
            else {
                temp->is_Final = true;
                temp->disk_pos.push_back(data);
            }
            return;
        }
        if (temp == nullptr) {
            temp = new ts_node(val[index]);
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

    void insert(const string& val, long long& data) {
        if (root == nullptr) {
            root = new ts_node(val[0]);
        }
        int index = 0;
        insert(val, index, root, data);
    }

    vector <long long> exact_match(string& searchval, int& index, ts_node*& tsn) {
        vector <long long> result;
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

    vector <string> exact_match(string searchval) {
        int index = 0;
        vector <long long> disk_pos = exact_match(searchval, index, root);
        vector <string> result;
        fstream file(datafilename);
        string line;
        for (int i = 0; i < disk_pos.size(); i++) {
            file.seekg(disk_pos[i], ios::beg);
            getline(file, line, '\n');
            size_t found = line.find_last_of("/\\");
            result.push_back(line.substr(0, found));
        }
        return result;
    }

    vector <long long> partial_match_find_words(ts_node* tsn, string partialword) {
        vector <long long> result;
        if (tsn == nullptr) { return result; }
        vector <long long> vec0 = partial_match_find_words(tsn->left, partialword);
        vector <long long> vec2 = partial_match_find_words(tsn->right, partialword);

        if (tsn->is_Final) {
            //result.push_back(partialword);
            result.insert(result.end(), tsn->disk_pos.begin(), tsn->disk_pos.end());
        }
        partialword.push_back(tsn->val);

        vector <long long> vec1 = partial_match_find_words(tsn->middle, partialword);
        result.insert(result.end(), vec0.begin(), vec0.end());
        result.insert(result.end(), vec1.begin(), vec1.end());
        result.insert(result.end(), vec2.begin(), vec2.end());

        return result;
    }

    vector <string> partial_match(string searchval) {
        ts_node* temp = root;
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
        vector <long long> disk_pos = partial_match_find_words(temp, searchword);
        fstream file(datafilename);
        string line;
        for (int i = 0; i < disk_pos.size(); i++) {
            file.seekg(disk_pos[i], ios::beg);
            getline(file, line, '\n');
            size_t found = line.find_last_of("/\\");
            result.push_back(line.substr(0, found));
        }
        return result;

    }

    long long size(ts_node* tsn) {
        if (!tsn) { return 0; }
        int currval = 0;
        currval += size(tsn->left);
        currval += size(tsn->middle);
        currval += size(tsn->right);

        return currval + 1;
    }

    long long size() {
        ts_node* temp = root;
        return size(temp);
    }

    void print(ts_node* tsn, string partialword) {
        if (!tsn) { return; }

        print(tsn->left, partialword);

        string prev = partialword;
        if (tsn->is_Final) cout << partialword << endl;
        if (!tsn->no_val) partialword.push_back(tsn->val);
        print(tsn->middle, partialword);

        print(tsn->right, prev);

    }

    void print() {
        ts_node* temp = root;
        string partialword = {};
        print(temp, partialword);
    }

    void read_file() {
        fstream file(datafilename);
        string line;
        long long init_dir;
        while(file.peek()!= EOF){
            init_dir = file.tellg();
            getline(file, line, '\n');
            size_t found = line.find_last_of("/\\");
            insert(line.substr(found+1), init_dir);
        }
    }

};

} // namespace ternary_search_tree

} // namespace eda

#include "ternary_search_tree/impl/ternary_search_tree.ipp"

#endif // TERNARY_SEARCH_TREE_TERNARY_SEARCH_TREE_HPP_
