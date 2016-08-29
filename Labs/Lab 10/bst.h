//Jackson Chandler
//jccyb4
//12388312
//lab 10
//11/19/2014

typedef struct node_{
	int data;
	struct node_*left;
	struct node_*right;

}BST;

BST* build_balanced_tree(int a[], int low, int high);
BST* delete_node(BST* tree, int data);
BST* min(BST* tree_node);
void padding(char ch, int n);
void structure(BST* root, int level);
void print(BST* root);
