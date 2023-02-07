// constructing vectors
#include <iostream>
#include <vector>
#include "Vector.hpp"
/* ============================== CONSTRUCTORS/DESTRUCTOR ============================== */
		
		/**** default *****/
// int main()
// {
//     std::vector<int> myVec;

//     myVec.push_back(10);
//     myVec.push_back(20);
//     myVec.push_back(30);

//     for (int i = 0; i < myVec.size(); i++) {
//         std::cout << myVec[i] << " ";
//     }

//     return 0;
// }

		/**** fill constr *****/
int main()
{
    ft::vector<int> myVec(5, 0);

    for (int i = 0; i < 5; i++) {
        std::cout << myVec[i] << " ";
    }
    return 0;
}

			/**** range constr *****/
// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5};
//     std::vector<int> myVec(arr, arr + 5);

//     for (int i = 0; i < myVec.size(); i++) {
//         std::cout << myVec[i] << " ";
//     }

//     return 0;
// }