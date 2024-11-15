#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

class Person
{
public:
    string mName;
    string mProducts;
    double mSalary;
    Person()
    {
        mProducts="None";
        mSalary=0;
        mName="";
    }
    Person(string nume, string produs, double salariu)
    {
        mName=nume;
        mProducts=produs;
        mSalary=salariu;
    }
    bool operator==(const Person & a) const
    {
        if(this->mName==a.mName && this->mSalary==a.mSalary)
            return true;
        else
            return false;
    }
    bool operator<(const Person & b) const
    {
        if(b.mName.size()>this->mName.size())
            return true;
        else
            return false;
    }
};


class Product
{
public:
    string mName;
    string mType;
    double mPrice;
    Product()
    {
        mType="None";
        mPrice=0;
        mName="";
    }
    Product(string nume, string tip, double pret)
    {
        mName=nume;
        mType=tip;
        mPrice=pret;
    }
    bool operator==(const Product & a) const
    {
        if(this->mName==a.mName && this->mPrice==a.mPrice)
            return true;
        else
            return false;
    }
    bool operator<(const Product & b) const
    {
        if(b.mName.size()>this->mName.size())
            return true;
        else
            return false;
    }
};


class Store
{
protected:
    string mStoreName;
    string mType;
    vector<Person> mBuyers;
    vector<Product> mProducts;
public:
    Store(string magazin, string tip)
    {
        mStoreName=magazin;
        mType=tip;
    }
    virtual void add(const Person & a) = 0;
    virtual void remove(const Person & a) = 0;
    virtual void addProduct(const Product & a) = 0;
    virtual void removeProduct(const Product & a) = 0;
    virtual Store* operator+() = 0;
    virtual Store* operator-(const Person & a) = 0;
    string getStoreName() const
    {
        return mStoreName;
    }
    string getType() const
    {
        return mType;
    }
    uint16_t getBuyersSize() const
    {
        return mBuyers.size();
    }
    uint16_t getProductsSize() const
    {
        return mProducts.size();
    }
    Person getBuyers(uint16_t i) const
    {
        return mBuyers[i];
    }
    Product getProducts(uint16_t i) const
    {
        return mProducts[i];
    }
};


class MiniMarket : public Store
{
public:
    MiniMarket( string nume_magazin) : Store( nume_magazin, "MiniMarket")
    {
        mBuyers.clear();
        mProducts.clear();
    }
    Store* operator-(const Person &a)
    {
        for(int i=0;i<mBuyers.size();i++)
        {
            if(mBuyers[i] == a)
                mBuyers.erase(mBuyers.begin()+i);
        }
        return this;
    }
    Store* operator+()
    {
        return this;
    }
    void add(const Person &a)
    {
        mBuyers.push_back(a);
    }
    void remove(const Person &a)
    {
        for(int i=0;i<mBuyers.size();i++)
        {
            if(mBuyers[i]==a)
                mBuyers.erase(mBuyers.begin()+i);
        }
    }
    void addProduct(const Product &b)
    {
        mProducts.push_back(b);
    }
    void removeProduct(const Product &b)
    {
        for(int i=0;i<mProducts.size();i++)
        {
            if(mProducts[i]==b)
                mProducts.erase(mProducts.begin()+i);
        }
    }

};

class Market : public Store
{
public:
    Market( string nume_magazin) : Store( nume_magazin, "Market")
    {
        mBuyers.clear();
        mProducts.clear();
    }
    Store* operator-(const Person &a)
    {
        for(int i=0;i<mBuyers.size();i++)
        {
            if(mBuyers[i] == a)
                mBuyers.erase(mBuyers.begin()+i);
        }
        return this;
    }
    Store* operator+()
    {
        return this;
    }
    void add(const Person &a)
    {
        mBuyers.push_back(a);
    }
    void remove(const Person &a)
    {
        for(int i=0;i<mBuyers.size();i++)
        {
            if(mBuyers[i]==a)
                mBuyers.erase(mBuyers.begin()+i);
        }
    }
    void addProduct(const Product &b)
    {
        mProducts.push_back(b);
    }
    void removeProduct(const Product &b)
    {
        for(int i=0;i<mProducts.size();i++)
        {
            if(mProducts[i]==b)
                mProducts.erase(mProducts.begin()+i);
        }
    }
};

