#include "LinkedList.hpp"
#include <iostream>
int main(int argc, char* argv[]) {
    int arr[1] = {2};
    LinkedList<int> Ll(65, arr);
    std::cout << Ll.getNode(1)->getPayload() << "\n";
    return 0;
}