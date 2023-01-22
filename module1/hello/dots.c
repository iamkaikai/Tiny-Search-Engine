/* dots.c --- 
 * 
 * 
 * Author: Yenkai Huang
 * Created: Sat Jan 14 16:16:49 2023 (-0500)
 * Version: 1.0
 * 
 * Description: 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){

	int n, t, i;
	if(argc != 3){
		printf("usage: dots n t \n");
		exit(EXIT_FAILURE);
	}

	n=atoi(argv[1]);
	t=atoi(argv[2]);

	for(i=0; i<n; i++){
		printf(".");
		fflush(stdout);
		sleep(t);
	}
	printf("args: %s %s %s \n", argv[0],argv[1],argv[2]);
	exit(EXIT_SUCCESS);

}
