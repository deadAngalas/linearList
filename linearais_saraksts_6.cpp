#include<iostream>
#include<cstdlib>
#include<conio.h>
#define N 100

using namespace std;

struct Node
{
  int data; // 4 bytes
  Node *link; // 4 bytes for adress as it is integer
};

void ProgEnd()
{
  system("cls");
  cout << "\n\n\t\t\tCLOSING...\n\n";
  cout <<"              ,---------------------------," << endl;
  cout <<"              |  ---------------------  |"<< endl;
  cout <<"              | |                       | |"<< endl;
  cout <<"              | |     Linked            | |"<< endl;
  cout <<"              | |         List          | |"<< endl;
  cout <<"              | |            Program    | |"<< endl;
  cout <<"              | |                       | |"<< endl;
  cout <<"              |  _____________________  |"<< endl;
  cout <<"              |___________________________|"<< endl;
  cout <<"            ,---_____     []     _______------,"<< endl;
  cout <<"            |      ______________           |"<< endl;
  cout <<"        ___________________________________   | ___"<< endl;
  cout <<"        |                                   |   |    )"<< endl;
  cout <<"        |  _ _ _                 [-------]  |   |   ("<< endl;
  cout <<"        |  o o o                 [-------]  |      _)_"<< endl;
  cout <<"        |__________________________________ |       "<< endl;
  cout <<"    -------------------------------------|      ( )"<< endl;
  cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  cout << endl;
}

