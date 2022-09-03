using namespace std;

//Node class which is able to store token_number, customer name and the address of the adjacent node
class Node{
    public:
        int token_number;
        string customer_name;
        Node *next;
};

//Queue Implementation using Circular Linked List
class Queue{
    public:
        Queue(); 							//Constructor
        ~Queue();							//Destructor
        
        void enqueue(std::string name); 	//Inserting the customer's name, token number of the customer into the queue
        void dequeue();						//Displaying the customer's name, token number of the customer from the queue
        bool isEmpty();						//Checks if there are customers or not
    
    private:
    	Node* queue;						//The last entry of the Queue
    	int token;							//variable to check the token number
        
};

