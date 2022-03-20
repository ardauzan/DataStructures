#include "LinkedList.hpp"
#include <iostream>
int main(int argc, char* argv[]) {
    int arr[1] = {2};
    LinkedList<int> Ll(1, arr);
    std::cout << Ll.getHead()->getPayload() << "\n";
    return 0;
}