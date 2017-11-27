#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
int err;
int compt;
char nom;
char systemRM;
int c;
char *systemRm1;
char *systemRm2;

void OpenBDD();
void DeleteBDD();
void AddTable();
void DeleteTable();
void CleanBuffer();
char StringWithSpace();
char StringWithoutSpace();
void startApp();

#endif // STRING_H_INCLUDED
