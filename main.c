#include <stdio.h>
#include <stdlib.h>
#include "./string.h";

int main()
{
    //startApp();
    YamlContainer * yamlArray = NULL;

    yamlArray = loadYamlDb("C:/Users/Max/Desktop/wd/user.yml");
    showYamlContainer(yamlArray);

    return 0;
}
