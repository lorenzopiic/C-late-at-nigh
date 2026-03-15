#include<stdio.h>
#include<stdlib.h>
#include"hash_table.h"
#include<string.h>

static record* 
create_record (const char* k, const char* v) 
{
	record* newPtr = malloc(sizeof(*newPtr));
	if(newPtr == NULL) { return NULL; }
	newPtr->key = malloc(strlen(k)+1); 
	newPtr->value = malloc(strlen(v)+1); 
	
	if(newPtr->key == NULL || newPtr->value){
		free(newPtr->key);
		free(newPtr->value);
		free(newPtr);
		return NULL; 	
	}
	strcpy(newPtr->key,k);
	strcpy(newPtr->value,v);

	return newPtr; 
}

static hashtable* 
create_table()
{
	hashtable* ht = malloc(sizeof(*ht));
	if(ht == NULL) return NULL; 
	ht->capacity = 53; 
	ht->count = 0; 
	ht->buckets = calloc(ht->capacity, sizeof(record*));
	if(ht->buckets== NULL) return NULL;

	return ht;
} 

static void
delete_record (record* rec) 
{
    free(rec->key);
    free(rec->value);
    free(rec);
}


void 
delete_hash_table (hashtable* ht) 
{
 	for (size_t i = 0; i < ht->size; i++) {
        record* temp = ht->buckets[i];
        if (temp != NULL) {
            delete_record(temp);
        }
    }
    free(ht->buckets);
    free(ht);
}
