#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node() //default constructor
    {
        cout<<"default constructor"<<endl;
        data = 0;
        next = NULL;
    }
    Node(int value) // parameterised constructor
    {
        this->data = value;
        this->next = NULL;
    }
};
class Linklist: public Node
{
    Node* head;
    public:
    Linklist() //default constructor
    { 
        head = NULL; 
    }
    void insertathead(int);
    void insertattail(int);
    bool searchinlist(int);
    void printfromlist();

};
void Linklist::insertathead(int value)
{
    Node* newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
}
void Linklist::insertattail(int value)
{
    Node* temp = head;
    Node* newNode = new Node(value);
        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }    
}
void Linklist::printfromlist()
{
    Node* temp = head;
        if(head == NULL)
        {
            cout<<"list is empty"<<endl;
            return;
        }
        else
        {
            while(temp!=NULL)
            {
                cout<<temp->data<<"->";
                temp = temp->next;
            }
        }
        cout<<"NULL"<<endl;
}
bool Linklist::searchinlist(int key)
{
    Node* temp = head;
    while(temp!= NULL)
    {
        if(temp->data == key)
        {
            return true;
        }
        temp = temp->next;
        }
        return false;
}
int main()
{
    Linklist L;
    L.printfromlist();
    L.insertattail(1);
    L.insertattail(2);
    L.insertattail(3);
    L.insertattail(4);
   
    L.printfromlist();
   
    L.insertathead(5);
   
    L.printfromlist();
    bool res = L.searchinlist(5);
    if(res == true)
        cout<<"key found";
    else
        cout<<"no key found";


    
}