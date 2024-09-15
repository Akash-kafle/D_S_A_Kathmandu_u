#pragma once
#include <fstream>

template <typename D>
class Data
{
    D *data;
};

template <typename T>
class Codding
{
private:
    Data<T> UserData;
    long long length_of_data{};
    std::string path_to_file;

public:
    bool Compress(Data<T> *data);
    T Decompress();
};

template <typename T>
bool Codding<T>::Compress(Data<T> *data)
{
    // parsing the data to be looked as bytes and saving
    if (data == nullptr)
    {
        return false;
    }

    uint64_t bytes_data = Convert_to_bytes(data);
}

template <typename T>
T Codding<T>::Decompress()
{
    // De-parsing the data from compressed bytes to actual data

    return T;
}

template <typename T>
uint64_t Convert_to_bytes(Data<T> *data)
{
    return uint64_t{0};
}