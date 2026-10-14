

#include "EditorEngine.h"
#include "FileRedactor.h"

int main(int argc, char* argv[])
{
    if (argc < 2) return -1;

    auto editor = EditorEngine(argv[1]);

    editor.initialize();

    return 0;
}


