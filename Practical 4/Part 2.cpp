#include <iostream>
using namespace std;

struct Node
{
    int token;
    Node *next;
};

Node *head = NULL;

void insertbeg(int value)
{
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

void insertMiddle(int value, int position)
{
    if (position <= 1)
    {
        insertbeg(value);
        return;
    }

    Node *newNode = new Node;
    newNode->token = value;

    Node *temp = head;

    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Invalid Position." << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
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

int main()
{
    int choice, token, position;

    do
    {
        cout << "\n1. Insert at the front" << endl;
        cout << "2. Insert at the back" << endl;
        cout << "3. Insert in the middle" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

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

        case 3:
            cout << "Enter Patient Token: ";
            cin >> token;

            cout << "Enter Position: ";
            cin >> position;

            insertMiddle(token, position);
            display();
            break;

        case 4:
            cout << "Program Ended." << endl;
            break;

        default:
            cout << "Invalid Choice." << endl;
        }

    } while (choice != 4);

    return 0;
}