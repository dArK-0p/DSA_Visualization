#include "Array.h"
#include "Helper.h"

int main() {
	char st_ord[2];
	getSortTechniqueAndOrder(st_ord);

	Array array(getLength());
	
	array.sortArray(st_ord[0], st_ord[1]);


	return 0;
}