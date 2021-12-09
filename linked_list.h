/**
 * \file        linked_list.h
 * \brief       Header file containing structures and function prototypes for
 * 	            dealing with linked lists.
 * \author      P. Prunty
 * \version     1.0
 * \date        2019-11-19
 */

#ifndef LINKED_LIST_H_KYDIEQVO
#define LINKED_LIST_H_KYDIEQVO

/*! \struct     _Node
 *  \brief      A data structure representing a node in the linked list.
 */
typedef struct _Node {
    struct _Node *next;     //!< Pointer to the next node in list
    struct _Node *prev;     //!< Pointer to the previous node in list
    int N;                  //!< Dimension of the square matrix (size of memory)
    double **data;          //!< Double pointer to the data
} Node;


/*! \struct     _List
 *  \brief      A data structure representing a list to hold pointers to the first and last nodes
 *              in a linked list.
 */
typedef struct _List {
    Node *head;    //!< Pointer to first node in list
    Node *tail;    //!< Pointer to last node in list
} List;


// Function prototypes
int append_new_node(List *const inlist, const int N);

void print_list_contents(List list);

void remove_node(List *in, Node *node);

void read_list_from_file(const char *const filename, List *mylist);

#endif /* end of include guard: LINKED_LIST_H_KYDIEQVO */

