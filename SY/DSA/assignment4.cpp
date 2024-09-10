#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	string data;
	Node *next;
	Node *prev;

	Node(){
		data = 0;
		next = NULL;
		prev = NULL;
	}

	Node(string d){
		data = d;
		prev = NULL;
		next = NULL;
	}

};

class Text Editor{
public:
	Node *head;

	void insert_text_start(string d){
		Node *nn = new Node(d);
		if(head == NULL){
			head = nn;
			cout << endl << "The List was empty and the text you entered is now the head";
		}
		else{
			Node *temp = head;
			nn-> next = temp;
			temp-> prev = nn;
		}
	}

	void insert_text_end(string d){
		Node *nn = new Node(d);
		Node *temp = new Node();
		temp = head;

		if(head == NULL){
			head = nn;
			cout << endl << "The list was empty hence text stored at the start ";
			return;
		}
		else{

			while(temp-> next != NULL){
				temp = temp-> next;
			}
			temp-> next = nn;
			nn-> prev = temp;
		}

	}

	void insert_text_inbetween(string d, string key){
		Node *nn = new Node(d);
		Node *temp = head;

		while(temp-> data != key && temp-> next != NULL){
			temp = temp-> next;
		}

		nn-> prev = temp;
		nn-> next = temp-> next;
		temp-> next = nn;
		temp = temp-> next-> next;
		temp-> prev = nn;
	}

	void delete_from_start(string d){
		if(head == NULL){
			cout << endl << "There is no text.";
			return;
		}
	}

	void delete_from_end(string d){

	}

	void delete_from_inbetween(string d, string key){

	}

	void Display_text(){

	}

	void Search_text(string key){

	}

	void Reverse_Print(){

	}

};