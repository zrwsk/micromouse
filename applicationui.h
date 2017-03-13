#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include <cstdio>

using namespace std;
using namespace boost::filesystem;

class ApplicationUI {
    public:
        void clearScreen();
        string showFileSelectionScreen(string dir);
};

