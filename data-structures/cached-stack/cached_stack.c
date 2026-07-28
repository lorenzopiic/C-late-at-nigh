/* Implemenation of a generic "cached" stack data structure. 
 * For fun and for stydying the "tagged union" technique.
 * Copyright (C) Lorenzo Tomasello 2026                      */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"cached_stack.h"

int main(void) {
    Stack* STACK = NULL; 
	Cache* CACHE = NULL; 
    
	int instructions_choice;
	int push_options_choice; 
   	main_loop_instructions();
    printf(">>> ");
	while(1){
		if(!check_input(&instructions_choice)){
		fprintf(stderr,"\nPlease, enter a number >>> ");
        continue;
      }
	if(instructions_choice == 3 ) { break; }
      switch (instructions_choice) {
			case 1:
            print_divider();
            push_options();
            printf(">>> ");

            while (1) {
                if (!check_input(&push_options_choice)) {
                    fprintf(stderr, "\nError! You entered characters instead of a number!\n");
                } else if (!check_push_options_choice(&push_options_choice)) {
                    fprintf(stderr, "\nError! You entered an invalid choice!\n");
                } else {
                    break; 
                }
                print_divider();
                push_options();
                fprintf(stdout,"\nEnter a valid choice now >>> ");
            }
			// Ok, now we are sure that the choice of what to push is a number between 1-5 //
            type_t* data = manage_push_options_choice(&push_options_choice); 
            break;
        case 2:
            break;
        default:
            printf("\nError! Invalid choice...\n\n");
            main_loop_instructions();
            break;
        }
            fprintf(stdout,"Insert new choice >>> ");
            fflush(stdout);
    } // end while loop() // 
    puts("Program ended!");

        return 0;
}


void main_loop_instructions(void) {
    printf("Enter your choice:\n");
    printf("1 to push an element into the stack\n");
    printf("2 to pop an element from the stack\n");
    printf("3 to end the program\n");
}

void push_options(void){
	printf("What kind of data do you want to push?\n\n");
	printf("1 >>> short\n2 >>> char\n3 >>> int\n4 >>> double\n5 >>> string\n");
}
void print_divider(void){
	fprintf(stdout,"\n\n/* =========================================== */\n\n"); 	
}
void clean_buffer(void){
        int c;
        while((c = getchar())!= '\n' && c != EOF);
}

bool check_input(int* target){
    int check = fscanf(stdin, "%d", target);
    if (check == 1) {
        return true;
    } else {
        clean_buffer();
        return false;
    }
}

bool check_push_options_choice(int* choice){
	switch(*choice){
		case 1:
		case 2:
		case 3: 
		case 4: 
		case 5:
			return true; 
		default:
			return false; 
	}
}

type_t* manage_push_options_choice(int* option){
		type_t* ret = NULL; 
		switch(*option){
			case 1:
        		printf("\n");    
				fprintf(stdout,"Enter the short >>> ");
				short sh; 
				fscanf(stdin,"%hd",&sh);
			   	fprintf(stdout,"debugging >>> read %hd", sh);	
				ret = allocate_short(&sh);
			   break;
			case 2:
        		printf("\n");    
        		fprintf(stdout,"Enter the char >>> ");
        		char ch; 
				char buf[1000];
        
        		fscanf(stdin,"%999s", buf); // BUFFER OVERFLOW PROTECTION // 
        
        	while(strlen(buf) != 1){
            	fprintf(stderr,"Error >>> Enter just one char at a time...\n");
            	fprintf(stdout,"Enter the char >>> ");
            	fscanf(stdin, "%999s", buf); 
        	}
        
       		 if(strlen(buf) == 1){
            	ch = buf[0];
        		}

       			 ret = allocate_char(&ch);
        		break;
			case 3:
        		printf("\n");    
				fprintf(stdout,"Enter the int >>> ");
			   	int integer = 0;
				fscanf(stdin,"%d",&integer);
			   	ret = allocate_int(&integer);
				break;
			case 4:
        		printf("\n");    
				fprintf(stdout,"Enter the double >>> ");
				double doub; 
				fscanf(stdin,"%lf", &doub);
				ret = allocate_double(&doub); 	
				break;
			case 5:
        		printf("\n");    
				size_t string_lenght = 0;  
				char* string = manage_string_input(&string_lenght);
				 ret = allocate_string(string,string_lenght);
				break; 				
			} // end switch //
		
	print_divider(); 	
	return ret;
}
type_t* allocate_short(short* sh) {
	type_t* ret = malloc(sizeof(*ret));
	if(ret != NULL){
		ret->type.short_num = *sh; 
		ret->tag = TYPE_SHORT; 
	} else {
		perror("Allocation Error");
		return NULL; 
	}	
	return ret;  
}

