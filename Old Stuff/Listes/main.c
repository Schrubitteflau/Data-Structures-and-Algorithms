#include <stdio.h>
#include <conio.h>

#include "list.h"

int main(void)
{
	ListElement *myList = new_list();

	if (is_list_empty(myList))
		printf("La liste est vide\n");
	else
		printf("La liste n'est pas vide\n");

	printf("Nombre d'elements dans la liste : %d\n", list_length(myList));

	myList = insert_back(myList, 1);
	print_list(myList);
	printf("Nombre d'elements dans la liste : %d\n", list_length(myList));

	myList = insert_front(myList, 2);
	myList = insert_back(myList, 3);
	print_list(myList);
	printf("Nombre d'elements dans la liste : %d\n", list_length(myList));

	myList = delete_front(myList);
	print_list(myList);
	printf("Nombre d'elements dans la liste : %d\n", list_length(myList));

	delete_back(myList);
	print_list(myList);
	printf("Nombre d'elements dans la liste : %d\n", list_length(myList));

	myList = clear(myList);

	print_list(myList);
	printf("Nombre d'elements dans la liste : %d\n", list_length(myList));


	// Insert back : b
	// Insert front : f
	// Delete back : n
	// Delete front : g
	// Clear : c
	// Print : p
	// Taille : s
	int c = '\0';
	int i = 0;
	while (c != 'q')
	{
		if (kbhit())
		{
			c = getch();

			switch (c)
			{
				case 'b':
					myList = insert_back(myList, i++);
					print_list(myList);
					break;

				case 'f':
					myList = insert_front(myList, i++);
					print_list(myList);
					break;

				case 'n':
					delete_back(myList);
					print_list(myList);
					break;

				case 'g':
					myList = delete_front(myList);
					print_list(myList);
					break;

				case 'c':
					myList = clear(myList);
					break;

				case 'p':
					print_list(myList);
					break;

				case 's':
					printf("La taille est de %d\n", list_length(myList));
					break;
			}
		}
	}


	return 0;
}