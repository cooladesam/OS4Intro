#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>

#include "process.h"
#include "util.h"

#define DEBUG 0			//change to 1 to enable verbose

typedef int (*Comparer) (const void *a, const void *b);

/**
 * compares  processes
 */
int my_comparer_priority(const void *this, const void *that)
{
  int first_int = *(((int*)this + 2) );
  
  int second_int = *(((int*)that + 2) );
  
	return (second_int - first_int);
}



int my_comparer_arrival(const void *this, const void *that) {
	int first_int = *(((int*)this + 1) );
  
	int second_int = *(((int*)that + 1) );
  
	return (first_int - second_int);
}


int main(int argc, char *argv[]){

  int count;
  int x;
  for (x =0 ;x<2; x++){
  
	if (argc < 2) {
		   fprintf(stderr, "Usage: ./func-ptr <input-file-path>\n");
		   fflush(stdout);
		   return 1;
	}

/* Parse the input */
	FILE *input_file = fopen(argv[1], "r");
	if (!input_file) {
		   fprintf(stderr, "Error: Invalid filepath\n");
		   fflush(stdout);
		   return 1;
	}

	Process *processes = parse_file(input_file);

/* sort the input  */
	Comparer process_comparer;
    

    
 if (count == 0) {
			printf("\nSorted by Priority\n");
			process_comparer = &my_comparer_priority;
		
 } else {
   
			printf("\nSorted by Arrival Time\n");
   
			process_comparer = &my_comparer_arrival;
		}
    
#if DEBUG
	for (int i = 0; i < P_SIZE; i++) {
		    printf("%d (%d, %d) ",
				processes[i].pid,
				processes[i].priority, processes[i].arrival_time);
	}
	printf("\n");
#endif
	qsort(processes, P_SIZE, sizeof(Process), process_comparer);
/* print sorted data  */

	for (int i = 0; i < P_SIZE; i++) {
		    printf("%d (%d, %d)\n",
				processes[i].pid,
				processes[i].priority, processes[i].arrival_time);
	}
	fflush(stdout);
	fflush(stderr);

	/* clean up */
	free(processes);
	fclose(input_file);
    count++;
  }
	return 0;
