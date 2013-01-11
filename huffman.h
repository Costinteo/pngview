#ifndef HUFFMAN_H
#define HUFFMAN_H

typedef struct htree {
    int symbol;
    struct htree *left, *right;
} htree_t;

htree_t *huffman_create_tree(int count, int *symbols, int *lengths);

#endif
