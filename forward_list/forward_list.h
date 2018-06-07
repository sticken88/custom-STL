#ifndef __FORWARD_LIST__
#define __FORWARD_LIST__
//@file
#include <iostream>

namespace mst
{
  /**
   * ForwardList. This class imitated the forward_list class in the STL that
   * comews with the C++.
   */
template <class T>
   class ForwardList
   {
   public:
      /**
      * ForwardList constructor.
      * Initializes the head of the list and helper variables.
      */
      ForwardList(){
         head = NULL;
         size = 0;
      }

      ~ForwardList(){}

      // TODO: what happens with an empty list?
      // STL says undefined behavior. Here is seg fault
      T& front(void)
      {
         return head->value;
      }

      bool empty(void)
      {
         return head == NULL;
      }

      void push_front(T value)
      {
         // fist create the new node
         list_node* new_node = create_node(value);
         // add it to the list
         new_node->next = head;
         head = new_node;
         size++;
      }

      void pop_front(void)
      {
         // copy the header
         list_node* _tmp = head;
         // update the head
         head = head->next;
         // delete the old head
         delete _tmp;
         size--;
      }

      void print(void)
      {
         while(head != NULL)
         {
            std::cout << head->value << std::endl;
            head = head->next;
         }
      }

   private:
      /* Define the stucture of each node */
      struct list_node{
      T value;
      list_node *next;
      };

      list_node *head;
      int size;

      /* Used to create a new node */
      list_node* create_node(T& value)
      {
         list_node* node = new list_node;
         node->value = value;
         node->next = NULL;

         return node;
      }
   };
};

#endif
