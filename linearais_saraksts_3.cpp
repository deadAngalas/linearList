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

Node *AddFirst(Node *head) // return adress
{
  Node *cur;
  cur = new Node; // izdalam ram uz 8 bait
  cur = CreateNode();
  cur->link = head;
  head = cur;
  return head;
}

void *AddEnd(Node *head)
{
  Node *cur, *cur1;
  // new node -----------
  cur1 = new Node;
  cur1 = CreateNode();
  // --------------------

  // list travelling
  cur = head;
  while (cur->link != NULL)
    {
      cur = cur->link;
    }

  cur->link = cur1;
  return head;
}

Node *AddBefore(Node *head)
{
  Node *cur;
  cur = head;
  // ask user
  int x;
  cout << "Before which node add: ";
  cin >> x;

  // check how many nodes exist
  int amount = 0;
  while(cur != NULL)
  {
    cur = cur->link;
    amount++;
  }

  //cout << "\namount = " << amount << endl;
  cur = head;
  // check is there x node or not
  if(x <= amount)
  {
    if(x == 1)
    {
      Node *first;
      first = new Node;
      first = CreateNode();

      first->link = head;
      head = first;
    }
    else
    {
      Node *prev, *vid;
      int i = 1;
      while(i < x)
      {
        prev = cur;
        cur = cur->link;
        i++;
      }
        vid = new Node;
        vid = CreateNode();

        prev->link = vid;
        vid->link = cur;
    }
  }
  else cout << "There is not your node number!";

 return head;
}

int main()
{
  Node *head = NULL; // create place in computer memory adress
  // node is not created
  enum KEYS { num1 = 49, num2 = 50, num3 = 51 , num4 = 52, num5 = 53, num6 = 54, num7 = 55, num8 = 56, num9 = 57, num10 = 45, num11 = 61 };
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
      cout << "3. Add node to list beginning\n";
      cout << "4. Add node to list end\n";
      cout << "5. Add node before\n";
      cout << "8. Print List\n";
      cout << "9. Stop Program\n\n";

      choice = getch();

      switch(choice)
      {
        case num1: head = CreateNode(); break;
        case num2:
        {
          if(head)
          {
            cout << "Head data: " << head->data << endl;
            cout << "Head link: " << head->link << endl;
          }
          else cout << "Head does not exists! Create Head!\n";
          system("pause>nul");
          break;
        }
        case num3: // add node to list beginning
                head = AddFirst(head);
                break;
        case num4: // add node to list end
        {
          if(head)
          {
            AddEnd(head);
          }
          else cout << "Head does not exists! Create Head!\n";
          break;
        }
        case num5: // add node before specific node
        {
          if(head)
          {
            head = AddBefore(head);
          }
          else cout << "Head does not exists! Create Head!\n";
          break;
        }
        case num6:
        {

          break;
        }
        case num7:
        {

          break;
        }
        case num8: PrintList(head); break;
        case num9: cout << "\nProgram is stopped! Goodbye!"; break;
        case num10: cout << "h"; break;
        case num11: cout << "f"; break;
        default: cout << "Incorrect choice!\n";
      }
    } while(choice != num9);

  system("pause>nul");
  return 0;
}
