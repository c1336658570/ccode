/*
3.阅读下面的代码，判断 a 中哪些元素被改变了，解释原因。

struct node {
	char a;
	int b;
	short c;
};
struct n {
	char a;
	int b;
};
int main(int argc, char* argv[])
{
	struct node a[2] = {{1,2,3},{4,5,6}};
	*(int *)((char *)a + 2 * sizeof(struct n)) = 100;
	return 0;
}
*/

# include <stdio.h>

struct node {
	char a;
	int b;
	short c;
};
struct n {
	char a;
	int b;
};
int main(int argc, char* argv[])
{
	struct node a[2] = {{1,2,3},{4,5,6}};
	*(int *)((char *)a + 2 * sizeof(struct n)) = 100;
    printf("%d\n", a[1].b);
	return 0;
}