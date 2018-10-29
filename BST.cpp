#ifndef BST_H
#define BST_H
#include <iostream>
#include <queue>
using namespace std;

template <class K, class E>
struct Node {
	Node(K ky, E el, Node<K, E> *left = 0, Node<K, E> *right = 0)
		: key(ky), element(el), leftChild(left), rightChild(right) { }
	Node<K, E> *leftChild;
	K key;
	E element;
	Node<K, E> *rightChild;
};

template <class K, class E>
class BST {
public:
	BST() { root = 0; } // empty BST
	void Insert(K &newkey, E &el) { Insert(root, newkey, el); }
	void Preorder() { Preorder(root); }
	void Inorder() { Inorder(root); }
	void Postorder() { Postorder(root); }
	bool Find(const K&, E&);
	void Delete(K &oldkey) { Delete(root, oldkey); }

	void Levelorder();
private: // helper hä
	void Visit(Node<K, E> *);
	void Insert(Node<K, E>* &, K &, E &);
	void Preorder(Node<K, E> *);
	void Inorder(Node<K, E> *);
	void Postorder(Node<K, E> *);
	void Delete(Node<K, E>* &, K &);

	Node<K, E> *root;

};

template <class K, class E>
void BST<K, E>::Visit(Node<K, E> *ptr)
{ cout << ptr->key << ":" << ptr->element << " "; }

template <class K, class E>
void BST<K, E>::Insert(Node<K, E>* &ptr, K &newkey, E &el) { //InsertX helperh
	if (ptr == 0) ptr = new Node<K, E>(newkey, el);
	else if (newkey < ptr->key) Insert(ptr->leftChild, newkey, el);
	else if (newkey > ptr->key) Insert(ptr->rightChild, newkey, el);
	else ptr->element = el; // Update element
}
template <class K, class E>
void BST<K, E>::Preorder(Node<K, E> *currentNode) { // h
	if (currentNode) {
		Visit(currentNode);//􀀀 Visitt <􀀀tÀ\ è¸0 %Xà ´$ä.
		Preorder(currentNode->leftChild);
		Preorder(currentNode->rightChild);

	}
}
template <class K, class E>
void BST<K, E>::Inorder(Node<K, E> *currentNode) { // h
	if (currentNode) {
		Inorder(currentNode->leftChild);
		Visit(currentNode);
		Inorder(currentNode->rightChild);
	}
}
template <class K, class E>
void BST<K, E>::Postorder(Node<K, E> *currentNode) { //Äh
	if (currentNode) {
		Postorder(currentNode->leftChild);
		Postorder(currentNode->rightChild);
		Visit(currentNode);
	}
}

template <class K, class E>
void BST<K, E>::Levelorder() { //¨0􀀀 h
	queue<Node<K, E>*>q;
	Node<K, E> *currentNode = root;
	while (currentNode)
	{
		Visit(currentNode);
		if (currentNode->leftChild) q.push(currentNode->leftChild);
		if (currentNode->rightChild) q.push(currentNode->rightChild);
		if (q.empty()) return;
		132 currentNode = q.front();
		q.pop();
	}
}

template <class K, class E>
bool BST<K, E>::Find(const K& k, E& e)
{
	Node<K, E> *ptr = root;
	while (ptr)
		if (k < ptr->key) ptr = ptr->leftChild;
		else if (k > ptr->key) ptr = ptr->rightChild;
		else { e = ptr->element; return true; }
		return false;
}
 template <class K, class E>
 void BST<K, E>::Delete(Node<K, E>* &ptr, K &oldkey)
 {
	 Node<K, E>*tmpptr; Node<K, E> *tmpdaddyptr;
	 if (ptr == 0) return; // øð xÜ􀀀 Æ<À\, øå return

	 if (oldkey < ptr->key) Delete(ptr->leftChild, oldkey);

	 else if (oldkey > ptr->key) Delete(ptr->rightChild, oldkey);
	 else
	 {//이 괄호가 맞는지 확인
		 if (!ptr->leftChild && !ptr->rightChild) // Ýt Æät
		 {
			 delete ptr; ptr = 0; return;
		 }//
		 else if (ptr->leftChild && !ptr->rightChild) //|½ÝÌ ät
		 {
			 tmpptr = ptr; ptr = ptr->leftChild; delete tmpptr; return;
		 }
		 else if (!ptr->leftChild && ptr->rightChild) // $x½ ÝÌ ät
		 {
			 tmpptr = ptr; ptr = ptr->rightChild; delete tmpptr; return;
		 }
		 else
		 { //PÝL:
			 Node<K, E> *rc = ptr->rightChild; // rc􀀀 è¸x subtree
			 if (!rc->leftChild) // rc􀀀 |½Ýt Æ<t rc􀀀 ø xÜ!
			 {
				 ptr->key = rc->key;// rcxÜX key/element/rightChild ô| ptrxÜ\ .0à
				 ptr->element = rc->element;
				 ptr->rightChild = rc->rightChild;
				 delete rc;
			 }
			 else // rcX |½ Ýt  ½°, rcX |½ÝX |½ÝX
			 {
				 while (rc->leftChild->leftChild)//rcX leftchild􀀀 t¬XÀ JD L LÀ
				 {
					 rc = rc->leftChild;
				 }
				 ptr->key = rc->leftChild->key;
				 ptr->element = rc->leftChild->element;
				 rc->leftChild = rc->leftChild->rightChild;
				 delete rc->leftChild;
			 }
		 }
	 }
 }
	194 #endif