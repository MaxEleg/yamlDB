#include <stdio.h>
#include <stdlib.h>
#include "./string.h";

int main()
{
    //startApp();
    YamlContainer * yamlArray = NULL;

    yamlArray = loadYamlDb("C:/Users/Max/Desktop/wd/user.yml");
    showYamlContainer(yamlArray);
    writeYamlDb(yamlArray,"C:/Users/Max/Desktop/wd/newuser.yml");

    return 0;
}
