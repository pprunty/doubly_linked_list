/**
 * \file	 	main.c
 * \brief       The program will read data from a file, create and populate a linked
 *              list to hold this data. It will print the list to screen. It will
 *              then remove certain nodes from the list depending on specified
 *              criteria and print the final filtered list.
 * \author 		P. Prunty
 * \version 	1.0
 * \date 		2019-11-26
 */
#include <stdio.h>
#include <stdlib.h>

// Headers
#include "linked_list.h"
#include "parse.h"

int main(int argc, char *argv[]) {

    List mylist;
    mylist.head = mylist.tail = NULL;    //< Null indicates empty list
    CLOptions opts;

    // Read command line parameters and store in opts
    parse_command_line(argc, argv, &opts);

    // Read data from file. Create list and populate nodes
    read_list_from_file(opts.infilename, &mylist);

    // Print contents of initial linked list
    printf("\n---------\nOriginal Data\n---------\n");
    print_list_contents(mylist);

    // Filtering. Remove nodes that are not within specified sizes
    Node *it = mylist.head;

    while (it != NULL) {
        Node *nextit = it->next;
        if (it->N < opts.min_size || it->N > opts.max_size) {
            remove_node(&mylist, it);
        }
        it = nextit;
    }

    // Print contents of filtered linked list
    printf("\n---------\nAfter Filtering\n---------\n");
    print_list_contents(mylist);

    return 0;
}
