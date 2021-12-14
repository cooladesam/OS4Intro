#include <stdio.h>
#include <stdlib.h>

int add (int a, int b);

int multiply (int a, int b);

int subtract (int a, int b);

int divide (int a, int b);

int end();


int (*operands[5]) (int a, int b);
int main (void)
{

  int operand1;
  int operand2;
  int operation;
  int result = (*operands[operation]) (operand1, operand2);
	
	
	printf("Operand 'a': ");
	scanf("%d\n", &operand1);
  
	printf("Operand 'b': ");
	scanf("%d\n", &operand2);
  
	printf("Specify the Operation to Complete: \n'0'-add\n'1'-subtract:\n'2'-multiply\n'3'-divide\n'4'-exit program\n");
	scanf("%d", &operation);
	
	operands[0] = add;
  
	operands[1] = subtract;
	
  operands[2] = multiply;
	
  operands[3] = divide;
	
  operands[4] = end;

	
  printf("X = %d\n", result);

	return result;
}

int add (int a, int b){ 
  printf ("Adding 'a' and 'b'\n");
  return a + b; 
  }

int multiply (int a, int b){ 
  printf ("Multiplying 'a' and 'b'\n");
  return a*b; 
}

int subtract (int a, int b){ 
  printf ("Subtracting 'a' and 'b'\n");
  return a-b; 
}


int divide (int a, int b){ 
  printf ("Dividing 'a' and 'b'\n"); 
  return a/b; 
}

int end(){ 
  printf ("Exiting\n"); 
  exit(0); 
}