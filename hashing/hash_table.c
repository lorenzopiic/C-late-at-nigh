#include<stdio.h>
#include<stdlib.h>
#include"hash_table.h"
#include<math.h>
#include<string.h>


int main(void)
{

    hashtable *ht = create_table();
    delete_hash_table(ht);
}

static record *create_record(const char *k, const char *v)
{
    record *newPtr = malloc(sizeof(*newPtr));
    if (newPtr == NULL) {
	return NULL;
    }
    newPtr->key = malloc(strlen(k) + 1);
    newPtr->value = malloc(strlen(v) + 1);

    if (newPtr->key == NULL || newPtr->value) {
	free(newPtr->key);
	free(newPtr->value);
	free(newPtr);
	return NULL;
    }
    strcpy(newPtr->key, k);
    strcpy(newPtr->value, v);

    return newPtr;
}

static hashtable *create_table()
{
    hashtable *ht = malloc(sizeof(*ht));
    if (ht == NULL)
	return NULL;
    ht->capacity = 53;
    ht->count = 0;
    ht->buckets = calloc(ht->capacity, sizeof(record *));
    if (ht->buckets == NULL)
	return NULL;

    return ht;
}

static void delete_record(record * rec)
{
    free(rec->key);
    free(rec->value);
    free(rec);
}


void delete_hash_table(hashtable * ht)
{
    for (size_t i = 0; i < ht->capacity; i++) {
	record *temp = ht->buckets[i];
	if (temp != NULL) {
	    delete_record(temp);
	}
    }
    free(ht->buckets);
    free(ht);
}

unsigned long hash(const char *s, const int a, const int m)
{
    unsigned long hash = 0;
    for (size_t i = 0; i < strlen(s); i++) {
	hash += pow(a, strlen(s) - (i + 1)) * s[i];
	hash = hash % m;
    }
    return hash;
}

static int
get_hash(const char *s, const int num_buckets, const int attempt)
{
    const int hash_a = hash(s, HT_PRIME_1, num_buckets);
    const int hash_b = hash(s, HT_PRIME_2, num_buckets);
    return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

void insert(hashtable * ht, const char *key, const char *value)
{
    record *newPtr = create_record(key, value);
    int index = get_hash(record->key, ht->capacity, 0);
    record *current_record = ht->buckets[index];
    int i = 1;
    while (current_record != NULL) {
	index = get_hash(record->key, ht->capacity, i);
	current_record = ht->buckets[index];
	i++;
    }
    ht->buckets[index] = newPtr;
    ht->count++;
}

char *search(hashtable * ht, const char *key)
{
    int index = get_hash(key, ht->capacity, 0);
    record *record = ht->buckets[index];
    int i = 1;

    while (record != NULL) {
	if (strcmp(record->key, key) == 0) {
	    return record->value;
	}
	index = get_hash(key, ht->capacity, i);
	item = ht->items[index];
	i++;
    }
    return NULL;
}
