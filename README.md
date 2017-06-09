Project Malloc EPITECH :

Students : Alexandre BRUN - Arthur CORUBLE

Function free_block() : Go through linked list of memory blocks from the beggining, check if the current
                        memory block is free to use and if it's size is at least equal to the one asked.
                        If so, return the current block. Else return NULL to indicate nothing has been found.

Function malloc(size_t) :   First check if the asked size is different from 0, if it is not, return NULL.
                            If the size is not 0, we try to get a block using the free_block() function.
                            Then, if we found a block, we mark it as used (is_free = 0), we cast it as (void*)
                            and move one byte to return only the space and not the metadata and the space.
                            If we don't find any free blocks of the size, we define a total_size (the size of
                            the metadata + the size asked) and asked the system for this size, using sbrk().
                            We check the return value of sbrk() and return NULL in case of error.
                            If sbrk() succeed, we define our header as the return value of sbrk(), set it's
                            attributes correctly, manipulate the linked list to add this node, and return
                            with the same process as before.

Function free(void \*) :    First of, same as malloc, we check if the pointer really points to something.
                            If not, return NULL.
                            Then, we get the metadata back from the block, casting it back to t_block.
                            We look for the break using sbrk(0). If the last adress of the pointer sent is
                            the same as the break, we will totally get rid of it.
                            If there is only one element in the linked list, set both head and tail to null.
                            If not, manipulate the linked list to have the right pointers and the right end.
                            Then, sbrk() is used with substracting the sizes of the metadata and it's data,
                            resulting in a real free of the memory to the system. Then return to exit free().
                            If we are not at the end, simply mark the block as free.

Function realloc(void \*, size_t) : Check if the sent pointer is not null or if the size is not null.
                                    If they are, just malloc the size asked.
                                    Get back the metadata, check if the size of the block is not already
                                    sufficient. If it is, just return the sent pointer.
                                    If not, create a new variable, malloc it of the asked size, copy it's
                                    data if malloc succeeded, and free the sent pointer.
                                    Then, return the new data.

Global :    Use of mutex for threading, have a global lock, defined as extern in the .h file.
            For each function except the free_block() and realloc() ones, 
            lock the memory region using the mutex lock,
            process, then unlock the mutex before returning the memory.
