// fifo2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "fifo.h"
#include "iostream"

using namespace std;


#define TX_BUFFER_SIZE 100
#define RX_BUFFER_SIZE 100

#define COMM_READ_MESSAGE_SIZE 4

FIFO_t USART1_rxFifo;
FIFO_t USART1_txFifo;

static unsigned char txBuffer[TX_BUFFER_SIZE];
static unsigned char rxBuffer[RX_BUFFER_SIZE];



int _tmain(int argc, _TCHAR* argv[])
{

	unsigned char dataBuffer3[COMM_READ_MESSAGE_SIZE];
	//char dataBuffer1[COMM_READ_MESSAGE_SIZE];
	unsigned char dataBuffer2[COMM_READ_MESSAGE_SIZE];
//	char dataBuffer3[COMM_READ_MESSAGE_SIZE];

	FIFO_init(&USART1_rxFifo, rxBuffer, RX_BUFFER_SIZE);
    FIFO_init(&USART1_txFifo, txBuffer, TX_BUFFER_SIZE);

	cout << &USART1_txFifo << "addres  " << endl;
	cout << sizeof(USART1_txFifo) << "size of the buffer " << endl;
	cout << USART1_txFifo.dataBuffer << "addres of buffer " << endl;
	cout << USART1_txFifo.count << "count initial " << endl;
	cout << USART1_txFifo.headIndex << "head initial " << endl;
	cout << USART1_txFifo.tailIndex << "tail initial " << endl;


	dataBuffer3[0] = 0x01;
	dataBuffer3[1] = 0x02;
	dataBuffer3[2] = 0x03;
	dataBuffer3[3] = 0x04;
													//dataBuffer[3] = COMM_computeChecksum(dataBuffer, 3);
								//////////////////////	/*
								//////////////////////unsigned char COMM_computeChecksum(unsigned char* buffer, unsigned char length)
								//////////////////////{   //this code was provided with the ICD from GGI & SNC
								//////////////////////    unsigned char buf;
								//////////////////////    union
								//////////////////////    {
								//////////////////////        long           sum;
								//////////////////////        unsigned char  bytes[4];
								//////////////////////    } cksum;
								//////////////////////
								//////////////////////    unsigned char i;
								//////////////////////
								//////////////////////    cksum.sum = 1;
								//////////////////////
								//////////////////////    for ( i = 0; i < length; i++ )
								//////////////////////    {
								//////////////////////        buf = buffer[i];
								//////////////////////        cksum.sum += buf;
								//////////////////////    }
								//////////////////////
								//////////////////////    return cksum.bytes[0];
								//////////////////////
								//////////////////////}
								//////////////////////	*/

	//USART1_sendMessage(dataBuffer, 4);  // function call
	//void USART1_sendMessage(unsigned char* buf, int size) // function
	//FIFO_push(&USART1_txFifo, &buf[1], size-1);             // inside the last function/
	//int FIFO_push(FIFO_t * f, const void * p, int nbytes);  prototype

	//unsigned char* buf;
//	char* carac;
    
	//for(int i=0; i < 4; i++ )
	//{
	//*carac = 'a'; //(unsigned char)
		//if (!FIFO_isFull(&USART1_txFifo))
		{
		//printf(" pushing into the fifo\n");
		
        FIFO_push(&USART1_txFifo, dataBuffer3, 4);   // a[i] defined  = *(p+i) pointer   
		
		
		cout << USART1_txFifo.size << "size  " << endl;
		cout << USART1_txFifo.count << "count " << endl;
		cout << USART1_txFifo.headIndex << "head " << endl;
		cout << USART1_txFifo.tailIndex << "tail  " << endl;

		cout << (int)dataBuffer3[0] << "data 0 push " << endl;
		cout << (int)dataBuffer3[1] << "data 1 push " << endl;
		cout << (int)dataBuffer3[2] << "data 2 push " << endl;
		cout << (int)dataBuffer3[3] << "data 3 push " << endl;
		printf(" **************************************\n");

		
		}

	

	
printf(" **************************************\n");
printf("			SECOND STEP\n");
printf(" **************************************\n");
cout << USART1_txFifo.size << "size  " << endl;
		cout << USART1_txFifo.count << "count " << endl;
		cout << USART1_txFifo.headIndex << "head " << endl;
		cout << USART1_txFifo.tailIndex << "tail  " << endl;
 //while(1)
 //   {
 //       if (!FIFO_isEmpty(&USART1_rxFifo))
 //       {   //analyse each received caracter one by one.
 //           FIFO_pull(&USART1_rxFifo,dataBuffer,1);
 //           COMM_analyse(dataBuffer[0]);
	//for(int i1=0; i1 < 4; i1++ )
	{
		//&carac = &carac + 1;

		// if (!FIFO_isEmpty(&USART1_txFifo))
		 {
		cout << " *********** " << endl;		
		int rta = FIFO_pull(&USART1_txFifo, dataBuffer2, 4);
		//int rta = FIFO_pull(&USART1_txFifo, dataBuffer2[1], 1);
		//int rta = FIFO_pull(&USART1_txFifo, dataBuffer2[2], 1);
		//int rta = FIFO_pull(&USART1_txFifo, dataBuffer2[3], 1);
		//cout << " pushing into the fifo position" << i1 << endl ;// " the value" << carac << endl;
		cout << USART1_txFifo.size << "size  " << endl;
		//cout << USART1_txFifo.count << "count " << endl;
		cout << USART1_txFifo.headIndex << "head " << endl;
		cout << USART1_txFifo.tailIndex << "tail  " << endl;

		cout << (int)dataBuffer2[0] << "data 0 pull " << endl;
		cout << (int)dataBuffer2[1] << "data 1 pull " << endl;
		cout << (int)dataBuffer2[2] << "data 2 pull " << endl;
		cout << (int)dataBuffer2[3] << "data 3 pull " << endl;
		 }
	//else
	{
		cout << " FIFO is empty  now.. " << endl;
		 }

		
     }
    
printf(" **************************************\n");

		if(FIFO_isEmpty(&USART1_txFifo))
		{
		printf("empty");
		}else{
		printf("no empty");
		}

	printf("hola");
	return 0;
}

