#ifndef __FORWARD_LIST__
#define __FORWARD_LIST__

namespace mst
{
template <class T>
   class ForwardList
   {
   public:
      ForwardList(){
         head = NULL;
      }

      ~ForwardList(){}
   private:
      /* Define the stucture of each node */
      struct list_node{
      T value;
      list_node *next;
      };

      list_node *head;
   };
};

#endif
