#include "reverse_iterator.hpp"
#include <iostream>     // std::cout
#include <iterator>     // std::reverse_iterator
#include <vector>       // std::vector

/*
  ===========================test base ===========================
*/

// int main () 
// {
//   std::vector<int> myvector;
//   for (int i=0; i<10; i++) 
//     myvector.push_back(i);

//   typedef std::vector<int>::iterator iter_type;

//   ft::reverse_iterator<iter_type> rev_end (myvector.begin());
//   ft::reverse_iterator<iter_type> rev_begin (myvector.end());

//   std::cout << "myvector:";
//   for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }
// output : myvector: 0 1 2 3 4 5 6 7 8 9

/*
  ===========================test constructor ===========================
*/

// int main ()
// {
//   std::vector<int> myvector;
//   for (int i=0; i<10; i++)
//         myvector.push_back(i);

//   typedef std::vector<int>::iterator iter_type;
//                                                          // ? 0 1 2 3 4 5 6 7 8 9 ?
//   iter_type from (myvector.begin());                     //   ^
//                                                          //         ------>
//   iter_type until (myvector.end());                      //                       ^
//                                                          //
//   ft::reverse_iterator<iter_type> rev_until (from);     // ^
//                                                          //         <------
//  ft::reverse_iterator<iter_type> rev_from (until);     //                     ^

//   std::cout << "myvector:";
//   while (rev_from != rev_until)
//     std::cout << ' ' << *rev_from++;
//   std::cout << '\n';

//   return 0;
// }

//output : myvector: 9 8 7 6 5 4 3 2 1 0
/*
  =========================== test operator * ===========================
*/

// int main () 
// {
//   std::vector<int> myvector;
//   for (int i=0; i<10; i++)
//       myvector.push_back(i);

//   typedef std::vector<int>::iterator iter_type;
//                                                          // ? 9 8 7 6 5 4 3 2 1 0 ?
//   iter_type from (myvector.begin());                     //   ^
//                                                          //         ------>
//   iter_type until (myvector.end());                      //                       ^
//                                                          //
//   ft::reverse_iterator<iter_type> rev_until (from);     // ^
//                                                          //         <------
//   ft::reverse_iterator<iter_type> rev_from (until);     //                     ^

//   std::cout << "myvector:";
//   while (rev_from != rev_until)
//     std::cout << ' ' << *rev_from++;
//   std::cout << '\n';

//   return 0;
// }

/*
  =========================== test operator + ===========================
*/

// int main () 
// {
//   std::vector<int> myvector;
//   for (int i=0; i<10; i++)
//     myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9
//   typedef std::vector<int>::iterator iter_type;
//   std::reverse_iterator<iter_type> rev_it;

//   rev_it = myvector.rbegin() + 3;
//   std::cout << "The fourth element from the end is: " << *rev_it << '\n';

//   return 0;
// }

// output : The fourth element from the end is: 6

/*
  ===========================test operator++ ===========================
*/

// int main () 
// {
//   std::vector<int> myvector;
//   for (int i=0; i<10; i++) myvector.push_back(i);

//   typedef std::vector<int>::iterator iter_type;
//                                                          // ? 9 8 7 6 5 4 3 2 1 0 ?
//   iter_type from (myvector.begin());                     //   ^
//                                                          //         ------>
//   iter_type until (myvector.end());                      //                       ^
//                                                          //
//   ft::reverse_iterator<iter_type> rev_until (from);     // ^
//                                                          //         <------
//   ft::reverse_iterator<iter_type> rev_from (until);     //                     ^

//   std::cout << "myvector:";
//   while (rev_from != rev_until) {
//     std::cout << ' ' << *rev_from;
//     ++rev_from;
//   }
//   std::cout << '\n';

//   return 0;
// }
// output : myvector: 9 8 7 6 5 4 3 2 1 0

/*
  ===========================test operator += (no)===========================
*/

// int main ()
// {
//   std::vector<int> myvector;

//   for (int i=0; i<10; i++)
//     myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

//   typedef std::vector<int>::iterator iter_type;

//   ft::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();
  

//   rev_iterator += 2;

//   std::cout << "The third element from the end is: " << *rev_iterator << '\n';

//   return 0;
// }
// output : The third element from the end is: 7

/*
  ===========================test operator - (no)===========================
*/

// int main () 
// {
//   std::vector<int> myvector;
//   for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