type_t* allocate_char(char* ch) {
	type_t* ret = malloc(sizeof(*ret));
	if(ret != NULL){
		ret->type.char_num = *ch;
		ret->tag = TYPE_CHAR;
	} else {
		perror("Allocation Error");
		return NULL; 
	}
	 return ret; 
}

type_t* allocate_int(int* integer){
	type_t * ret = malloc(sizeof(*ret));
	if(ret != NULL){
		ret->type.int_num = *integer;
		ret->tag = TYPE_INT;
	} else{
		perror("Allocation error");
		return NULL; 
	}
	return ret; 
}

type_t * allocate_double(double* doub){
	type_t * ret = malloc(sizeof(*ret));
	if(ret != NULL){
		ret->type.double_num = *doub;
		ret->tag = TYPE_DOUBLE;
	} else {
		perror("Allocation error...");
		return NULL;
	}
	return ret; 
}

type_t* allocate_string(char* src_string,size_t len){
	type_t* ret = malloc(sizeof(*ret));
	if(ret != NULL){
		char* dest_string = malloc(sizeof(len));
	   	if(dest_string != NULL){
			strncpy(dest_string,src_string,len);
			ret->tag = TYPE_STRING;
			ret->type.string = dest_string;
			} else {
				perror("Allocation error...");
				return NULL; 
			}	
		}	
	return ret; 
}

char* manage_string_input(size_t* len){
	fprintf(stdout, "Enter the string >>> ");
    
    size_t capacity = 16; 
    size_t length = 0;    
    
    char* str = malloc(capacity);
    if (str == NULL) {
        perror("Allocation error...");
        return NULL;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        str[length++] = (char)c; 
        if (length == capacity) {
            capacity *= 2;
            char* temp = realloc(str, capacity);
            if (temp == NULL) {
                perror("Reallocation error...");
                free(str);
                return NULL;
            }
            str = temp;
        }
    }
    str[length] = '\0';
    char* final_str = realloc(str, length + 1);
    if (final_str != NULL) {
        str = final_str;
    }
	*len = length; 
    return str;
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
	}	stacknode* temp = stackPtr->head;
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
			cachePtr->top = newNode;
			cachePtr->bottom = newNode; 
			cachePtr->top->nextNode = NULL; 
			cachePtr->bottom->nextNode = NULL; 
			cachePtr->nodes_counter++;	
			return;
		}
		newNode->nextNode = cachePtr->top;
	   	cachePtr->top = newNode; 		
		cachePtr->nodes_counter++;
	} else {
		perror("Allocation Error...");
		newNode = NULL; 
		return;
	}
}

void manage_cache_fullness(Cache* cachePtr,type_t item){
		printf("Warning! The cache memory is full!\n"
				"Using it will override the last pushed information\n"
				"Do you want to use it anyway?\n"
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
		   stacknode* del = cachePtr->bottom;
		   switch(del->value.tag){
			   case 0: 
			   case 1:
			   case 2: 
			   case 3:
			       break;
			   case 4:
				   free(del->value.type.string);
			       del->value.type.string = NULL; 
			       break;		
			}
		free(del);
		del = NULL;
		cachePtr->nodes_counter--;
		set_cache_bottom(cachePtr); 	
	} else {
		fprintf(stdout,"Ok the cache will remain the same...\n");
		}
	}
}

void set_cache_bottom(Cache* cachePtr){
	stacknode* current = cachePtr->top;
	stacknode* previous = NULL; 
	
	while(current != NULL){
		previous = current; 
		current = current->nextNode; 
	}
	if(previous != NULL){
	cachePtr->bottom = previous; 
	cachePtr->bottom->nextNode = NULL; 
	}
	previous = NULL; 
	current  = NULL; 
}







