#ifndef rbt_h
#define rbt_h


typedef struct rbt_node *rbt;

extern rbt rbt_delete(rbt b, char *str);
extern rbt rbt_free(rbt b);
extern rbt rbt_insert(rbt b, char *str);
extern rbt rbt_new();
extern rbt right_rotate(rbt b);
extern rbt left_rotate(rbt b);
extern rbt colour_flip(rbt b);
extern void rbt_inorder(rbt b, void f(char *str));
extern void rbt_preorder(rbt b, void f(char *str));

extern int rbt_search(rbt b, char *str);

#endif/*RBT_H*/