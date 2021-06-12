#pragma once

#ifndef _STRING_H
#define _STRING_H

class String
{
private:
	char* buffer;
	int length;
	int size;

	void DeepCopy(const char* src, int size = 0);

public:
	// 생성자
	String();
	String(int size);
	String(char c);
	String(String&);
	String(const char* str);
	String(char* str);
	String(const char* init, int m);

	~String();


	// 연산자 오버로딩
	String& operator=(const String&);
	String& operator=(const char*);
	String operator+(const char*);
	bool operator==(String t);
	bool operator!();

	// 형변환 연산자 오버로딩
	operator char* ();


	bool IsEmpty();
	int Length();

	String Concat(String t);
	String Substr(int i, int j);
	int Find(String pat);
};



#endif