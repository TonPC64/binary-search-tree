//////// ‰ø≈Ï Main.cpp //////
#include<iostream>
#include<String>
#include "bst.h"
using namespace std;

BinarySearchTree<int> t(-999); 

void insert();
void print();
void find();
void remove();

////////////////////////////// MAIN //////////////////////////////

void main(){
	
	string choice;
	bool stop = true;
	
	
	do{
	system("cls");
	cout<<"/////// BINARY SEARCH TREE \\\\\\\\\\\\ \n\n";
	cout<<"\t1.) Insert\n\t2.) Print\n\t3.) Find\n\t4.) Remove\n\t5.) Quit\n\n";
	cout<<"Enter Choice : ";
	cin>>choice;

	switch(choice[0]){
	case '1':
		insert();
	break;
	case '2':
		print();
	break;
	case '3':
		find();
	break;
	case '4':
		remove();
	break;
	case '5' :
		system("cls");
		stop = false;
		break;
	default :
		cout<<"\n!!! Wrong choice Please Try Again !!! \n\n";
		system("pause");
	break;
	}
	}while(stop);
}

////////////////////////////// INSERT ///////////////////////////////

void insert(){
	int x;
	bool stop=true;
	do{
	system("cls");
	cout<<"======= INSERT MODE ======\n";
	cout<<"\nEnter element for insert to Tree : ";
	cin>>x;
	if(t.find(x)==-999)
	{
		t.insert(x);
		stop=false;
		cout<<"\n!!! Insert Element Successful. !!!\n"<<endl;

	}
	else 
		cout<<"\nThis element has in Tree. \n!!! Please Try Again. !!!\n\n";
		system("pause");
	}while(stop);
		
}

////////////////////////////// PRINT ////////////////////////////////

void print(){
	string choice;
	bool stop=true;

	do{
	system("cls");
	cout<<"====== PRINT MODE ======\n\n";
	cout<<"\t1.) Pre Order\n\t2.) In Order\n\t3.) Post Order\n\t4.) Back\n\n";
	cout<<"Enter Choice : ";
	cin>>choice;
	cout<<endl;

	if(choice[0]>'0'&&choice[0]<'4')
	{
		t.printTree(choice[0]);
		cout<<endl<<endl;
		system("pause");
	}
	else if(choice[0]=='4') 
		stop=false;
	else 
	{
		cout<<"!!! Wrong choice Please Try Again !!! \n\n";
		system("pause");
	}
	}while(stop);
}

////////////////////////////// FIND /////////////////////////////////

void find(){
	string choice;
	int x;
	bool stop= true;
	do{
	system("cls");
	cout<<"====== FIND MODE ======\n\n";
	cout<<"\t1.) Find Element\n\t2.) Find Min\n\t3.) Find Max\n\t4.) Back\n\n";
	cout<<"Enter Choice : ";
	cin>>choice;
	switch(choice[0]){
	case '1' :
		system("cls");
		cout<<" ====== FIND ELEMENT MODE ======\n\n";
		cout<<"Enter element for Find in Tree : ";
			cin>>x;
			if(t.findChild(x)==-999){
			cout<<"\n!!! CHILD NOT FOUND !!!\n\n";
			}
			system("pause");
		break;
	case '2' :
		system("cls");
		cout<<" ====== FIND MIN MODE ======\n\n";
		t.findMin();
		system("pause");
		break;
	case '3' :
		system("cls");
		cout<<" ====== FIND MAX MODE ======\n\n";
		t.findMax();
		system("pause");
		break;
	case '4' :
		stop=false;
		break;
	default :
		cout<<"!!! Wrong choice Please Try Again !!! \n\n";
		system("pause");
	break;
	}

	}while(stop);
}

////////////////////////////// REMOVE ///////////////////////////////

void remove(){

	int x;
	
	system("cls");
	cout<<"======= REMOVE MODE ======\n";
	cout<<"\nEnter element for Remove in Tree : ";
	cin>>x;
	if(t.find(x)!=-999)
	{
		t.remove(x);
		cout<<"\n!!! Remove Element Successful. !!!\n"<<endl;

	}
	else 
		cout<<"\nThis element haven't in Tree. \n!!! Please Try Again. !!!\n\n";
		system("pause");
	
}