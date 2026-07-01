#include <stdio.h>
#include <stdint.h>
#include "ring_buff.h"

void ring_buf_init(RingBuffer* rb)
{
    rb->head = 0;
    rb->tail = 0;
}

int ring_buf_empty(RingBuffer* rb)
{
    // returns 1 if empty, and 0 if NOT empty
    return (rb->head == rb->tail);
}

/* consider the buffer full when it is 
exactly one item away from being full*/
int ring_buf_full(RingBuffer* rb)
{
    if((rb->head + 1) % RING_BUF_SIZE == rb->tail)
    {
        return 1;
    }

    return 0;
}


int ring_buf_write(RingBuffer* rb, uint8_t data)
{
    if (ring_buf_full(rb)) return 0;

    rb->buf[rb->tail] = data;

    // tail needs to wrap round
    rb->tail = (rb->tail + 1) % RING_BUF_SIZE;
    return 1;
}


int ring_buf_read(RingBuffer* rb, uint8_t* data)
{
    if (ring_buf_empty(rb)) return 0;
    *data = rb->buf[rb->head];

    // advance the ptr, taking note of the wrap around logic
    rb->head = (rb->head + 1) % RING_BUF_SIZE;
    return 1;
}

int main()
{
    RingBuffer rb;
    ring_buf_init(&rb);

    
    printf("Ring buffer status: %d\n", ring_buf_empty(&rb));

    return 0;
}

