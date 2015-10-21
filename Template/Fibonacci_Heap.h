#include <cstdio>
#include <unordered_map> // should compile with "-std=c++0x or -std=c++11"
#include <iostream>
#include <cassert>

template <typename T>
class Fibonacci_Heap
{
private:
    class Fibonacci_Heap_Node
    {
    public:
        T key;
        int degree;
        Fibonacci_Heap_Node *father;
        Fibonacci_Heap_Node *son;
        Fibonacci_Heap_Node *lbrother;
        Fibonacci_Heap_Node *rbrother;

        Fibonacci_Heap_Node()
        {
            degree = 0;
            father=son=lbrother=rbrother=NULL;
        }
    };

    Fibonacci_Heap_Node *root;
    Fibonacci_Heap_Node *min;

    Fibonacci_Heap_Node* consolidate(Fibonacci_Heap_Node *x,Fibonacci_Heap_Node *y)
    {
        if (y->key < x->key)
        {
            Fibonacci_Heap_Node *t;
            t = x;
            x = y;
            y = t;
        }
        if (y->lbrother) y->lbrother->rbrother = y->rbrother;
        if (y->rbrother) y->rbrother->lbrother = y->lbrother;
        y->father = x;
        y->lbrother = NULL;
        y->rbrother = x->son;
        if (x->son)
        {
            x->son->lbrother = y;
        }
        x->son = y;
        return x;
    }

    // consolidate two tree with same degree & find the min
    void maintain()
    {
        std::unordered_map<int,Fibonacci_Heap_Node* > h;
        h.clear();

        Fibonacci_Heap_Node *p;
        p = root->son;

        while (p)
        {
            Fibonacci_Heap_Node *temp;
            temp = p->rbrother;

            if (min==NULL || p->key < min->key)
            {
                min = p;
            }
            while (h.find(p->degree)!=h.end())
            {
                p = consolidate(h[p->degree],p);
                h.erase(p->degree);
                p->degree++;
            }
            h.insert(std::make_pair(p->degree,p));
            p = temp;
        }
    }

public:
    Fibonacci_Heap()
    {
        root = new Fibonacci_Heap_Node();
        min=NULL;
    }

    void insert(T x)
    {
        Fibonacci_Heap_Node *a;
        a = new Fibonacci_Heap_Node();
        a->key = x;
        a->father = root;
        a->rbrother = root->son;
        if (root->son)
        {
            root->son->lbrother = a;
        }
        root->son = a;
        if (min==NULL || a->key < min->key)
        {
            min = a;
        }
    }

    T find_min()
    {
        assert(min!=NULL);
        return min->key;
    }

    void del_min()
    {
        assert(min!=NULL);
        if (min->lbrother) min->lbrother->rbrother = min->rbrother;
        if (min->rbrother) min->rbrother->lbrother = min->lbrother;
        if (root->son == min) root->son = min->rbrother;
        // -------
        if (min->son)
        {
            Fibonacci_Heap_Node *p,*temp;
            p = min->son;
            p->father = root;
            temp = root->son;
            root->son = p;
            while (p->rbrother)
            {
                p = p->rbrother;
                p->father = root;
            }
            p->rbrother = temp;
            temp->lbrother = p;
        }
        delete min;
        min = NULL;
        maintain();
    }
};
