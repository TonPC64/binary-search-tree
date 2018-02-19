///// bst.h ////
#include <iostream> 
using namespace std;
/////////////////////////////////////////////////////////////////////////

template<class Comperable>
class BinarySearchTree;


////////////////////// BINARY NODE ////////////////////////////////

template<class Comperable>
class BinaryNode
{
	Comperable element;
	BinaryNode *left;
	BinaryNode *right;

	BinaryNode( const Comperable & theElement, BinaryNode *lt, BinaryNode *rt ) : element( theElement ), left( lt ), right( rt ){}
	friend class BinarySearchTree<Comperable>;
};

///////////////////// CLASS INTERFACE ///////////////////////////////

template <class Comperable>
class BinarySearchTree{
public:
	explicit BinarySearchTree( const Comperable & notFound); 
	BinarySearchTree( const BinarySearchTree & rhs);
	BinarySearchTree();
	~BinarySearchTree();

	const Comperable & findMin() const;
	const Comperable & findMax() const;
	const Comperable & find( const Comperable & x) const;
	const Comperable & findChild( const Comperable & x) const;
	bool isEmpty() const;
	void printTree(char c) const;

	void makeEmpty();
	void insert( const Comperable & x);
	void remove( const Comperable & x);

	const BinarySearchTree & operator=( const BinarySearchTree & rhs);

private:
	BinaryNode<Comperable> *root;
	const Comperable ITEM_NOT_FOUND;

	const Comperable & elementAt( BinaryNode<Comperable> *t) const;

	void insert( const Comperable & x, BinaryNode<Comperable> * &t ) const;
	void remove( const Comperable & x, BinaryNode<Comperable> * &t ) const;
	BinaryNode<Comperable> * findMin( BinaryNode<Comperable> * t ) const;
	BinaryNode<Comperable> * findMax( BinaryNode<Comperable> * t ) const;
	BinaryNode<Comperable> * find(const Comperable & x, BinaryNode<Comperable> * t ) const;
	void makeEmpty( BinaryNode<Comperable> * & t) const;
	void printTreePre( BinaryNode<Comperable> *t ) const;
	void printTreeIn( BinaryNode<Comperable> *t ) const;
	void printTreePost( BinaryNode<Comperable> *t ) const;
	BinaryNode<Comperable> * clone( BinaryNode<Comperable> *t ) const;
};

//////////////////////////////////////////////////////////////////////
template <class Comperable>
BinarySearchTree<Comperable>::BinarySearchTree( const Comperable & notFound ) : root( NULL ), ITEM_NOT_FOUND( notFound )
{
}

template <class Comperable>
BinarySearchTree<Comperable>::BinarySearchTree( ) :
 root( NULL ), ITEM_NOT_FOUND( Comperable() )
{
}
 
/////////////////////// ELEMENT AT ////////////////////////////////////

template <class Comperable>
const Comperable & BinarySearchTree<Comperable>::elementAt( BinaryNode<Comperable> *t) const
{
	return  t == NULL ? ITEM_NOT_FOUND : t->element;
}

//////////////////////// FIND CHILD PUBLIC /////////////////////////////////////

template <class Comperable>
const Comperable & BinarySearchTree<Comperable>::find( const Comperable & x) const
{
return elementAt( find(x, root));
}
template <class Comperable>
const Comperable & BinarySearchTree<Comperable>::findChild( const Comperable & x) const
{
if(find(x, root)!=NULL) cout<<"\nFOUND MEMORY OF CHILD IS "<<find(x, root)<<"\n\n";
return elementAt( find(x, root));
}


//////////////////////// FIND MIN PUBLIC /////////////////////////////////////

template <class Comperable>
const Comperable & BinarySearchTree<Comperable>::findMin() const
{
if(findMin(root)!=NULL) cout<<"\nMIN ELEMENT OF TREE IS "<<elementAt(findMin(root))<<"\n\nMEMORY OF CHILD IS "<<findMin(root)<<"\n\n";
else  cout<<"\n!!! CHILD NOT FOUND !!!\n\n";
return elementAt( findMin(root));
}

//////////////////////// FIND MAX PUBLIC /////////////////////////////////////

template <class Comperable>
const Comperable & BinarySearchTree<Comperable>::findMax() const
{
if(findMax(root)!=NULL) cout<<"\nMAX ELEMENT OF TREE IS "<<elementAt(findMax(root))<<"\n\nMEMORY OF CHILD IS "<<findMax(root)<<"\n\n";
else cout<<"\n!!! CHILD NOT FOUND !!!\n\n";
return elementAt( findMax(root));
}

//////////////////////// FIND PRIVATE ///////////////////////////////////

template <class Comperable>
BinaryNode<Comperable> * BinarySearchTree<Comperable>::find( const Comperable & x, BinaryNode<Comperable> *t ) const
{
	if( t==NULL)
		return NULL;
	else if(x < t->element)
		return find(x,t->left );
	else if( t->element < x )
		return find(x,t->right );
	else
	
		return t;
}

///////////////////////// FIND MIN PRAVATE/////////////////////////////////

