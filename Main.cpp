//////// Main.cpp //////
#include <iostream>
#include <string>
#include "bst.h"
using namespace std;

BinarySearchTree<int> t(-999); 

void insert();
void print();
void find();
void remove();

////////////////////////////// MAIN //////////////////////////////
int main() {
	
	string choice;
	bool stop = true;
	
	do {
		system("cls");
		cout<<"/////// Assignment2:BST \\\\\\\\\\\\\\ \n\n";
		cout<<"\t1.Insert\n";
		cout<<"\t2.PrintTree\n";
		cout<<"\t3.Find\n";
		cout<<"\t4.Remove\n";
		cout<<"\t5.Quit\n\n";
		cout<<"Enter Choice: ";
		cin>>choice;

		switch(choice[0]) {
			case '1': {
				insert();
				break;
			}
			case '2': {
				print();
				break;
			}
			case '3': {
				find();
				break;
			}
			case '4': {
				remove();
				break;
			}
			case '5': {
				system("cls");
				stop = false;
				break;
			}
			default: {
				cout<<"\n!!! Wrong choice. Please Try Again !!! \n\n";
				system("pause");
				break;
			}
		}
	} while(stop);
	return 0;
}

////////////////////////////// INSERT ///////////////////////////////

void insert() {
	int element;
	bool stop = true;

	do {
		system("cls");
		cout<<"======= INSERT MODE ======\n";
		cout<<"\nEnter Element: ";
		cin>>element;
		
		if (t.find(element) == -999) {
			t.insert(element);
			stop = false;
			cout<<"\nInsert Element Successful. !!!\n"<<endl;
		} else {
			cout<<"\nThis element has in Tree. \n!!! Please Try Again. !!!\n\n";
			system("pause");
		}
	} while(stop);
}

////////////////////////////// PRINT ////////////////////////////////

void print() {
	string choice;
	bool stop = true;

	do {
		system("cls");
		cout<<"====== PRINT MODE ======\n\n";
		cout<<"\t1.Pre Order\n";
		cout<<"\t2.In Order\n";
		cout<<"\t3.Post Order\n";
		cout<<"\t4.Back\n\n";
		cout<<"Enter Choice: ";
		cin>>choice;
		cout<<endl;

		if(choice[0] > '0' && choice[0] < '4') {
			t.printTree(choice[0]);
			cout<<endl<<endl;
			system("pause");
		} else if(choice[0]=='4') {
			stop=false;
		} else {
			cout<<"!!! Wrong choice Please Try Again !!! \n\n";
			system("pause");
		}
	} while(stop);
}

////////////////////////////// FIND /////////////////////////////////

void find() {
	string choice;
	int element;
	bool stop = true;

	do {

		system("cls");
		cout<<"====== FIND MODE ======\n\n";
		cout<<"\t1.Find Element\n";
		cout<<"\t2.Find Min\n";
		cout<<"\t3.Find Max\n";
		cout<<"\t4.Back\n\n";
		cout<<"Enter Choice : ";
		cin>>choice;

		switch(choice[0]) {
			case '1': {
				system("cls");
				cout<<" ====== FIND ELEMENT MODE ======\n\n";
				cout<<"Enter element for Find in Tree : ";
				cin>>element;

				if(t.findChild(element) == -999) {
					cout<<"\n!!! CHILD NOT FOUND !!!\n\n";
				}
				system("pause");
				break;
			}
			case '2': {
				system("cls");
				cout<<" ====== FIND MIN MODE ======\n\n";
				t.findMin();
				system("pause");
				break;
			}
			case '3': {
				system("cls");
				cout<<" ====== FIND MAX MODE ======\n\n";
				t.findMax();
				system("pause");
				break;
			}
			case '4': {
				stop=false;
				break;
			}
			default: {
				cout<<"!!! Wrong choice Please Try Again !!! \n\n";
				system("pause");
				break;
			}
		}
	} while(stop);
}

////////////////////////////// REMOVE ///////////////////////////////

void remove() {

	int element;
	
	system("cls");
	cout<<"======= REMOVE MODE ======\n";
	cout<<"\nEnter Element: ";
	cin>>element;
	if(t.find(element) != -999) {
		t.remove(element);
		cout<<"\n!!! Remove Element Successful. !!!\n\n";
	} else {
		cout<<"\nThis element haven't in Tree. \n";
		cout<<"!!! Please Try Again. !!!\n\n";
		system("pause");
	}
}
