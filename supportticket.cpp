/*
Charles Kolb
Data Structures and Algorithims 
CS-3353-23039
*/


#include <iostream>
#include <string.h>
using namespace std;
// this will probably end up being a type of queue (fifo)
class Node {
    public:
     string name;
     int id;
     string issue;
     Node* nextptr;
     Node* prevptr;

    Node(int newid, string newname, string newissue) {
       this->id = newid;
       this->name = newname;
       this->issue = newissue;
        nextptr = nullptr;
        prevptr = nullptr;
     }
    };
    

    Node* addTicketToQueue(Node* a, Node* head) {
        if (head == nullptr) {
            head = a;
            return head;
        }
        
        head->prevptr = a;
        a->nextptr = head;
        head = a;
        
        return head;
    }

    Node * assignTail(Node* tail, Node* head) {
        Node* curr = head;

        while (curr->nextptr != nullptr) {
            curr = curr->nextptr;
        }

        tail = curr;

        return tail;
    }


   bool searchForTicket(int searchid, Node* head, Node* tail) {
        if (head == nullptr) {return false; }
        if (head->id == searchid) {
            cout << "Ticket Found:" << endl;
            cout << "TicketID: " << head->id <<
		    " Customer Name: " << head->name <<
		    " Issue: " << head->issue << endl;
	    return true;
        }
        while (head != tail) {
            if (head->id != searchid && tail->id != searchid) {
                head = head->nextptr;
                tail = tail->prevptr;
            } else if (head->id == searchid) {
               cout << "Ticket Found:" << endl;
               cout << "TicketID: " << head->id
		   << " Customer Name: " << head->name
		   << " Issue: " << head->issue << endl;
              return true;
            } else if (tail->id == searchid) {
                 cout << "Ticket Found:" << endl;
                 cout << "TicketID: " << tail->id
		      << " Customer Name: " << tail->name
		      << " Issue: " << tail->issue << endl;
              return true;
            }
        }

        cout << "Ticket not found in the pool."<< endl;
        return false;
   }  

    void traverseTicketQueue(Node* head, Node* tail) {
        if (head == nullptr) {
            cout << "Ticket pool is empty. No tickets to display." << endl;
            return;
        }
        cout << "All Pending Tickets in Pool: " << endl;
        while (tail != nullptr){
            cout << "TicketID: " << tail->id
		 << " Customer Name: " << tail->name
		 << " Issue: " << tail->issue << endl;
            tail = tail->prevptr;
        }
       
    }

    // test to reverse ticket queue
   void reverseTicketQueue(Node* tail) {
        while (tail != nullptr){
            cout << "TicketID: " << tail->id
		 << " Customer Name: " << tail->name
		 << " Issue: " << tail->issue << endl;
            tail = tail->prevptr;
        }
    }

    Node* serveTicket(Node* tail) {
       if (tail == nullptr) {
		cout << "No Ticket to be served" << endl;
		return nullptr;
       }
       cout << "TicketID: " << tail->id
	    << " Customer Name: " << tail->name
	    << " Issue: " << tail->issue << endl;
       Node* temp = tail->prevptr;
       delete tail;
       temp->nextptr = nullptr;
       return temp;
    }


    void peekTicket(Node* tail) {
        cout << "TicketID: " << tail->id
	     << " Customer Name: " << tail->name
	     << " Issue: " << tail->issue << endl;
    }




    
int main(void) {
	bool systemOn = true;
	Node* head = nullptr;
	Node* tail = nullptr;
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
				string issue;
				cout << "Enter Ticket ID:";
				cin >> id;
				cout << "Enter Customer Name:";
				cin >> name;
				cout << "Enter Issue Description:";
				cin.ignore();
				getline(cin, issue);
				Node* newTicket = new Node(id, name, issue);
				if (searchForTicket(newTicket->id, head, tail) == false) {
					head = addTicketToQueue(newTicket, head);
					tail = assignTail(tail, head);
					cout << "Ticket added successfully to the pool." << endl;
				} else {
					cout << "Ticket already is queued" << endl;
				}
				break;
			}
			case 2: 
				cout << "Serving Ticket";
				tail = serveTicket(tail);
				break;
			case 3: 
				cout << "Next Ticket to be Served:";
				peekTicket(tail);
				break;
			case 4:
				int id;
				cout << "Enter TicketID to search:";
				cin >> id;
				searchForTicket(id, head, tail);
				break;
			case 5: 
				traverseTicketQueue(head, tail); 
				break;
			case 6: 
				cout << "Exiting System. Goodbye!" << endl;
				systemOn = false;
				break;
		}
	}
	return 0;
}
