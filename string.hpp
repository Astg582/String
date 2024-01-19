#include "string.h"


Str::Str(){
		m_size = 0;
		m_cap = 0;
		m_ptr = nullptr;
}

Str::Str(size_t size, char val){
	
		if(m_ptr){
			m_ptr = new char[size];
			m_size = size;
			m_cap = size;
	
			for(size_t i = 0; i < m_size; ++i){
				m_ptr[i] = val;
			}
		} 

}

size_t Str::size(){
        return m_size;
}

size_t Str::cap(){
		return m_cap;
}

void Str::print(){
		if(m_ptr != nullptr){
            for(size_t i = 0; i < m_size; ++i){
    			std::cout << this->m_ptr[i];
            }
		}
}

void Str::realloc(){
		if(m_cap == 0){
			m_cap = 8;
			m_ptr = new char[m_cap];
			return;
		}
		m_cap *= 2;
		char* tmp = new char[m_cap];
		for(size_t i = 0; i < m_size; ++i){
			tmp[i] = m_ptr[i];
		}
		for(size_t i = m_size; i < m_cap; ++i){
			tmp[i] = 0;
		}
		delete[] m_ptr; 
		m_ptr = nullptr;
		m_ptr = tmp;
		tmp = nullptr;
}

void Str::shrink_to_fit(){
		if(m_size < m_cap){
			char* tmp = new char[m_size];
			for(size_t i = 0; i < m_size; ++i){
				tmp[i] = m_ptr[i];
			}
			delete[] m_ptr;
			m_cap = m_size;
			m_ptr = tmp;
			tmp = nullptr;
		}
	}
	
void Str::push_back(char val){
		if(m_ptr == nullptr || m_size == m_cap){
				realloc();
		}
			m_ptr[m_size] = val;
			++m_size;
	}
	
bool Str::empty(){
		return !m_ptr;
}
	
void Str::clear(){
		if(m_ptr){
			delete[] m_ptr;
			m_ptr = nullptr;
			m_size = 0;
			m_cap = 0;
		}
}
	
Str::~Str(){
		clear();
}



