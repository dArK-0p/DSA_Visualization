#include "Array.h"
#include "Helper.h"

int main() {
	Array array(getLength());
	
	char st_ord[2];
	getSortTechniqueAndOrder(st_ord);

	array.sortArray(st_ord[0], st_ord[1]);

	return 0;
}