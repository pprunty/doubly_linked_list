#include <stdio.h>
#include <stdlib.h>

// Headers
#include "linked_list.h"
#include "matrix.h"


/*! \brief          A simple function used to create and append a new node to the linked list.
 *  \param inlist   A list containing pointers to the head and tail of the linked list.
 *  \param N        The size, N, of the n x n square matrix the new appended node will store.
 */
int append_new_node(List *const inlist, const int N) {


    // Dynamically allocate memory for Node structure to hold an N x N matrix
    Node *new_node = malloc(sizeof(Node));

    // Allocate memory
    alloc_cont_mem_sq_mat(&(new_node->data), N);

    // New node stores an n x n square matrix. Initialize N here.
    new_node->N = N;

    // If the head is empty then let the head become the new node and the tail be the new node
    if (inlist->head == NULL) {
        // Create an origin node
        inlist->head = new_node;
        inlist->tail = new_node;
    }
    /* If the head of the list isn't empty, i.e there exists a head, then add a new node to the tail, the previous to this node then
       points to the tail, and the tail points to the new node */
    else {
        // The tail (the last item in the list) points to the next item which is our new node
        inlist->tail->next = new_node; //<! Same as (*new.node).prev = (*inlist).tail

        // Our new node points to the previous node, namely the tail, since this is a doubly linked list
        new_node->prev = inlist->tail;

        // The tail is then our new node
        inlist->tail = new_node;

// 		Can use this if we are starting a list from the head (i.e a list does not already exist) instead of working with an existing list and adding to the tail
//		inlist->head->prev = new_node;
//		new_node->next = inlist->head;
//		inlist->head = new_node;
    }

    return 0;

}

/*! \brief          A simple function used to read a list containing matrix data.
 *  \param filename The name of the data file to read
 *  \param mylist   The linked list to read data into.
 */
void read_list_from_file(const char *const filename, List *mylist) {


    // Pointer to file, open file named "data.txt" in read mode
    FILE *fp;
    fp = fopen(filename, "r");

    // Go get the size of the file
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    // Set character array to be the size of the file
    char data_to_read[file_size];

    // Initialize pointer to stopstring so we can tell strtol where to stop later
    char *stopstring;

    // If our file is empty then print a standard error and exit program
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file 'data.txt'.\n");
        exit(1);
    }
    else {

        // Get the first line of the data, and continue to do so, until there are no more lines
        while (fgets(data_to_read, sizeof(data_to_read) /* file_size */, fp) != NULL) {

            // Let n be the first integer on each line
            int n = strtol(data_to_read, &stopstring,10);
            /*^ Note above: String to long int function takes our data, a pointer to the next string (the next int),
             * and a base number as arguments */

            //Send mylist data and dimension size for each line to append the new node
            append_new_node(mylist, n);

            //Iterate through each element of the matrix and set its value to the next floating point number in the data
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    mylist->tail->data[i][j] = strtof(stopstring, &stopstring); //<! String to float takes the next value
                }
            }
        }
    }
    fclose(fp);
}

/*! \brief          A simple function used to remove a node from a linked list.
 *  \param in       The inbound linked list.
 *  \param node     The node to be removed
 */
void remove_node(List *in, Node *node) {


    /* Case 1.  The node is the head and the tail then the next node, as well as the previous node, is empty (NULL) */
    if (node == in->head && node == in->tail) {
        node->next = NULL;
        node->prev = NULL;
        in->tail = NULL;
        in->head = NULL;
    }

    /* Case 2. The node is the tail, and we want to remove it from the list, then the previous node in the list
     * becomes the tail and the node next to the new tail is empty (since the previous node to the one we wanted to
     * remove is now the tail) */
    else if (node == in->tail) {
        in->tail = node->prev;          //<! Previous node is now the tail
        node->prev->next = NULL;        //<! The next node to the previous node is now empty
    }

    /* Case 3. The node is the head, and we want to remove it, then the next node in the list becomes our head, and
     * the previous node to the the new head is empty (since the next node to the one we wanted to remove is now the
     * head) */
    else if (node == in->head) {
        in->head = node->next;
        node->next->prev = NULL;
    }

    /* Case 4. If the node is not the head, and not the tail, i.e it is somewhere in the middle of the list, then the
     * previous node points to the next node, which is the node next to the one we wanted to remove. The next node now
     * points to the previous node which is the previous node to the one we wanted to remove. */
    else if (node != in->head && node != in->tail) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    free(node->data[0]);    // Go to the chunk memory which holds the matrix, starting at [0] and free its memory
    free(node->data);       // Free the chunk of memory that holds the array of pointers for the matrix
    free(node);             // Free the memory allocated for the node

}

/*! \brief          A simple function used to print the contents of the linked list.
 *  \param list     The linked list.
 */
void print_list_contents(List list) {


    // Set a pointer to a temporary node and let this node be the head (start) of the list
    Node *temp;
    temp = list.head;


    /* Whilst the temporary node does not point to null (i.e it is the tail) then
     * send the data corresponding to the node to the print matrix function along
     * with its dimension captured in the read_list_from_file function */
    while (temp->next != NULL) {
        print_sq_matrix(temp->data, temp->N);
        temp = temp->next;  //<! After sending the first node (the head) to be printed, make the head the next node and continue
    }

}
