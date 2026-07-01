#include <stdint.h>

#define RING_BUF_SIZE 16

typedef struct RingBuffer
{
    uint8_t buf[RING_BUF_SIZE];
    volatile uint32_t head;
    volatile uint32_t tail;
} RingBuffer;

void ring_buf_init(RingBuffer* rb);
int ring_buf_empty(RingBuffer* rb);
int ring_buf_full(RingBuffer* rb);
int ring_buf_write(RingBuffer* rb, uint8_t data);
int ring_buf_read(RingBuffer* rb, uint8_t* data);
