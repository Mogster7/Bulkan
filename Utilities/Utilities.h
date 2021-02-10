//------------------------------------------------------------------------------
//
// File Name:	Utilities.h
// Author(s):	Jonathan Bourim (j.bourim)
// Date:        6/6/2020 
//
//------------------------------------------------------------------------------
#pragma once

constexpr unsigned MAX_OBJECTS = 2;

namespace utils
{
    float Random(float min = 0.0f, float max = 1.0f);
    std::vector<char> ReadFile(const std::string& filename);
    void CheckVkResult(vk::Result result, const std::string& error);
    void AssertVkBase(VkResult result);
}






