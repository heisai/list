
//#include<vector>
#include<iostream>
//#include<algorithm>

template <typename T>
struct list_linknode
{
    struct list_linknode *next;
    struct list_linknode *prev;
    T data;
};

template <typename T>
struct list_iterator{
    using link_type = list_linknode<T>* ;
    list_iterator(link_type x):node(x){}
    list_iterator(){}
    list_iterator(const list_iterator& x):node(x.node){}
    link_type node;

    list_iterator& operator++() {
        node = (link_type)((*node).next);
        return *this;
    }
    list_iterator operator++(int) {
        list_iterator tmp = *this;
        ++*this;
        return tmp;
    }
    list_iterator& operator--() {
        node = (link_type)((*node).prev);
        return *this;
    }
    list_iterator operator--(int) {
        list_iterator tmp = *this;
        --*this;
        return tmp;
      }

    bool operator==(const list_iterator& x) const { return node == x.node; }
    bool operator!=(const list_iterator& x) const { return node != x.node; }
    T &operator*() const { return (*node).data; }

};
template <typename T>
class List
{
public:
    using iterator = list_iterator<T> ;
    using linknode = list_linknode<T>*;
    using reference = T&;
  public:
    List()
    {
        Node = new list_linknode<T>;
        Node->prev = Node;
        Node->next = Node;
    }

    iterator begin(){ return Node->next;}
    iterator end(){ return Node;}
    void push_back(T value)
    {
        insert(end(),value);
    }
    void push_front(T value)
    {
        insert(begin(),value);
    }
    void pop_back()
    {
        erase(--end());
    }
    void pop_front()
    {
        erase(begin());
    }

    iterator erase(iterator position)
    {
       linknode next_node =  position.node->next;
       linknode prev_node =  position.node->prev;
       //prev_node->next = position.node->next; 等价  prev_node->next = next_node;
       prev_node->next = next_node;
       next_node->prev = prev_node;
       destory(position.node);
       return prev_node;

    }
    void clear()
    {
        erase(this->begin(),this->end());
    }
    iterator erase(iterator first,iterator last)
    {
        for(;first!=last;)
        {
            erase(first++);
        }
        return last;
    }
    void destory(linknode position)
    {
        position->data = T();
        delete position;
    }
    iterator insert(iterator position, const T& value)
    {
        linknode tmp = new list_linknode<T>;
        tmp->data = value;
        tmp->next = position.node;
        tmp->prev = position.node->prev;
        position.node->prev->next = tmp;
        position.node->prev = tmp;
        return tmp;
    }
    void insert(iterator position, iterator first, iterator last)
    {
        for(;first!=last;++first)   insert(position,*first);
    }
    void insert(iterator position, unsigned int  n, const T& x)
    {
        for(;n>0;n--)   insert(position,x);
    }
    reference front(){ return *begin();}
    reference back(){ return  *(--end());}
    bool empty(){ return  Node->prev == Node->next;}
    int length;
    linknode Node;
};
using namespace std;
int main(int argc, char *argv[])
{


    List<int> list1;
    list1.push_back(0);
    list1.push_back(0);
    list1.push_back(0);

    List<int> list;
    list.push_back(11);
    list.push_back(12);
    list.push_back(13);
    list.insert(list.begin(),3,6);
    list.insert(++list.begin(),list1.begin(),list1.end());
    list.push_front(999);

    list.pop_back();
    list.pop_front();

    for(auto iter = list.begin();iter!=list.end();iter++)
    {
        cout<<(*iter)<<endl;
    }
    list.clear();

}
