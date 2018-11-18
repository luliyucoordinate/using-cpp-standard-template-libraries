#pragma once
// Hash_Function_Objects.h
// Hash function object types for Ex4_07
#ifndef HASH_FUNCTION_OBJECTS_H
#define HASH_FUNCTION_OBJECTS_H

#include <string>                                // For string class
#include <utility>                               // For pair type
#include <tuple>                                 // For tuple type

using Subject = std::string;

// Hash a phone number
class SubjectHash
{
public:
	size_t operator()(const Subject& phone) const
	{
		return std::hash<std::string>()(phone);
	}
};

#endif