//   typedef std::vector<int>::iterator iter_type;

//   ft::reverse_iterator<iter_type> rev_iterator;

//   rev_iterator = myvector.rend() - 3;

//   std::cout << "myvector.rend()-3 points to: " << *rev_iterator << '\n';

//   return 0;
// }
// output : myvector.rend()-3 points to: 2

/*
  ===========================test operator -- ===========================
*/

// int main () 
// {
//   std::vector<int> myvector;

//   for (int i=0; i<10; i++)
//     myvector.push_back(i);
//   typedef std::vector<int>::iterator iter_type;

//   ft::reverse_iterator<iter_type> rev_begin (myvector.end());
//   ft::reverse_iterator<iter_type> rev_end (myvector.begin());

//   ft::reverse_iterator<iter_type> rev_iterator = rev_begin;
//   while ( rev_iterator != rev_end )
//     std::cout << *rev_iterator++ << ' ';
//   std::cout << '\n';

//   while ( rev_iterator != rev_begin )
//     std::cout << *(--rev_iterator) << ' ';
//   std::cout << '\n';

//   return 0;
// }

/*
  ===========================test operator -= (no)===========================
*/

// int main () 
// {
//   std::vector<int> myvector;
//   for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

//   typedef std::vector<int>::iterator iter_type;

//   ft::reverse_iterator<iter_type> rev_iterator = myvector.rend();

//   rev_iterator -= 4;

//   std::cout << "rev_iterator now points to: " << *rev_iterator << '\n';

//   return 0;
// }

/*
  ===========================test operator -> ===========================
*/
// #include <utility>      // std::make_pair
// #include <map>          // std::map
// #include <string>       // std::string

// int main () 
// {
//   std::map<int,std::string> numbers;
//   numbers.insert (std::make_pair(1,"one"));
//   numbers.insert (std::make_pair(2,"two"));
//   numbers.insert (std::make_pair(3,"three"));

//   typedef std::map<int,std::string>::iterator map_iter;

//   ft::reverse_iterator<map_iter> rev_end (numbers.begin());

//   ft::reverse_iterator<map_iter> rev_iterator (numbers.end());

//   for ( ; rev_iterator != rev_end ; ++rev_iterator )
//     std::cout << rev_iterator->first << ' ' << rev_iterator->second << '\n';

//   return 0;
// }

/*
  ===========================test operator [](no) ===========================
*/
// int main () 
// {
//   std::vector<int> myvector;
//   for (int i=0; i<10; i++) myvector.push_back(i);  // myvector: 0 1 2 3 4 5 6 7 8 9

//   typedef std::vector<int>::iterator iter_type;

//   ft::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

//   std::cout << "The fourth element from the end is: " << rev_iterator[3] << '\n';

//   return 0;
// }

/*
  =========================== relational operator ===========================
*/

// int main ()
//{
//   std::vector<int> myvector;

//   for (int i=0; i<10; i++)
//     myvector.push_back(i);

//   typedef std::vector<int>::iterator iter_type;
//                                                          // ? 9 8 7 6 5 4 3 2 1 0 ?
//   iter_type from (myvector.begin());                     //   ^
//                                                          //         ------>
//   iter_type until (myvector.end());                      //                       ^
//                                                          //
//   ft::reverse_iterator<iter_type> rev_until (from);     // ^
//                                                          //         <------
//   ft::reverse_iterator<iter_type> rev_from (until);     //                     ^

//   std::cout << "myvector:";
//   while (rev_from != rev_until)
//     std::cout << ' ' << *rev_from++;
//   std::cout << '\n';

//   return 0;
// }

/*
  =========================== operator -(no) ===========================
*/
// int main ()
// {
//   std::vector<int> myvector;
//   for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

//   typedef std::vector<int>::iterator iter_type;

//   std::reverse_iterator<iter_type> rev_it;

//   rev_it = 3 + myvector.rbegin();

//   std::cout << "The fourth element from the end is: " << *rev_it << '\n';

//   return 0;
// }

/*
  =========================== operator + (no)===========================
*/

// int main ()
// {
//   std::vector<int> myvector;
//   for (int i=0; i<10; i++) myvector.push_back(i);

//   ft::reverse_iterator<std::vector<int>::iterator> from,until;

//   from = myvector.rbegin();
//   until = myvector.rend();

//   std::cout << "myvector has " << (until-from) << " elements.\n";

//   return 0;
// }