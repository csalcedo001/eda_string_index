#ifndef RADIX_TREE_RADIX_TREE_IPP_
#define RADIX_TREE_RADIX_TREE_IPP_

#include "radix_tree/radix_tree.hpp"

namespace eda {

namespace radix_tree {

template <typename T>
RadixTree<T>::RadixTree() {
    this->prefix.resize(26);
    std::fill(this->prefix.begin(), this->prefix.end(), nullptr);
}

template <typename T>
void RadixTree<T>::recorrerRecursivo(BaseNode<T>* temp, const std::string& word) {
    if (temp->isTerminal) {
        std::cout << word << temp->content << ' ';
        for (auto it : temp->posicion) {
            std::cout << it.first << ',' << it.second << ' ';
        }
        std::cout << std::endl;
    }
    for (auto it : temp->prefix) {
        if (it != nullptr) {
            std::string tempWord = word + temp->content;
            recorrerRecursivo(it,tempWord);
        }
    }
}

template <typename T>
void RadixTree<T>::insert(const std::string& content, std::pair <int, int> posicion) {
    //Cuando la primera letra aún no está indexada
    if (this->prefix[(unsigned int)(unsigned char)content[0]-97] == nullptr) {
        auto* temp = new BaseNode<T>(content, posicion);
        this->prefix[(unsigned int)(unsigned char)content[0]-97] = temp;
        totalSize += (sizeof(posicion) + sizeof(content));
    } else { //Si ya está indexada, busca en el vector de nodos
        unsigned int index = 0;
        auto temp = this->prefix[(unsigned int) (unsigned char) content[0] - 97];
        //Recorre los nodos hasta que haya recorrido todos los caracteres del string
        while (index <= content.length()-1) {
            int tempIndex = 0;
            //Avanza el index mientras los caracteres sean iguales al nodo que se está evaluando
            while (content[index] == temp->content[tempIndex] && tempIndex <= temp->content.length() - 1) {
                index++;
                tempIndex++;
            }
            //Si aún no se termina de recorrer el contenido del nodo, se separa la parte diferente
            if (tempIndex < temp->content.length()) {
                auto newNode = new BaseNode<T>(temp->content.substr(tempIndex), temp->posicion[0]);
                totalSize += (sizeof(posicion) + sizeof(content));
                std::string nuevo = temp->content.substr(0, tempIndex);
                temp->content = nuevo;
                temp->isTerminal = false;
                temp->prefix[(unsigned int) (unsigned char) newNode->content[0] - 97] = newNode;
            }
            //Busca en el vector de nodos si el caracter ya está indexado
            if(index == content.length()) return;
            if (temp->prefix[(unsigned int) (unsigned char) content[index] - 97] == nullptr) {
                auto newNode = new BaseNode<T>(content.substr(index), posicion);
                totalSize += (sizeof(posicion) + sizeof(content));
                temp->prefix[(unsigned int) (unsigned char) content[index] - 97] = newNode;
                return;
            } else { //Si ya está indexado, se avanza hasta ese nodo
                temp = temp->prefix[(unsigned int) (unsigned char) content[index] - 97];
            }
        }
    }
}

template <typename T>
void RadixTree<T>::exact_match(std::string) {
    auto temp = this->prefix[(unsigned int)(unsigned char)word[0]-97];
    if (temp == nullptr) {
        std::cout << "Palabra no encontrada" << std::endl;
        return;
    } else {
        int index = 0;
        std::string tempWord;
        while (index <= word.length()-1) {
            if (temp == nullptr) {
                return;
            }
            int tempIndex = 0;
            while (word[index] == temp->content[tempIndex] && tempIndex <= temp->content.length() - 1) {
                index++;
                tempIndex++;
            }
            if (tempIndex < temp->content.length()) {
                return;
            }
            tempWord += temp->content;
            if(index == word.length()) return;
            temp = temp->prefix[(unsigned int) (unsigned char) word[index] - 97];
        }
        for (auto it : temp->posicion) {
            std::cout << it.first << ' ' << it.second << std::endl;
        }
    }
}

template <typename T>
void RadixTree<T>::partial_match(std::string) {
    auto temp = this->prefix[(unsigned int)(unsigned char)word[0]-97];
    if (temp == nullptr) {
        std::cout << "Palabra no encontrada" << std::endl;
        return;
    } else {
        int index = 0;
        std::string tempWord;
        while (index <= word.length()-1) {
            if (temp == nullptr) {
                return;
            }
            int tempIndex = 0;
            while (word[index] == temp->content[tempIndex] && tempIndex <= temp->content.length() - 1) {
                index++;
                tempIndex++;
            }
            if (tempIndex < temp->content.length()) {
                recorrerRecursivo(temp, tempWord);
                return;
            }
            tempWord += temp->content;
            if(index == word.length()) return;
            temp = temp->prefix[(unsigned int) (unsigned char) word[index] - 97];
        }
    }
}

template <typename T>
long long RadixTree<T>::size() {
	// TODO: implement size retrieval

	return 0;
}

template <typename T>
void RadixTree<T>::print() {
	// TODO: implement print method
}

} // namespace radix_tree

} // namespace eda

#endif // RADIX_TREE_RADIX_TREE_IPP_
