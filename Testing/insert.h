#ifndef INSERT_H_INCLUDED
#define INSERT_H_INCLUDED

struct Node;
struct Node* create_node(int data);
void delete_all_nodes(struct Node** head);
void b_insert(struct Node** head, int data);
void n_insert(struct Node** head, int data, int pos);
void e_insert(struct Node** head, int data);

#endif // INSERT_H_INCLUDED