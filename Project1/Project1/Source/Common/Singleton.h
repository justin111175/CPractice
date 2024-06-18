#pragma once
#include <iostream>

template <typename T>
class Singleton
{
public:
    static T& GetInstance()
    {
        Create();
        return *sInstance;
    }

    static void Create()
    {
        if (sInstance == nullptr)
        {
            sInstance = new T();
        }
    }

    static void Destroy()
    {
        if (sInstance != nullptr)
        {
            delete sInstance;
            sInstance = nullptr;
        }
    }

protected:
    Singleton() = default;
    virtual ~Singleton() = default;

private:
    static T* sInstance;
};


// Initialize the static member
template <typename T>
T* Singleton<T>::sInstance = nullptr;