#include<iostream>
using namespace std;
struct Node {
    int token;
     Node *next;
};
Node *head = NULL;
void insertbeg(int value){
    Node *newNode = new Node;
    newNode->token = value;
    newNode->next = head;
    head = newNode;
}


void insertEnd(int value)
{
    Node *newNode = new Node;
    newNode->token = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}


void display()
{
    if (head == NULL)
    {
        cout << "Queue is Empty." << endl;
        return;
    }

    Node *temp = head;

    cout << "Patient Queue: ";

    while (temp != NULL)
    {
        cout << temp->token << " ";
        temp = temp->next;
    }

    cout << endl;
}


int main(){
    int i,choice,token;
do{
    cout<<"1.Insert at the front"<<endl;
    cout<<"2.Insert at the back"<<endl;
    cout<<"3.Insert in the middle"<<endl;
    cout<<"4.Exit"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;

switch (choice)
{
 case 1:
            cout << "Enter Patient Token: ";
            cin >> token;
            insertbeg(token);
            display();
            break;

        case 2:
            cout << "Enter Patient Token: ";
            cin >> token;
            insertEnd(token);
            display();
            break;
}
} while(choice!=4);
return 0;

}