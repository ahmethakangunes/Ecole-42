#include <iostream>

void megaphone(std::string argv){
    int i;

    i = -1;
    while (argv[++i])
        if(argv[i] >= 'a' && argv[i] <= 'z')
            argv[i] -= 32;
    std::cout << argv;
}

int main(int argc, char **argv){
    if (argc > 1)
    {
        int i;

        i = 1;
        while (argv[i])
            megaphone(argv[i++]);
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}