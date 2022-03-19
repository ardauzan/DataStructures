#pragma once
template <typename T> class LinkedList {
    private:
        struct node {
            private:
                T payload;
                node* next;
            public:
                node();
                node(T);
                node(T, node*);
                node(const node&);
                virtual ~node();
                T getPayload() const;
                void setPayload(T);
                node* getNext() const;
                void setNext(node*);
        };
        int size;
        node* const head;
    public:
        LinkedList();
        LinkedList(int);
        LinkedList(int, T[]);
        LinkedList(const LinkedList&);
        virtual ~LinkedList();
        int getSize() const;
        virtual void setSize(int);
        node* getHead() const;
        virtual void addNode(T);
        virtual void deleteNode(int);
};