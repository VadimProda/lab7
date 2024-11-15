#ifndef CSTRING_VECTOR_H
#define CSTRING_VECTOR_H

#include <cassert>

#include <vector>
#include <iostream>
#include <cstring>

#include "cstring_utils.h"


static char const * DELIM { ", " };

/* динамический массив С-строк */
class cstring_vector {

    /* массив С-строк */
    char ** data; 
    /* логический размер (заполненность) */
    size_t  size;
    /* физический размер (ёмкость) */
    size_t capacity;

    // Mинимальная ёмкость
    const static int MIN_CAPACITY = 5;

    // Множитель для увеличения ёмкости при её нехватке
    const static int CAPACITY_FACTOR = 2;
    
public:
    
    cstring_vector() : size(0), capacity(MIN_CAPACITY)
    {
        data = new char* [capacity];
    }
    
    
    cstring_vector(char ** cstr_array, size_t size)
    {
        init_from_cstr_array(cstr_array, size);
    }
    
    cstring_vector(char const** cstr_array, size_t size)
    {
        init_from_cstr_array(const_cast<char**>(cstr_array), size);
    }
    
    cstring_vector(std::vector<std::string> str_vector)
    {
        capacity = size > MIN_CAPACITY ? size : MIN_CAPACITY;
        data = new char* [capacity];
        for (size_t i = 0; i < size; ++i) 
        {
            data[i] = new char[str_vector[i].length() + 1];
            strcpy(data[i], str_vector[i].c_str());
        }
    }
    // Деконструктор
    ~cstring_vector() {
        for (size_t i = 0; i < size; ++i) {
            delete[] data[i]; 
        }
        delete[] data; 
    }

    // Конструктор копий
    cstring_vector(const cstring_vector& other) 
    {
        init_from_cstr_array(other.data, other.size);
    }

    // Move-конструктор
    cstring_vector(cstring_vector&& other): data(other.data), size(other.size), capacity(other.capacity) 
    {
        other.data = nullptr; 
        other.size = 0;
        other.capacity = 0;
    }

    // Операция копирующего присваивания (copy-and-swap)
    cstring_vector& operator=(cstring_vector other) 
    {
        swap(other); 
        return *this;
    }

    // Функция swap
    void swap(cstring_vector& other)
    {
        std::swap(data, other.data);
        std::swap(size, other.size);
        std::swap(capacity, other.capacity);
    }

    // Операция обращения по индексу
    char*& operator[](size_t index) 
    {
        assert(index < size); 
        return data[index]; 
    }

    // Константная версия операции обращения по индексу
    const char* const& operator[](size_t index) const 
    {
        assert(index < size);
        return data[index]; 
    }
   
    void push_back(const char* cstr) 
    {
        if (size >= capacity) 
        {
            reallocate(); 
        }
        data[size] = new char[strlen(cstr) + 1];
        strcpy(data[size], cstr); 
        ++size; 
    }

    // Метод для перераспределения памяти
    void reallocate() 
    {
        size_t new_capacity = capacity * CAPACITY_FACTOR;
        char** new_data = new char* [new_capacity]; 

        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data; 
        capacity = new_capacity;
    }

    /* размер массива */
    size_t get_size() const
    {
        return size;
    }
    
    /* печать содержимого массива */
    void print() const
    {
        assert(data);
        //assert(size <= capacity);
        std::cout << "{";
		if (size)
		{
			for (size_t i = 0; i < size - 1; ++i)
			{
				print_cstring(data[i]);
				std::cout << DELIM;
			}        
            print_cstring(data[size - 1]);
		}
        std::cout << "}";
    }
    
    /* печать содержимого массива */
    void println() const
    {
        print();
        std::cout << std::endl;
    }



private:

    // TODO MIN_CAPACITY
    // TODO CAPACITY_FACTOR

    /* инициализация текущего массива
       копией массива строк cstr_array из size элементов */
    void init_from_cstr_array(char** cstr_array, size_t size)
    {
        capacity = size * CAPACITY_FACTOR; 
        this->size = size; 
        data = new char* [capacity];
        for (size_t i = 0; i < size; ++i) 
        {
            data[i] = new char[strlen(cstr_array[i]) + 1];
            strcpy(data[i], cstr_array[i]);
        }
    }

};


/* CSTRING_VECTOR_H */
#endif
