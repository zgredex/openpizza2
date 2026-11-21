/* MessageList_Construct: allocates the message buffer (0x54b390). */
struct MessageList {
    void *buffer;
    int count;
    int capacity;
    MessageList *Construct();
};

extern "C" void *operator_new(unsigned int size);

MessageList *MessageList::Construct()
{
    buffer = operator_new(0xf0);
    capacity = 0x3c;
    count = 0;
    return this;
}
