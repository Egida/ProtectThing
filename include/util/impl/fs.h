#ifndef FS_HPP
#define FS_HPP

#include <filesystem>
#include <string>

#include "util/util.h"

class FS final : Util {
public:
    FS() : Util("FS", "Filesystem-related helper utilties") {}

    static std::string read_to_string(const std::filesystem::path& file_path);
};

#endif // FS_HPP
