/* StatsPeriodReport_StreamConstruct: constructor that binds the vtable and
   loads the report when a stream is supplied (0x401000). */
extern int DAT_0055c2e0[];

struct StatsPeriodReport {
    void Load(void *stream);
    StatsPeriodReport *StreamConstruct(void *stream);
};

StatsPeriodReport *StatsPeriodReport::StreamConstruct(void *stream)
{
    *(void **)this = DAT_0055c2e0;
    if (stream != 0)
        Load(stream);
    return this;
}
