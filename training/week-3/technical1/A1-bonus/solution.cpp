#include <bits/stdc++.h>

struct node {
    int value;
    node* next;

    node(int value) : value{value}, next{nullptr} {}
};

struct linked_list {
    int length;
    node* root;

    linked_list() : length{}, root{nullptr} {}

    node& operator [](int index) {
        if (!check(index)) {
            exit(EXIT_FAILURE);
        }

        node* to_get{root};
        while (index--) {
            to_get = to_get->next;
        }

        return *to_get;
    }

    void append(int value) {
        if (!length) {
            root = new node(value);
        } else {
            (*this)[length - 1].next = new node(value);
        }

        length++;
    }

    void pop(int index) {
        if (!check(index)) {
            exit(EXIT_FAILURE);
        }

        node* to_delete{nullptr};
        if (!index) {
            to_delete = root;
            root = to_delete->next;
        } else {
            node* parent{root};
            while (--index) {
                parent = parent->next;
            }

            to_delete = parent->next;
            parent->next = to_delete->next;
        }

        to_delete->next = nullptr;
        delete to_delete;

        length--;
    }

private:
    bool check(int index) {
        if (index >= length) {
            std::cerr << "[Error] The length of the linked list is less than the requested index" << std::endl;
            return false;
        }

        if (index < 0) {
            std::cerr << "[Error] The linked list does not support negative indices" << std::endl;
            return false;
        }

        return true;
    }
};

int main() {
    linked_list list{};
    do {
        std::string instruction; std::cin >> instruction;
        if (instruction == "exit") {
            break;
        } else if (instruction == "length") {
            std::cout << list.length << std::endl;
        } else if (instruction == "add") {
            int value; std::cin >> value;
            list.append(value);
        } else if (instruction == "remove") {
            int index; std::cin >> index;
            list.pop(index);
        } else if (instruction == "get") {
            int index; std::cin >> index;
            std::cout << list[index].value << std::endl;
        }
    } while (true);
}