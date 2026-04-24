#include<stdio.h>
#include<stdlib.h>

int* randomBuild(int argc,char**argv);

int main(int argc, char**argv)
{
	srand(time(NULL));
	int* arr = randomBuild(argc,argv);
   	int arr[5] = {23,34,6,2,5};	
	
	mergesort()
	return 0; 
}
int* randomBuild(int argc,char**argv){

	if(argc != 2){
		fprintf(stderr,"Error! Usage >>> <%s> <size>\n",argv[0]);
	}
}

