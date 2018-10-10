#include "main.hpp"

void    fillRandStr(char *str, size_t size) {
    if (str == NULL)
        return ;
    for (unsigned i = 0; i < size; i++)
        str[i] = (rand() % ('z' - 'a')) + 'a';
    str[size] = 0;
}

Data    *deserialize(void *ptr) {
    serialized_t    *data_s;
    Data            *data_d;

    try {
        data_d = new Data;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return (NULL);
    }

    data_s = reinterpret_cast<serialized_t *>(ptr);
    data_d->str1 = static_cast<std::string>(data_s->str1);
    data_d->str2 = static_cast<std::string>(data_s->str2);
    data_d->num = data_s->num;

    return (data_d);
}

void    *serialize(void) {
    serialized_t    *data;

    try {
        data = new serialized_t;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return (NULL);
    }

    fillRandStr(data->str1, STR_LENGTH + 1);
    fillRandStr(data->str2, STR_LENGTH + 1);
    data->num = rand();

    return (reinterpret_cast<void *>(data));
}

int main(void) {
    void    *p = NULL;
    Data    *data = NULL;
    serialized_t    *pt;

    srand(time(NULL));

    p = serialize();
    if (p == NULL)
        return (-1);

    pt = reinterpret_cast<serialized_t *>(p);
    std::cout << "Serialized:" << std::endl;
    std::cout << pt->str1 << std::endl;
    std::cout << pt->num << std::endl;
    std::cout << pt->str2 << std::endl << std::endl;

    data = deserialize(p);
    if (data == NULL)
        return (-1);

    std::cout << "Deserialized:" << std::endl;
    std::cout << data->str1 << std::endl;
    std::cout << data->num << std::endl;
    std::cout << data->str2 << std::endl;

    return (0);
}