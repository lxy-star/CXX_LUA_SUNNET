#ifndef CONFIG_H
#define CONFIG_H

class Config
{
private:
    /* data */
    
public:
    Config(/* args */);
    ~Config() = default;
    void parse_arg(int argc,char* argv[]);
    int thread_size;
    int process_num; 
};

#endif