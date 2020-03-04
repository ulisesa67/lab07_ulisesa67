#include <cassert>
#include "linkedList.h"
#include "linkedListFuncs.h"

//Precondition: A valid linked-list that may be possibly be empty
// and an integer value
// Postcondition: A new node with provided value is added to the
// end of the list. The head and tail pointers are appropriately
// updated


void addIntToEndOfList(LinkedList *list, int value)
{
   assert(list != NULL); // if list is NULL, we can do nothing.

   Node *p; // temporary pointer

   // TODO:
   // (1) Allocate a new node.  p will point to it.

   p = new Node;

   // (2) Set p's data field to the value passed in

   p -> data = value;
   // (3) Set p's next field to NULL

   p ->next = NULL;

   if (list->head == NULL){

      // (4) Make both head and tail of this list point to p
      list->head = p;
      list->tail = p;
   
   }
   
   else{

      // Add p at the end of the list.

      // (5) The current node at the tail? Make it point to p instead of NULL
      list->tail->next = p;
      // (6) Make the tail of the list be p now.

      list->tail = p;

   }
}


// Precondition: A valid linked-list on the heap and an integer value
// Poscondition: A new node is created with provided value and is
// added to the start of the list. The head and tail pointers are
// appropraitely updated


void addIntToStartOfList(LinkedList *list, int value)
{
   assert(list != NULL); // if list is NULL, we can do nothing.

   // Add code for this.
   // HINTS:
   //  You will need to allocate a new Node.
   //  You will need two cases just as in addIntToEndOfList,
   //  one for when list->head is NULL and another for when it is not.
   // You need to consider how to make sure that list->head changes to point to the new node
   // that you allocated.  And you will need to make sure that when you are done,
   // that if the new node is now the ONLY thing on the list, that tail points to it also,
   // and that the new node is pointing to NULL.
   // Otherwise, you'll need to be sure that
   //   if it is the only node on the list, or to the "old" head if there


   Node *p;

   p = new Node;

   p->data = value;

   p->next = NULL;

   if(list->head == NULL){
	   list->head = p;
	   list->tail = p;
   }

   else{
	   p->next = list->head;
	   list->head = p;
   }
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return a pointer to node with the largest value.
// You may assume list has at least one element
// If more than one element has largest value,
//  break tie by returning a pointer to the one the occurs
//  earlier in the list, i.e. closer to the head

Node *pointerToMax(LinkedList *list)
{

   // Code may assume that these assertions are true;
   //  so does not need to do error checking for these conditions.
   assert(list != NULL);
   assert(list->head != NULL);
   Node *p = list -> head;
   int max = list->head->data;
   Node *maxPointer;
   while(p != NULL){
	   if(p->data > max)
		   max = p->data;
	   p = p->next;
   }
   p = list->head;
   while(p != NULL){
	   if(p->data == max){
		   maxPointer = p;
		   break;
	   }
	   p = p->next;
   }
   return maxPointer;
}




// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return a pointer to node with the smallest value.
// You may assume list has at least one element
// If more than one element has smallest value,
//  break tie by returning a pointer to the one the occurs
//  earlier in the list, i.e. closer to the head

Node *pointerToMin(LinkedList *list)
{

   // Code may assume that these assertions are true;
   //  so does not need to do error checking for these conditions.

   assert(list != NULL);
   assert(list->head != NULL);
   Node *p = list->head;
   int min = list->head->data;
   Node *minPointer;
   while(p != NULL){
	   if(p->data < min)
		   min = p->data;
	   p = p->next;
   }

   p = list->head;
   while(p != NULL){
	   if(p->data == min){
		   minPointer = p;
		   break;
	   }
	   p = p->next;
   }
   return minPointer;
}
// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the largest value in the list.
// This value may be unique, or may occur more than once
// You may assume list has at least one element

int largestValue(LinkedList *list)
{

   // Code may assume that these assertions are true;
   //  so does not need to do error checking for these conditions.

   assert(list != NULL);
   assert(list->head != NULL);
   Node *p = list->head;
   int max = list->head->data;
   while(p != NULL){
	   if(p->data > max)
		   max = p->data;
	   p = p->next;
   }
   return max;
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the smallest value in the list.
// This value may be unique, or may occur more than once
// You may assume list has at least one element

int smallestValue(LinkedList *list)
{
   // Code may assume that these assertions are true;
   //  so does not need to do error checking for these conditions.

   assert(list != NULL);
   assert(list->head != NULL);

   Node *p = list->head;
   int min = list->head->data;
   while(p!=NULL){
	   if(p->data < min)
		   min = p->data;
	   p = p->next;
   }
   return min;
}
// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the sum of all values in the list.
// You may assume that list is not NULL
// However, the list may be empty (i.e. list->head may be NULL)
//  in which case your code should return 0.

int sum(LinkedList *list)
{
   // Code may assume that these assertions are true;
   //  so does not need to do error checking for these conditions.

   assert(list != NULL);

   if(list->head == NULL)
	   return 0;

   Node *p = list->head;
   int mySum;
   while(p!=NULL){
	   mySum += p->data;
	   p = p->next;
   }
   return mySum;
}
