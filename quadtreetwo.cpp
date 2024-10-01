#include <iostream>
#include <vector>

using namespace std;

class Node{
public:
	bool val;
	bool isLeaf;
	Node* topLeft;
	Node* topRight;
	Node* bottomLeft;
	Node* bottomRight;

	Node(){
		val=false;
		isLeaf=false;
		topLeft=NULL;
		topRight=NULL;
		bottomLeft=NULL;
		bottomRight=NULL;
	}

	Node(bool _val, bool _isLeaf){
		val=_val;
		isLeaf=_isLeaf;
		topLeft=NULL;
		topRight=NULL;
		bottomLeft=NULL;
		bottomRight=NULL;
	}

	Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight){
		val=_val;
		isLeaf=_isLeaf;
		topLeft=_topLeft;
		topRight=_topRight;
		bottomLeft=_bottomLeft;
		bottomRight=_bottomRight;
	}
};

class Solution{
public:
	Node* intersect(Node* quadTree1, Node* quadTree2){
		if(quadTree1->isLeaf && quadTree2->isLeaf){
			return new Node(quadTree1->val || quadTree2->val, true);
		}else if(quadTree1->isLeaf){
			return quadTree1->val ? quadTree1 : quadTree2;
		}else if(){
			return quadTree2->val ? quadTree2 : quadTree1;
		}else{
            Node* tl=intersect(quadTree1->topLeft, quadTree2->topLeft);
            Node* tr=intersect(quadTree1->topRight, quadTree2->topRight);
            Node* bl=intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
            Node* br=intersect(quadTree1->bottomRight, quadTree2->bottomRight);

            bool isLeaf=tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf &&
            tl->val==tr->val && tr->val==bl->val && bl->val==br->val;

            if(isLeaf){
                //se retorna un nuevo children, hijo
                return new Node(tl->val, true);
            }else{
                //se crea un nuevo non-leaf node
                return new Node(true, false, tl, tr, bl, br);
            }
        }
	}
};

int main(){
	return 0;
}