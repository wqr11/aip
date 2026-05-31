typedef unsigned short int uint16;
typedef unsigned int uint32;

class str
{
private:
    uint32 size = 0;
    uint32 capacity = 1024;
    char *s = new char[capacity]();

public:
    str() {}

    str(const char *news)
    {
        *this = news;
    }

    str &operator=(const char *news)
    {
        int len = strlen(news);

        while (capacity <= len)
        {
            capacity *= 2;
            char *new_s = new char[capacity]();
            memmove(new_s, s, size);
            delete[] s;
            s = new_s;
        }

        memset(s, 0, size);
        memmove(s, news, len);
        size = len;

        return *this;
    }

    char *tocharptr()
    {
        return this->s;
    }

    ~str()
    {
        delete[] s;
        s = nullptr;
    }
};
