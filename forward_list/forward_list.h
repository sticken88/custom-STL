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

      ~ForwardList()
      {
         clear();
      }

      // fill version of the STL method
      //void assign(int n, int val)
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

      bool empty(void)
      {
         return head == NULL;
      }

      // TODO: what happens with an empty list?
      // STL says undefined behavior. Here is seg fault
      //int front(void)
      T& front(void)
      {
         return head->value;
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
         list_node *tmp = head;
         while(tmp != NULL)
         {
            std::cout << tmp->value << std::endl;
            tmp = tmp->next;
         }
      }

      //void push_front(int value)
      void push_front(T value)
      {
         // fist create the new node
         list_node* new_node = create_node(value);
         // add it to the list
         new_node->next = head;
         head = new_node;
         size++;
      }

      void resize(unsigned int n)
      {
        if(n == 0) clear();

        if((n > 0) && (n < size)) shrink_list(n);

        if(n > size)
        {
           T value;
           expand_list(n, value);
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

   private:
      /* Define the stucture of each node */
      struct list_node{
      //int value;
      T value;
      list_node *next;
      };

      list_node *head;
      int size;

      /* Used to create a new node */
      //list_node* create_node(int value)
      list_node* create_node(T& value)
      {
         list_node* node = new list_node;
         node->value = value;
         node->next = NULL;

         return node;
      }

      void shrink_list(unsigned int n)
      {
         list_node *ptr = head;
         // get to the last valid element
         while(--n) // the pre increment will do the trick
         {
            ptr = ptr->next;
         }
         // now ptr points to the last valid element
         // necessary to proper adjust the pointers
         list_node *next = ptr->next;
         ptr->next = NULL;
         while(next != NULL)
         {
            list_node *tmp = next;
            next = next->next;
            delete tmp;
            tmp = NULL; // otherwise the memory remains dirty
            size--;
         }
      }

      void expand_list(unsigned int n, T value)
      {
         int elements = n-size;
         // move to the last valid element
         list_node *original_head = head;
         // move to the last valid element
         while(head->next != NULL) head = head->next;

         // save the last valid pointer
         list_node *last_valid = head;
         // move the head to the next element where to insert new nodes
         head = head->next;

         // finally insert the new elements
         for(int i=0; i<elements; i++)
         {
            push_front(value);
         }

         // link the original list with the newly created one
         last_valid->next = head;
         // finally restore the original head
         head = original_head;
      }
   };
};

#endif
