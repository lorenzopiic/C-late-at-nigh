/* Implemenation of a generic "cached" stack data structure. 
 * For fun and for stydying the "tagged union" tecnique.
 * Copyright (C) Lorenzo Tomasello 2026                      */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CACHESIZE 100
typedef enum types_tag {
	TYPE_SHORT  = 0,
	TYPE_CHAR   = 1,
	TYPE_INT    = 2,
	TYPE_DOUBLE = 3,
	TYPE_STRING = 4
} tags_t;

typedef union {
	short short_num;
	char char_num;
	int int_num; 
	double double_num; 	
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

typedef struct Cache {
	stacknode* head;
   	stacknode* tail; 	
	size_t nodes_counter;
}Cache;

//======================================//

			
void push(Stack* stackPtr, type_t value);
void pop(Stack* stackPtr, Cache* cachePtr);

void manage_cache_fullness(Cache* cachePtr,type_t item); 

//======================================//
int main(void) {
	return 0; 

		Stack* STACK = NULL; 

			

}

void push(Stack* stackPtr, type_t item){
	stacknode* newNode = malloc(sizeof(*newNode));
	if(newNode != NULL){
		switch(item.tag){
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
		if(stackPtr == NULL){
			stackPtr->head = newNode; 
		   	stackPtr->head->nextNode = NULL; 
			stackPtr->nodes_counter++;
			return; 			
		}
		newNode->nextNode = stackPtr->head;
	   	stackPtr->head = newNode; 		
		stackPtr->nodes_counter++; 
	} else {
		perror("Allocation Error...");
		newNode = NULL; 
		return;
	}
}

void pop(Stack* stackPtr, Cache* cachePtr){
	if(stackPtr->head == NULL){
	  	fprintf(stderr,"Stack is empty...\n"); 
		exit(EXIT_FAILURE); 
	}
	stacknode* temp = stackPtr->head;
	if(cachePtr->nodes_counter < CACHESIZE){
		push_back(cachePtr, stackPtr->head->value);
	}else{
		manage_cache_fullness(cachePtr,stackPtr->head->value); 
	}
	switch(stackPtr->head->value.tag){
		case 0: 
		case 1: 
		case 2: 
		case 3:
			stackPtr->head = stackPtr->head->nextNode;
			free(temp);
			temp = NULL;	
			break;
		case 4:
			stackPtr->head = stackPtr->head->nextNode;
			free(temp->value.type.string);
			temp->value.type.string = NULL;
			free(temp);
			temp = NULL; 
			break;		
	}
	stackPtr->nodes_counter--;
}

void push_back(Cache* cachePtr,type_t item){
	stacknode* newNode = malloc(sizeof(*newNode));
	if(newNode != NULL){
		newNode->nextNode = NULL; 
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
		if(cachePtr == NULL){
			cachePtr->head =  newNode;
			cachePtr->head->nextNode = NULL; 
			cachePtr->nodes_counter++;	
			return;
		}
		newNode->nextNode = cachePtr->head;
	   	cachePtr->head = newNode; 		
		cachePtr->nodes_counter++; 
	} else {
		perror("Allocation Error...");
		newNode = NULL; 
		return;
	}
}

manage_cache_fullness(Cache* cachePtr,type_t item){
		fprintf(stdout,"Warning! The cache memory is full!\n",
				       "Using it will override the last pushed information\n",
					   "Do you want to use it anyway?\n",
					   "1 to push\n2 to avoid\nEnter your choice >>> ");
		unsigned short choice = 0; 
		scanf("%hu", &choice);
		if(choice != 1 && choice != 2){
		while(choice != 1 && choice != 2){
			fprintf(stderr,"Invalid choice!");
		   	fprintf(stdout,"Enter a valid choice >>> "); 	
			scanf("%hu", &choice);
		}
	} else {
		if(choice == 1){
			push_back(cachePtr, item);
			
			show_cache_tail(cachePtr); 	
		} else{
			fprintf(""); 
		}	
	}
}

show_cache_tail(Cache* cachePtr){
	
}
