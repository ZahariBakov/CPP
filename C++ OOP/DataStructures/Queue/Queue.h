// Queue.h
// Template Queue class definition derived from class List.
#ifndef QUEUE_H
#define QUEUE_H

#include "List.h" // List class definition

template< typename QUEUETYPE >
class Queue: private List< QUEUETYPE > 
{
public:
   // enqueue calls List member function insertAtBack
   void enqueue( const QUEUETYPE &data ) 
   { 
      List<QUEUETYPE>::insertAtBack( data );
   } // end function enqueue

   // dequeue calls List member function removeFromFront
   bool dequeue( QUEUETYPE &data ) 
   { 
      return List<QUEUETYPE>::removeFromFront( data );
   } // end function dequeue

   // isQueueEmpty calls List member function isEmpty
   bool isQueueEmpty() const 
   {
      return List<QUEUETYPE>::isEmpty(); 
   } // end function isQueueEmpty

   // printQueue calls List member function print
   void printQueue() const 
   { 
      List<QUEUETYPE>::print(); 
   } // end function printQueue
}; // end class Queue

#endif
