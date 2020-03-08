#include <linked_list.h>
namespace lab5 {
    linked_list::linked_list() {
        head= nullptr;
        tail= nullptr;

    }

    linked_list::linked_list(std::string &data) {
        head= nullptr;
        tail= nullptr;
        append(data);
    }

    linked_list::linked_list(const linked_list &original) {
        node* current_node= original.head;
        for ( int i=0; i<original.listSize(); i++){
            append(current_node->data);
            current_node=current_node->next;

        }

    }

    linked_list::~linked_list() {
        head=nullptr;
        tail=nullptr;

    }

    linked_list &lab5::linked_list::operator=(const linked_list &RHS) {
        //return <#initializer#>;
        if (this == &RHS)
            return *this;
        else {
            node *current_node = RHS.head;
            for (int i = 0; i < RHS.listSize(); i++) {
                append(current_node->data);
                current_node = current_node->next;
            }
            return *this;

        }
    }


    bool linked_list::isEmpty() const {
        return head == nullptr? true: false;

    }

    unsigned linked_list::listSize() const {
        node* count_node= head;
        int count=0;
        while (count_node != nullptr){
            count++;
            count_node=count_node->next;
        }
        return count;

    }

    void linked_list::insert(const std::string input, unsigned int location) {
        node* previous_node;
        node* current_node = head;
        node* temp_node = new node(input);
        if ((location == 0 && head == nullptr) || location == listSize())
            append(input);


        else if(location == 0 && head != nullptr){
            temp_node -> next = current_node ;
            head = temp_node ;

        }

        else if (location > listSize())
            throw std::out_of_range("Out of position.");

        else if(location == listSize()){
            append(input);
        }
        else{
            for(int i=0; i<location; i++){
                previous_node = current_node;
                current_node = current_node->next;
            }
            previous_node->next = temp_node;
            temp_node->next = current_node;
        }
    }

    void linked_list::append(const std::string input) {
        node *input_node = new node(input);
        input_node->next = nullptr;
        if (head == nullptr){
            head = input_node;
            tail = input_node;

        }
        else {
            tail->next = input_node;
            tail = input_node;
        }
    }

    void linked_list::remove(unsigned location) {
        int position = 0;
        node* current_node = nullptr;
        node* previous_node = nullptr;

        if(location >= listSize())
            throw std::out_of_range("Out of position.");
        else if(head == nullptr)
            throw std::out_of_range("Linked list is empty.");
        else if(head != nullptr && location == 0)
            head = head -> next;
        else if(location == listSize()-1 ){
            current_node = head;
            for(int i = 0; i< listSize()-1; i++){
                previous_node = current_node;
                current_node = current_node -> next;
            }
            tail = previous_node;
            tail -> next = nullptr;
        }
        else{
            current_node = head;
            do{
                if (position == location){
                    current_node = current_node -> next;
                    (previous_node -> next) -> next = nullptr;
                    previous_node -> next = current_node;
                }
                else{
                    previous_node = current_node;
                    current_node = current_node -> next;
                }
                position ++;
            }
            while(position <= location);
        }
    }

    std::ostream& operator<<(std::ostream &stream, linked_list &RHS) {
        node* current_node = RHS.head;
        while (current_node != nullptr){
            stream << current_node -> data;
            stream << " -> ";
            current_node = current_node -> next;
        }
        stream << "NULL";
        return stream;
    }

    std::istream& operator>>(std::istream &stream, linked_list &RHS) {
        std::string temp;
        stream >> temp;
        RHS.append(temp);
        return stream;
    }

    void linked_list::sort() {
        std::string node1;
        std::string node2;
        node* current_node;
        for (int i= listSize() -1 ; i > 0 ; i--){
            current_node = head;
            for(int j = 0; j < i; j++) {
                node1 = current_node->data;
                node2 = (current_node->next)->data;
                if ((islower(node1.at(0)) && islower(node2.at(0))) || (isupper(node1.at(0)) && isupper(node2.at(0)))) {
                    if ((node1.compare(node2)) > 0) {
                        current_node->data = node2;
                        (current_node->next)->data = node1;
                    }
                } else if (isupper(node1.at(0)) && islower(node2.at(0))) {
                    current_node->data = node2;
                    (current_node->next)->data = node1;
                }
                current_node = current_node -> next;
            }
        }
    }

    std::string linked_list::get_value_at(unsigned location) const {
        std::string temp;
        node* current_node = head;
        for(int i=0; i<location; i++){
            current_node = current_node->next;
        }
        temp = current_node->data;
        return std::string(temp);
    }
}