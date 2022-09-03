#include <iostream>
#include "miniproject.h"
using namespace std;

/*
	CONSTRUCTOR FOR CLASS QUEUE
	here initially the queue is initialized to NULL and token is initialized to 0 i.e. there are no customers
*/
Queue::Queue(){
    queue=NULL;
    token=0;
}

/*
	DESTRUCTOR OF CLASS QUEUE
*/
Queue::~Queue(){
    
}

/*
	If the queue is NULL i.e. when there is no  customer then it returns true otherwise it returns false
*/
bool Queue::isEmpty(){
    if(queue==NULL){
        return true;
    }
    else{
        return false;
    }
}

//Inserting the customer's name, token number of the customer into the queue
void Queue::enqueue(string name){
    token = token + 1;
	Node* newNode= new Node(); 																//Creating a new node
	newNode->token_number=token;															//Assigning the token number to the node
    newNode->customer_name=name;															//Assigning the customer's name to the node
    /*
    	If the customer is the first to arrive
	*/
	if(isEmpty()){
        newNode->next=newNode;																//The node points to itself and is assigned as queue
        queue=newNode;
    }
    else{
        newNode->next=queue->next;															//The last entered node points to the first entered node
        queue->next=newNode;																
        queue=newNode;
    }
    cout<<endl;
    cout<<name<<endl;
	cout<<"Token Number :  "<<token<<endl;
	cout<<"NIC ASIA BANK BIRTAMOD"<<endl;	//Displays the respective token number assigned to the customer
}

/*
Displaying the customer's name, token number of the customer from the queue
*/
void Queue::dequeue(){
    int data;
    string nam;
    
    //If there are no customers's
    if(isEmpty()){
    	/*If true then displays the following*/
        cout<<"No customers are to be served."<<std::endl;
    }
    else{
    	/*If false then stores the token number in data variable and customers name in nam variable and removes the current node from the queue*/
    	Node* f=queue->next;
        data=f->token_number;
        nam=f->customer_name;
        queue->next=f->next;
        if(f==queue){
            queue=NULL;
        }
        cout<<endl;
		cout<<"Token Number : "<<data<<endl;
		cout<<"NAME: "<<nam<<endl;
		cout<<"Please proceed."<<endl;
		cout<<"NIC ASIA BANK BIRTAMOD"<<endl;//Displays the customer's name and their corresponding token number 
    }
    
}


int main(){
	char choice;
    int a;
    Queue q;
    
    cout<<"\n\t ------C++ PROGRAM TO GENERATE TOKEN------"<<endl;

    do{
    	int pin;																							//Stored the security pin to Bank Staffs and Bank Administrator 
		/*
			Displays the options for the customers, Bank Staff and Bank Administrator and takes the input from the user
		*/
		cout<<endl;
    	cout<<endl<<"Please enter 0 for getting a token(For Customers Only)"<<endl;
    	cout<<"Please enter 1 to call a customer(For Bank Purpose Only)" <<endl;
    	cout<<"Please enter 2 to terminate the program (For Bank administrator Only)"<<endl;
   		cin>>a;
   		
   		/*
   			Selects the case to be executed according to the input given the user
   		*/
   		switch(a){
   			/*
   				For the Customers. If given input is 0, then the customers name is asked and is assigned a particular token number
   			*/
   			case 0:
   				{
   				cin.ignore();
   				string N;
        		cout<<endl<<"please enter your name"<<endl;
        		getline(cin, N);
        		q.enqueue(N);
        		choice='y';
        		break;
        	}
        	/*
        		For the Bank staff. If the given input is 1, then the customers name and their corresponding token number are callled out on basis of First Come First serve
        	*/
        	case 1:
        	{
        		cout<<"Enter the pin code\t";
        		cin>>pin;																		//Asks for the security pin
        		/*
        			if the pin is correct then the function is executed, else error is displayed
				*/
				if(pin==2020){
        			q.dequeue();																	//customers name and their corresponding token number are callled out on basis of First Come First serve		
				}
        		else{
        			cout<<"Invalid Pin Number. Please Try Again"<<endl;	//Error Displayed
				}
        		choice='y';
        		break;
        	}
        	
        	
        	/*
        		For the Bank Administrator. If the given input is 2 , then the program terminates.
        	*/
        	
        	case 2:
        	{
        		
        		cout<<"Enter the pin code\t";
        		cin>>pin;																				//takes the security pin
        		/*
        			if the pin is correct then the program terminates, else error is displayed and the program doesnot terminates
				*/
        		if(pin==8576){
        			cout<<endl;
        			cout<<"The Token service is currently shut down due to some technical problems.\n    Any inconvinience caused is highly regretted.   \n\t NIC ASIA BANK Birtamode Branch" <<endl <<endl <<endl;
					choice='y';
				}
        		else{
        			cout<<"Invalid Pin Number. Please Try Again"<<endl;
					choice='y';
				}
        		break;
        	}
        	/*
        	If given input does not match any of the above cases then default case is executed where the user is asked to give correct input.
        	*/
        	default:
        		{
        		cout<<"\tplease enter correct command"<<endl <<endl;
        		choice='y';
        		break;
			}
		}
    	} while(choice=='y');
}
    





