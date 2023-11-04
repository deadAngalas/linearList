#include<iostream>
#include<cstdlib>
#define N 100

using namespace std;

struct Node
{
  int data;
  Node *link;
};

Node *CreateNode()
{
  Node *newNode; 		//1
  newNode = new Node;	//2
  cout << "\nIevadiet skaitli, kuru pievienot:  ";
  cin >> newNode->data;	//3
  newNode->link = NULL;	//4
  return newNode;		//5
}

void PrintList (Node *head)
{
  Node *cur;
  cout<<"Saraksta elementi:\n";
  cur = head;		//1
  while (cur != NULL)
      {
        cout << cur->data<<" ";	//2
        cur = cur->link; //pareja uz nakamo mezgli
      }
}

int main()
{

  Node *mezgls1, *mezgls2, *mezgls3;

  mezgls1 = CreateNode();
  mezgls2 = CreateNode();
  mezgls3 = CreateNode();

  // 1 2 3
  //mezgls1->link = mezgls2;
  //mezgls2->link = mezgls3;

  // 3 2 1
  mezgls3->link = mezgls2;
  mezgls2->link = mezgls1;

  cout << "\nmezgls1 data: " << mezgls1->data << endl;
  cout << "mezgls1 link: " << mezgls1->link << endl;

  cout << "\nmezgls2 data: " << mezgls2->data << endl;
  cout << "mezgls2 link: " << mezgls2->link << endl;

  cout << "\nmezgls3 data: " << mezgls3->data << endl;
  cout << "mezgls3 link: " << mezgls3->link << endl;

  // ar funkciju print
  cout << "\n\nPrint FUNCKIJA" << endl << endl;
  PrintList(mezgls3);

  system("pause>nul");
  return 0;
}