template <class Comperable>
BinaryNode<Comperable> * BinarySearchTree<Comperable>::findMin( BinaryNode<Comperable> *t) const
{
	if( t==NULL)
		return NULL;
	if( t->left == NULL)
		return t;
	return findMin( t->left );
}

//////////////////////////// FIND MAX PRIVATE //////////////////////////////////

template <class Comperable>
BinaryNode<Comperable> * BinarySearchTree<Comperable>::findMax( BinaryNode<Comperable> *t ) const
{
	if( t != NULL)
		while(t->right !=NULL )
			t = t->right;
	return t;
}

////////////////////////// INSERT PUBLIC ///////////////////////////////////

template<class Comperable>
void BinarySearchTree<Comperable>::insert( const Comperable & x ) 
{
insert(x,root);
}

////////////////////////// INSERT PRIVATE ///////////////////////////////////

template<class Comperable>
void BinarySearchTree<Comperable>::insert( const Comperable & x, BinaryNode<Comperable> * & t ) const
{
	if( t == NULL)
		t = new BinaryNode<Comperable>( x, NULL, NULL);
	else if( x < t->element)
		insert( x, t->left);
	else if( t->element < x )
		insert( x, t->right );
	else
		;
}
/////////////////////////// REMOVE PUBLIC////////////////////////////////////

template<class Comperable>
void BinarySearchTree<Comperable>::remove( const Comperable & x) 
{
remove(x,root);
}
/////////////////////////// REMOVE PRIVATE////////////////////////////////////

template<class Comperable>
void BinarySearchTree<Comperable>::remove( const Comperable & x,BinaryNode<Comperable> * & t) const
{
	if( t == NULL)
		return;
	if( x < t->element)
		remove( x, t->left );
	else if( t->element < x )
		remove( x, t->right );
	else if( t->left != NULL && t->right != NULL )
	{
		t->element = findMin( t->right )->element;
		remove( t->element,t->right);
	}
	else
	{
		BinaryNode<Comperable> *oldNode = t;
		t = ( t->left != NULL ) ? t->left : t->right;
		delete oldNode;
	}
}
/////////////////////////// CONSTUCTOR FUNTION ////////////////////////////////////

template<class Comperable>
BinarySearchTree<Comperable>::~BinarySearchTree()
{
	makeEmpty();
}

template <class Comperable>
void BinarySearchTree<Comperable>::makeEmpty()
{
	makeEmpty(root);
}

/////////////////////////// MAKE EMPTY  PRIVATE////////////////////////////////////

template <class Comperable>
void BinarySearchTree<Comperable>::makeEmpty( BinaryNode<Comperable> * & t) const
{
	if( t != NULL )
	{
		makeEmpty( t->left);
		makeEmpty( t->right);
		delete t;
	}
	t = NULL;
}

/////////////////////////// PRINT TREE PUBLIC ////////////////////////////////////

template <class Comperable>
void BinarySearchTree<Comperable>::printTree(char c) const
{
	if( isEmpty())
		cout<<"Empty Tree";
	else
		switch(c){
		case '1' : 
			printTreePre( root );
		break;
		case '2' : 
			printTreeIn( root );
		break;
		case '3' : 
			printTreePost( root );
		break;
	}
		
}

/////////////////////////// PRINT TREE PRE PRIVATE ////////////////////////////////////

template <class Comperable>
void BinarySearchTree<Comperable>::printTreePre( BinaryNode<Comperable> *t ) const
{
	if( t != NULL )
	{
		cout<< t->element <<" ";
		printTreePre( t->left );
		printTreePre( t->right);
	}
}
/////////////////////////// PRINT TREE IN PRIVATE ////////////////////////////////////

template <class Comperable>
void BinarySearchTree<Comperable>::printTreeIn( BinaryNode<Comperable> *t ) const
{
	if( t != NULL )
	{
		
		printTreeIn( t->left );
		cout<< t->element << " ";
		printTreeIn( t->right);
	}
}
/////////////////////////// PRINT TREE POST PRIVATE ////////////////////////////////////

template <class Comperable>
void BinarySearchTree<Comperable>::printTreePost( BinaryNode<Comperable> *t ) const
{
	if( t != NULL )
	{
		
		printTreePost( t->left );
		printTreePost( t->right);
		cout<< t->element << " ";
	}
}

/////////////////////////// OPERATOR ////////////////////////////////////

template <class Comperable>
const BinarySearchTree<Comperable> & BinarySearchTree<Comperable>::operator=( const BinarySearchTree<Comperable> & rhs)
{
	if( this != &rhs )
	{
		makeEmpty();
		root = clone(rhs.root);
	}
	return *this;
}

/////////////////////////// CLONE ////////////////////////////////////

template<class Comperable>
BinaryNode<Comperable> * BinarySearchTree<Comperable>::clone(BinaryNode<Comperable> * t ) const
{
	if(t == NULL )
		return NULL;
	else
		return new BinaryNode<Comperable>( t->element, clone(t->left),clone(t->right));
}

///////////////////////// IS EMPTY ////////////////////////////////
template <class Comperable>
bool BinarySearchTree<Comperable>::isEmpty( ) const
{
    return root == NULL;
}