#include "assignment/binary_search_tree.hpp"

namespace assignment {

  BinarySearchTree::~BinarySearchTree() {
    BinarySearchTree::Clear();
  }

  void BinarySearchTree::Insert(int key, int value) {
    if (root_ == nullptr) {
      root_ = new Node(key,value);
    } else {
      insert(key, value, root_);
    }
  }

  bool BinarySearchTree::Remove(int key) {
    if (root_ != nullptr) {
      return remove(key,root_);
    }
    return false;
  }

  void BinarySearchTree::Clear() {
    clear(root_);
    root_ = nullptr;
  }

  std::optional<int> BinarySearchTree::Find(int key) const {
    Node* node = find(key, root_);
    if (node != nullptr) {
      return node->value;
    } else {
      return std::nullopt;
    }
  }

  bool BinarySearchTree::Contains(int key) const {
    return find(key, root_) != nullptr;
  }

  bool BinarySearchTree::IsEmpty() const {
    return root_ == nullptr;
  }

  std::optional<int> BinarySearchTree::FindMin() const {
    if(root_ != nullptr) {
      return find_min(root_)->key;
    }
    return std::nullopt;
  }

  std::optional<int> BinarySearchTree::FindMax() const {
    if(root_ != nullptr) {
      return find_max(root_)->key;
    }
    return std::nullopt;
  }

  Node* BinarySearchTree::root() const {
    return root_;
  }

  // вспомогательные методы

  void BinarySearchTree::insert(int key, int value, Node*& node) {
    if (node == nullptr) {
      node = new Node(key,value);
      node->right = nullptr;
      node->left = nullptr;
    } else {
      if (key > node->key) {
        insert(key, value, node->right);
      }
      if (key < node->key) {
        insert(key, value, node->left);
      }
      if (key == node->key) {
        node->value = value;
      }
    }
  }

  bool BinarySearchTree::remove(int key, Node*& node) {
    if (node != nullptr) {
      if (key > node->key) {
        return remove(key, node->right);
      }

      if (key < node->key) {
        return remove(key, node->left);
      }

      if (key == node->key) {
        if (node->right == nullptr && node->left == nullptr) {
          node = nullptr;
          return true;
        } else if (node->right != nullptr && node->left == nullptr) {
          node = node->right;
          node->right = nullptr;
          return true;
        } else if (node->left != nullptr && node->right == nullptr) {
          node = node->left;
          node->left = nullptr;
          return true;
        } else {
          Node* min_node = find_min(node->right);
          node->key = min_node->key;
          node->value = min_node->value;
          return remove(min_node->key, node->right);
        }
      }
    }
  }

  void BinarySearchTree::clear(Node* node) {
    if(node == nullptr) {
      return;
    }
    clear(node->left);
    clear(node->right);
    delete node;
  }

  Node* BinarySearchTree::find(int key, Node* node) const {
    if (node == nullptr) {
      return nullptr;
    }

    if(key < node->key) {
      return find(key, node->left);
    }

    if(key > node->key) {
      return find(key, node->right);
    }
    return node;
  }

  Node* BinarySearchTree::find_min(Node* node) const {
    if (node->left == nullptr) {
      return node;
    } else {
      return find_min(node->left);
    }
  }

  Node* BinarySearchTree::find_max(Node* node) const {
    if (node->right == nullptr) {
      return node;
    } else {
      return find_max(node->right);
    }
  }

}  // namespace assignment