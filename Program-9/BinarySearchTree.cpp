#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
BSTNode<T>::BSTNode(const T& value, BSTNode<T> *l, BSTNode<T> *r): left(l),
                    right(r), data(value)
{
} // BSTNode()

template <typename T>
BinarySearchTree<T>::BinarySearchTree(): root(NULL)
{
} //BinarySearchTree()

template <typename T>
void BinarySearchTree<T>::makeEmpty(const BSTNode<T> *t) const
{

  if(!t)
    return;

  makeEmpty(t->right);
  makeEmpty(t->left);
  delete t;
} // makeEmpty()

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
  makeEmpty(root);
  root = NULL;
} // ~BinarySearchTree()

template <typename T>
void BinarySearchTree<T>::insert(BSTNode<T> *t, const T &value)
{

  if(value < t->data)
  {

    if(t->left)
      insert(t->left, value);
    else // else statement
      t->left = new BSTNode<T>(value, NULL, NULL);
  } // if statement

  else // else statement
  if(t->data < value)
  {

    if(t->right)
      insert(t->right, value);
    else // else statement
      t->right = new BSTNode<T>(value, NULL, NULL);
  } // else if statement
  else // else statemtn
  {
    assert(value < t->data || t->data < value);
    cout << "Found duplicate." << endl;
  } // duplicate found.

} // insert()


template <typename T>
void BinarySearchTree<T>::insert(const T& value)
{

  if(!root)
    root = new BSTNode<T>(value, NULL, NULL);
    
  else // else statement
    insert(root, value);
 
} // insert()

template <typename T>
const BSTNode<T> * BinarySearchTree<T>::findMin(const BSTNode<T> *t) const
{
  const BSTNode<T> * current = t;

  while (current->left)
    current = current->left;

  return current;
} // findMin()

template <typename T>
void BinarySearchTree<T>::removeNode(BSTNode<T> *&t, const T &value)
{
    //check the four things to remove a node.
    //check is leaf
  BSTNode<T>* newParent;

  if(!(t->left)  && !(t->right))
  {
    delete t;
    t = NULL;
  } // leaf
  else // else statement
  if(!(t->left)  && t->right)
  {
    newParent = t->right;
    delete t;
    t = newParent;
  } //only has right sub-tree
  else // else statement
  if(t->left && !(t->right))
  {
    newParent = t->left;
    delete t;
    t = newParent;
  } // else statement
  else // else statement
  {
    const BSTNode<T>* rightMin = findMin(t->right);
    t->data = rightMin->data; //copy the data
    remove(t->right, t->data);
  }// else deleting a node that has two children.
} // removeNode()

template <typename T>
void BinarySearchTree<T>::remove(BSTNode<T> * &t, const T &value)
{
  //if t is root

  if(!(t < root) && !(root < t))
  {
    const BSTNode<T> * t = find(root, value);
    assert(t != NULL);

    if(!t)
    {
      cout << "Not found." << endl;
      return;
    } // if statement
  } // if statement

  if(!(t->data < value) &&
     !(value < t->data) )
  {
    //remove this node
    removeNode(t, value);
  } // data is equal to value

  else // else statement
  if ( value < t->data)
    remove(t->left, value);
  
  else // else statement
    remove(t->right, value);
    
} // remove()

template <typename T>
void BinarySearchTree<T>::remove(const T &value)
{
  assert(root);
  remove(root, value);
} // remove()

template <typename T>
const BSTNode<T>* BinarySearchTree<T>::find(const BSTNode<T> *t, const T &value)
                                            const
{

  if(!t)
    return NULL;

  //Want if (parent->data is equal to  value)

  if(!(t->data < value) && !(value < t->data))
    return t;  // data is equal to value

  if(value < t->data)
    return find(t->left, value);

  else // else statement
    return find(t->right, value);

  return NULL;
} // find();

template <typename T>
void BinarySearchTree<T>::find(const T& value) const
{
  assert( root != NULL);
  const BSTNode<T> * found = find(root, value);

  if(!found)
    cout << "Not found." << endl;
    
  else // else statement
    cout << "Found." << endl;

} // find()

template <typename T>
void BinarySearchTree<T>::inOrder( const BSTNode<T> *t) const 
{

  if(t)
  {
    inOrder(t->left);
    cout << t->data << ", ";
    inOrder(t->right);
  } // if statement

} // inOrder()

template <typename T>
void BinarySearchTree<T>::inOrder() const
{
  inOrder(root);
  cout << endl;
} // inOrder()

template <typename T>
void BinarySearchTree<T>::postOrder(const BSTNode<T> *t) const
{

  if(t)
  {
    postOrder(t->left);
    postOrder(t->right);
    cout << t->data << ", ";
  } // if statement

} // postOrder()

template <typename T>
void BinarySearchTree<T>::postOrder() const
{
  postOrder(root);
  cout << endl;
} // postOrder()
