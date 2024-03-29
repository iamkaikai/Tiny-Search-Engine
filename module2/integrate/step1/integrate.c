/* integrate.c --- 
 * 
 * 
 * Author: Yenkai Huang
 * Created: Wed Jan 11 14:30:57 2023 (-0500)
 * Version: 1.2
 * 
 * Description: a little function of integration 
 * 
 */
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <stdbool.h>
# include <math.h>
# include <stdint.h>
# include <string.h>

double f(double x){
	double y;
	y=2*pow(x,2)+9*x+4;
	return y;
}

int main(int argc, char *argv[]){
	printf("\n");
	double a,b,p;
	uint32_t n;
	char mode[] = "";
	int i;
  double result;
	double area;
	double h;
	
	a = atof(argv[1]);
	b = atof(argv[2]);
	
	//determine num of arg
	if(argc == 1){
		printf("usage: integrate a, b, [-p] or [-n], value\n");
		exit(EXIT_FAILURE);		
	}else if(argc == 5 ){

		printf("input is correct!\n");

		//check if b>a
		if(b > a){
			printf("b > a checked!!!\n");
			strcpy(mode, argv[3]);
			
			//if -p/ mode//////////////////////////////////////////////////////
			if(strcmp(mode, "-p") == 0){
				printf("using -p \n");
				//check whether the value of -p is a float
													
				if( sscanf(argv[4], "%lf", &p) == 1){				
					printf("precision = %lf\n",p);
					if(p < 1 && p>0){
						n = 1;
						double diff = 1;
						double prev_result = 0;
						while(diff>p){
							result = 0;
							h = (b-a)/(double)n;
							for(i=0;i<n;i++){
								result += (( f(a+i*h) + f(a+(i+1)*h) )*h/2.0);
							}
							diff = fabs(result - prev_result);
							prev_result = result;
							n +=1;

						}
						printf("\ninterval:[%lf-%lf], p:%lf, result=%lf\n\n",a,b,p,result);
					}else{
						printf("value of -p must between 0 and 1!!\n");
						exit(EXIT_FAILURE);
					}

				}else{
					printf("the value of arg4 is NOT a double!!\n");
					exit(EXIT_FAILURE);
				}
				
				//if it's -n mode/////////////////////////////////////////////////	
			}else if(strcmp(mode, "-n") == 0){
				printf("using -n... \n");
				//check whether the value of -n is a 32 unsigned int
				int len = strlen(argv[4]);
				//				uint32_t value;
				for(int i=0; i<len; i++){
					if( !isdigit(argv[4][i]) ){
						printf("In arg4, please enter a 32-bit unsigned int!!!\n");
						exit(EXIT_FAILURE);
					}
				}
				
				char *ptr;
				unsigned long int arg4 = strtoul(argv[4], &ptr, 10);
				
				if( arg4 >0 && arg4 <= UINT32_MAX && *ptr == '\0'){
					//printf("the value of arg4: %s is a uint32_t!\n", argv[4]);
					uint32_t value = (uint32_t)arg4;
					printf("n = %s \n",argv[4]);
					h = (b-a)/(double)value;
					for(i=0;i<value;i++){
						result += (( f(a+i*h) + f(a+(i+1)*h) )*h/2);
					}
					printf("\ninterval:[%lf-%lf], n:%u, result=%lf\n\n",a,b,value,result);
	
				}else{
					printf("In arg4: please input valid 32-bit int!!\n");
					exit(EXIT_FAILURE);
				}
				
			}else{
				printf("wrong input of '%s' in arg3 (accept '-n' or '-p' only!!) \n",mode);
				exit(EXIT_FAILURE);
			}
			
		}else{
			printf("b must be greater than a!!\n");
			exit(EXIT_FAILURE);
		}
	
	}else{
		printf("usage: integrate a, b, [-p] or [-n], value\n");
		exit(EXIT_FAILURE);
	}
	
		
	for(i=0;i<n;i++){
		
		result += (( f(a+i*h) + f(a+(i+1)*h) )*h/2);
		
	}
	exit(EXIT_SUCCESS);
}
