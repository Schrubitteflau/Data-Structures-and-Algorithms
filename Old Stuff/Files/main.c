#include <stdio.h>
#include <conio.h>

#include "queue.h"

/* Les files -> FIFO : First In First Out
Le premier élément inséré sera le premier retiré
*/

int main(void)
{
	Queue *myQueue = new_queue();
	int c = 0, i = 0;

	while (c != 'q')
	{
		if (kbhit())
		{
			c = getch();

			switch (c)
			{
				case 'e':
					enqueue_queue(myQueue, i++);
					break;

				case 'd':
					dequeue_queue(myQueue);
					break;

				case 'p':
					print_queue(myQueue);
					break;

				case 's':
					printf("Taille de la file : %d\n", queue_length(myQueue));
					break;

				case 'c':
					clear_queue(myQueue);
					break;
			}
		}
	}

	clear_queue(myQueue);

	return 0;
}