#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <map>
using namespace std;
struct TreeNode
{
	char left;
	char right;
	TreeNode(){ left = 0; right = 0; }
};
char BuildTree(string a, string b, TreeNode * Tree/*, char * characterPrev, char * characterMiddle*/){
	char root=a[0]; /*根节点*/
	if (a.length() == 1){
		return root;
	}
	int rootIndex = b.find(root); /*查找root在中序中的位置*/
	string MiddleLeft = b.substr(0, rootIndex);
	string MiddleRight = b.substr(rootIndex+1, b.length() - rootIndex-1);
	string PrevLeft  = a.substr(1, rootIndex);
	string PrevRight = a.substr(rootIndex + 1, b.length() - rootIndex - 1);
	if (MiddleLeft.length() > 0){
		Tree[root].left = BuildTree(PrevLeft, MiddleLeft, Tree);
	}
	else{
		Tree[root].left = 0;
	}
	if (MiddleRight.length() > 0){
		Tree[root].right = BuildTree(PrevRight, MiddleRight, Tree);
	}
	else{
		Tree[root].right = 0;
	}
	return root;
}
void printTree(char root,TreeNode * Tree){
	char l = Tree[root].left;
	char r = Tree[root].right;
	if (l != 0){
		printTree(l, Tree);
	}
	if (r != 0){
		printTree(r, Tree);
	}
	cout << root;
}
int main()
{
	string a, b; /*输入数据*/
	TreeNode * Tree= new TreeNode['Z'+1]; /*还原树*/
	char root; /*根节点*/
	cin >> a >> b; 
	root = BuildTree(a, b, Tree);
	printTree(root, Tree);
}