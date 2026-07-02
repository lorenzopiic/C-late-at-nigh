#define CACHESIZE 100
#include <stdlib.h>
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
	stacknode* top;
   	stacknode* bottom; 	
	size_t nodes_counter;
}Cache;

//======================================//
void instructions(void);
void options(void); 
void clean_buffer(void);
bool check_input(int* target);
type_t manage_option_choice(int* option);

type_t allocate_short(short* sh);
type_t allocate_char();
type_t allocate_int();
type_t allocate_double(); 

/* Stack */

void push(Stack* stackPtr, type_t value);
void pop(Stack* stackPtr, Cache* cachePtr);

/* Cache */

void push_back(Cache* cachePtr,type_t item);
void manage_cache_fullness(Cache* cachePtr,type_t item); 
void set_cache_bottom(Cache* cachePtr);


//======================================//

