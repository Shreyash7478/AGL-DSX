#include"bst.h"
#include<iostream>

int fact(int n){
	if(n==1){
		return 1;
	}
	return n*fact(n-1);
}

node::node(){}

node::node(int x){
	data = x;
	left = NULL;
	right = NULL;
	
}

bst::bst(){
	root = NULL;	
	mirror = false;
}

void bst::insert(int x, node *Troot){
	if(x>Troot->data){
		if(Troot->right==NULL){
			Troot->right = new node(x);
			return;
		}
		insert(x,Troot->right);
		return;
	}else{
		if(Troot->left==NULL){
				Troot->left = new node(x);
				return;
			}
		insert(x,Troot->left);
	}
}

void bst::insert(int x){
	if(root==NULL){
		root = new node(x);
		return;
	}
	if(x>root->data){
		if(root->right==NULL){
			root->right = new node(x);
			return;
		}
		insert(x,root->right);
		return;
	}else{
		if(root->left==NULL){
				root->left = new node(x);
				return;
			}
		insert(x,root->left);
	}
}

void bst::inorder(){
	if(root == NULL){
		return;
	}
	if(mirror){
		std::cout<<"This tree is Mirror Image of it's orignal \n";
	}
	inorder(root->left);
	std::cout<<root->data<<std::endl;
	inorder(root->right);
}

void bst::inorder(node *Troot){
	if(Troot==NULL){
		return;
	}
	inorder(Troot->left);
	std::cout<<Troot->data<<std::endl;
	inorder(Troot->right);
}

bool bst::is_identical(node *bst1, node *bst2){
	if(bst2 == NULL && bst1 == NULL){
		return 1;
	}
	if(bst2 == NULL || bst1 == NULL){
		return 0;
	}
	if(bst2->data != bst1->data){
		return 0;
	}
	return is_identical(bst1->left,bst2->left) && is_identical(bst1->right,bst2->right);
}


bool bst::operator==(bst bst2){
	return is_identical(bst2.root,root);
}

bool bst::is_identical_structural(node *bst1, node *bst2){
	if (bst2 == NULL && bst1 == NULL){
		return 1;
	}
	if (bst2 == NULL || bst1 == NULL){
		return 0;
	}
	return is_identical(bst1->left, bst2->left) && is_identical(bst1->right, bst2->right);
}

bool bst::is_structurally_same(bst bst2){
	return is_identical_structural(root,bst2.root);
}

void bst::do_mirror(node *root)
{
	if (root == NULL){
		return;
	}
	do_mirror(root->left);
	do_mirror(root->right);
	node *temp = root->left;
	root->left = root->right;
	root->right = temp;
}

void bst::mirror_image(){
	mirror = !mirror;
	do_mirror(root);
}

void bst::r_inorder(node *root ,int l = 0){
	if(root==NULL){
		return;
	}
	r_inorder(root->right, l+3);
	for(int i =0;i<l;i++){
		std::cout<<"\t";
	}
	std::cout<<root->data<<std::endl;
	r_inorder(root->left,l);

}

void bst::r30(){
	r_inorder(root);
}

void bst::path(node *root, int *arr = NULL, int l=0){
	
	if(root->left == NULL && root->right == NULL){
		for(int i = 0;i<l;i++){
			std::cout<<arr[i]<<"  ->  ";
		}
		std::cout << root->data << "\n";
		return;
	}
	int *arr_new = new int[l+1];
	for(int i = 0;i<l;i++){
		arr_new[i] = arr[i];
	}
	arr_new[l] = root->data;
	if(root->left!=NULL){
		path(root->left,arr_new,l+1);
	}
	if(root->right!=NULL){
		path(root->right,arr_new,l+1);
	}
}

void bst::path(){
	path(root);
}

bool bst::sum_leaf(node *root,int sum){
	if(root==NULL){
		if(sum==0){
			return true;
		}
		return false;
	}
	sum = sum - root->data;
	return sum_leaf(root->left,sum) || sum_leaf(root->right,sum);
}

bool bst::sum_leaf(int sum){
	return sum_leaf(root,sum);
}

int bst::possible_structs(int n){
	if(n==0||n==1){
		return 1;
	}
	int c = 0;
	for( int i = 0 ; i < n ; i++ ){
		c = c + possible_structs(i)*possible_structs(n - 1- i);
	}
	return c;
}