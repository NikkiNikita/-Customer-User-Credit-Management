#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <cstring>
using namespace std;

class Node
{
public:
    string ConNo;
    string ConName;
    string ConPassword;
    string ConSex;
    string ConAge;
    string ConEmail;
    string ConAmount;
    string ConRank;
    string ConconAge;
    string ConEvalueate;
    int Discount;
    Node *next;
    Node()
    {
        this->next=NULL;
    }
    Node (string ConNo,
    string ConName="",
    string ConPassword="",
    string ConSex="",
    string ConAge="",
    string ConEmail="",
    string ConAmount="E",
    string ConRank="1000",
    string ConconAge="0",
    string ConEvalueate="E",
    int Discount=0,Node *next=NULL)
    {
        this->ConNo= ConNo;

        this->ConName=ConName;

        this->ConPassword =ConPassword;

        this->ConSex=ConSex;

        this->ConAge=ConAge;

        this->ConEmail=ConEmail;

        this->ConAmount =ConAmount;

        this->ConRank=ConRank;

        this->ConconAge =ConconAge;

        this->ConEvalueate=ConEvalueate;

        this->Discount= Discount;
        this->next=next;
    }
};
#endif // CLIENT_H
