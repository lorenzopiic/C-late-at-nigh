#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int* randomBuild(int argc,char**argv);
void mergesort(int* arr, int begin, int end);
void merge(int *arr, size_t begin size_t middle,size_t end);
int main(int argc, char**argv)
{
	srand(time(NULL));
	int* arr = randomBuild(argc,argv);
	if(arr == NULL){
		return -1; 
	}
	
	mergesort(arr,0,atoi(argv[1]));
	return 0; 
}
int* randomBuild(int argc,char**argv){

	if(argc != 2){
		fprintf(stderr,"Error! Usage >>> <%s> <size>\n",argv[0]);
		return NULL; 
	}
	size_t size = atoi(argv[1]);
	fprintf(stdout,"Size for this run >>> %ld\n", size); 
	
	int* ret = malloc(sizeof(int) * size);
	if(ret == NULL)
		return NULL; 
	for(size_t i=0;i<size;i++){
		ret[i] = (rand() % 100) + 1;
	}
	for(size_t i=0;i<size;i++){
		fprintf(stdout,"%d ", ret[i]); 
	}
	puts(" "); 
	return ret; 
}

void mergesort(int* arr, int begin, int end)
{
	if(begin>= end)
		return; 
	size_t middle =(begin+end) / 2; 
	
	printf("%d\n", arr[middle]);
   	
	mergesort(arr,begin,middle);
	mergesort(arr,middle+1, end);

	merge(arr,begin,middle,end);
}
void merge(int *arr, size_t begin size_t middle,size_t end)
{
	size_t left_size = middle-begin+1; 
	size_t right_size = end - middle; 




}

