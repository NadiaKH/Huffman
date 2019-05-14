#ifndef TREE_STACK_H
#define TREE_STACK_H

#include <stack>
#include <string>

#include "node.h"


template<typename T>
struct TreeStack {
    
    TreeStack(Node<T> * root) { nodeStack_.push(root); }
    Node<T> * top(){ return nodeStack_.top(); }
    //bool empty() { return nodeStack_.empty(); }
    //size_t size() {return nodeStack_.size(); }
    std::string getCode() { return strStack_; }
    
    
    bool pushLeftBranch();
    bool pushNextRight();
    
private:
    Node<T> * topLeft() {
        if (nodeStack_.empty()) return nullptr;
        return nodeStack_.top()->left();
    }

    Node<T> * topRight() {
        if (nodeStack_.empty()) return nullptr;
        return nodeStack_.top()->right();
    }

    std::string strStack_;
    std::stack<Node<T>*> nodeStack_;
};


template <typename T>
bool TreeStack<T>::pushLeftBranch() {
    if (nodeStack_.empty()) return false;
    Node<T> * left = nullptr;
    bool stackChanged = false;

    while((left = topLeft())) {
        stackChanged = true;
        nodeStack_.push(left);
        strStack_.push_back('0');
    }
    return stackChanged;
}


template <typename T>
bool TreeStack<T>::pushNextRight(){
    if (nodeStack_.empty()) return false;
    Node<T> * top = nodeStack_.top();
    Node<T> * right = nullptr;

    while(!(right = topRight()) && !strStack_.empty()) {
        strStack_.pop_back();
        nodeStack_.pop();
    }

    if (!right) return false;
    if (right == top) return false;

    nodeStack_.push(right);
    strStack_.push_back('1');

    return true;
}

#endif // TREE_STACK_H
