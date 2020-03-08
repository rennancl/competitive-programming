#include <stdlib.h>
#include <stdio.h>

int pai[26];

int find(int i)
{
    if (pai[i] == i)
        return i;
    return find(pai[i]);
}

void union_(int x, int y){
	int xset = find(x);
    int yset = find(y);
    if(yset < xset)  pai[xset] = yset; else pai[yset] = xset;
	return;
}

int main(int argc, char const *argv[])
{
	int tests;
	int vertices, edges;
	char char1, char2;
	int node1, node2;
	int components = 0;
	int isComponent = 0;
	int i, j, k;

	scanf("%d\n", &tests);
	for ( i = 0; i < tests; i++)
	{
		components = 0;
		for (j = 0; j < 26; ++j)
		{
			pai[j] = j;
		}

		scanf("%d %d\n", &vertices, &edges);	
		for (k = 0; k < edges; k++)
		{
			scanf("%c %c\n", &char1, &char2);
			node2 = (int)char1 - 'a';
			node1 = (int)char2 - 'a';
			union_(node1, node2);
		}

		printf("Case #%d:\n", i+1);
		for (j = 0; j < vertices; j++)
		{
			isComponent = 0;
			for ( k = 0; k < vertices; k++)
			{
				if(j == find(k)) {
					printf("%c,", (char)k + 'a');
					isComponent = 1;
				}
			}
			if(isComponent) {
				printf("\n");
				components++;
			}
		}
		printf("%d connected components\n\n", components);
	}
	return 0;
}