#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node {
    public:
        Node *next;
        string data;
        Node():next(nullptr),data(""){}
};


class Stack {
    public:
        Stack():head(nullptr),tail(nullptr){}

        bool isEmpty()
        {
            return tail == nullptr;
        }

        void pushStack(const string &data)
        {
            Node *newNode = new Node;
            newNode->data = data;
            if(head==nullptr)
            {
                head=newNode;
                tail=newNode;
            }
            else 
            {
                newNode->next = tail;
                tail=newNode;
            }
        }

        void popStack()
        {
            Node *current = tail;
            if(tail!=nullptr)
            {
                cout << "Item poped: " << tail->data << endl;
                tail = tail->next;
                delete current;
                current = nullptr;
            }
        }

        void deleteAll()
        {
            Node *current = tail;
            while(tail!=nullptr)
            {
                tail = tail->next;
                delete current;
                current = tail;
            }
        }

        void printStack()
        {
            Node *current = tail;
            cout << "Your Stack: ";
            while(current!=nullptr)
            {
                cout << current->data << "-->" ;
                current = current->next;
            }
            cout << "null\n";
        }
    
    private:
        Node *head;
        Node *tail;
};


int main()
{
    Stack myStack;
    bool run=true;
    string input;
    vector<string> someString;
    
    cout << "Please enter the item you want to push to the stack, enter q to begin the process.\n";
    
    while(run==true)
    {
        while(cin>>input)
        {
            if(input=="q")
            {
                cout << "Proccessing...\n";
                break;
            }
            else
            {
                someString.push_back(input);
            }
        }
        
        for(auto item: someString)
        {
            myStack.pushStack(item);
        }
        myStack.printStack();
        
        cout << "\nEnter pop to pop an item, enter peek to see the current stack.\n";
        cout << "Enter add to add more item, enter exist to terminate the program.\n";
        
        while(cin>>input)
        {
            if(input == "pop")
            {
                myStack.popStack();
            }
            else if(input == "peek")
            {
                myStack.printStack();
            }
            else if(input == "add")
            {
                cout << "\nPlease enter the items you want to save in the stack, enter q to start the process.\n";
                myStack.printStack();
                myStack.deleteAll();
                break;
            }
            else if(input == "exist")
            {
                run = false;
                myStack.deleteAll();
                cout << "Program closed.\n";
                break;
            }
        }
    }
    return 0;
}

