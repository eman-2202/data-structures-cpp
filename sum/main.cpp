#include <iostream>
#include <string>
using namespace std;

/*int main()
{
    int num1,num2,result;
    cout<<"enter num1: ";
    cin>>num1;
    cout<<"enter num2: ";
    cin>>num2;
    result=((num1+num2)*3)-10;
    cout<<"the result = "<<result;
    return 0;
}*/
int main()
{
    string name;
    float grade;
    cout<<"enter your full name: ";
    getline(cin,name);
    cout<<"enter your grade: ";
    cin>>grade;
    cout<<"-------------User Information--------------\n";
    cout<<"Name :"<<name<<endl;
    cout<<"Grade : "<<grade<<"/100"<<endl;
}
