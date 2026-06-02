/* Implementation inspired by the Deitel, ALL RIGHTS DESERVED TO THE AUTHORS */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct treeNode {
   	int data;	
	struct treeNode* leftPtr;
	struct treeNode* rightPtr; 
}node_t;

void insertNode(node_t** rootPtr, int value);
void in_order(node_t** treePtr);
void pre_order(node_t** treePtr);
void post_order(node_t** treePtr);

int main(void){
	
	node_t* rootPtr = NULL;
	srand(time(NULL));
	puts("Putting in the tree these random numbers >>> "); 
	for(unsigned i=0; i<= 10; i++) {
		int item = rand() % 15;
		if(item == 0) item++;
		printf("%3d", item);
	   	insertNode(&rootPtr,item);	
	}
		
	return 0; 

}
void insertNode(node_t** rootPtr, int value) {
	if(rootPtr == NULL){ 
	/* Checking if the root node has already been allocated...
	 * otherwise, we have to allocate the memory*/
	
	*rootPtr = malloc(sizeof(*(*rootPtr)));
	if(rootPtr != NULL) {
		(*rootPtr)->data = value; 
		(*rootPtr)->leftPtr = NULL; 
		(*rootPtr)->rightPtr = NULL; 
		} else {
			perror("Allocation error...");
			exit(EXIT_FAILURE);
		}
		return;
	 } else { // rootPtr already exist
	 	node_t* newNode = malloc(sizeof(*newNode));
		if(newNode != NULL) {
			newNode->data = value;
			newNode->rightPtr = NULL; 
			newNode->leftPtr = NULL; 

			node_t* cp = *rootPtr; 	// cp = current pointer 
			node_t* pp = NULL; 		// pp = parent pointer
			
			while(cp != NULL){
				pp = cp; 
				if(cp->data == value){ return; }

				if(value > cp->data){ cp = cp->rightPtr; }	
				else { cp = cp->leftPtr; }
			}
		if(value > pp->data){
			pp->rightPtr = newNode; 
		}	else { pp->leftPtr = newNode; }

		} else {
			perror("Allocation error...");
			exit(EXIT_FAILURE);

	}
}
void in_order(node_t** treePtr);
void pre_order(node_t** treePtr);
void post_order(node_t** treePtr);



