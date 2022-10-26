#include<bits/stdc++.h>
using namespace std;
struct Node
{
   int coef;
   int pow;
   struct Node *next;
};

void node_creation(int x, int y, struct Node **temp)
{
   struct Node *a, *r;
   a = *temp;
   if(a == NULL)
   {
      r =(struct Node*)malloc(sizeof(struct Node));
      r->coef = x;
      r->pow = y;
      *temp = r;
      r->next = (struct Node*)malloc(sizeof(struct Node));
      r = r->next;
      r->next = NULL;
   } 
   else
   {
      r->coef = x;
      r->pow = y;
      r->next = (struct Node*)malloc(sizeof(struct Node));
      r = r->next;
      r->next = NULL;
   }
}

//polynomial addition
void add(struct Node *p1, struct Node *p2, struct Node *result)
{
   while(p1->next && p2->next) 
   {
      if(p1->pow > p2->pow) 
      {
         result->pow = p1->pow;
         result->coef = p1->coef;
         p1 = p1->next;
      }
      else if(p1->pow < p2->pow)
      {
         result->pow = p2->pow;
         result->coef = p2->coef;
         p2 = p2->next;
      } 
      else 
      {
         result->pow = p1->pow;
         result->coef = p1->coef+p2->coef;
         p1 = p1->next;
         p2 = p2->next;
      }
      result->next = (struct Node *)malloc(sizeof(struct Node));
      result = result->next;
      result->next = NULL;
   }
   while(p1->next || p2->next)
   {
      if(p1->next)
      {
         result->pow = p1->pow;
         result->coef = p1->coef;
         p1 = p1->next;
      }
      if(p2->next)
      {
         result->pow = p2->pow;
         result->coef = p2->coef;
         p2 = p2->next;
      }
      result->next = (struct Node *)malloc(sizeof(struct Node));
      result = result->next;
      result->next = NULL;
   }
}

//resultant polynomial
void display(struct Node *node)
{
   while(node->next != NULL)
   {
      printf("%dx^%d", node->coef, node->pow);
      node = node->next;
      if(node->next != NULL)
         printf(" + ");
   }
}
int main()
{
   struct Node *p1 = NULL, *p2 = NULL, *result = NULL;
   //creating polynomial1 p1 and polynomial2 p2
   node_creation(2,3,&p1);
   node_creation(1,1,&p1);
   node_creation(5,0,&p1);
   node_creation(3,4,&p2);
   node_creation(2,2,&p2);
   node_creation(8,1,&p2);
   printf("polynomial 1: ");
   display(p1);
   printf("\npolynomial 2: ");
   display(p2);
   result = (struct Node *)malloc(sizeof(struct Node));
   add(p1, p2, result);
   printf("\nresultant polynomial: ");
   display(result);
   return 0;
}
