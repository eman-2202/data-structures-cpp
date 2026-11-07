#include <iostream>
#include <string>
using namespace std;

class Employee
{
    int id;
    int age;
    string name;
public:
    Employee *pNext;
    Employee *pPrev;
    Employee(){id=0;age=0;name="";pNext=NULL;pPrev=NULL;}
    Employee(int _id,int _age,string _name)
    {
        id=_id;age=_age;name=_name;
        pNext=NULL;
        pPrev=NULL;
    }
    int getId(){return id;}
    void printEmployee()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<id<<endl;
        cout<<"Age: "<<age<<endl;
    }
};
class LinkedList
{
protected:
    Employee *pStart;
    Employee *pEnd;
public:
    LinkedList(){pStart=pEnd=NULL;}
    ~LinkedList(){freeList();}
    void addNode(Employee *e);
    void DisplayAll();
    Employee*searchNode(int id);
    //void insertNode(int id,int age,string name,int prev_id);
    int deleteNode(int id);
    void freeList();
};
void LinkedList::addNode(Employee *e)
{
    Employee*pItem=e;
    if(!pStart)
    {
        pStart=pEnd=pItem;
    }
    else
    {
        pEnd->pNext=pItem;
        pItem->pPrev=pEnd;
        pEnd=pItem;
    }
}
void LinkedList::DisplayAll()
{
    Employee *pItem=pEnd;
    if(!pItem)
    {
        cout<<"The List is Empty!!"<<endl;
    }
    cout<<"Employee information is "<<endl;
    while(pItem)
    {
        pItem->printEmployee();
        pItem=pItem->pPrev;

    }
}
Employee* LinkedList::searchNode(int id)
{
    Employee *pItem=pStart;
    while(pItem &&pItem->getId()!=id)
    {
        pItem=pItem->pNext;
    }
    return pItem;
}
/*void LinkedList::insertNode(int id,int age,string name,int prev_id)
{
    Employee * pItem=new Employee(id,age,name);
    Employee *pResult=searchNode(prev_id);
    if(!pStart)
    {
        cout<<"The List is Empty!!"<<endl;
    }
    else if(pResult==pStart)
    {
        pStart->pPrev=pItem;
        pItem->pNext=pStart;
        pStart=pItem;
    }
    else if(pResult==pEnd)
    {
        pEnd->pNext=pItem;
        pItem->pPrev=pEnd;
        pEnd=pItem;
    }
    else
    {
        pResult->pPrev->pNext=pItem;
        pItem->pPrev=pResult->pPrev;
        pItem->pPrev=pItem;
        pItem->pNext=pResult;
    }
}*/
 int LinkedList::deleteNode(int id)
 {
     int flag=0;
     if (!pStart)
     {
         return flag;
     }
     Employee *pItem=searchNode(id);
     if(!pItem)
     {
         flag=0;
     }
     else
     {
         if(pStart==pEnd)
        {
            pStart=pEnd=NULL;
            flag=1;
        }
        /*else if(pItem==pStart)
        {
            pStart=pItem->pNext;
            pStart->pPrev=NULL;
            flag=1;
        }*/
        else if(pItem==pEnd)
        {
            pEnd=pItem->pPrev;
            pEnd->pNext=NULL;
            flag=1;
        }
        /*else
        {
            pItem->pPrev->pNext=pItem->pNext;
            pItem->pNext->pPrev=pItem->pPrev;
            flag=1;
        }*/
        delete pItem;
     }
     return flag;
 }
 void LinkedList::freeList()
 {
     Employee *pItem;
     while(pStart)
     {
         pItem=pStart;
         pStart=pItem->pNext;
         delete pItem;
     }
     pEnd=NULL;
 }
 class Stack : LinkedList
 {
 public:
    Stack():LinkedList(){}
    ~Stack(){deleteStack();}
    void push(Employee * e){addNode(e);};
    Employee *pop();
    void printStack(){DisplayAll();};
    Employee *searchStack(int id){return searchNode(id);};
    int deleteNodeinStack(int id){return deleteNode(id);};
    void deleteStack(){freeList();};
 };
 Employee * Stack::pop()
 {
     Employee *pResult=pEnd;
     if(!pStart)
     {
         pResult=NULL;
     }
     else
     {
         if(pStart==pEnd)
         {
             pStart=pEnd=NULL;
         }
         else
         {
             pEnd=pEnd->pPrev;
             pEnd->pNext=NULL;
         }
     }
     return pResult;
 }

int main()
{
    Employee e1[]={{1,23,"eman"}, {2,26,"maryam"},{3,22,"Mena"}};
    Stack s1;
    s1.push(&e1[0]);
    s1.push(&e1[1]);
    s1.push(&e1[2]);
    //s1.printStack();
    s1.pop();
    s1.printStack();
    return 0;
}
