#include <iostream>
#include <string>

template <typename T>
class SomeContainer
{
public:
    SomeContainer(const std::size_t size);
    
    void fill_data(T filler);

    void printData();
private:
    T* data_;
    int m_size;
};

template<typename T>
SomeContainer::SomeContainer(const std::size_t size)
: m_size(size)
{
    data_ = new T[m_size];
}

template<typename T>
void SomeContainer<T>::fill_data(T filler)
{
    for(std::size_t i = 0; i < m_size; i++)
    {
        data_[i] = filler;
    }
}

template<typename T>
void SomeContainer<T>::printData()
{
    for(std::size_t i = 0; i < m_size; i++)
    {
        std::cout << data_[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    SomeContainer<float> float_container{5};
    float_container.fill_data(5.0f);
    float_container.printData();
    return 0;

}