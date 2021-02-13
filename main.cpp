#include <iostream>
#include <string>

class DataViewer
{
    std::string data;
public:
    void Display();
protected:
    virtual std::string ReadData() = 0;
    virtual bool isValid(const std::string& d) = 0;
    virtual void ShowData(const std::string& d) = 0;
    virtual void hook_0() {}
    virtual void hook_1() {}
    virtual void hook_2() {}

    virtual ~DataViewer() {}
};

void DataViewer::Display()
{
    hook_0();

    data = ReadData();   // step 1

    hook_1();

    if (isValid(data))   // step 2
        ShowData(data);  // sted 3

    hook_2();
}

class SimpleViewer : public DataViewer
{

    std::string ReadData() override {
        std::cout << "Enter string: ";
        std::string user_str;
        std::cin >> user_str;
        return user_str;
    }

    bool isValid(const std::string &d) override {
        if (!d.empty())
            return true;
        return false;
    }

    void ShowData(const std::string &d) override {
        std::cout << "\nPrecessed string: "
                  << d << "\n\n\n";
    }
};


int main()
{

    SimpleViewer viever;
    viever.Display();

    return 0;
}















