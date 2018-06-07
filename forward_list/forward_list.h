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

      void clear(void)
      {
         while(head != NULL)
         {
            list_node *tmp = head;
            head = head->next;
            delete tmp; // TODO: use the smart pointers?
         }
         size = 0;
      }

      // fill version of the STL method
      void assign(int n, const T& val)
      {
         // first destroy the current content of the list
         clear();
         // then push the new values
         while(n--)
         {
            push_front(val);
         }
      }

      void reverse(void)
      {
         list_node *prev = NULL;
         list_node *next = NULL;

         while(head != NULL)
         {
            // save the next node
            next = head->next;
            // the new next is the previous!
            head->next = prev;
            // and move forward the pointers
            prev = head;
            head = next;
         }

         // on a not null list the new valid head is pointed by
         // 'prev', so set the head to this pointer.
         head = prev;
      }

      void print(void)
      {
         list_node *tmp = head;
         while(tmp != NULL)
         {
            std::cout << tmp->value << std::endl;
            tmp = tmp->next;
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
