#include "String.h"

#include <cstring>


String::String()
{
    data.clear();
}

String::String(const char* str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        data.push_back(str[i]);

        i++;
    }  
}

void String::Print()
{
    for (size_t i = 0; i < data.size(); ++i)
    {
        std::cout << data[i];
    }
}

char* String::ToChar()
{
    int size = data.size();

    char* thisChain = new char[size + 1];

    for (size_t i = 0; i < data.size(); ++i)
    {
        thisChain[i] = data[i];
    }

    thisChain[size] = '\0';

    return thisChain;
}

String String::operator + (String other)
{
    String newString;

    for (size_t i = 0; i < this->data.size(); ++i)
    {
        newString.data.push_back(this->data[i]);
    }

    newString.data.push_back(' ');

    for (size_t i = 0; i < other.data.size(); ++i) 
    {
        newString.data.push_back(other.data[i]);
    }

    return newString;
}

String String::operator+(char* other)
{
    String thisString;
    String newString(other);

    for (size_t i = 0; i < this->data.size(); ++i)
    {
        thisString.data.push_back(this->data[i]);
    }

    return thisString + newString;
}

void String::operator+=(String other)
{
    data.push_back(' ');

    for (size_t i = 0; i < other.data.size(); ++i)
    {
        data.push_back(other.data[i]);
    }
}

void String::operator+=(char* other)
{
    String newString(other);

    data.push_back(' ');

    for (size_t i = 0; i < newString.data.size(); ++i)
    {
        data.push_back(newString.data[i]);
    }
}

int String::operator < (String other)
{
    char* thisChain = ToChar();
    char* otherChain = other.ToChar();
    
    while (*thisChain && *otherChain && *thisChain == *otherChain) 
    {
        ++thisChain;
        ++otherChain;
    }

    if (*thisChain < *otherChain) 
    {
        return 1;
    }
    else if (*thisChain > *otherChain) 
    {
        return -1;
    }
    else 
    {
        return 0;
    }
}

int String::operator>(String other)
{
    char* thisChain = ToChar();
    char* otherChain = other.ToChar();

    while (*thisChain && *otherChain && *thisChain == *otherChain)
    {
        ++thisChain;
        ++otherChain;
    }

    if (*thisChain < *otherChain)
    {
        return -1;
    }
    else if (*thisChain > *otherChain)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void String::operator*(unsigned int qnty)
{
    if (qnty == 0)
    {
        data.clear();
    }
    else
    {
        String temp{};

        for (int i = 0; i < qnty; i++)
        {
            temp += this->ToChar();
        }

        this->data = temp.data;
    }
}