class SuperMarket : public Store
{
public:
    SuperMarket( string nume_magazin) : Store( nume_magazin, "SuperMarket")
    {
        mBuyers.clear();
        mProducts.clear();
    }
    Store* operator-(const Person &a)
    {
        for(int i=0;i<mBuyers.size();i++)
        {
            if(mBuyers[i] == a)
                mBuyers.erase(mBuyers.begin()+i);
        }
        return this;
    }
    Store* operator+()
    {
        return this;
    }
    void add(const Person &a)
    {
        mBuyers.push_back(a);
    }
    void remove(const Person &a)
    {
        for(int i=0;i<mBuyers.size();i++)
        {
            if(mBuyers[i]==a)
                mBuyers.erase(mBuyers.begin()+i);
        }
    }
    void addProduct(const Product &b)
    {
        mProducts.push_back(b);
    }
    void removeProduct(const Product &b)
    {
        for(int i=0;i<mProducts.size();i++)
        {
            if(mProducts[i]==b)
                mProducts.erase(mProducts.begin()+i);
        }
    }
};

class Mall : public Store
{
public:
    Mall( string nume_magazin) : Store( nume_magazin, "Mall")
    {
        mBuyers.clear();
        mProducts.clear();
    }
    Store* operator-(const Person &a)
    {
        for(int i=0;i<mBuyers.size();i++)
        {
            if(mBuyers[i] == a)
                mBuyers.erase(mBuyers.begin()+i);
        }
        return this;
    }
    Store* operator+()
    {
        return this;
    }
    void add(const Person &a)
    {
        mBuyers.push_back(a);
    }
    void remove(const Person &a)
    {
        for(int i=0;i<mBuyers.size();i++)
        {
            if(mBuyers[i]==a)
                mBuyers.erase(mBuyers.begin()+i);
        }
    }
    void addProduct(const Product &b)
    {
        mProducts.push_back(b);
    }
    void removeProduct(const Product &b)
    {
        for(int i=0;i<mProducts.size();i++)
        {
            if(mProducts[i]==b)
                mProducts.erase(mProducts.begin()+i);
        }
    }
};

void print()
{
    cout<<"Average Salary for MiniMarkets -nan"<<'\n';
    cout<<"Average Salary for Markets -nan"<<'\n';
    cout<<"Average Salary for SuperMarkets -nan"<<'\n';
    cout<<"Average Salary for Malls -nan"<<'\n';
    cout<<"Products Sale in MiniMarkets 0"<<'\n';
    cout<<"Products Sale in Markets 0"<<'\n';
    cout<<"Products Sale in SuperMarkets 0"<<'\n';
    cout<<"Products Sale in Malls 0"<<'\n';
}

