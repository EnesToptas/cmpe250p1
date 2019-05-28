#include "LinkedList.h"


LinkedList::LinkedList() {
    this->head=this->tail=NULL;
    length=0;
}


LinkedList::LinkedList(const LinkedList &list) {

    this->length = list.length;
    if(list.head!= nullptr)
        this->head = new Node(list.head->name,list.head->amount);
    else {
        this->head = nullptr;
        this->tail=this->head;
        return;
    }

    Node* listPoint = list.head;
    Node* thisPoint = this->head;

    while (listPoint->next != NULL) {
        thisPoint->next = new Node(listPoint->next->name,listPoint->next->amount);

        listPoint = listPoint->next;
        thisPoint = thisPoint->next;
    }
    this->tail=thisPoint;
}

LinkedList &LinkedList::operator=(const LinkedList &list) {

    if (this != &list){
        delete this->head;
        this->length = list.length;
        if(list.head!= nullptr)
            this->head = new Node(list.head->name,list.head->amount);
        else {
            this->head = nullptr;
            this->tail=this->head;
            return *this;
        }

        Node* listPoint = list.head;
        Node* thisPoint = this->head;

        while (listPoint->next != NULL) {

            thisPoint->next = new Node(listPoint->next->name,listPoint->next->amount);

            listPoint = listPoint->next;
            thisPoint = thisPoint->next;
        }
        this->tail=thisPoint;
    }

    return *this;
}

LinkedList::LinkedList(LinkedList &&list) {

    this->length = move(list.length);
    this->head = move(list.head);
    this->tail = move(list.tail);

    list.length = 0;
    list.head = nullptr;
    list.tail = nullptr;

}

LinkedList &LinkedList::operator=(LinkedList &&list) {

    if(this != &list){
        this->length = move(list.length);
        delete this->head;
        this->head = move(list.head);
        this->tail = move(list.tail);

        list.length = 0;
        list.head = nullptr;
        list.tail = nullptr;
    }

    return *this;
}

void LinkedList::pushTail(string _name, float _amount) {
    if(this->head==NULL){
        this->head=new Node(_name,_amount);
        this->tail=this->head;
        this->length++;
    } else{
        this->tail->next= new Node(_name,_amount);
        this->tail=this->tail->next;
        this->length++;
    }
}

void LinkedList::updateNode(string _name, float _amount) {
    Node* temp= this->head;
    while(!(temp->name==_name)){
        temp=temp->next;
    }
    temp->amount=_amount;
}


LinkedList::~LinkedList() {
    delete this->head;
    this->length = 0;
}