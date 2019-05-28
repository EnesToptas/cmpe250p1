#include "SurveyClass.h"

void SurveyClass::handleNewRecord(string _name, float _amount) {
    Node* temp= this->members->head;
    if(temp==NULL){
        this->members->pushTail(_name, _amount);
        return;
    }
    bool doesExist=0;
    while(temp!=NULL){
        if((temp->name==_name)){
            doesExist=1;
            break;
        }
        temp=temp->next;
    }
    (doesExist ? this->members->updateNode(_name, _amount) : this->members->pushTail(_name, _amount));

}

float SurveyClass::calculateMinimumExpense() {
    Node* temp= this->members->head;
    float min;
    if(temp!= nullptr)
        min= temp->amount;
    else
        min = 0;
    while(temp!=NULL){
        if(min>temp->amount){
            min=temp->amount;
        }
        temp=temp->next;
    }
    return min;
}

float SurveyClass::calculateMaximumExpense() {
    Node* temp= this->members->head;
    float max;
    if(temp!= nullptr)
        max= temp->amount;
    else
        max = 0;
    while(temp!=NULL){
        if(max<temp->amount){
            max=temp->amount;
        }
        temp=temp->next;
    }
    return max;
}

float SurveyClass::calculateAverageExpense() {
    Node* temp= this->members->head;
    if(temp== nullptr)
        return 0;
    float total=0;
    float average=0;
    while(temp!=NULL){
        total+=temp->amount;
        temp=temp->next;
    }
    average=total/this->members->length;
    average = ((int)(average * 100) / 100.0);
    return average;
}

SurveyClass::SurveyClass() {
    this->members= new LinkedList();
}
SurveyClass::SurveyClass(const SurveyClass &other) {

    this->members = new LinkedList(*(other.members));
}
SurveyClass &SurveyClass::operator=(const SurveyClass &list) {
    delete this->members;
    this->members = new LinkedList(*(list.members));
    return *this;
}
SurveyClass::SurveyClass(SurveyClass &&other) {

    this->members = new LinkedList(move(*other.members));
    other.members = nullptr;

}
SurveyClass &SurveyClass::operator=(SurveyClass &&list) {

    delete this->members;
    (this->members) = new LinkedList(move(*list.members));
    list.members = nullptr;
    return *this;
}

SurveyClass::~SurveyClass() {
    delete this->members;
}