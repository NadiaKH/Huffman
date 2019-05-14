#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include <vector>


template <typename T>
struct HuffmanTree;


template <typename T>
struct Node {
    Node(size_t indx_left, size_t indx_right, unsigned int freq)
        : m_indx_left(indx_left),
          m_indx_right(indx_right),
          m_freq(freq),
          m_is_leaf(0), 
          treeStorage_(nullptr) {}
    
    Node(T ch, unsigned int freq)
        : m_char(ch),
          m_freq(freq),
          m_is_leaf(1), 
          treeStorage_(nullptr) {}

    unsigned int getFreq() const { return m_freq; }
    T getChar() const { return m_char; }

    Node * left() const{
        if (m_is_leaf || !treeStorage_)
            return nullptr;
        return &(*treeStorage_)[m_indx_left];
    }

    Node * right() const {
        if (m_is_leaf || !treeStorage_)
            return nullptr;
        return &(*treeStorage_)[m_indx_right];
    }
    
private:
    T m_char;
    bool m_is_leaf;
    unsigned int m_freq;
    size_t m_indx_left;
    size_t m_indx_right;
    std::vector<Node<T>> * treeStorage_;
    
    friend HuffmanTree<T>;
};


#endif // NODE_H
