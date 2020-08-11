struct kfifo fifo;
int ret;

ret = kfifo_alloc(&fifo, PAGE_SIZE, GFP_KERNEL);
if(ret)
  return ret;

// fifo now represents a page_size queue
//
// if we want to do the init ourselves
void kfifo_init(struct kfifo *fifo, void *buffer, unsigned int size);

// enqueuing
unsigned int kfifo_in(struct kfifo *fifo, const void *from , unsigned int len);
// the return value can be o to len of bytes


// dequeue
unsigned int kfifo_out(struct kfifo *fifo, void *to, unsigned int len);


// just peek
unsigned int kfifo_out_peek(struct kfifo *fifo, void *to, unsigned int len, unsigned offset);

// other functions
static inline unsigned int kfifo_len(struct kfifo *fifo);
static inline unsigned int kfifo_avail(struct kfifo *fifo); // avaiable spce in bytes
static inline int kfifo_is_empty(struct kfifo *fifo);
static inline int kfifo_is_full(struct kfifo *fifo);

static inline void kfifo_rest(sttuct kfifo *fifo);
void kfifo_free(struct kfifo *fifo);  // use this when you iniit the fifo yourself

/*
 * Example Code
 */
unsigned int i;
// already create fifo size is 8KB
for(i=0; i<32; i++){
  kfifo_in(fifo, &i, sizeof(i));
}

// now fiifo contains 0-31
unsigned int val;
int ret;

ret = kfifo_out_peek(fifo, &val, sizeof(val), 0);
if(ret != sizeof(val))
  return -EINVAL;

printk(KERN_INFO "%u\n", val);  // should print 0

// Dequeue and print all
while(kfifo_avail(fifo)){
  unsigned int val;
  int ret;

  ret = kfifo_out(fifo, &val, sizeof(val));
  if(ret != sizeof(val))
      return -EINVAL;

  printk(KERN_INFO "%u\n", val);
}




















