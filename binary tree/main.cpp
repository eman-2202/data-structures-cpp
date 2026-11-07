#include <iostream>
#include <math.h>
using namespace std;

class Employee
{
    int id;
    int age;
    string name;
    int code;
public:
    Employee *pLeft;
    Employee *pRight;
    Employee(){id=0;age=0;name="";code=0;pLeft=NULL;pRight=NULL;}
    Employee(int _id,int _age,string _name,int _code)
    {
        id=_id;age=_age;name=_name;code=_code;
        pLeft=NULL;
        pRight=NULL;
    }
    void setId(int _id){id=_id;}
    int getId(){return id;}
    void setAge(int _age){age=_age;}
    int getAge(){return age;}
    void setName(string _name){name=_name;}
    string getName(){return name;}
    void setCode(int _code){code=_code;}
    int getCode(){return code;}
    void printEmployee()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<id<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"code: "<<code<<endl;
    }
};
class Binary_Tree
{
public:
    Employee *pParent;
    Binary_Tree(){pParent=NULL;}
    ~Binary_Tree(){}
    Employee * insertNode(Employee *pRoot,Employee * pData);
    Employee * searchNode(int code);
    void InOrderTranverse(Employee *pRoot);
    void PreOrderTranverse(Employee *pRoot);
    void PostOrderTranverse(Employee *pRoot);
    int getHight(Employee *pRoot);
    Employee *deleteNode(Employee* pRoot,int code);
    Employee *findMin(Employee *pRoot);
    Employee *findMax(Employee * pRoot);
};

Employee * Binary_Tree::insertNode(Employee *pRoot,Employee * pData)
{
    if(!pRoot) //if empty
    {
        pData->pLeft=pData->pRight=NULL;
        return pData;
    }
    else //if there is at least one node
    {
        if(pData->getCode()<=pRoot->getCode()) //if data<node go left
        {
            pRoot->pLeft=insertNode(pRoot->pLeft,pData);
        }
        else //if data>node go right
        {
            pRoot->pRight=insertNode(pRoot->pRight,pData);
        }
    }
    return pRoot;
}
Employee * Binary_Tree::searchNode(int code)
{
    Employee *pItem=pParent;
    while(pItem && pItem->getCode()!=code)
    {
        if(code< pItem->getCode())
        {
            pItem=pItem->pLeft;
        }
        else
        {
            pItem=pItem->pRight;
        }
    }
    return pItem;
}
void Binary_Tree::InOrderTranverse(Employee *pRoot) //(Left,Data,Right)
{
    if (!pRoot) return;
    InOrderTranverse(pRoot->pLeft);
    pRoot->printEmployee();
    InOrderTranverse(pRoot->pRight);
}
void Binary_Tree::PreOrderTranverse(Employee *pRoot) //(Data, Left,Right)
{
    if (!pRoot) return;
    pRoot->printEmployee();
    PreOrderTranverse(pRoot->pLeft);
    PreOrderTranverse(pRoot->pRight);
}
void Binary_Tree::PostOrderTranverse(Employee *pRoot) //(Left,Right,Data)
{
    if (!pRoot) return;
    PostOrderTranverse(pRoot->pLeft);
    PostOrderTranverse(pRoot->pRight);
    pRoot->printEmployee();
}
int Binary_Tree::getHight(Employee *pRoot) //the hight of each node
{
    if(!pRoot)
        return -1;
    int left_hight=getHight(pRoot->pLeft);
    int right_hight=getHight(pRoot->pRight);
    return max(left_hight,right_hight)+1;
}
Employee *Binary_Tree::findMin(Employee*pRoot)
{
    if(!pRoot){return NULL;}
    Employee *pTemp=pRoot;
    while(pTemp->pLeft!=NULL)
    {
        pTemp=pTemp->pLeft;
    }
    return pTemp;
}
Employee *Binary_Tree::findMax(Employee*pRoot)
{
    if(!pRoot){return NULL;}
    Employee *pTemp=pRoot;
    while(pTemp->pRight!=NULL)
    {
        pTemp=pTemp->pRight;
    }
    return pTemp;
}
Employee *Binary_Tree::deleteNode(Employee*pRoot,int code)
{
    if(!pRoot)
    {
        return pRoot;
    }
    if(code<pRoot->getCode())
    {
        pRoot->pLeft=deleteNode(pRoot->pLeft,code);
    }
    else if(code>pRoot->getCode())
    {
        pRoot->pRight=deleteNode(pRoot->pRight,code);
    }
    else
    {
        //no child leaf
        if(!pRoot->pLeft && !pRoot->pRight)
        {
            delete pRoot;
            pRoot=NULL;
            return pRoot;
        }
        //one child on the right the left pointer is null
        else if(!pRoot->pLeft)
        {
            Employee *ptemp=pRoot;
            pRoot=pRoot->pRight;
            delete ptemp;
        }
        // one child at the left , the right pointer is null
        else if(!pRoot->pRight)
        {
            Employee * ptemp=pRoot;
            pRoot=pRoot->pLeft;
            delete ptemp;
        }
        //2 child
        else
        {
            Employee *ptemp=findMin(pRoot->pRight);
            pRoot->setCode(ptemp->getCode());
            pRoot->setId(ptemp->getId());
            pRoot->setAge(ptemp->getAge());
            pRoot->setName(ptemp->getName());
            pRoot->pRight=deleteNode(pRoot->pRight,ptemp->getCode());
        }
        return pRoot;
    }
}
int main()
{
    Employee e1[]={{1,23,"eman",5}, {2,26,"maryam",3},{3,22,"Mena",6},{4,18,"Abdullah",9}};
    Binary_Tree t1;
    t1.pParent=t1.insertNode(t1.pParent,&e1[0]);
    t1.pParent=t1.insertNode(t1.pParent,&e1[1]);
    t1.pParent=t1.insertNode(t1.pParent,&e1[2]);
    t1.pParent=t1.insertNode(t1.pParent,&e1[3]);
    //t1.InOrderTranverse(t1.pParent);
    //t1.PostOrderTranverse(t1.pParent);
    //t1.PreOrderTranverse(t1.pParent);
    //int hight=t1.getHight(t1.pParent);
    //cout<<"the hight of the tree is "<<hight<<endl;
    t1.PostOrderTranverse(t1.deleteNode(t1.pParent,5));
    return 0;
}
