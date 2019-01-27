/*文件操作实现*/
#include "FileOperation.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ostream>
#include <cstdlib>
#include "SinglyLinkedList.h"

using namespace std;

FileOperation::FileOperation(){}
FileOperation::~FileOperation(){}



char * FileOperation::OutputNumFile()
{
    ifstream examplefile1 ("Number.txt");
    if (! examplefile1.is_open())
            { cout << "Error opening file"; exit (1); }
            while (! examplefile1.eof() ) {
                examplefile1.getline (buffer,100);
            }
        return buffer;
}

void FileOperation::InputNumFile(){

    ifstream examplefile1 ("Number.txt");
    if (! examplefile1.is_open())
            { cout << "Error opening file"; exit (1); }
            while (! examplefile1.eof() ) {
                examplefile1.getline (buffer,100);
            }
    long long int n;
    string ss=buffer;
    stringstream s(ss);
    s>>n;
    stringstream sss;
    n+=1;
    sss<<n;
    ofstream examplefile ("Number.txt");

    if (examplefile.is_open())
        {
            examplefile<<sss.str();
            examplefile.close();
        }
}

void FileOperation::WriteFile(SinglyLinkedList& B)
{
    Node *p=B.head;
    ofstream examplefile ;
    examplefile.open("example.txt",std::ios_base::app);
    if (examplefile.is_open())
        {
            examplefile << p->ConNo <<" "<<p->ConName<<" "
                        << p->ConPassword<< " "<< p->ConSex<<" "
                        << p->ConAge<<" "<<p->ConEmail<<" "
                        << p->ConAmount<<" "<<p->ConRank<<" "
                        << p->ConconAge<<" "<<p->ConEvalueate<<" "
                        << p->Discount<<"\n";
            examplefile.close();
        }
}
void FileOperation::UpdateFile(SinglyLinkedList &list,int i){
    Node *p=list.head;
    ofstream examplefile ;
    examplefile.open("example.txt");
    for(int j=0;j<i;j++){
            examplefile << p->ConNo <<" "<<p->ConName<<" "
                        << p->ConPassword<< " "<< p->ConSex<<" "
                        << p->ConAge<<" "<<p->ConEmail<<" "
                        << p->ConAmount<<" "<<p->ConRank<<" "
                        << p->ConconAge<<" "<<p->ConEvalueate<<" "
                        << p->Discount<<"\n";
            p=p->next;
      }
    examplefile.close();


}

void FileOperation::deleteFile(){

    string dbfile="example.txt";
    ofstream fileout(dbfile.c_str(), ios::out|ios::trunc );
    fileout.close();
}


SinglyLinkedList& FileOperation::ReturnCon(SinglyLinkedList& B)
{
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
        int i=0;
        ifstream file1("example.txt");
        char  line[1024]={0};
            while(file1.getline(line, sizeof(line)))
            {
                stringstream  word(line);
                word >> ConNo>> ConName>> ConPassword >> ConSex>>
                        ConAge >> ConEmail >> ConAmount >>
                        ConRank >> ConconAge >> ConEvalueate >> Discount;
                B.insert(ConNo, ConName, ConPassword , ConSex,
                        ConAge , ConEmail , ConAmount ,
                        ConRank , ConconAge , ConEvalueate , Discount,i++);
       }
            file1.clear();
            file1.close();
            return B;
}
