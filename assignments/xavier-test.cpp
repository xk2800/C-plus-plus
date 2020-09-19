#include <fstream>
#include <iostream>

struct id_generator
{
    id_generator()
    : _id (0)
    {
        std::ifstream ifs("previous_id.txt");
        ifs >> _id;
    }

    ~id_generator()
    {
        std::ofstream ofs("previous_id.txt", std::ios_base::out | std::ios_base::trunc);
        ofs << _id;
    }

    int operator()() { return _id++; }

    int _id;
};

int main()
{
    id_generator idgen;

    std::cout << "next id is: " << idgen() << std::endl;
    std::cout << "next id is: " << idgen() << std::endl;

    return 0;
}