#include <filesystem>
#include <fstream>

#include <sharg/detail/safe_filesystem_entry.hpp>

int main()
{
    std::filesystem::path my_file = std::filesystem::temp_directory_path() / "dummy.txt";

    std::ifstream file{my_file};  // Create the file.
    sharg::detail::safe_filesystem_entry file_guard{my_file};  // Safe cleanup in case of errors.

    // Do something on the file, that can possibly throw.
    // If an unhandled exception is thrown, the file guard destructor safely removes the file from the filesystem.

    file_guard.remove();  // Explicitly remove the file.
}