Node *CreateNode()
{
  Node *newNode;
  newNode = new Node;	// 8 bytes for new node
  cout << "\nEnter number to node: ";
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

Node *AddEnd(Node *head)
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

Node *FindNode(Node *head, int x)
{
  Node *cur;
  cur = head;

  while(cur != NULL && cur->data != x)
  {
      cur = cur->link;
  }

  return cur;
}

Node *PreviousNode(Node *head, int x)
{
  Node *cur, *prev;
  cur = head;

  while(cur != NULL && cur->data != x)
  {
      prev = cur;
      cur = cur->link;
  }

  return prev;
}

Node *AddBefore(Node *head)
{
  // ask user
  int x;
  Node *cur, *newNode, *prev;
  cout << "Before which node add: ";
  cin >> x;

  // exist or not exist

  cur = FindNode(head, x);
  if(cur)
  {
    cout << "Node exist!\n";
    newNode = CreateNode();
    prev = PreviousNode(head, x);
    if(head->data == x)
    {
      newNode->link = head;
      head = newNode;
    }
    else
    {
      prev->link = newNode;
      newNode->link = cur;
      //newNode->link = cur;
      //prev->link = newNode;
    }
    cout << "New node is added!\n";
  }
  else cout << "Node does not exist!\n";

 return head;
}

Node *NextNode(Node *head, int x)
{
  Node *cur, *next;
  cur = head;

  while(cur != NULL && cur->data != x)
  {
      cur = cur->link;
  }
  //cur = cur->link;
  next = cur->link;

  return next;
}

Node *AddAfter(Node *head)
{
  int x;
  Node *cur, *newNode, *next;
  cout << "After which node add: ";
  cin >> x;

  cur = FindNode(head, x);

  if(cur)
  {
    cout << "Node exist!\n";
    newNode = CreateNode();
    next = NextNode(head, x);

    if(!next)
    {
      cur->link = newNode;
    }
    else
    {
      cur->link = newNode;
      newNode->link = next;
    }

    cout << "New node is added!\n";
  }
  else cout << "Node does not exist!\n";

  return head;
}

int NumberOfNodes(Node *head)
{
  Node *cur;
  cur = head;
  int amount = 0;

  while(cur != NULL)
  {
    cur = cur->link;
    amount++;
  }

  return amount;
}

Node* RemoveNodeBeginning(Node *head)
{
  Node* cur;
  cur = head->link; // next node after head
  delete head;

  return cur; // return new head
}

Node* RemoveNodeEnd(Node *head)
{
  Node *cur, *prev;

  if(head->link != NULL) // if there is more nodes after head
  {
    cur = head;

    while(cur->link!=NULL)
    {
      prev = cur;
      cur = cur->link;
    }
    delete cur; // delete last
    prev->link = NULL;
  }
  else // if head is the one node
  {
    head = RemoveNodeBeginning(head);
  }
  return head;
}

Node* RemoveAll(Node *head)
{
  Node* cur;
  while(head != nullptr)
  {
    cur = head;
    head = head->link; // next node
    delete cur; // delete current node
  }
  //head = nullptr;
  return head;
}

Node* RemoveBefore(Node *head)
{
  int x;
  cout << "Before which node remove: ";
  cin >> x;

  Node *cur, *prev, *prev2;

  cur = FindNode(head, x);

  if(cur)
  {
    cout << "Node exist!\n";
    if(head->data == x)
    {
      cout << "Nothing to delete!\n";
    }
    else
    {
      prev = PreviousNode(head, x);
      if(prev->data == head->data)
      {
        head = cur;
        delete prev;
      }
      else
      {
        prev2 = PreviousNode(head, prev->data);
        prev2->link = cur;
        delete prev;
      }
      cout << "Node has been removed!\n";
    }
  }
  else cout << "Node does not exist!\n";
  return head;
}

Node* RemoveAfter(Node *head)
{
  int x;
  cout << "After which node remove: ";
  cin >> x;

  Node *cur, *next, *next2;
  cur = FindNode(head, x);

  if(cur)
  {
    cout << "Node exist!\n";
    if(cur->link == NULL)
    {
      cout << "Nothing to delete!\n";
    }
    else
    {
      next = NextNode(head, x);
      if(next->link == NULL)
      {
        head = RemoveNodeEnd(head);
      }
      else
      {
        next2 = NextNode(head, next->data);
        delete next;
        cur->link = next2;
      }
      cout << "Node has been removed!\n";
    }
  }
  else cout << "Node does not exist!\n";
  return head;
}

int main()
{
  Node *head = NULL; // create place in computer memory adress
  // node is not created
  enum KEYS { num1 = 49, num2 = 50, num3 = 51 , num4 = 52, num5 = 53, num6 = 54, num7 = 55, num8 = 56, num9 = 57, num10 = 45, num11 = 61, num12 = 112, num13 = 91, num14 = 93 };
  /*
  num10 = 45; it is   -
  num11 = 61; it is   =
  num12 = 112; it is  p
  num13 = 91; it is   [
  num14 = 93; it is   ]
  */
  int choice;

  system("cls");
  cout << "\n\t\tLinked List\n\n";
  cout << "\n Author: Vladislav Ryazancev\n Ver: 5.2.7\n Date (start): 06.09.2023 / 14:33\n Date (end): 11.10.2023 / 16:13\n\n";

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
      cout << "6. Add node after\n";
      cout << "7. Show how many nodes exist\n";
      cout << "8. Print List\n";
      cout << "9. Remove node at the beginning\n";
      cout << "10. Remove node at the end (-)\n";
      cout << "11. Remove node before (=)\n";
      cout << "12. Remove node after (p)\n";
      cout << "13. Remove all nodes ([)\n";
      cout << "14. Stop Program (])\n\n";

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
          if(head)
          {
            AddAfter(head);
          }
          else cout << "Head does not exists! Create Head!\n";
          break;
        }
        case num7:
        {
          int amount = NumberOfNodes(head);
          cout << "Now there is " << amount << " node/s!";
          break;
        }
        case num8: PrintList(head); break;
        case num14: cout << "\nProgram is stopped! Goodbye!"; ProgEnd(); break;
        case num9:
        {
          if(head)
          {
            head = RemoveNodeBeginning(head);
            cout << "First node has been removed!\n";
          }
          else cout << "Head does not exists! Create Head!\n";
          break;
        }
        case num10:
        {
          if(head)
          {
            head = RemoveNodeEnd(head);
            cout << "Last node has been removed!\n";
          }
          else cout << "List is empty! Can not remove!\n";
          break;
        }
        case num11:
        {
          if(head)
          {
            head = RemoveBefore(head);
          }
          else cout << "List is empty! Can not remove!\n";
          break;
        }
        case num12:
        {
          if(head)
          {
            head = RemoveAfter(head);
          }
          else cout << "List is empty! Can not remove!\n";
          break;
        }
        case num13:
        {
          if(head)
          {
            head = RemoveAll(head);
            cout << "All nodes have been removed!!\n";
          }
          else cout << "List is empty! Can not remove!\n";
          break;
        }
        default: cout << "Incorrect input!\n";
      }
    } while(choice != num14);

  system("pause>nul");
  return 0;
}
