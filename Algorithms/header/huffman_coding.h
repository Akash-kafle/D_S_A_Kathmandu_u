#pragma once
#include <fstream>
template <typename T>
class Codding
{
private:
    T *data;
    long long length_of_data{};
    std::string path_to_file;

public:
    bool Compress(T *data = nullptr);
    T Decompress();
};

template <typename T>
bool Codding<T>::Compress(T *data = nullptr)
{
    // parsing the data to be looked as bytes and saving
}

template <typename T>
T Codding<T>::Decompress()
{
    
    return
}