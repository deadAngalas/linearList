#include<iostream>
#include<cstdlib>
#include <conio.h>
#define N 100

using namespace std;

struct Node
{
  int data; // 4 bytes
  Node *link; // 4 bytes for adress as it is integer
};

Node *CreateNode()
{
  Node *newNode;
  newNode = new Node;	// 8 bytes for new node
  cout << "\nEnter number to node:  ";
  cin >> newNode->data;
  newNode->link = NULL;
  return newNode;
}

void PrintList (Node *head)
{
  Node *cur; // adress
  cout<<"\nList elements:\n";
  cur = head;
  while (cur != NULL)
    {
      cout << cur->data << " ";
      cur = cur->link; //pareja uz nakamo mezgli
    }
}

int main()
{
  Node *head; // create place in computer memory adress

  enum KEYS { num1 = 49, num2 = 50, num3 = 51 , num4 = 52, num9 = 57 };
  int choice;

  system("cls");
  cout << "\n\t\tLinked List\n\n";
  cout << "\n Author: Vladislav Ryazancev\n Ver: 2.0.3\n Date (start): 29.04.2023 / 12:47\n Date (end): 01.05.2023 / 20:47\n\n";

  do
    {
      system("pause>nul");
      system("cls");

      cout << "\n What do you want to do: \n\n";
      cout << "1. Create head\n";
      cout << "2. Print head value and link\n";
      cout << "3. Create more nodes\n";
      cout << "4. Print List\n";
      cout << "9. Stop Program\n\n";

      choice = getch();

      switch(choice)
      {
        case num1: head = CreateNode(); break;
        case num2: cout << "Head data: " << head->data << endl;
                cout << "Head link: " << head->link << endl;
                system("pause>nul");
                break;
        case num3: // more nodes cikl
                system("pause>nul");
                break;
        case num4: PrintList(head);
                break;
        case num9: cout << "\nProgram is stopped! Goodbye!";
                break;

        default: cout << "Incorrect choice!\n";
      }
    } while(choice != num9);

  system("pause>nul");
  return 0;
}
