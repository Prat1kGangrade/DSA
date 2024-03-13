/*                          LINKED LIST

linked list: multiple blocks of mamory linked to each other.


 # limitation of arrays

 1. fixed size.                         (once allocated a mamory then it can't be changed)
 2. Contiguous blocks of mamory.
 3. inserting or deleting is costly.

 # properties of linked list

 1. size can be modified.
 2. Non contiguous mamory.
 3. insertion and deletion at any point is easier.

      node => data|next
      where
           node: block of mamory
           data: int, float, char
           next: pointer which points the next node (stores the adress of next node)

           10k           20k          30k           40k
        | 1|20k|  =>  | 1|30k|  =>  | 1|40k|  =>  | 1|NULL|
           ^
         HEAD

        HEAD: HEAD pointer stores the address of the first node of the
              linked list.
*/
