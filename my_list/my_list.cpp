#include <iostream>
#include <vector>
using namespace std;

template <class T>
class List
{
private:
    struct Node
    {
        Node* prev_p;
        Node* next_p;
        T element;
        Node(const T& elem) : element(elem)
        {
            next_p = prev_p = nullptr;
        }
    };
    Node* start_;
    Node* end_;
    int size_;
public:
    List()
    {
        end_ = start_ = nullptr;
        size_ = 0;
    }

    List(const T& elem)
    {
        start_ = end_ = new Node(elem);
        size_ = 1;
    }

    List(const std::vector<T>& vec)
    {
        for (int i = 0; i < vec.size(); ++i)
        {
            push_back(vec[i]);
        }
    }

    bool isEmpty()
    {
        if (size_ == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int size() const
    {
        return size_;
    }

    void push_back(const T& elem)
    {
        if (start_ == nullptr)
        {
            start_ = end_ = new Node(elem);
            size_ = 1;
            return;
        }
        Node* current = new Node(elem);
        end_->next_p = current;
        current->prev_p = end_;
        end_ = current;
        ++size_;
    }

    void push_start(const T& elem)
    {
        if (start_ == nullptr)
        {
            start_ = end_ = new Node(elem);
            size_ = 1;
            return;
        }
        Node* current = new Node(elem);
        start_->prev_p = current;
        current->next_p = start_;
        start_ = current;
        ++size_;
    }

    T pop_back()
    {
        if (size_ <= 1)
        {
            if (size_ == 0)
            {
                return T();
            }
            T current = start_->element;
            delete start_;
            start_ = end_ = nullptr;
            size_ = 0;
            return current;
        }
        T current = end_->element;
        Node* before_end = end_->prev_p;
        before_end->next_p = nullptr;
        delete end_;
        end_ = before_end;
        --size_;
        return current;
    }

    T pop_start()
    {
        if (size_ <= 1)
        {
            if (size_ == 0)
            {
                return T();
            }
            T current = start_->element;
            delete start_;
            start_ = end_ = nullptr;
            size_ = 0;
            return current;
        }
        T current = start_->element;
        Node* after_start = start_->next_p;
        after_start->prev_p = nullptr;
        delete start_;
        start_ = after_start;
        --size_;
        return current;
    }

    ~List()
    {
        while (start_ != nullptr)
        {
            Node* next = start_->next_p;
            delete start_;
            start_ = next;
        }
        start_ = end_ = nullptr;
        size_ = 0;
    }
};

int main()
{
    return 0;
}