#ifndef EDA_STRING_INDEX_RADIXTREE_H
#define EDA_STRING_INDEX_RADIXTREE_H

#ifndef RADIX_TREE_RADIXTREE_H
#define RADIX_TREE_RADIXTREE_H

#include <vector>
#include <string>

template <typename T>
class Node {
public:
    std::string content;
    std::vector <Node<T>*> prefix;
    bool isTerminal{};

    explicit Node(const std::string& content) {
        this->content = content;
        this->prefix.resize(26);
        std::fill(this->prefix.begin(), this->prefix.end(), nullptr);
        this->isTerminal = true;
    }
};

template <typename T, const int size = 26>
class RadixTree {
private:
    std::vector <Node<T>*> prefix;

public:
    RadixTree() {
        this->prefix.resize(size);
        std::fill(this->prefix.begin(), this->prefix.end(), nullptr);
    }

    void insert(const std::string& content) {
        //Cuando la primera letra aún no está indexada
        if (this->prefix[(unsigned int)(unsigned char)content[0]-97] == nullptr) {
            auto* temp = new Node<T>(content);
            this->prefix[(unsigned int)(unsigned char)content[0]-97] = temp;
        } else { //Si ya está indexada, busca en el vector de nodos
            unsigned int index = 0;
            auto temp = this->prefix[(unsigned int) (unsigned char) content[0] - 97];
            //Recorre los nodos hasta que haya recorrido todos los caracteres del string
            while (index <= content.length()-1) {
                //Avanza el index mientras los caracteres sean iguales al nodo que se está evaluando
                while (content[index] == temp->content[index] && index < temp->content.length() - 1) {
                    index++;
                }
                //Si aún no se termina de recorrer el contenido del nodo, se separa la parte diferente
                if (index < temp->content.length()) {
                    auto newNode = new Node<T>(temp->content.substr(index));
                    std::string nuevo = temp->content.substr(0, index);
                    temp->content = nuevo;
                    temp->prefix[(unsigned int) (unsigned char) newNode->content[0] - 97] = newNode;
                }
                //Busca en el vector de nodos si el caracter ya está indexado
                if (temp->prefix[(unsigned int) (unsigned char) content[index] - 97] == nullptr) {
                    auto newNode = new Node<T>(content.substr(index));
                    temp->prefix[(unsigned int) (unsigned char) content[index] - 97] = newNode;
                    return;
                } else { //Si ya está indexado, se avanza hasta ese nodo
                    temp = temp->prefix[(unsigned int) (unsigned char) content[index] - 97];
                }
            }
        }
    }
};

#endif //RADIX_TREE_RADIXTREE_H

#endif //EDA_STRING_INDEX_RADIXTREE_H