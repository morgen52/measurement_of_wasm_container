#include <stdio.h>
#include <stdlib.h>

#define decl_tree_type(T)                                                       \
        typedef struct node_##T##_t node_##T##_t, *node_##T;                    \
        struct node_##T##_t { node_##T left, right; T value; };                 \
                                                                                \
        node_##T node_##T##_new(T v) {                                          \
                node_##T node = malloc(sizeof(node_##T##_t));                   \
                node->value = v;                                                \
                node->left = node->right = 0;                                   \
                return node;                                                    \
        }                                                                       \
        node_##T node_##T##_insert(node_##T root, T v) {                        \
                node_##T n = node_##T##_new(v);                                 \
                while (root) {                                                  \
                        if (root->value < n->value)                             \
                                if (!root->left) return root->left = n;         \
                                else root = root->left;                         \
                        else                                                    \
                                if (!root->right) return root->right = n;       \
                                else root = root->right;                        \
                }                                                               \
                return 0;                                                       \
        }

#define tree_node(T) node_##T
#define node_insert(T, r, x) node_##T##_insert(r, x)
#define node_new(T, x) node_##T##_new(x)

decl_tree_type(double);
decl_tree_type(int);

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
int main()
{
	struct timeval my_tv;
	gettimeofday(&my_tv,NULL);
	time_t my_t = my_tv.tv_sec;
	long my_us = my_tv.tv_usec;
	struct tm *my_tm;
	char my_buf[1024];
	my_tm = localtime(&my_t);
	strftime(my_buf, sizeof(my_buf), "%M:%S", my_tm);
	printf("start complete time:%s.%06ld\n", my_buf, my_us);
// additional code
        int i;
        tree_node(double) root_d = node_new(double, (double)rand() / RAND_MAX);

        for (i = 0; i < 10000; i++)
                node_insert(double, root_d, (double)rand() / RAND_MAX);

        tree_node(int) root_i = node_new(int, rand());
        for (i = 0; i < 10000; i++)
                node_insert(int, root_i, rand());

        return 0;
}