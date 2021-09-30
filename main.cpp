#include <iostream>
#include <stack>
#include <windows.h>
#include <cstdlib>
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
		int Size=0;
	public:
		linkedList()
			{
				tail = NULL;
			}	
		void addNodeEnd(int value)
		{
			node *newnode = new node; //iskiria vieta atmintyje naujam "node" tipo kintamajam ir sukuria rodykle "temp", rodancia i nauja elementa
			node *temp;
			newnode->data = value; 
			if(IsEmpty())
			{
			newnode->next=newnode;
			tail = newnode;
			}
			else
			{
			newnode->next=tail;
			temp=tail;
			while(temp->next !=tail)temp=temp->next;
			temp->next=newnode;
			newnode->next=tail;
			}
			 temp=NULL;
			 Size++;
		}
		void addNodeStart(int value)
		{
			node *newnode = new node;
			newnode->data = value;
			if(IsEmpty())
			{
			tail = newnode;
			newnode->next=tail;
			}
			else
			{
			node *temp;
			temp=tail;
			while(temp->next !=tail)temp=temp->next;
			temp->next =newnode;
			newnode->next=tail;
			tail=newnode;
			}
			Size++;
		}
		void deleteNodeStart()
		{
			if(IsEmpty())
			{
				cout<<"EMPTY\n";
				return ;
			}
			else
			{
				node *temp;
				node *end;
				temp = tail;
				end = tail;
				while(end->next !=tail)end=end->next;
				tail=tail->next;
				end->next=tail;
				delete temp;
			}
			Size--;
		}
		void deleteNodeEnd()
		{
			if(IsEmpty())
			{
				cout<<"EMPTY\n";
				return ;
			}
			else
			{
				node *temp;
				node *end;
				temp = tail;
				end = tail;
				while(end->next !=tail)end=end->next;
				while(temp->next->next !=tail)temp=temp->next;
				temp->next = tail;
				delete end;
			}
			Size--;
		}
		void deleteNodePosition(int position)
		{
			position %=Size;
			if (position == 1)
			{
				deleteNodeStart();
				return;
			}
			else if(position == 0)
			{
				deleteNodeEnd();
				return;
			}
			else
			{
				node *cur;
				node *after;
				node *before;
				cur = tail;
				after = tail;
				before = tail;
				for(int i = 0; i <position-1;i++)cur=cur->next;
				for(int i = 0; i <position;i++)after=after->next;
				for(int i = 0; i <position-2;i++)before=before->next;
				before->next = after;
				delete cur;
			}

		}
		void addNodePosition(int position, int value)
		{
			position %=Size;
			if (position == 1)
			{
				addNodeStart(value);
				return;
			}
			else if(position == 0)
			{
				addNodeEnd(value);
				return;
			}
			else
			{
				node *cur;
				node *after;
				cur = tail;
				after = tail;
				node *newnode = new node;
				newnode->data=value;
				for(int i = 0; i <position-2;i++)cur=cur->next;
				for(int i = 0; i <position-1;i++)after=after->next;
				newnode->next=after;
				cur->next=newnode;
				Size++;
			}
		}
		void display()
		{
			if(IsEmpty())
			{
				cout<<"EMPTY\n";
				return ;
			}
			node *temp = tail;
			cout << temp->data << "\t";
			temp = temp->next;
			while(temp!= tail)
			{
				cout << temp->data << "\t";
				temp = temp->next;
			}
		}
		bool IsEmpty()
		{
			return(tail==NULL ||Size==0);
		}
		int size()
		{
			return Size;
		}
		bool search(int value)
		{
		node *cur;
		cur =tail;
		for(int i = 1; i<=Size;i++)
		{
		if(cur->data == value)return true;	
		}
		return false;
		}
		int searchPos(int value)
		{
		node *cur;
		cur =tail;
		for(int i = 1; i<=Size;i++)
		{
		if(cur->data == value)return i;	
		cur=cur->next;
		} 
		return -1;
		}
		void clear()
		{
			while(!IsEmpty())
			{deleteNodeEnd();}
		}
		void reversePointers()
		{
		node *cur = tail;
        node *before=tail;
		node *after = NULL;
		node *temp;
		while(before->next !=tail)before=before->next;
		temp=before;
        while (cur != temp) {
            after = cur->next;
            cur->next = before;
            before = cur;
            cur = after;
        }
		cur->next=before;
		tail=cur;
		};
		void reverseStack()
		{
		stack<int> stack;
        node* cur;
        cur = tail;
        for (int i = 1; i <= Size; i++)
        {
            stack.push(cur->data);
            cur = cur->next;
        }
        clear();
        while (!stack.empty())
        {
            addNodeEnd(stack.top());
            stack.pop();
        }
		}
};
void printMeniuBar(linkedList &list)
{
	cout<<"CIRCULAR LINKEDLIST COMMAND MENIU \t Size = "<<list.size()<<"\n\n";
	cout<<"COMMANDS: \n\n";
	cout<<"PRESS 1 FOR DISPLAY\n";
	cout<<"- - - - - - - - - - - -\n";
	cout<<"PRESS 2 to addNodeStart\n";
	cout<<"- - - - - - - - - - - -\n";
	cout<<"PRESS 3 to addNodeEnd\n";
	cout<<"- - - - - - - - - - - -\n";
	cout<<"PRESS 4 to addNodePosition\n";
	cout<<"- - - - - - - - - - - -\n";
	cout<<"PRESS 5 to deleteNodeStart\n";
	cout<<"- - - - - - - - - - - -\n";
	cout<<"PRESS 6 to deleteNodeEnd\n";
	cout<<"- - - - - - - - - - - -\n";
	cout<<"PRESS 7 to deleteNodePosition\n";
	cout<<"- - - - - - - - - - - -\n";
	cout<<"PRESS 8 to search\n";
	cout<<"- - - - - - - - - - - -\n";
	cout<<"PRESS 9 to reverse\n";
	cout<<"- - - - - - - - - - - -\n";
	cout<<"PRESS 0 to exit program\n";
}
int inputValue()
{	while(true)
	{
	system("cls");
	cout<<"Input a Value: ";
	int value;
	cin>>value;
	if (value == int(value))return value;
	}

}
void optionSearch(linkedList &list)
{
system("cls");
int option;
cout<<"Choose which search you want to execute: \n";
cout<<"1 Check if the value exists in the list\n";
cout<<"2 Check in what position is the value (-1 means it doesnt exist)\n";
cout<<"INPUT : ";
cin>>option;
cout<<"\nInput the value you want to check: ";
int value;
cin>>value;
	switch(option)
	{
	case 1:
	if(list.search(value))cout<<"IT'S IN THE LIST\n";
	else cout<<"VALUE IS NOT IN THE LIST";
	system("pause");
	break;
	case 2:
	cout<<"Position: "<<list.searchPos(value)<<endl;
	system("pause");
	break;
	default:cout<<"BAD INPUT";
	}
}
void optionreverse(linkedList list)
{
system("cls");
int option;
cout<<"Choose which search you want to execute: \n";
cout<<"1 Reverse the list with Pointers\n";
cout<<"2 Reverse the list with a Stack\n";
cout<<"INPUT : ";
cin>>option;
	switch(option)
	{
	case 1:
	list.reversePointers();
	break;
	case 2:
	list.reverseStack();
	break;
	default:cout<<"BAD INPUT";
	}

}
int main()
{
	linkedList listas;
	int position;
while(1)
	{
	system("CLS");
	printMeniuBar(listas);
	int answer;
	cin>>answer;
	switch(answer)
	{
	case 1:
	system("cls");
	listas.display();
	cout<<endl;
	system("pause");
	break;
	case 2:
	system("cls");
	listas.addNodeStart(inputValue());
	break;
	case 3:
	system("cls");
	listas.addNodeEnd(inputValue());
	break;
	case 4:
	system("cls");
	cout<<"Size= "<<listas.size()<<"\n";
	cout<<"Position can go over the size and will loop\n";
	cout<<"Position that is equel to the size will be added to the end\n";
	cout<<"Position 1 will be added to the start\n";
	cout<<"negative position is not accepted\n";
	cout<<"Input position: ";
	cin>>position;
	if(position <0)
	{
		cout<<"\nBAD INPUT\n";
		system("pause");
		break;
	}
	listas.addNodePosition(position,inputValue());
	break;
	case 5:
	listas.deleteNodeStart();
	break;
	case 6:
	listas.deleteNodeEnd();
	break;
	case 7:
	system("cls");
	cout<<"Size= "<<listas.size()<<"\n";
	cout<<"Position can go over the size and will loop\n";
	cout<<"Position that is equel to the size will be deleted at the end\n";
	cout<<"Position 1 will deleted at the start\n";
	cout<<"negative position is not accepted\n";
	cout<<"Input position: ";
	cin>>position;
	if(position <0)
	{
		cout<<"\nBAD INPUT\n";
		system("pause");
		break;
	}
	listas.deleteNodePosition(position);
	break;
	case 8:
	optionSearch(listas);
	break;
	case 9:
	optionreverse(listas);
	break;
	default: exit(0); 
	}
	
	}
	return 0;
}

