#include <iostream>
#include <string>
using namespace std;
// this will probably end up being a type of queue (fifo)
class Node {
    private:
     string name;
     int id;
     string issue;
     Node* nextptr;
     Node* prevptr;

     public:
};

int main() {
bool systemOn = true;
while (systemOn) {
    int choice;
    cout << "--- Customer Support Ticket System ---" << endl;
    cout << "1. Add a Ticket" << endl;
    cout << "2. Serve a Ticket" << endl;
    cout << "3. Peek Next Ticket" << endl;
    cout << "4. Search Ticket by ID" << endl;
    cout << "5. Display All Tickets" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;


    switch (choice) {
        case 1: {
        int id = 0;
        string name = "";
        string issue = "";
        cout << "Enter Ticket ID:";
        cin >> id;
        cout << "Enter Customer Name:";
        cin >> name;
        cout << "Enter Issue Description:";
        cin >> issue;
        //Create node with variables function call
        }
        break;
        case 2: 
        cout << "Serving Ticket";
        //function to print info at head of queue and "dequeue" it
        break;
        case 3: 
        cout << "Next Ticket to be Served:";
        //node function to print out data of behind head of queue
        break;
        case 4: { 
        int id;
        cout << "Enter TicketID to search:";
        cin >> id;
        // function that looks and prints node data if found
        }
        break;
        case 5: 
        //function that loops through queue and prints all nodes
        break;
        case 6: 
        cout << "Exiting System. Goodbye!";
        systemOn = false;
        break;
    }
}
    return 1;
}