#include <iostream>
#include <list>
template<typename T>
class List{
public:
template<typename T1> friend std::ostream &operator<<(std::ostream& , List<T1>& );
    List(T u){
        start = new List<T>::node();
        tmp = start;
        start->data = u;
    }
    List(List<T> &rhs){
        List<T>::node *tmp_rhs = rhs.start;
        start = new List<T>::node();
        start->data = rhs.start->data;
        tmp = start;
        tmp_rhs = tmp_rhs->next;
        while (tmp_rhs!=nullptr)
        {
            auto tmp_this = new List<T>::node();
            tmp->next = tmp_this;
            tmp_this->data = tmp_rhs->data;
            tmp = tmp_this;
            tmp_rhs = tmp_rhs->next;
        }
    }
    List(){
        start = nullptr;
        tmp = start;
    }
    void push_back(const T& t){
        if (start==nullptr)
        {
            start = new List<T>::node();
            start->data = t;
            tmp = start;
            return;
        }
        tmp->next = new List<T>::node();
        tmp = tmp->next;
        tmp->data = t;
    }
    void push_front(const T& t){
        List<T>::node* tm = new List<T>::node();
        tm->next = start;
        tm->data =t;
        start = tm;
    }
    void Print(){
        p(start);
    }
    ~List(){
        delete_ptr(start);
    }
    void insert(const T& val, size_t index){
        List<T>::node* t = start;
        for (int i = 0; ; i++)
        {
            if (i == index-1)
            {
                List<T>::node* tmp1 = new List<T>::node();
                List<T>::node* tmp2 = t->next;
                t->next = tmp1;
                tmp1->next = tmp2;
                tmp1->data = val;
                break;
            }
            t = t->next;
        }
        
    }
    void remove(size_t index){
        List<T>::node* t = start;
        for (int i = 0; ; i++)
        {
            if (i == index-1)
            {
                List<T>::node* tmp2 = (t->next)->next;
                delete[] t->next;
                t->next = tmp2;
                break;
            }
            t = t->next;
        }
        
    }
    void pop_front(){
        List<T>::node* tmp2 = start;
        start = start->next;
        delete[] tmp2;
    }
    void pop_back(){
        List<T>::node* tmp2 = start;
        while (((tmp2->next)->next) != nullptr)
        {
            tmp2 = tmp2->next;
        }
        delete[](tmp2->next);
        tmp = tmp2;
        tmp->next = nullptr;
    }
    void clean(){
        delete_ptr(start);
        start = nullptr;
        tmp = start;
    }
    List<T>& operator=(List<T>& rhs){
        List<T>::node *tmp_rhs = rhs.start;
        delete_ptr(start);
        int c = 0;
        start = new List<T>::node();
        start->data = tmp_rhs->data;
        tmp = start;
        tmp_rhs = tmp_rhs->next;
        while (tmp_rhs!=nullptr)
        {
            auto tmp_this = new List<T>::node();
            tmp->next = tmp_this;
            tmp_this->data = tmp_rhs->data;
            tmp = tmp_this;
            tmp_rhs = tmp_rhs->next;
            tmp_this->next = nullptr; 
        }
        return *this;
    }
   
private:
    struct node{
        T data;
        List<T>::node* next = nullptr;
    };
    void delete_ptr(List<T>::node* h){
        if (start == nullptr)
        {
            return;
        }
        if (h->next== nullptr)
        {
            delete[] h;
            return;
        }
        delete_ptr(h->next);
        delete[] h;
    }
    void p(List<T>::node* tmp1){
        if (start==nullptr)
        {
            return;
        }if ((tmp1->next)!=nullptr)
        {
            std::cout<<(tmp1->data);
            p(tmp1->next);
        }else{
            std::cout<<(tmp1->data);
        }
    }
    List<T>::node* start;
    List<T>::node* tmp;
};
template<typename T>
std::ostream &operator<<(std::ostream& o, List<T>& l){
    auto t = l.start;
    while (t!=nullptr)
    {
        o<<(t->data);
        t=t->next;
    }
    return o;
}
int main(){
    List<int> g;
    g.push_back(2);// add 2 from back
    g.push_back(3);// add 3 from back
    g.push_front(1);// add 1 from front
    g.pop_back();//delete 1 from back
    std::cout<<g<<'\n';
}
