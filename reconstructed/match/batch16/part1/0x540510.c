// SoundPakManager_FindExtensionEntry @ 0x540510 (153 bytes)
// Finds the pak entry whose lowercase extension matches.

extern "C" char *strcpy(char *dest, const char *source);
extern "C" int strcmp(const char *a, const char *b);
#pragma intrinsic(strcpy)
#pragma intrinsic(strcmp)

namespace CRT {
    char *Strlwr(char *text);
}

class Node {
public:
    char pad[0x40];
    char name[0x10];
    Node *next;
};

class SoundPakManager {
public:
    char pad[0x628];
    Node *head;

    int FindExtensionEntry(char *extension);
};

int SoundPakManager::FindExtensionEntry(char *extension)
{
    char buffer[16];
    Node *node;

    strcpy(buffer, extension);
    CRT::Strlwr(buffer);
    node = this->head;
    while (node != 0) {
        if (strcmp(node->name, buffer) == 0)
            return (int)node;
        node = node->next;
    }
    return 0;
}
