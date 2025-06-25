//
// Created by eloide-novela on 24-06-2025.
//

#include "hash.hpp"
#include "../../lib/SHA256.hpp"

namespace util 
{
namespace hash 
{
    std::string encode(const std::string &src)
    {
        sha256 sha;
        sha.update(src);
        auto digest = sha.digest();
        return sha256::toString(digest);
    }
}
}