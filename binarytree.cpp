
template <typename T>
class TreeNode
{
public:
    T key;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
    TreeNode(): key(0), left(nullptr), right(nullptr), parent(nullptr) {}
};

template <typename T>
class BinaryTree
{
    TreeNode<T> * top;
public:
    BinaryTree() {}

    TreeNode<T> * find(TreeNode<T> * node, T key );
    void insert(T key);
    void insert(TreeNode<T> * node,T key);
    void Tdelete(T key);
    T key(TreeNode<T> * Node);
    TreeNode<T> * left(TreeNode<T> * node);
    TreeNode<T> * right(TreeNode<T> * node);
    TreeNode<T> * parent(TreeNode<T> * node);
};

template <typename T>
TreeNode<T> *BinaryTree<T>::find(TreeNode<T> *node, T key)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (node->key == key)
    {
        return node;
    }
    if (key < node->key)
    {
        return find(node->left, key);
    }
    else
    {
        return BTfind(node->right, key);
    }
}

template <typename T>
void BinaryTree<T>::insert(T key)
{
    if (top == nullptr)
    {
        TreeNode<T> * newNode = new TreeNode<T>;
        newNode->key = key;
        top = newNode;
        return;
    }
    else
    {
        insert(top, key);
    }
}
template <typename T>
void BinaryTree<T>::insert(TreeNode<T> *node, T key)
{
    if(key < node->key)
    {
        if(node->left == nullptr)
        {
            TreeNode<T> * newNode = new TreeNode<T>;
            newNode->key = key;
            newNode->parent = node;
            node->left = newNode;
            return;
        }
        else
        {
            insert(node->left, key);
        }
    }
    else
    {
        if(node->right == nullptr)
        {
            TreeNode<T> * newNode = new TreeNode<T>;
            newNode->key = key;
            newNode->parent = node;
            node->right = newNode;
            return;
        }
        else
        {
            insert(node->right, key);
        }
    }
}
template <typename T>
void BinaryTree<T>::Tdelete(T key)
{
    TreeNode<T> * node = find(top, key);
    if(node == nullptr)
    {
        return;
    }
    if( (node->left == nullptr) && (node->right == nullptr))
    {
        delete node;
        return;
    }
    if( (node->left == nullptr) && (node->right != nullptr))
    {
        if (node->parent->right == node)
        {
            node->parent->right = node->right;
        }
        else
        {
            node->parent->left = node->right;
        }
        node->right->parent = node->parent;
        delete node;
        return;
    }
    if( (node->left != nullptr) && (node->right == nullptr))
    {
        if (node->parent->right == node)
        {
            node->parent->right = node->left;
        }
        else
        {
            node->parent->left = node->left;
        }
        node->left->parent = node->parent;
        delete node;
        return;
    }
    if ( (node->left != nullptr) && (node->right != nullptr))
    {
         TreeNode<T> * successor = node->right;
         while (successor->left != nullptr)
         {
             successor = successor->left;
         }
         node->key = successor->key;
         delete successor;
         return;
    }
}
template <typename T>
T BinaryTree<T>::key(TreeNode<T> *Node)
{
    return Node->key;
}

template <typename T>
TreeNode<T> * BinaryTree<T>::right(TreeNode<T> *node)
{
    return node->right;
}

template <typename T>
TreeNode<T> * BinaryTree<T>::left(TreeNode<T> *node)
{
    return node->left;
}

template <typename T>
TreeNode<T> * BinaryTree<T>::parent(TreeNode<T> *node)
{
    return node->parent;
}





