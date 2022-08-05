#include "dll.h"
int main() {
    // Write more tests for dll

    create_example_dll();

    print_dll(test_DLL);
    push_back(&test_DLL, (Data){405, 23.3});
    push_front(&test_DLL, (Data){407, 27.3});
    printf("\n");
    print_dll(test_DLL);
    pop_front(&test_DLL);
	printf("\n");
    print_dll(test_DLL);
    pop_back(&test_DLL);
    printf("\n");
    print_dll(test_DLL);//the pops cant free more, bc the original test_DLL is not dynamically allocated
    return 0;
}
