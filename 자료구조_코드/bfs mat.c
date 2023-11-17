// bfs mat
#include <stdio.h>
#define NULL 0
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50
typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;


void graph_init(GraphType* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = NULL;
}

void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u, int v)
{
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	g->adj_mat[u][v] = 1;
}
int visited[MAX_VERTICES];

#define MAX_QUEUE_SIZE 100
typedef int element;
typedef struct {
	element  queue[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;
//
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(QueueType* q)
{
	q->front = q->rear = 0;
}

int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

void bfs_mat(GraphType* g, int v)
{
	int w;
	QueueType q;
	init(&q);
	visited[v] = TRUE;
	printf("%d ", v);
	enqueue(&q, v);	
	while (!is_empty(&q)) {
		v = dequeue(&q);
		for (w = 0; w < g->n; w++)
			if (g->adj_mat[v][w] && !visited[w]) {
				visited[w] = TRUE;
				printf("%d ", w);
				enqueue(&q, w);
			}
	}
}
//
main()
{
	int i;
	GraphType g;

	graph_init(&g);

	for (i = 0; i < 4; i++)
		insert_vertex(&g, i);
	insert_edge(&g, 0, 1);
	insert_edge(&g, 1, 0);
	insert_edge(&g, 0, 3);
	insert_edge(&g, 3, 0);
	insert_edge(&g, 1, 2);
	insert_edge(&g, 2, 1);
	insert_edge(&g, 1, 3);
	insert_edge(&g, 3, 1);
	insert_edge(&g, 2, 3);
	insert_edge(&g, 3, 2);
	bfs_mat(&g, 0);
}
