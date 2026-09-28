// Header file for the structure example of an article with an article number, quantity, and description.

#ifndef STRUCTURE_EX_H
#define STRUCTURE_EX_H

#include <stdio.h>

struct Article{
	int Article_number;
	int Quantity;
	char Description[20];
};

void Print(struct Article* myArticle);

#endif