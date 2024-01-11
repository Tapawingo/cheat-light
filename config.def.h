#ifndef FILESYSTEM
    #include <filesystem>
#endif

std::filesystem::path APPDATA = std::getenv("LOCALAPPDATA");
const std::filesystem::path sourceDirectory = APPDATA / "cheat";
