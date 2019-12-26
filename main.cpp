#include <iostream>

class SimpleCircle
{
    int *itsRadius;

public:
    SimpleCircle();
    SimpleCircle(int num);
    SimpleCircle(const SimpleCircle & obj);
    ~SimpleCircle();
    int getItsRadius() const;
    void setItsRadius(int value);
    const SimpleCircle &operator++ ();
    const SimpleCircle operator++ (int);
    SimpleCircle &operator= (const SimpleCircle & tmp);
};

SimpleCircle::SimpleCircle()
{
    itsRadius = new int(5);
}

SimpleCircle::SimpleCircle(int num)
{
    itsRadius = new int(num);
}

SimpleCircle::SimpleCircle(const SimpleCircle &obj)
{
    int val = obj.getItsRadius();
    itsRadius = new int(val);
}

SimpleCircle::~SimpleCircle()
{
    delete itsRadius;
    itsRadius = nullptr;
}

int SimpleCircle::getItsRadius() const
{
    return *itsRadius;
}

void SimpleCircle::setItsRadius(int value)
{
    *itsRadius = value;
}

const SimpleCircle &SimpleCircle::operator++()
{
    ++(*itsRadius);
    return *this;
}

const SimpleCircle SimpleCircle::operator++(int)
{
    SimpleCircle temp(*this);
    ++(*itsRadius);
    return temp;
}

SimpleCircle &SimpleCircle::operator=(const SimpleCircle &tmp)
{
    if (this == &tmp)
        return *this;
    delete itsRadius;
    itsRadius = new int;
    *itsRadius = tmp.getItsRadius();
    return *this;
}

int main()
{
    SimpleCircle circle(9);
    SimpleCircle c2;
    ++circle;
    c2++;
    SimpleCircle c3(circle);

    std::cout << circle.getItsRadius() << std::endl;
    std::cout << c2.getItsRadius() << std::endl;
    std::cout << c3.getItsRadius() << std::endl;

    c2 = ++c3;

    std::cout << c2.getItsRadius() << std::endl;
}
