/* Implemenation of a generic "cached" stack data structure
 * to studying the so called "tagged union" tecnique.
 *
 * (C) lorenzopiic 2026                                   */




#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum types_tag {
	TYPE_SHORT  = 0,
	TYPE_CHAR   = 1,
	TYPE_NUM    = 2,
	TYPE_DOUBLE = 3,
	TYPE_STRING = 4
} tags_t;

typedef union {
	short shortNum;
	char charNum;
	int intNum; 
	double doubleNum; 	
	char* string;
}types;

typedef struct tagged_type {
	types type; 
	tags_t tag;
}type_t;

typedef struct stacknode {
  	type_t value; 
	struct stacknode* nextNode; 
}stacknode;

typedef struct Stack {
	stacknode* head;
	size_t nodes_counter;
}Stack;

//======================================//

			
void push(Stack* stackPtr, type_t value);


//======================================//
int main(void) {
	return 0; 
}

void push(Stack* stackPtr, type_t item){
	 
	stacknode* newNode = malloc(sizeof(*newNode));
	if(newNode != NULL){
		switch(item.tag) {
			case 0: 
			case 1: 
			case 2: 
			case 3:
			   newNode->value = item;	
			   break;
			case 4: 
			   char* temp = malloc(strlen(item.type.string) + 1);
			   if(temp != NULL) {
			   	strcpy(temp, item.type.string);
			   	temp[strlen(item.type.string)] = '\0';
			   	newNode->value.tag = item.tag;
			  	newNode->value.type.string = temp;
			} else {
				perror("Allocation Error...");
				temp = NULL;
			   	free(newNode);
				return; 	
			}
		   	break; 	   
		} // end Switch // 

		newNode->nextNode = stackPtr->head;
	   	stackPtr->head = newNode; 		
		stackPtr->nodes_counter++; 
	} else {
		perror("Allocation Error...");
		newNode = NULL; 
		return;
	}
}

void pop() {


}
