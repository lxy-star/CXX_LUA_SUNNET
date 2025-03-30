#include "../include/config.h"

#include "unistd.h"
#include "stdlib.h"

Config::Config()
{
    //固定配置成员变量
    thread_size = 4;
    process_num = 1;
}

void Config::parse_arg(int argc, char *argv[])
{
    const char *str = "t:p";
    int opt;
    while ((opt = getopt(argc, argv, str)) != -1)
    {
        //根据运行时参数赋值成员变量
        switch (opt)
        {
        case 't':
            /* code */
            thread_size = atoi(optarg);
            break;
        case 'p':
            process_num = atoi(optarg);
            break;
        default:
            break;
        }
    }
}