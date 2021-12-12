#include "Header.h"
#include "NewType.h"
void main() {
	date argu1 = Input_date();
	date argu2 = Input_date();
	coudate argu = CompareDate(argu1, argu2);
	Output_date(argu.small);
	Output_date(argu.big);
}
	