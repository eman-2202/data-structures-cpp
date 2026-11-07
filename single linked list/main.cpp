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
    Employee(){id=0;age=0;name="";pNext=NULL;}
    Employee(int _id,int _age,string _name)
    {
        id=_id;age=_age;name=_name;
        pNext=NULL;
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
    Employee *pStart;
    Employee *pEnd;
public:
    LinkedList(){pStart=pEnd=NULL;}
    ~LinkedList(){freeList();}
    void addNode(int id,int age,string name);
    void DisplayAll();
    Employee*searchNode(int id);
    void insertNode(int id,int age,string name,int prev_id);
    int deleteNode(int id);
    void freeList();
};
void LinkedList::addNode(int id,int age,string name)
{
    Employee *pItem=new Employee(id,age,name);
    if(!pStart)
    {
        pStart=pEnd=pItem;
    }
    else
    {
        pEnd->pNext=pItem;
        pEnd=pItem;
    }
}
void LinkedList::DisplayAll()
{
    Employee *pItem=pStart;
    if(!pItem)
    {
        cout<<"the list is empty!";
    }
    else
    {
        cout<<"Employee information is "<<endl;
        while(pItem!=NULL)
        {
            pItem->printEmployee();
            pItem=pItem->pNext;
        }
    }
}
Employee *LinkedList::searchNode(int id)
{
    Employee *pItem=pStart;
    while (pItem && pItem->getId()!=id)
    {
        pItem=pItem->pNext;
    }
    return pItem;
}

void LinkedList::insertNode(int id,int age,string name,int prev_id)
{
    Employee *pItem=new Employee(id,age,name);
    Employee *result=searchNode(prev_id);
    if(result==pStart)
    {
        pItem->pNext=result;
        pStart=pItem;
    }
    else if (result==pEnd)
    {
        pEnd->pNext=pItem;
        pEnd=pItem;
    }
    else
    {
        pItem->pNext=result->pNext;
        result->pNext=pItem;
    }
}
int LinkedList::deleteNode(int id)
{
    Employee *pItem=searchNode(id);
    int flag=0;
    if (pItem==NULL) //if empty
    {
        flag=0;
    }
    else if(pItem==pStart)//first node
    {
        pStart=pItem->pNext;
        pItem->pNext=NULL;
        if(pStart==NULL){pEnd=NULL;}
        flag=1;
    }
    else if(pItem==pEnd) //last node
    {
        Employee*presult=pStart;
        while(presult->pNext!=pItem)
        {
            presult=presult->pNext;
        }
        pEnd=presult;
        pEnd->pNext=NULL;
        flag=1;
    }
    else
    {
        Employee*presult=pStart;
        while (presult->pNext!=pItem)
        {
            presult=presult->pNext;
        }
        presult->pNext=pItem->pNext;
        flag=1;
    }
    delete pItem;
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
int main()
{
    LinkedList l1;
    l1.addNode(1,23,"eman");
    l1.addNode(2,26,"maryam");
    l1.addNode(3,22,"Mena");
    //l1.DisplayAll();
    //Employee *e1=l1.searchNode(2);
    //e1->printEmployee();
    return 0;
}
