// Created by Hassan Faris
// Prof. Manju Muralidharan on 11/22/25.
//

#ifndef FA25EC3_TREE_H
#define FA25EC3_TREE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
   TEMPLATE TREE CLASS
   Multiple parents may point to the same child.
   Students must manage storage, pointers, and dynamic allocation.

   Requirements:
   1. Templated Tree class.
   2. Nodes stored dynamically.
   3. Each node has:
      - id
      - data
      - vector of children pointers
   4. Students must prevent memory leaks.
   5. Students must create createRoot, addNode, findNode, print functions, etc.

   DO NOT IMPLEMENT ANYTHING HERE.
   Only placeholders and TODO comments.
*/


template <typename U>
class Node {
public:
    string id;
    U data;
    vector<Node<U>*> children;

    // TODO: Write constructor
    Node(const string &nodeID, const U &value)
            : id(nodeID),
            data(value) {}
};

template <typename T>
class Tree {
private:
    Node<T>* root;
    vector<Node<T>*> allNodes;

    Node<T>* findNodeFrom(Node<T>* current, const string &id) {
        if (!current) return nullptr;
        if (current->id == id) return current;

        for (Node<T>* child : current->children) {
            Node<T>* found = findNodeFrom(child, id);
            if (found) return found;
        }
        return nullptr;
    }

public:
    Tree(): root(nullptr) {
    }

    void createRoot(const string &id, const T &value) {
        Node<T>* existing = findNode(id);
        if (existing) {
            existing->data = value;
            root = existing;
            return;
        }

        Node<T>* node = new Node<T>(id, value);
        root = node;
        allNodes.push_back(node);
    }

    void addNode(const string &parentID, const string &childID, const T &value) {
        Node<T>* parent = findNode(parentID);
        if (!parent) {
            return;
        }

        Node<T>* child = findNode(childID);
        if (!child) {
            // Create new child
            child = new Node<T>(childID, value);
            allNodes.push_back(child);
        }

        parent->children.push_back(child);
    }

    Node<T>* findNode(const string &id) {
        if (!root) return nullptr;
        return findNodeFrom(root, id);
    }


    void printAll() {
        cout << "===== Story Tree =====" << endl;

        for (Node<T>* node : allNodes) {
            if (!node) continue;
            cout << "Node " << node->id << ": " << node->data << endl;

            if (node->children.empty()) {
                cout << "  Child -> (none)" << endl;
            } else {
                for (Node<T>* child : node->children) {
                    if (child) {
                        cout << "  Child -> " << child->id << endl;
                    }
                }
            }
            cout << endl;
        }

        cout << "=======" << endl;
    }

    void playGame() {
        if (!root) {
            cout << "No story loaded." << endl;
            return;
        }

        Node<T>* current = root;

        cout << "===== Begin Adventure =====" << endl << endl;

        while (current) {
            cout << current->data << endl;

            if (current->children.empty()) {
                cout << "There are no further paths." << endl;
                cout << "Your journey ends here." << endl;
                break;
            }

            cout << "Choose your next action:" << endl;
            for (size_t i = 0; i < current->children.size(); ++i) {
                cout << (i + 1) << ". " << current->children[i]->data << endl;
            }

            cout << "Selection: ";
            int choice;
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Ending adventure." << endl;
                break;
            }

            if (choice < 1 || static_cast<size_t>(choice) > current->children.size()) {
                cout << "Invalid choice, try again." << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            current = current->children[choice - 1];
            cout << endl;
        }

        cout << endl << "===== Adventure Complete =====" << endl;
    }

    ~Tree() {
        for (Node<T>* node : allNodes) {
            delete node;
        }
        allNodes.clear();
        root = nullptr;
    }
};


#endif //FA25EC3_TREE_H
