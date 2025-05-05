class Stack
{
private:
    int* m_data;
    int m_capacity;
    int m_topI;

    void resize();

public:
    Stack();
    Stack(const Stack& other);
    Stack& operator=(const Stack& other);
    ~Stack();

    void push(int elem);
    int pop();
    bool isEmpty() const;
    void multiPop(int N);
    void show() const;
};
