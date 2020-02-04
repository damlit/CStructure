#include "list.h"

int main() {

List L;
init(&L);
write(L);
insert(&L, 1);
insert(&L, 2);
write(L);
insert(&L, 3);
search(L, 2);
search(L, 4);
insertAfter(&L, 4, 2);
write(L);
deleteFromList(&L, 2);
write(L);
deleteFromList(&L, 5);
write(L);
insertBefore(&L, 5, 3);
write(L);
clear(&L);
write(L);


return 0;
}
