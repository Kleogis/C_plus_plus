#include "Node.h"
#include <string>

using namespace std;

Node::Node(string d) {
    data = d;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    balanceFactor = 0;
}