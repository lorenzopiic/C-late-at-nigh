#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10000

typedef struct listNode {
	char data;
	struct listNode* nextPtr;
}listnode;

void insert(listnode** sPtr, char value);
char delete(listnode** sPtr, char value);
int isEmpty(listnode*sPtr);
void printList(listnode* sPtr);
void instructions(void);
int main(void)
{
    listnode *startPtr = NULL;
    char item = '0';

    instructions();
    printf(">>> ");
    int choice = 0;
    fscanf(stdin, "%d", &choice);
	
	if (choice != 1 && choice != 2) {
		fprintf(stderr,"Invalid choice...\n");
   		return 1; 
	}
	while (choice != 3) {
        switch (choice) {
        case 1:
            printf("Enter a character to isert >>> ");
            char buf[SIZE];
            scanf("%s", buf);
            if(strlen(buf) != 1){
				fprintf(stderr,"Error >>> Enter just one char at a time...\n");
                break;
                } else {
					item = buf[0];
                }
				insert(&startPtr, item);
            	printList(startPtr);
            break;
        case 2:
            if (!isEmpty(startPtr)) {   // the list is not empty //
                printf("Enter a character to be deleted >>> ");
                fscanf(stdin, "\n%c", &item);

                if (delete(&startPtr, item)) {
                    printf("The character <%c> has been deleted\n", item);
                    printList(startPtr);
                } else {
                    printf("Couldn't find the element <%c> to delete\n",
                           item);
                }
            } else {            // the list is empty //
                printf("The list in empty\n");
            }
            break;
        default:
            printf("Ivalid choice...\n");
            instructions();
            break;
        }
        printf(">>> ");
        fscanf(stdin, "\n%d", &choice);
		while(choice != 1 && choice != 2) {
		fprintf(stderr,"Invalid choice...\n");
        printf(">>> ");
        fscanf(stdin, "\n%d", &choice);
		}
   		return 1; 
    }
    puts("Program ended!");
    
	return 0;
}


void instructions(void)
{
    printf("Enter your choice\n");
    printf("1 to insert an element into the list\n");
    printf("2 to delete an element from the list\n");
    printf("3 to end the program\n");
}

	
void insert(listnode** sPtr, char value)
{
	listnode* newPtr = malloc(sizeof(*newPtr));
	if(newPtr != NULL){
		newPtr->data = value; 
		newPtr->nextPtr = NULL;

		listnode* currentPtr = *sPtr;
		listnode* previousPtr = NULL;

	while(currentPtr != NULL && value > currentPtr->data){
		previousPtr = currentPtr; 
		currentPtr = currentPtr->nextPtr; 
	}
	if(previousPtr == NULL){
		newPtr->nextPtr = *sPtr;
		*sPtr = newPtr;
	} else {
   		previousPtr->nextPtr = newPtr; 
		newPtr->nextPtr = currentPtr;
		}
	} else {
		perror("Error >>> ");
	}
}

char delete(listnode** sPtr, char value)
{
	if(value == (*sPtr)->data){
		listnode* tempPtr = *sPtr;
		*sPtr = (*sPtr)-> nextPtr;
	   	free(tempPtr);
		return value;	
	} else {
	listnode* previousPtr = *sPtr;
	listnode* currentPtr = (*sPtr)->nextPtr; 

	while(currentPtr != NULL && currentPtr->data != value){
		previousPtr = currentPtr; 
		currentPtr = currentPtr->nextPtr; 
	}
	/* check if the element was found or not*/
	if(currentPtr != NULL){
		listnode* tempPtr = currentPtr; 
		(*previousPtr).nextPtr = (*currentPtr).nextPtr;	
		free(tempPtr);
		return value;
		}
	}
	return '\0';
}

int isEmpty(listnode* sPtr){
	return sPtr == NULL; 

}

void printList(listnode* sPtr){
	
	if(isEmpty(sPtr)){
		puts("The fcking list is empty..."); 	
	} else {
		while(sPtr != NULL){
			printf("%c >>> ", sPtr->data); 
			sPtr = sPtr->nextPtr;
		}
		puts("NULL \n"); 
	}
}



