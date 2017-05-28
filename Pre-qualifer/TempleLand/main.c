#include<stdio.h>
#include<stdlib.h>

int main()
{
	int strip = 0;//no.of strips
	int parts = 0;//no. of parts divided
	int condition = 0;
	int *height;
	scanf("%d", &strip);
	for(int a = 0; a < strip; a++)
	{
		scanf("%d", &parts);
		height = malloc(parts * sizeof(int));
		for(int b = 0; b < parts; b++)
		{
			scanf("%d", &height[b]);
		}
		if(height[0] == 1 && height[parts-1] == 1)
		{
			for(int c = 0; c < (parts/2)-1; c++)
			{
				if(height[c] == height[c+1] - 1)
				{
					condition = 1;
				}
			}
			for(int c = parts/2; c < parts-1; c++)
				{
					if(height[c] == height[c+1] - 1)
					{
						condition = 1;
					}
				}
		}
		else condition = 0;

		if(condition == 0)
		{
			printf("no\n");
		}
		else if(condition == 1)
		{
			printf("yes\n");
		}
	}
}
