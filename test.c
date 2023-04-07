#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
	int colResult = 0, rowResult = 0;
	int i, t;
	int x = 0, y = 0;
	int temp1 = 1, temp2 = 1;
	char rookString[10] = "da58339";
	//Loop through rookString to findour how many number and alpha
	for (i = 0; i < strlen(rookString); i++)
	{
		if (isalpha(rookString[i]))
			x++;
		if (isdigit(rookString[i]))
			y++;
	}
	
	x -= 1;
	y -= 1;
	
	// Loop through rookString again
	for (i = 0; i < strlen(rookString); i++)
	{		
		// Convert string to rook's position
		if (isalpha(rookString[i]))
		{
			for (t = 0; t < x; t++)
			{
				temp1 = temp1 * 26;
			}
			colResult = temp1 * (rookString[i] - 'a' + 1) + colResult;
			temp1 = 1;
			x--;
		}
		if (isdigit(rookString[i]))
		{
			for (t = 0; t < y; t++)
			{
				temp2 = temp2 * 10;
			}
			rowResult = temp2 * (rookString[i] - '0') + rowResult;
			temp2 = 1;
			y--;
		}
	}	
	printf("%d, %d", colResult, rowResult);
	return 0;
}