//Single Responsibilty Principle
//A class must be able to do one thing or responsibility.
#include <iostream>
#include <vector>
class Product
{
    public:
        float price;
        std::string name;

    public:
        Product(float price, std::string name)
        {
            this->name = name;
            this->price = price;
        }
};

class ShoppingCart
{
    private:
        std::vector<Product*> products;
    public:
        void addProducts(Product* p)
        {
            products.push_back(p);
        }

        const std::vector<Product*> getProduct()
        {
            return products;
        }

        double calTotalPrice()
        {
            double total=0;
            for(auto &p:products)
            {
                total = total + p->price;
            }
            return total;
        }
};

class PrintInvoice
{
    private:
        ShoppingCart* sc;
    public:
        PrintInvoice(ShoppingCart* s)
        {
            sc = s;
        }

        void printInvoice()
        {
            for(auto& s:sc->getProduct())
            {
                std::cout << "Price:"<< s->price;
            }
        }
};

class StoreDB
{
    private:
        ShoppingCart* sc;
    public:
        StoreDB(ShoppingCart* s)
        {
            sc = s;
        }

        void storeDb()
        {
            for(auto&s3:sc->getProduct())
            {
                std::cout << "Store in DB...";
            }
        }
};


int main()
{
    ShoppingCart* sc = new ShoppingCart();
    sc->addProducts(new Product(10,"XYZ"));
    sc->addProducts(new Product(20,"PPPYZ"));
    std::cout << "Total Price:" << sc->calTotalPrice();

    PrintInvoice* p = new PrintInvoice(sc);
    p->printInvoice();

    StoreDB* db = new StoreDB(sc);
    db->storeDb();

    delete sc;
    sc =nullptr;
    delete p;
    p = nullptr;
    delete db;
    db = nullptr;
    return 0;


}