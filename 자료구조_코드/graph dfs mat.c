// graph dfs mat
#include <stdio.h>
#define MAX_VERTICES 4
int adj_mat[MAX_VERTICES][MAX_VERTICES] = {
	{0,1,0,1},
	{1,0,1,1},
	{0,1,0,1},
	{1,1,1,0} };
int visited[MAX_VERTICES];
int n = 4;

void graph_dfs_mat(int v)
{
	int w;
	visited[v] = 1;
	printf("%d ", v);
	for (w = 0; w < n; w++)
		if (adj_mat[v][w] && !visited[w])
			graph_dfs_mat(w);
}
void main()
{
	graph_dfs_mat(0);
}
/*  */
void read_graph(char* file_name)
{
	int i, j;
	FILE* fp = fopen(file_name, "r");
	if (fp == NULL) return;
	fscanf(fp, "%d\n", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			fscanf(fp, "%d", &adj_mat[i][j]);
		}
	}
	fclose(fp);
}

/*  */
void write_graph(char* file_name)
{
	int i, j;
	FILE* fp = fopen(file_name, "w");
	if (fp == NULL) return;
	fprintf(fp, "%d\n", n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			fprintf(fp, " %d ", adj_mat[i][j]);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
}