#include <iostream>
#include "SinglyLinkedList.h"
#include <sstream>
using namespace std;


void SinglyLinkedList::clear()
{
    Node* p=head;
    while(p!=NULL)
    {
        Node *q=p;
        p=p->next;
        delete q;
    }
}

SinglyLinkedList::SinglyLinkedList()
{
    this->head=NULL;
}

SinglyLinkedList::~SinglyLinkedList()
{
    clear();
}

bool SinglyLinkedList::getNode(string x){
    Node *p=head;
    int i=0;
    while(p!=NULL)
    {
        if(p->ConName==x)
        {
            return true;
        }
        else
        {
            i++;
            p=p->next;
        }
    }
        return false;
}

bool SinglyLinkedList::getNode(string x,string y)
{
    Node *p=head;
    int i=0;
    while(p!=NULL)
    {
        if((p->ConName==x)&&(p->ConPassword==y))
        {
            return true;
        }
        else
        {
            i++;
            p=p->next;
        }
    }
        return false;
}

void SinglyLinkedList::insert(string ConNo,
    string ConName,
    string ConPassword,
    string ConSex,
    string ConAge,
    string ConEmail,
    string ConAmount,
    string ConRank,
    string ConconAge,
    string ConEvalueate,
    int Discount,int i)
{
    Node* q=NULL;
    if(head==NULL||i<=0)
    {
        q=new Node (ConNo, ConName, ConPassword , ConSex,
                    ConAge , ConEmail , ConAmount ,
                    ConRank , ConconAge , ConEvalueate , Discount,head);
        head=q;

    }
    else
    {
        int j=0;
        Node* p=head;
        while(p!=NULL&&j<i-1)
        {
            j++;
            p=p->next;
        }
        q=new Node (ConNo, ConName, ConPassword , ConSex,
                    ConAge , ConEmail , ConAmount ,
                    ConRank , ConconAge , ConEvalueate , Discount,p->next);
        p->next=q;
    }
}


void SinglyLinkedList::remove(SinglyLinkedList& list,int i)
{
    if(i==0)
    {
        Node *p=list.head;
        list.head=p->next;
        delete p;
    }
    else
    {
        int j=0;
        Node *q=list.head;
        while(q!=NULL&&j<i-1)
        {
            j++;
            q=q->next;
        }
        Node *p=q->next;
        q->next=p->next;
        delete p;
    }

}

void SinglyLinkedList::reverse()
{

    Node *p=head->next;
    Node *q=NULL;
    head->next=NULL;
    while(p!=NULL)
    {
        q=p->next;
        p->next=head->next;
        head->next=p;
        p=q;
    }
}


void SinglyLinkedList::update(string s,string Name,string passWord,string Email)
{
    Node *p =head;
    while(p!=NULL)
    {
        if(p->ConName==s)
            break;
        p=p->next;
    }
    p->ConName=Name;
    p->ConPassword=passWord;
    p->ConEmail=Email;
}


Node* SinglyLinkedList::BackOneMessage(string Name){
    ptr=head;
    int i=0;

    while(ptr!=NULL)
    {
        if(ptr->ConName==Name)
        {
            return ptr;
        }
        else
        {
            i++;
            ptr=ptr->next;
        }
    }
    return ptr;
}

int SinglyLinkedList::RenNum(int i){
    Node *p = head;
    while(p!=NULL){
        p=p->next;
        i++;
    }
    return i;

}
void SinglyLinkedList::promote(string s,int money){
    Node *p =head;
    while(p!=NULL)
    {
        if(p->ConName==s)
            break;
        p=p->next;
    }
    stringstream strStream;
    strStream<<p->ConAmount;
    int val;
    strStream>>val;
    val+=1;
    cout<<val;
    stringstream s1;
        s1<<val;
    string str= s1.str();
    p->ConAmount=str;
    if(money<1000){
        strStream<<p->ConRank;
        int val;
        strStream>>val;
        val+=50;
        strStream<<val;
            s1<<val;
        string str= s1.str();
        p->ConRank=str;
        p->ConEvalueate="D";
        p->Discount=90;
    }else if(money>=1000&&money<3000)
    {
        strStream<<p->ConRank;
        int val;
        strStream>>val;
        val+=100;
        strStream<<val;
            s1<<val;
        string str= s1.str();
        p->ConRank=str;
        p->ConEvalueate="C";
        p->Discount=80;
    }else if(money>=3000&&money<5000)
    {
        strStream<<p->ConRank;
        int val;
        strStream>>val;
        val+=150;
        strStream<<val;
            s1<<val;
            string str= s1.str();
        p->ConRank=str;
        p->ConEvalueate="C";
        p->Discount=70;
    }else if(money>=5000&&money<10000)
    {
        strStream<<p->ConRank;
        int val;
        strStream>>val;
        val+=200;
        strStream<<val;
            s1<<val;
            string str= s1.str();
        p->ConRank=str;
        p->ConEvalueate="B";
        p->Discount=70;
    }else
    {
        strStream<<p->ConRank;
        int val;
        strStream>>val;
        val+=50;
        strStream<<val;
            s1<<val;
            string str= s1.str();
        p->ConRank=str;
        p->ConEvalueate="A";
        p->Discount=50;
    }
}
void SinglyLinkedList::sort()
{
    Node *p,*q;
    Node *temp=new Node();
    for(p=head; p!=NULL; p=p->next)
    {
        for(q=p->next; q!=NULL; q=q->next)
        {
            if(p->Discount<q->Discount)
            {
                temp->ConNo= p->ConNo;
                temp->ConName= p->ConName;
                temp->ConPassword = p->ConPassword;
                temp->ConSex = p->ConSex;
                temp->ConAge = p->ConAge;
                temp->ConEmail = p->ConEmail;
                temp->ConAmount = p->ConAmount;
                temp->ConRank = p->ConRank;
                temp->ConconAge = p->ConconAge;
                temp-> ConEvalueate = p->ConEvalueate;
                temp-> Discount= p->Discount;

                 p->ConNo =q->ConNo;
                 p->ConName=q->ConName;
                 p->ConPassword= q->ConPassword;
                 p->ConSex = q->ConSex;
                 p->ConAge = q->ConAge;
                 p->ConEmail = q->ConEmail ;
                 p->ConAmount = q->ConAmount;
                 p->ConRank = q->ConRank;
                 p->ConconAge = q->ConconAge;
                 p->ConEvalueate = q->ConEvalueate;
                 p->Discount =q->Discount;

                 q->ConNo =temp->ConNo;
                 q->ConName=temp->ConName;
                 q->ConPassword= temp->ConPassword;
                 q->ConSex = temp->ConSex;
                 q->ConAge = temp->ConAge;
                 q->ConEmail = temp->ConEmail ;
                 q->ConAmount = temp->ConAmount;
                 q->ConRank = temp->ConRank;
                 q->ConconAge = temp->ConconAge;
                 q->ConEvalueate = temp->ConEvalueate;
                 q->Discount =temp->Discount;
            }
        }
    }
}
