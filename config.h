
// Get local appdata directory
std::filesystem::path APPDATA = std::getenv("LOCALAPPDATA");

// Set cheat directory
std::filesystem::path sourceDirectory = APPDATA / "cheat";
