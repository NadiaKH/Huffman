#ifndef HUFFMAN_CODE_H
#define HUFFMAN_CODE_H

#include <string>
#include <unordered_map>

#include "types.h"
#include "huffman_tree.h"
#include "tree_stack.h"

template <typename T>
struct HuffmanCode {
    HuffmanCode(HuffmanTree<T> & tree) {
        init(tree);
    }
    
    std::string operator[](T ch) {
        auto it = m_umap.find(ch);
        if (it == m_umap.end())
            return std::string();
        (*it).second;
    }
    
private:
    std::unordered_map<T, std::string> m_umap;
    void init(HuffmanTree<T> & tree);
    Node<T> * NextNode(TreeStack<T> & st);
};


template <typename T>
Node<T> * HuffmanCode<T>::NextNode(TreeStack<T> & st) {
    if (st.pushLeftBranch())
        return st.top();
    if (st.pushNextRight())
        return st.top();
    return nullptr;
}


template <typename T>
void HuffmanCode<T>::init(HuffmanTree<T> & tree) {
    TreeStack st(tree.getRoot());

    Node<T> * node = nullptr;
    while((node = NextNode(st))) {
        m_umap[node->getChar()] = st.getCode();
    }
}

#endif // HUFFMAN_CODE_H
