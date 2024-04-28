//============================================================================
// Name        : LinkedList.cpp
// Author      : Chase Carter
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Lab 3-3 Lists and Searching
//============================================================================

#include <algorithm>
#include <iostream>
#include <time.h>

#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// forward declarations
double strToDouble(string str, char ch);

// define a structure to hold bid information
struct Bid {
    string bidId; // unique identifier
    string title;
    string fund;
    double amount;
    Bid() {
        //bidId = "";
        amount = 0.0;
    }
};

//============================================================================
// Linked-List class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a linked-list.
 */
class LinkedList {

private:
    //Internal structure for list entries, housekeeping variables
    struct Node {
        Bid bid;
        Node* next;

        // default constructor
        Node() {
            next = nullptr;
        }

        // initialize with a bid
        Node(Bid aBid) {
            bid = aBid;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int size = 0;

public:
    LinkedList();
    virtual ~LinkedList();
    void Append(Bid bid);
    void Prepend(Bid bid);
    void PrintList();
    void Remove(string bidId);
    Bid Search(string bidId);
    int Size();
};

/**
 * Default constructor
 */
LinkedList::LinkedList() {
////////////////////////////////////////////////////////////////////
// FIXME (1): Initialize housekeeping variables

// Set head and tail equal to null.
    head = nullptr;
    tail = nullptr;
    size = 0;
}
////////////////////////////////////////////////////////////////////////
/**
 * Destructor
 */
LinkedList::~LinkedList() {
// Start at the start of the list.
    Node* current = head;
    Node* temp;

// Create a loop over for the nodes, 
// Seperate node from list then remove it.
    while (current != nullptr) {

// Get current the node.
        temp = current; 

// Get current node and move it into the next node.
        current = current->next;

// Remove node.
        delete temp; 
    }
}

/**
 * Append a new bid to the end of the list
 */
void LinkedList::Append(Bid bid) {
// FIXME (2): Implement append logic

//////////////////////////////////////////////////////////////////////////

// Create new node
     Node* newNode = new Node(bid);

// If there is nothing at the head assign 
    newNode->next = nullptr;

// new node becomes the head and the tail
    if (head == nullptr) {

// Make the head the new node.
        head = newNode;

// Make the tail the new node.
        tail = newNode;

// Increase the size of the count.
        ++size;
    }
// else 
    else {

// Make the tail point to the head which is the new node.
        tail->next = newNode;

// Set the tail to the new node.
        tail = newNode;

// increase size count
        ++size;
    }
}
    
///////////////////////////////////////////////////////////////////////


/**
 * Prepend a new bid to the start of the list
 */
void LinkedList::Prepend(Bid bid) {
 
////////////////////////////////////////////////////////////////

// FIXME (3): Implement prepend logic

// Create new node
    Node* newNode = new Node(bid);

// If there is nothing at the head assign 
    newNode->next = nullptr;

 // new node becomes the head and the tail
    if (head == nullptr) {

// Make the head the new node.
        head = newNode;

// Make the tail the new node.
        tail = newNode;

// Increase the size of the count.
         ++size;

    }
// else
    else {

// The node points to current head as its next node
        newNode->next = head;

// The head now becomes the new node
        head = newNode;

// Increase size count
        ++size;
    }
}
////////////////////////////////////////////////////////////////

/**
 * Simple output of all bids in the list
 */
void LinkedList::PrintList() {  
       
/////////////////////////////////////////////////////////////////

// FIXME (4): Implement print logic

// Start at the head.
    Node* temp = head;

// Create a while loop over each node looking for a match.
    while (temp != nullptr) {

// Make the output current bidID, title, amount and fund.
        cout << temp->bid.title << " | ";
        cout << temp->bid.amount << " | ";
        cout << temp->bid.fund << endl;

// Set current equal to next
        temp = temp->next;
    }
//////////////////////////////////////////////////////////////////
}

/**
 * Remove a specified bid
 *
 * @param bidId The bid id to remove from the list
 */
void LinkedList::Remove(string bidId) {
      
////////////////////////////////////////////////////////////////////
// FIXME (5): Implement remove logic

// If the head node is empty.
    if (head == nullptr)

// Return.
        return;

// Start at the head of list.
    Node* current = head;
    Node* prev = nullptr;

// If head needs to be deleted.
    if (current->bid.bidId == bidId) {

// Make head point to the next node in the list  
        head = current->next;

// Deletes current node.
        delete current;

// Decrease size count.
        --size;

// If head is null, the list is empty. 
        if (head == nullptr)

 // Set the tail to null too.
            tail = nullptr;

// Exit the function
        return;
    }
    
// While loop over each node looking for a match.   
    while (current != nullptr && current->bid.bidId != bidId) {

// Search for the bid to remove.
        prev = current;

// Make current node point beyond the next node.
        current = current->next;
    }
// If the current bid id is equal empty bid id.
    if (current == nullptr)

// Return.
        return;

// If bid was not found. 
    prev->next = current->next;

// Remove bid
    delete current;

// Decrease size count.
    --size;

// Update tail if the last node is removed.
    if (prev->next == nullptr)

// The tail is the last node after it is removed.
        tail = prev;

}
//////////////////////////////////////////////////////////////////////
/**
 * Search for the specified bidId
 *
 * @param bidId The bid id to search for
 */
Bid LinkedList::Search(string bidId) {

////////////////////////////////////////////////////////////////////////

// FIXME (6): Implement search logic

// Start at the head of the list
    Node* temp = head;

// Loop until the end of the list is reached
    while (temp != nullptr) {

// If the current node matches the bidId, return the bid
        if (temp->bid.bidId == bidId) {

// Return.
            return temp->bid;
        }
// Move to the next node
        temp = temp->next;
    }

// Return empty bid if its not found.    
    return Bid();
}
////////////////////////////////////////////////////////////////////////


/**
 * Returns the current size (number of elements) in the list
 */
int LinkedList::Size() {

// Return the size of the list 
    return size;
}

//============================================================================
// Static methods used for testing
//============================================================================

/**
 * Display the bid information
 *
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid) {
    cout << bid.bidId << ": " << bid.title << " | " << bid.amount
        << " | " << bid.fund << endl;

// Returns function
    return;
}

/**
 * Prompt user for bid information
 *
 * @return Bid struct containing the bid info
 */
Bid getBid() {
    Bid bid;

    cout << "Enter Id: ";
    cin.ignore();
    getline(cin, bid.bidId);

    cout << "Enter title: ";
    getline(cin, bid.title);

    cout << "Enter fund: ";
    cin >> bid.fund;

    cout << "Enter amount: ";
    cin.ignore();
    string strAmount;
    getline(cin, strAmount);
    bid.amount = strToDouble(strAmount, '$');

    return bid;
}

/**
 * Load a CSV file containing bids into a LinkedList
 *
 * @return a LinkedList containing all the bids read
 */
void loadBids(string csvPath, LinkedList* list) {
    cout << "Loading CSV file " << csvPath << endl;

// initialize the CSV Parser
    csv::Parser file = csv::Parser(csvPath);

    try {
// loop to read rows of a CSV file
        for (int i = 0; i < file.rowCount(); i++) {

// initialize a bid using data from current row (i)
            Bid bid;
            bid.bidId = file[i][1];
            bid.title = file[i][0];
            bid.fund = file[i][8];
            bid.amount = strToDouble(file[i][4], '$');

//cout << bid.bidId << ": " << bid.title << " | " << bid.fund << " | " << bid.amount << endl;
// add this bid to the end
            list->Append(bid);
        }
    }
    catch (csv::Error& e) {
        std::cerr << e.what() << std::endl;
    }
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}

/**
 * The one and only main() method
 *
 * @param arg[1] path to CSV file to load from (optional)
 * @param arg[2] the bid Id to use when searching the list (optional)
 */
int main(int argc, char* argv[]) {

    // process command line arguments
    string csvPath, bidKey;
    switch (argc) {
    case 2:
        csvPath = argv[1];
        bidKey = "98109";
        break;
    case 3:
        csvPath = argv[1];
        bidKey = argv[2];
        break;
    default:
        csvPath = "eBid_Monthly_Sales_Dec_2016.csv";
        bidKey = "98109";
    }

    clock_t ticks;

    LinkedList bidList;

    Bid bid;

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Enter a Bid" << endl;
        cout << "  2. Load Bids" << endl;
        cout << "  3. Display All Bids" << endl;
        cout << "  4. Find Bid" << endl;
        cout << "  5. Remove Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            bid = getBid();
            bidList.Append(bid);
            displayBid(bid);

            break;

        case 2:
            ticks = clock();

            loadBids(csvPath, &bidList);

            cout << bidList.Size() << " bids read" << endl;

            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " milliseconds" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;

        case 3:
            bidList.PrintList();

            break;

        case 4:
            ticks = clock();

            bid = bidList.Search(bidKey);

            ticks = clock() - ticks; // current clock ticks minus starting clock ticks

            if (!bid.bidId.empty()) {
                displayBid(bid);
            }
            else {
                cout << "Bid Id " << bidKey << " not found." << endl;
            }

            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;

        case 5:
            bidList.Remove(bidKey);

            break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}
