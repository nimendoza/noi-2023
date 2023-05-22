#include <bits/stdc++.h>

template<class type>
struct has_next {
    type* next;

    has_next() : next{nullptr} {}
    ~has_next() {
        delete next;
    }
};

struct node : has_next<node> {
    int value;

    node(int value) : value{value} {}
};

struct linked_list : has_next<node> {
    int length;

    linked_list() : length{} {}
};

linked_list* linked_list_create() {
    return new linked_list();
}

void linked_list_destroy(linked_list* list) {
    delete list;
}

void linked_list_add(linked_list* list, int value) {
    has_next<node>* back{list};
    while (back->next) {
        back = back->next;
    }

    back->next = new node(value);
    list->length++;
}

bool linked_list_check(linked_list* list, int index) {
    if (index >= list->length) {
        std::cerr << "[Error] The length of the linked list is less than the requested index" << std::endl;
        return false;
    }

    if (index < 0) {
        std::cerr << "[Error] The linked list does not support negative indices" << std::endl;
        return false;
    }

    return true;
}

void linked_list_remove(linked_list* list, int index) {
    if (!linked_list_check(list, index)) {
        return;
    }

    has_next<node>* parent{list};
    while (index--) {
        parent = parent->next;
    }

    node* to_delete{parent->next};
    parent->next = to_delete->next;
    to_delete->next = nullptr;
    delete to_delete;

    list->length--;
}

int linked_list_get(linked_list* list, int index) {
    if (!linked_list_check(list, index)) {
        return -1;
    }

    node* to_get{list->next};
    while (index--) {
        to_get = to_get->next;
    }

    return to_get->value;
}

int main() {
    linked_list* list = linked_list_create();
    do {
        std::string instruction; std::cin >> instruction;
        if (instruction == "exit") {
            break;
        } else if (instruction == "length") {
            std::cout << list->length << std::endl;
        } else if (instruction == "add") {
            int value; std::cin >> value;
            linked_list_add(list, value);
        } else if (instruction == "remove") {
            int index; std::cin >> index;
            linked_list_remove(list, index);
        } else if (instruction == "get") {
            int index; std::cin >> index;
            std::cout << linked_list_get(list, index) << std::endl;
        }
    } while (true);

    linked_list_destroy(list);
}