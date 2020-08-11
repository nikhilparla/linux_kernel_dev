# linux_kernel_dev
Example codes from the Linux Kernel Development book

### Queues
* Implemented as kfifo
* Check the queue.c file with all the herlper functions

### Maps
* Implemented as binary search trees and not as hashmaps
* Designed only for one specific use case of mapping a uniqueID to a pointer
* The kernel map structure is called 'idr'
* Check map.c file 
