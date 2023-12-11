#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
    public: 
        Node *next;
        string data;
        Node():next(nullptr),data(""){}
};

class Queue {
    public:
        Queue():head(nullptr),tail(nullptr){}

        bool isEmpty()
        {
            return head == nullptr;
        }

        void enqueue(const string &data)
        {
            Node *newNode = new Node;
            newNode->data = data;
            newNode->next = nullptr;
            if(head==nullptr)
            {
                head=newNode;
                tail=newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }

        void dequeue()
        {
            Node *current = head;
            if(head!=nullptr){
                string item = head->data;
                head = head->next;
                delete current;
                cout << "dequeue " << item << endl;
            }
        }

        void print()
        {
            Node *current = head;
            cout << "Your Queue: ";
            while(current!=nullptr)
            {
                cout << current->data << "-->";
                current = current->next;
            }
            cout << "null\n";
        }

        void deleteAll()
        {
            Node *current = head;
            while(head!=nullptr)
            {
                head = head->next;
                delete current;
                current = head;
            }
        }
    private:
        Node *head;
        Node *tail;
};


int main()
{
    Queue q;
    bool function = true;
    string input;
    vector<string> someString;
    
    cout << "Please enter the items you want to save in the queue, enter q to start the process.\n";
    
    while(function==true)
    {
        while(cin>>input)
        {
            if(input =="q")
            {
                cout << "Processing...\n";
                break;
            }
            else
            {
                someString.push_back(input);
            }
        }
        for(auto item: someString)
        {
            q.enqueue(item);
        }
        q.print();
        
        cout << "\nEnter d to dequeue an item, enter exist to exist the program\n";
        cout << "enter peek to see currene Queue, enter add to add more item to the queue.\n";
        
        while(cin>>input)
        {
            if(input == "add")
            {
                cout << "\nPlease enter the items you want to save in the queue, enter q to start the process.\n";
                q.print();
                q.deleteAll();
                break;
            }
            else if (input == "d")
            {
                q.dequeue();
            }
            else if (input == "peek")
            {
                q.print();
            }
            else if (input == "exist")
            {
                q.deleteAll();
                cout << "Program closed.\n";
                function = false;
                break;
            }
        }
    }
    return 0;
}




