#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int* randomBuild(int argc,char**argv);
void mergesort(int* arr, int begin, int end);
int main(int argc, char**argv)
{
	srand(time(NULL));
	int* arr = randomBuild(argc,argv);
	if(arr == NULL){
		return -1; 
	}
	return 0; 
	
	mergerort(arr,0,atoi(argv[1]));
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

void mergesort(int* arr, int begin, int end);
int main(int argc, char**argv)
