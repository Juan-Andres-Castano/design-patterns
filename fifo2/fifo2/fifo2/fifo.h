#ifndef FIFO_H_INCLUDED
#define FIFO_H_INCLUDED

#include "stdafx.h"

//#include <stdbool.h>

typedef struct
{
     unsigned char * dataBuffer;
     int headIndex; //r
     int tailIndex;  //w
     int size;
     int count;
} FIFO_t;

void FIFO_init(FIFO_t * pToMyFifo, unsigned char * pToMydataBuffer, int size);

int FIFO_pull(FIFO_t * pToMyFifo, unsigned char * pToMydataBuffer, int numberOfBytes);

int FIFO_push(FIFO_t * pToMyFifo, const unsigned char *pToMydataBuffer, int numberOfBytes);

bool FIFO_isFull(FIFO_t *pToMyFifo);

bool FIFO_isEmpty(FIFO_t *pToMyFifo);

int FIFO_getFreeSpace(FIFO_t *pToMyFifo);

#endif	/* FIFO_H */

/*           |------------------------------|
			\|/								|  head/tail  wrap			
          ____________						|
		  |          |						|	
          |          |                      |
  tail--->|----------|                      |
	|     | Data0    |                      |
   \|/	  |----------|                      | 
   read   | Data 1   |                      | 
		  |----------|                      | 
		  | Data 2   |                      | 
		  |----------|                      |
		  | Data 3   |                      |
		  |----------|  <---head            |
		  |			 |	    |               | 
		  | Free     |     \|/              |
		  |          |      write           | 
		  |----------|                      |
                |							|
				|--------------------------
*/