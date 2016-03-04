#include "fifo.h"
#include "stdafx.h"

//This initializes the FIFO structure with the given buffer and size
void FIFO_init(FIFO_t * pToMyFifo, unsigned char * pToMydataBuffer, int size)
{
     pToMyFifo->count = 0;
     pToMyFifo->headIndex = 0;
     pToMyFifo->tailIndex= 0;
     pToMyFifo->size = size;
     pToMyFifo->dataBuffer = pToMydataBuffer;
}


//This reads nbytes bytes from the FIFO
//The number of bytes read is returned
int FIFO_pull(FIFO_t * pToMyFifo, unsigned char *pToMydataBuffer, int numberOfBytes)
{

	 int i;
     unsigned char * p;
     p = pToMydataBuffer;

     for(i=0; i = numberOfBytes; i++){

          if( pToMyFifo->tailIndex != pToMyFifo->headIndex ){ //see if any data is available

               *p++ = pToMyFifo->dataBuffer[pToMyFifo->tailIndex];  //grab a byte from the buffer

               pToMyFifo->tailIndex++;  //increment the tail
			  // pToMyFifo->count--;

               if( pToMyFifo->tailIndex == pToMyFifo->size ){  //check for wrap-around

                    pToMyFifo->tailIndex = 0;
               }
          } else {
               return i; //number of bytes read 
          }
     }
     return numberOfBytes;

    /*int count = 0;
    //uint8_t *buf = (uint8_t*)p;
	int8_t *buf = (uint8_t*)p;

    while((nbytes > 0) && (f->count > 0))
    {
        buf[count] = f->buf[f->r];
        f->r = (f->r + 1) % f->size;
        f->count--;
        count++;
        nbytes--;
    }

    return count;*/
}

//This writes up to nbytes bytes to the FIFO
//If the head runs in to the tail, not all bytes are written
//The number of bytes written is returned
int FIFO_push(FIFO_t * pToMyFifo, const unsigned char *pToMydataBuffer, int numberOfBytes)
{
    int count = 0;
    const unsigned char * p;

	p = pToMydataBuffer ;

	for(count=0; count < numberOfBytes; count++)
	{
		

           //first check to see if there is space in the buffer
		if( (pToMyFifo->headIndex + 1 == pToMyFifo->tailIndex) ||
			( (pToMyFifo->headIndex + 1 == pToMyFifo->size) && (pToMyFifo->tailIndex==0) ) )
		{
			return count; // mo more room

		}else{

			pToMyFifo->dataBuffer[pToMyFifo->headIndex] = *p++;
			pToMyFifo->headIndex++;  //increment the head
			//pToMyFifo->count++;

			if( pToMyFifo->headIndex == pToMyFifo->size){  //check for wrap-around
                    pToMyFifo->headIndex = 0;
               }
		}

           
      

	
	}
	return numberOfBytes;     
    /*uint8_t *buf = (uint8_t*)p;

    while((nbytes > 0) && (f->count < f->size))
    {
        f->buf[f->w] = buf[count];
        f->w = (f->w + 1) % f->size;
        f->count++;
        count++;
        nbytes--;
    }*/

    //return count;
}

bool FIFO_isFull(FIFO_t *pToMyFifo)
{
    return (pToMyFifo->count == pToMyFifo->size);
}

// Return true if fifo is empty
bool FIFO_isEmpty(FIFO_t *pToMyFifo)
{
    return (pToMyFifo->count == 0);
}

int FIFO_getFreeSpace(FIFO_t *pToMyFifo)
{
    return (pToMyFifo->size - pToMyFifo->count);
}
