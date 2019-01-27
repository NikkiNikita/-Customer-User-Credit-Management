#ifndef FILEOPERATION_H
#define FILEOPERATION_H

#include <fstream>
#include <ostream>
#include <iostream>
#include "SinglyLinkedList.h"

using namespace std;

class FileOperation
{
public:
     FileOperation();
     ~FileOperation();
     void WriteFile(SinglyLinkedList& list);
     void UpdateFile(SinglyLinkedList& list,int i);
     char * OutputNumFile();
     void InputNumFile();
     void deleteFile();
     SinglyLinkedList& ReturnCon(SinglyLinkedList& B);
private :
     char buffer[256];
     SinglyLinkedList A;
};

#endif // FILEOPERATION_H