int main()
{
    int j,l;
    string maga[1000];
    string comanda, adaugat , nume, produs, tip, magazin;
    double salariu, cost;
    int nrMM=0, nrM=0, nrSM=0, nrML=0, k=0, pMM=0, pM=0, pSM=0, pML=0;
    double MM=0, mm=0, M=0, m=0, SM=0, sm=0, ML=0, ml=0;
    vector <Store *> magazine;
    vector <Person> clienti;
    vector <Product> produse;
    while(cin >> comanda)
    {
        if(comanda == "add")
        {
            cin >> adaugat;
            if(adaugat == "MiniMarket")
            {
                cin >> nume;
                nrMM++;
                magazine.push_back(new MiniMarket(nume));
            }
            if(adaugat == "Market")
            {
                cin >> nume;
                nrM++;
                magazine.push_back(new Market(nume));
            }
            if(adaugat == "SuperMarket")
            {
                cin >> nume;
                nrSM++;
                magazine.push_back(new SuperMarket(nume));
            }
            if(adaugat == "Mall")
            {
                cin >> nume;
                nrML++;
                magazine.push_back(new Mall(nume));
            }
            if(adaugat == "buyer")
            {
                cin >> nume >> produs >> salariu;
                Person client(nume, produs, salariu);
                clienti.push_back(client);
            }
            if(adaugat == "product")
            {
                cin >> nume >> tip >> cost >> magazin;
                maga[k]=magazin;
                k++;
                Product produs(nume, tip, cost);
                produse.push_back(produs);
            }
        }
        else
        if(comanda=="remove")
        {
            cin>>adaugat>>nume>>magazin;
            for(int i=0;i<clienti.size();i++)
            {
                if(clienti[i].mName==nume)
                {
                    for(int j=0;j<magazine.size();j++)
                    {
                        if(magazin==magazine[j]->getStoreName())
                        {
                            if(magazine[j]->getType()=="MiniMarket" && clienti[i].mSalary<500)
                            {
                                clienti[i].mSalary=0;
                                mm++;
                            }
                            if(magazine[j]->getType()=="Market" && clienti[i].mSalary>=500 && clienti[i].mSalary<=1000)
                            {
                                clienti[i].mSalary=0;
                                m++;
                            }
                            if(magazine[j]->getType()=="SuperMarket" && clienti[i].mSalary>1000 && clienti[i].mSalary<=2000)
                            {
                                clienti[i].mSalary=0;
                                sm++;
                            }
                            if(magazine[j]->getType()=="Mall" && clienti[i].mSalary>=2000)
                            {
                                clienti[i].mSalary=0;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<"Number of MiniMarkets: "<<nrMM<<'\n';
    cout<<"Number of Markets: "<<nrM<<'\n';
    cout<<"Number of SuperMarkets: "<<nrSM<<'\n';
    cout<<"Number of Malls: "<<nrML<<'\n';
    if(clienti.size()==0)
    {
        print();
        return 0;
    }
    else
    {
        for(int i=0;i<clienti.size();i++)
        {
            if(clienti[i].mSalary<500 && clienti[i].mSalary!=0)
            {
                mm++;
                MM=MM+clienti[i].mSalary;
            }
            if(clienti[i].mSalary>=500 && clienti[i].mSalary<1000)
            {
                m++;
                M=M+clienti[i].mSalary;
            }
            if(clienti[i].mSalary>=1000 && clienti[i].mSalary<2000)
            {
                sm++;
                SM=SM+clienti[i].mSalary;
            }
            if(clienti[i].mSalary>=2000)
            {
                ml++;
                ML=ML+clienti[i].mSalary;
            }
        }
        for(int i=0;i<magazine.size();i++)
            for(int j=0;j<clienti.size();j++)
            {
                if(clienti[j].mSalary<500 && magazine[i]->getType()=="MiniMarket")
                    magazine[i]->add(clienti[j]);
                if(clienti[j].mSalary>=500 && clienti[j].mSalary<1000 && magazine[i]->getType()=="Market")
                    magazine[i]->add(clienti[j]);
                if(clienti[j].mSalary>=1000 && clienti[j].mSalary<2000 && magazine[i]->getType()=="SuperMarket")
                    magazine[i]->add(clienti[j]);
                if(clienti[j].mSalary>=2000 && magazine[i]->getType()=="Mall")
                    magazine[i]->add(clienti[j]);
            }
        for(int i=0;i<magazine.size();i++)
            for(int j=0;j<produse.size();j++)
            {
                if(magazine[i]->getStoreName()==maga[j])
                    magazine[i]->addProduct(produse[j]);
            }
        for(int i=0;i<magazine.size();i++)
        {
            if(magazine[i]->getType()=="MiniMarket")
            {
                for(j=0;j<magazine[i]->getBuyersSize();j++)
                {
                    for(l=0;l<magazine[i]->getProductsSize();l++)
                    {
                        if(magazine[i]->getBuyers(j).mProducts==magazine[i]->getProducts(l).mName)
                            pMM++;
                    }
                }
            }
            if(magazine[i]->getType()=="Market")
            {
                for(j=0;j<magazine[i]->getBuyersSize();j++)
                {
                    for(l=0;l<magazine[i]->getProductsSize();l++)
                    {
                        if(magazine[i]->getBuyers(j).mProducts==magazine[i]->getProducts(l).mName)
                            pM++;
                    }
                }
            }
            if(magazine[i]->getType()=="SuperMarket")
            {
                for(j=0;j<magazine[i]->getBuyersSize();j++)
                {
                    for(l=0;l<magazine[i]->getProductsSize();l++)
                    {
                        if(magazine[i]->getBuyers(j).mProducts==magazine[i]->getProducts(l).mName)
                            pSM++;
                    }
                }
            }
            if(magazine[i]->getType()=="Mall")
            {
                for(j=0;j<magazine[i]->getBuyersSize();j++)
                {
                    for(l=0;l<magazine[i]->getProductsSize();l++)
                    {
                        if(magazine[i]->getBuyers(j).mProducts==magazine[i]->getProducts(l).mName)
                            pML++;
                    }
                }
            }

        }


    }
    cout<<"Average Salary for MiniMarkets "<<MM/mm<<'\n';
    cout<<"Average Salary for Markets "<<M/m<<'\n';
    cout<<"Average Salary for SuperMarkets "<<SM/sm<<'\n';
    cout<<"Average Salary for Malls "<<ML/ml<<'\n';
    cout<<"Products Sale in MiniMarkets "<<pMM<<'\n';
    cout<<"Products Sale in Markets "<<pM<<'\n';
    cout<<"Products Sale in SuperMarkets "<<pSM<<'\n';
    cout<<"Products Sale in Malls "<<pML<<'\n';

    return 0;
}