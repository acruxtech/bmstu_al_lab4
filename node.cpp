#include <vector>
#include <iostream>


struct node {
    int data;
    node* next;
};


int main() {
    std::vector<int> seq = {1, 2, 3, 4, 5};

    node* nd = new node{seq[0], nullptr};
    node* nd1 = new node{seq[1], nd};
    nd->next = nd1;

    node* last_created_nd = nd1;
    for (int i = 2; i < seq.size(); i++) {
        node* newNode = new node{seq[i], nullptr};
        last_created_nd->next = newNode;
        last_created_nd = newNode;
    }

    std::cout << nd->next->next->next->next->data << std::endl; 
    return 0;
}