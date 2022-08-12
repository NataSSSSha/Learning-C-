#include <iostream>

class Product
{
public:
    virtual void Print() = 0;
};

class Factory
{
public:
    int countOfProduct = 0;
    virtual Product* CreateProduct() = 0;
};

class Miner : public Product
{
public:
    virtual void Print() override
    {
        std::cout << "I'm miner" << std::endl;
    }

public:
    Product* GetFossil(Factory* factory)
    {
        return factory->CreateProduct();
    }
};

class Coal : public Product
{
    virtual void Print() override
    {
        std::cout << "You got coal" << std::endl;
    }
};

class Gold : public Product
{
    virtual void Print() override
    {
        std::cout << "You got gold" << std::endl;
    }
};

class Kazarm : public Factory
{
public:
    virtual Product* CreateProduct() override
    {
        return new Miner();
    }
};

class Mine1 :public Factory
{
public:
    Mine1(int count)
    {
        this->countOfProduct = count;
    }

    virtual Product* CreateProduct() override
    {
        if (countOfProduct > 0)
        {
            countOfProduct--;
            return new Coal();
        }
    }
};

class Mine2 : public Factory
{
public:
    Mine2(int count)
    {
        this->countOfProduct = count;
    }
public:
    virtual Product* CreateProduct() override
    {
        if (countOfProduct > 0)
        {
            countOfProduct--;
            return new Gold();
        }
    }
};


int main()
{
    Kazarm kazarm;
    Product* miner = kazarm.CreateProduct();
    miner->Print();

    Mine1 mine1(5);
    Mine2 mine2(2);

    Product* coal = static_cast<Miner*>(miner)->GetFossil(&mine1);
    coal->Print();

    Product* gold = static_cast<Miner*>(miner)->GetFossil(&mine2);
    gold->Print();
}
