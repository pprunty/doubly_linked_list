/**
 * \file            parse.c
 * \brief           A file which first sets default values and then parses command line arguments for the minimum and maximum dimension 
 *					of a matrix to be filtered (removed) from the given data. If command line arguments are inputted then the default values
 *					will be overwritten.
 * \author          P. Prunty
 * \version         1.0
 * \date            2019-11-29
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

// Headers
#include "parse.h"
#include "linked_list.h"

// argc represents the number of arguments entered into the command line input
// whilst argv[] is an array which holds each argument in the input

/*! \brief          A simple function used to parse flags from the command line using getopt.
 *  \param argc     Pointer to the argument character. argc represents the number of arguments entered into the command
 *                  line input
 *  \param argv     Pointer to the argument vector. argv[] is an array which holds each argument in the input
 *  \param opts     The command line options.
 */
void parse_command_line(const int argc, char *const *argv, CLOptions *opts) {


    // Variables for getopt function
    int options;
    int iflag = 0, xflag = 0, nflag = 0, hflag = 0;


    // Set default values for filename, max and min size for matrix dimensions to be removed in remove function
    opts->infilename = "data.txt";
    opts->max_size = 1000;
    opts->min_size = 0;

    // Note, setting this to zero removes automatic error checking. Manual error checking is hardcoded below
    // opterr = 0; However, I decided to keep getopt's error checking instead of mine

    // Begin parsing command line arguments using getopt
    while ((options = getopt(argc, argv, "i:x:n:h")) != -1)        //<! Flags with ':' after it takes an argument
    {
        switch (options) {
            // -i flag to parse filename argument
            case 'i' :
                iflag = 1;
                opts->infilename = optarg;

                break;

            case 'x' :
                xflag = 1;

                // Check if the argument is not a number, perform string to integer conversion
                if (optarg[0] >= '0' && optarg[0] <= '9') {
                    opts->max_size = atoi(optarg);
                } else {
                    fprintf(stderr, "WARNING: Illegal input for max. Max must be of an integer type.\n");
                    exit(1);
                }
                break;
            case 'n' :
                nflag = 1;

                // Similar argument as before
                if (optarg[0] >= '0' && optarg[0] <= '9') {
                    opts->min_size = atoi(optarg);
                } else {
                    fprintf(stderr, "WARNING: Illegal input for min. Min must be of an integer type.\n");
                    exit(1);
                }
                break;
            case 'h' :
                hflag = 1;
                printf("Usage: ./main [-i <filename>] [-n <min_size>] [-x <max_size>] [-h (prints usage)]\n");
                printf("Default: ./main [-i %s] [-n %d] [-x %d] [-h]\n", opts->infilename, opts->min_size,
                       opts->max_size);
                break;

                // Hardcoding getopt errors (not used)
//			case '?' :
//				if (optopt == 'i' || optopt == 'x' | optopt == 'n')
//					fprintf(stderr, "Option -%c requires an argument.\nArguments defaulted\n", optopt);
//				else
//					fprintf(stderr, "Unknown option -%c.\n", optopt);
//				break;	

            default :
                fprintf(stderr, "getopt");
        }
    }
}