/*
void USART1_rx_isr() {
    unsigned char carac;
    carac = RCREG1;
    if (!FIFO_isFull(&USART1_rxFifo))
    {
        FIFO_push(&USART1_rxFifo, &carac, 1);
    }
}


void USART1_tx_isr() {
    unsigned char carac;
    if (!FIFO_isEmpty(&USART1_txFifo)) {
        FIFO_pull(&USART1_txFifo, &carac, 1);
        TXREG1 = carac;
    } else {
        disableTxInterrupt();
        USART1_txStopped = 1;
    }
}
void USART1_init() {
    TXSTA1 = 0x20; //TXEN = 1
    RCSTA1 = 0x90; //SPEN = 1 and CREN = 1
    SPBRG1 = 15; // BAUDRATE = FOSC/(64(SPBGR1 + 1))
    // 9600 = 10 000 000/(64*(SPBGR1 + 1)) -> SPBGR1 = 15.28 = 15
    INTCON |= 0xC0; //GIE = 1 and PEIE = 1
    PIE1 |= 0x20; //RC1IE = 1
    USART1_txStopped = 1;
    FIFO_init(&USART1_rxFifo, rxBuffer, RX_BUFFER_SIZE);
    FIFO_init(&USART1_txFifo, txBuffer, TX_BUFFER_SIZE);
    // Enable RS232 Transceiver 
    LATCbits.LATC5 = 0;
    TRISCbits.TRISC5 = 0;
}


void USART1_sendMessage(unsigned char* buf, int size) {
    di();
    if (USART1_txStopped)
    {
        FIFO_push(&USART1_txFifo, &buf[1], size-1);
        TXREG1 = buf[0];
        enableTxInterrupt();
        USART1_txStopped = 0;
    }
    else
    {
        if (size <= FIFO_getFreeSpace(&USART1_txFifo))
        {
            FIFO_push(&USART1_txFifo, buf, size);
        }
    }
    ei();
}

static void enableTxInterrupt() {
    PIE1 |= 0x10;
}

static void disableTxInterrupt() {
    PIE1 &= ~0x10;
}

*/

