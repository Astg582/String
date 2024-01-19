#pragma once

class Str{
private:
	size_t m_size;
	size_t m_cap;
	char* m_ptr;
public:
	Str();
	Str(size_t size, char val);
	size_t size();
	size_t cap();
	void print();
	void realloc();
	void shrink_to_fit();
	void push_back(char val);
	bool empty();
	void clear();
	~Str();
};


