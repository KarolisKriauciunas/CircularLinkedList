#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;	
};

class linkedList
{
	private:
		node *tail;
	public:
		linkedList()  //konstruktorius 
			{
				tail = NULL;
			}
			
		void addNodeEnd(int value)
		{
			node *newnode = new node; //iskiria vieta atmintyje naujam "node" tipo kintamajam ir sukuria rodykle "temp", rodancia i nauja elementa
			newnode->data = value;    //priskiria reiksmes naujam elementui
			if(IsEmpty())
			{
			tail = newnode;
			newnode->next=tail;
			}
			else
			{
			newnode->next=tail;
			}
		}
		void addNodeStart(int value)
		{
			node *newnode = new node; //iskiria vieta atmintyje naujam "node" tipo kintamajam ir sukuria rodykle "temp", rodancia i nauja elementa
			newnode->data = value;    //priskiria reiksmes naujam elementui
			if(IsEmpty())
			{
			tail = newnode;
			newnode->next=tail;
			}
			else
			{
			newnode->next=tail;
			tail=newnode;
			}
		}
		void display()
		{
			node *temp = tail;
			do
			{
				cout << temp->data << "\t";
				temp = temp->next;
			}while(temp->next != tail);
		}
		bool IsEmpty()
		{
			return(tail==NULL);
		}
};
int main()
{
	linkedList listas;
	listas.addNodeEnd(25);
	listas.addNodeEnd(10);
	listas.addNodeEnd(3);
	listas.addNodeEnd(125);
	listas.display();
	system("pause");
	return 0;
}
