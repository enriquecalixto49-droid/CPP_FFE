// Print the structure values using a function

#include "Structure_ex.h"
#include <stdio.h>

void Print(struct Article* myArticle){
	printf("My article number is: %d\n", myArticle->Article_number);
	printf("My article quantity is: %d\n", myArticle->Quantity);
	printf("My article description is: %s\n", myArticle->Description);
};

int main(){
	struct Article a = {20,45,"My article is Total"};
	Print(&a);
	return 0;
}