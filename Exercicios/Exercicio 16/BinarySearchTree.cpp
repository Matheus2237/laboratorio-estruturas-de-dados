#include "BinarySearchTree.h"
#include <iomanip>
#include <iostream>
using namespace std;

BinarySearchTree::BinarySearchTree(){
    root = new TreeNode;
    root->Entry = 8;

    root->LeftNode = new TreeNode;
    root->LeftNode->Entry = 3;
    root->RightNode = new TreeNode;
    root->RightNode->Entry = 12;
    
    root->LeftNode->LeftNode = new TreeNode;
    root->LeftNode->LeftNode->Entry = 2;
    root->LeftNode->LeftNode->RightNode = NULL;
    root->LeftNode->RightNode = new TreeNode;
    root->LeftNode->RightNode->Entry = 5;
    root->LeftNode->RightNode->LeftNode = NULL;
    root->LeftNode->RightNode->RightNode = NULL;

    root->LeftNode->LeftNode->LeftNode = new TreeNode;
    root->LeftNode->LeftNode->LeftNode->Entry = 1;
    root->LeftNode->LeftNode->LeftNode->LeftNode = NULL;
    root->LeftNode->LeftNode->LeftNode->RightNode = NULL;

    root->RightNode->LeftNode = new TreeNode;
    root->RightNode->LeftNode->Entry = 10;
    root->RightNode->RightNode = new TreeNode;
    root->RightNode->RightNode->Entry = 15;
    root->RightNode->RightNode->LeftNode = NULL;
    root->RightNode->RightNode->RightNode = NULL;

    root->RightNode->LeftNode->LeftNode = new TreeNode;
    root->RightNode->LeftNode->RightNode = NULL;
    root->RightNode->LeftNode->LeftNode->Entry = 9;
    root->RightNode->LeftNode->LeftNode->LeftNode = NULL;
    root->RightNode->LeftNode->LeftNode->RightNode = NULL;
}

void BinarySearchTree::PreOrder(){
    PreOrder(root);
}

void BinarySearchTree::PreOrder(TreePointer r){
    if(r == NULL) return;

    cout << r->Entry <<" ";
    PreOrder(r->LeftNode);
    PreOrder(r->RightNode);
}

void BinarySearchTree::InOrder(){
    InOrder(root);
}

void BinarySearchTree::InOrder(TreePointer r){
    if(r == NULL) return;

    InOrder(r->LeftNode);
    cout << r->Entry << " ";
    InOrder(r->RightNode);
}

void BinarySearchTree::PostOrder(){
    PostOrder(root);
}

void BinarySearchTree::PostOrder(TreePointer r){
    if(r == NULL) return;

    PostOrder(r->LeftNode);
    PostOrder(r->RightNode);
    cout << r->Entry << " ";
}

int BinarySearchTree::Nodes(){
    return Nodes(root);
}

int BinarySearchTree::Nodes(TreePointer r){
    if(r == NULL) return 0;

    return 1 + Nodes(r->LeftNode) + Nodes(r->RightNode);
}

void BinarySearchTree::Print(){
    Print(root, 0);
}

void BinarySearchTree::Print(TreePointer &t, int s){
    int i;
    if(t!=NULL){
        Print(t->RightNode, s+3);
        for(i=1; i<=s; i++)
            cout << " ";
        cout << setw(6) <<t->Entry <<endl;
        Print(t->LeftNode, s+3);
    }
}

int BinarySearchTree::sumTreeKeys() const {
    return sumTreeKeys(root);
}

int BinarySearchTree::sumTreeKeys(const TreePointer& t) const {
    if (t == NULL)
        return 0;
    return t->Entry + sumTreeKeys(t->LeftNode) + sumTreeKeys(t->RightNode);
}

void BinarySearchTree::findParentOf(const int value) {
    TreePointer parent = nullptr;
    findParentOf(value, parent, root);
    showParentSearchResult(value, parent);
}

void BinarySearchTree::findParentOf(const int value, TreePointer& t, TreePointer& q) {
    if (q == nullptr)
        t = nullptr;
    else if (value < q->Entry)
        findParentOf(value, t = q, q->LeftNode);
    else if (value > q->Entry)
        findParentOf(value, t = q, q->RightNode);
}

void BinarySearchTree::showParentSearchResult(const int value, const TreePointer& parent) const {
    std::string result = parent != nullptr 
            ? " possui no pai de valor " + std::to_string(parent->Entry) 
            : " nao possui no pai.";
    std::cout << "  No " + std::to_string(value) << result << std::endl;
}

void BinarySearchTree::Insert(int x) {
    // Busca pelo local de inserção
    TreePointer p = NULL, q = root;
    while (q != NULL) {
        p = q;
        if (x > q->Entry)
            q = q->RightNode;
        else
            q = q->LeftNode;
    }

    // Alocação e inicialização do novo nó
    TreePointer r = new TreeNode;
    if (r == NULL) {
        std::cout << "Sem memoria suficiente" << std::endl;
        return;
    }
    r->Entry = x;
    r->LeftNode = NULL;
    r->RightNode = NULL;

    // Inserindo nó na árvore
    if (p == NULL)
        root = r;
    else if (x < p->Entry)
        p->LeftNode = r;
    else
        p->RightNode = r;
}

void BinarySearchTree::Delete(int x) {
    Delete(x, root);
}

void BinarySearchTree::Delete(int x, TreePointer& p) {
    // Verificação se a estrutura está vazia
    if (p == NULL) {
        std::cout << "Estrutura vazia!" << std::endl;
        return;
    }

    // Busca Pelo Elemento
    if (x < p->Entry)
        Delete(x, p->LeftNode);
    else if (x > p->Entry)
        Delete(x, p->RightNode);
    else {
        TreePointer q = p;
        if (q->RightNode == NULL)
            p = q->LeftNode;
        else if (q->LeftNode == NULL)
            p = q->RightNode;
        else
            DelMin(q, q->RightNode);
        delete q;
    }
}

void BinarySearchTree::DelMin(TreePointer& q, TreePointer& r) {
    if (r->LeftNode != NULL)
        DelMin(q, r->LeftNode);
    else {
        q->Entry = r->Entry;
        q = r;
        r = r->RightNode;
    }
}