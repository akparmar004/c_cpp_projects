#include <stdio.h>
#include <stdlib.h>

/* Define the structure of a memory block */
typedef struct memory_block {
  size_t size;
  struct memory_block *next;
} memory_block_t;

/* Define the head of the free list */
memory_block_t *free_list = NULL;

/* Allocate a block of memory of the given size */
void *my_malloc(size_t size) {
  /* Check if there is a free block of the given size */
  memory_block_t *block = free_list;
  while (block != NULL && block->size < size) {
    block = block->next;
  }

  /* If there is no free block of the given size, allocate a new one */
  if (block == NULL) {
    block = malloc(size + sizeof(memory_block_t));
    if (block == NULL) {
      return NULL;
    }

    block->size = size;
    block->next = NULL;
  }

  /* Remove the block from the free list */
  free_list = block->next;

  /* Return a pointer to the allocated memory */
  return (void *)block + sizeof(memory_block_t);
}

/* Free a block of memory */
void my_free(void *ptr) {
  /* Get the memory block header */
  memory_block_t *block = (memory_block_t *)((char *)ptr - sizeof(memory_block_t));

  /* Add the block to the free list */
  block->next = free_list;
  free_list = block;
}

/* Example usage */
int main() {
  /* Allocate a block of memory */
  void *ptr = my_malloc(100);

  if (ptr == NULL) {
    printf("Memory allocation failed\n");
    return 1; // Error handling
  }

  /* Use the memory */
  // For example, you can copy data into the allocated memory block:
  int data = 42;
  *(int *)ptr = data;
  printf("%d\n",*(int *)ptr);

  /* Free the memory */
  my_free(ptr);

  return 0;
}

