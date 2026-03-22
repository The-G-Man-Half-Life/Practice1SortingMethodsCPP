//include guards
#pragma once

//include of necessary elements
#include <vector>
#include <string>

class BalancedTree
{
private:

    /*Creation of the private class node that we will use to make
    the AVL tree but as we need it only for organizing the data inside
    this class no other class should be able to access it except 
    BalancedTree*/
    struct Node{
        int content;  //Content of the node 
        Node* left;   //Connection to the left node through pointers
        Node* right;  //Connection to the right node through pointers
        int height;   // Height of the node

        //Constructor 
        Node(int n) : content(n), left(nullptr), right(nullptr), height(1) {}
    };
    Node* root; // Root of the tree 

    //getters to obtain important info
    int getHeight(Node* node);
    int getBalanceFactor(Node* node);

    //Intern methods to balance the tree
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);

    //Intern recursive methods to help organize methods
    Node* insertHelper(Node* node, int& word);
    void inOrderHelper(Node* node, std::vector<int>& list);

public:
    /*public methods that will be used to contact the private methods 
    with the other classes that might require it*/
    void insertNumber(int number);
    std::vector<int>  getInorder();
};
