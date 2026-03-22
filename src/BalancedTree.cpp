//Includes
#include "BalancedTree.hpp"
#include <algorithm> //need to make use of std::max

//private methods

//Obtains the height of the tree
int BalancedTree::getHeight(Node* node){
    //Returns 0 in case there is no tree
    if (node == nullptr){
        return 0;
    }
    else{
    //Accesses the height safely
    return node -> height;
    }
}

/*Calculates if the tree is inclined by using the formula
(height left side of the node) - (height right side of the node) */
int BalancedTree::getBalanceFactor(Node* node){
    if(node == nullptr){
        return 0;
    }
    else{
        return getHeight(node -> left) - getHeight(node -> right);
    }
}

/*Turns towards the right if the left side is too heavy*/
BalancedTree::Node* BalancedTree::rotateRight(Node* y){
    //Variables
    Node* x;
    Node* z;

    //Define variables
    x = y -> left;
    z = x -> right;

    //Execute the turn
    x -> right = y; 
    y -> left = z;


    //Update the height of the nodes that were turned
    y -> height = std::max(getHeight(y -> left), getHeight(y -> right)) + 1;
    x -> height = std::max(getHeight(x -> left), getHeight(x -> right)) + 1;

    //Return the new root of this tree side
    return x;
}


/*Turns towards the left if the right side is too heavy*/
BalancedTree::Node* BalancedTree::rotateLeft(Node* x){
    //Variables
    Node* y;
    Node* z;

    //Define variables
    y = x -> right;
    z = y -> left;

    //Execute the turn
    y -> left = x;
    x -> right = z; 


    //Update the height of the nodes that were turned
    x -> height = std::max(getHeight(x -> left), getHeight(x -> right)) + 1;
    y -> height = std::max(getHeight(y -> left), getHeight(y -> right)) + 1;

    //Return the new root of this tree side
    return y;
}

//insert number in the tree
BalancedTree::Node* BalancedTree::insertHelper(Node* node, int& number){
    //variables
    int balance;
    
    //Normal insert step
    if(node == nullptr){
        return new Node(number);
    }

    /*This will take care of inserting the ints according to its value 
    if it is less than the value of the integer it will be send to the left
    else it will be send to the right*/
    if (number < node -> content){
        node -> left = insertHelper(node -> left, number);
    }
    else{
        node -> right = insertHelper(node -> right, number);
    }

    //Updating the height
    node -> height = 1 + std::max(getHeight(node -> left), getHeight(node ->right));

    //Review if the tree is not balanced
    balance = getBalanceFactor(node);

    //According to the kind of disbalance,in case we have, we apply 1 of these 4 different cases
    // Case left-left
    if (balance > 1 && number < node->left->content)
        return rotateRight(node);

    // Case right-right
    if (balance < -1 && number >= node->right->content)
        return rotateLeft(node);

    // Case left-right
    if (balance > 1 && number >= node->left->content) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Case right-left
    if (balance < -1 && number < node->right->content) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node; // Retun the balanced node
}

//Make the in Order travel as it will give back the vector in ascending order
void BalancedTree::inOrderHelper(Node* node, std::vector<int>& list){
    //allows us to stop at the leaves
    if (node != nullptr){
        inOrderHelper(node -> left, list); // First the low values
        // We passs those values to be inserted in the list recursively
        list.push_back(node -> content);
        inOrderHelper(node -> right, list); // Later we do the big values
    }
}

//public methods that will be called in the main

//method to insert all the numbers representing the words
void BalancedTree::insertNumber( int number){
    root = insertHelper(root, number);
}

// Store the result in a list to obtain the final ordering
std::vector<int> BalancedTree::getInorder(){
    //variable
    std::vector<int> sortedList;// list empty 
    
    //execution
    inOrderHelper(root, sortedList); //send the list for it to order it recursively
    return sortedList; // return the list of numbers ,that represent the words, organized
}