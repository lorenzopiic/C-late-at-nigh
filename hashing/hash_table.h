

typedef struct{
char * key; 
char* value;
} record; 

typedef struct{
	int capacity;
	int count; 
	record** buckets; 
 }hashtable; 


static record* create_record (const char* k, const char* v);
static hashtable* create_table();
static void delete_record (record* rec);
void delete_hash_table (hashtable* ht);
unsigned long hash(const char* s, const int a, const int m);
static int get_hash(const char* s, const int num_buckets, const int attempt);
