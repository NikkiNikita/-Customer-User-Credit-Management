#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
#include <iostream>
#include "Node.h"

using namespace std;

class SinglyLinkedList
{
public:
    Node *ptr;
    Node *head;
    SinglyLinkedList();
    ~SinglyLinkedList();
    void clear();
    void insert(string ConNo,
                string ConName,
                string ConPassword,
                string ConSex,
                string ConAge,
                string ConEmail,
                string ConAmount,
                string ConRank,
                string ConconAge,
                string ConEvalueate,
                int Discount,int i);
    void remove(SinglyLinkedList& list,int i);
    bool getNode(string x,string y);
    bool getNode(string x);
    void reverse();

    int RenNum(int i);

    void update(string s,string Name,string passWord,string Email);

    void sort();

    void promote(string s,int money);

    Node* BackOneMessage(string Name);


    friend ostream& operator << (ostream& out,SinglyLinkedList& A){
        Node *p = A.head;
        while(p!=NULL){
            out<<p->ConNo<<endl;
            p=p->next;
        }
        return out;
    }
};

#endif // SINGLYLINKEDLIST_H
