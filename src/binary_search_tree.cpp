#include "assignment/binary_search_tree.hpp"

namespace assignment {

  BinarySearchTree::~BinarySearchTree() {
    BinarySearchTree::Clear();
  }

  void BinarySearchTree::Insert(int key, int value) {
    // Write your code here...
  }

  bool BinarySearchTree::Remove(int key) {
    // Write your code here...
    return false;
  }

  void BinarySearchTree::Clear() {
    if (!IsEmpty()) {
      clear(root_);
    }
  }

  std::optional<int> BinarySearchTree::Find(int key) const {
    if (IsEmpty()) {
      return std::nullopt;
    } else {
      if (find(key,root_) == nullptr) {
        return std::nullopt;
      }
      return find(key,root_)->value;
    }
  }

  bool BinarySearchTree::Contains(int key) const {
    // Write your code here...
    return false;
  }

  bool BinarySearchTree::IsEmpty() const {
    return root_ == nullptr;
  }

  std::optional<int> BinarySearchTree::FindMin() const {
    // Write your code here...
    return std::nullopt;
  }

  std::optional<int> BinarySearchTree::FindMax() const {
    // Write your code here...
    return std::nullopt;
  }

  Node* BinarySearchTree::root() const {
    return root_;
  }

  // вспомогательные методы

  void BinarySearchTree::insert(int key, int value, Node*& node) {
    // Write your code here ...
  }

  bool BinarySearchTree::remove(int key, Node*& node) {
    // Write your code here...
    return false;
  }

  void BinarySearchTree::clear(Node* node) {
    if (node->left != nullptr) {
      clear(node->left);
    }
    if (node->right != nullptr) {
      clear(node->right);
    }
    delete node;
  }

  Node* BinarySearchTree::find(int key, Node* node) const {
    if (node->key == key) {
      return node;
    }
    if (node->left != nullptr) {
      if (key < node->key) {
        find(key,node->left);
      }
    }
    if (node->right != nullptr) {
      if (key > node->key) {
        find(key,node->right);
      }
    }
    return nullptr;
  }

  Node* BinarySearchTree::find_min(Node* node) const {
    // Write your code here...
    return nullptr;
  }

  Node* BinarySearchTree::find_max(Node* node) const {
    // Write your code here...
    return nullptr;
  }

}  // namespace assignment