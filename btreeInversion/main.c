//
//  main.c
//  btreeInversion
//
//  Created by LiLingyu on 16/3/6.
//  Copyright © 2016年 LiLingyu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct tnode
{
    int data;
    struct tnode* left;
    struct tnode* right;
}
tnode;


tnode* create_tree()
{
    int data;
    scanf("%d", &data);
    
    if (-1 == data) {
        return NULL;
    }
    
    tnode* parent = (tnode*)malloc(sizeof(*parent));
    assert(NULL!=parent);
    parent->data=data;
    
    parent->left = create_tree();
    parent->right = create_tree();
    
    
    
    return parent;
}
/*
tnode* create_root(int data)
{
    tnode* root_p = (tnode*)malloc(sizeof(*root_p));
    assert(NULL!=root_p);
    
    root_p->data = data;
    root_p->left = NULL;
    root_p->right = NULL;
    
    return root_p;
}

tnode* create_left(tnode* parent, int data)
{
    assert(NULL == parent->left);
    
    tnode* lp = (tnode*)malloc(sizeof(*lp));
    assert(NULL != lp);
    lp->data = data;
    lp->left = NULL;
    lp->right = NULL;
    
    parent->left=lp;
    
    return lp;
}

tnode* create_right(tnode* parent, int data)
{
    assert(NULL == parent->right);
    
    tnode* rp = (tnode*)malloc(sizeof(*rp));
    assert(NULL != rp);
    rp->data = data;
    rp->left = NULL;
    rp->right = NULL;
    
    parent->right=rp;
    
    return rp;
}
*/
void destroy_tree(tnode* root)
{
    if (NULL == root) {
        return;
    }
    
    tnode* left = root->left;
    tnode* right = root->right;
    
    free(root);
    
    destroy_tree(left);
    destroy_tree(right);
}

void pre_travesal_core(tnode* root)
{
    if (NULL==root) {
        return;
    }
    printf("%d\t", root->data);
    pre_travesal_core(root->left);
    pre_travesal_core(root->right);
}

void pre_travesal(tnode* root)
{
    pre_travesal_core(root);
    printf("\n");
}

void mid_travesal_core(tnode* root)
{
    if (NULL==root) {
        return;
    }
    
    mid_travesal_core(root->left);
    printf("%d\t", root->data);
    mid_travesal_core(root->right);
    
}

void mid_travesal(tnode* root)
{
    mid_travesal_core(root);
    printf("\n");
}

void sub_travesal_core(tnode* root)
{
    if (NULL==root) {
        return;
    }
    
    sub_travesal_core(root->left);
    sub_travesal_core(root->right);
    
    printf("%d\t", root->data);
}

void sub_travesal(tnode* root)
{
    sub_travesal_core(root);
    printf("\n");
}

void inverseBtree(tnode* root)
{
    if (NULL==root) {
        return;
    }
    
    tnode* tmp=root->left;
    root->left=root->right;
    root->right = tmp;
    
    inverseBtree(root->left);
    inverseBtree(root->right);
}

int main(int argc, const char * argv[]) {
    
    tnode* root = create_tree();
    
    pre_travesal(root);
    mid_travesal(root);
    sub_travesal(root);
    
    //inverse btree
    printf("******\n");
    inverseBtree(root);
    
    pre_travesal(root);
    mid_travesal(root);
    sub_travesal(root);

    
    destroy_tree(root);
    
    
    
    return 0;
}
