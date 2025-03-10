#include <iostream>
#include <string>

template<typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& val) : data(val), next(nullptr) {}
    Node(T&& val) : data(std::move(val)), next(nullptr) {}
};

template<typename T>
void printNodes(Node<T>* head)
{
    Node<T>* curr_node = head;

    /* Loop through linked list
     * The flow for looping through a linked list is generally the same.
     * In plain english, while our current node is valid, we do our logic (in this case output the data)
     * and then we "increment" our node. Eventually, our node becomes invalid, signaling we reached the
     * end of the list, thus we break the loop.
     */
    while (curr_node != nullptr) {
        std::cout << curr_node->data << std::endl;
        curr_node = curr_node->next;  // this is how we "increment", or move to our next node
    }
}

int main()
{
    /* Initialize the nodes to be used in our linked list
     * The compiler can infer the data type if we don't explicitly declare it.
     * But, I declared the type explicitly for this example
     */
    // Node<std::string> head("Head");  // OR Node head("Head")
    // Node<std::string> link1("One");
    // Node<std::string> link2("Two");
    // Node<std::string> tail("Tail");
    auto* head = new Node((std::string)"Head");  // OR Node head("Head")
    auto* link1 = new Node((std::string)"One");
    auto* link2 = new Node((std::string)"Two");
    auto* tail = new Node((std::string)"Tail");

    // "Link" our nodes by assigning next pointers
    head->next = link1;
    link1->next = link2;
    link2->next = tail;

    printNodes<std::string>(head);
    return 0;
}