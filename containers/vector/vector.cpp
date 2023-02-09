#include <iostream>
#include <vector>
#include "vector.hpp"
/* ============================== CONSTRUCTORS/DESTRUCTOR ============================== */
        // int main ()
        // {
        //   // constructors used in the same order as described above:
        //   ft::vector<int> first;                                // empty vector of ints
        //   ft::vector<int> second (4,100);                       // four ints with value 100
        //   ft::vector<int> third (second.begin(),second.end());  // iterating through second
        //   ft::vector<int> fourth (third);                       // a copy of third

        //   // the iterator constructor can also be used to construct from arrays:
        //   int myints[] = {16,2,77,29};
        //   ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
        //   std::cout << "The contents of fifth are:";
        //   for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        //     std::cout << ' ' << *it;
        //   std::cout << '\n';

        //   return 0;
        // }
        //The contents of fifth are: 16 2 77 29 
/* ============================== Begin & end ============================== */
        
      // int main ()
      // {
      //     std::vector<int> myvector;
      //     for (int i=1; i<=5; i++)
      //         myvector.push_back(i);
      //     std::cout << "myvector contains:";
      //     for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
      //         std::cout << ' ' << *it;
      //     std::cout << '\n';

      //     return 0;
      // }
      // int main ()
      // {
      //   std::vector<int> myvector;
      //   for (int i=1; i<=5; i++) myvector.push_back(i);

      //   std::cout << "myvector contains:";
      //   for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
      //     std::cout << ' ' << *it;
      //   std::cout << '\n';

      //   return 0;
      // } 
      // myvector contains: 1 2 3 4 5
/* ============================== Rbegin & rend ============================== */
        // int main ()
        // {
        //   std::vector<int> myvector (5);  // 5 default-constructed ints

        //   int i=0;

        //   std::vector<int>::reverse_iterator rit = myvector.rbegin();
        //   for (; rit!= myvector.rend(); ++rit)
        //     *rit = ++i;

        //   std::cout << "myvector contains:";
        //   for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        //     std::cout << ' ' << *it;
        //   std::cout << '\n';

        //   return 0;
        // }
        // int main ()
        // {
        //   std::vector<int> myvector (5);  // 5 default-constructed ints

        //   std::vector<int>::reverse_iterator rit = myvector.rbegin();

        //   int i=0;
        //   for (rit = myvector.rbegin(); rit != myvector.rend(); ++rit)
        //     *rit = ++i;

        //   std::cout << "myvector contains:";
        //   for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        //     std::cout << ' ' << *it;
        //   std::cout << '\n';

        //   return 0;
        // }
        // myvector contains: 5 4 3 2 1 
/* ============================== erase ============================== */
        // int main ()
        // {
        // std::vector<int> myvector;

        // // set some values (from 1 to 10)
        // for (int i=1; i<=10; i++) myvector.push_back(i);

        // // erase the 6th element
        // myvector.erase (myvector.begin()+5);

        // // erase the first 3 elements:
        // myvector.erase (myvector.begin(),myvector.begin()+3);

        // std::cout << "myvector contains:";
        // for (unsigned i=0; i<myvector.size(); ++i)
        // std::cout << ' ' << myvector[i];
        // std::cout << '\n';

        // return 0;
        // }
        // myvector contains: 4 5 7 8 9 10
/* ============================== swap ============================== */
        // int main ()
        // {
        //      std::vector<int> foo (3,100);   // three ints with a value of 100
        //      std::vector<int> bar (5,200);   // five ints with a value of 200
        //      foo.swap(bar);

        //      std::cout << "foo contains:";
        //      for (unsigned i=0; i<foo.size(); i++)
        //         std::cout << ' ' << foo[i];
        //      std::cout << '\n';
        //      std::cout << "bar contains:";
        //      for (unsigned i=0; i<bar.size(); i++)
        //         std::cout << ' ' << bar[i];
        //      std::cout << '\n';
        //      return 0;
        // }
        // foo contains: 200 200 200 200 200
        // bar contains: 100 100 100

/* ============================== TODO:isert ============================== */
// int main ()
// {
//   ft::vector<int> myvector (3,100);
//   ft::vector<int>::iterator it;

//   it = myvector.begin();
//   it = myvector.insert ( it , 200 );

//   myvector.insert (it,2,300);

//   // "it" no longer valid, get a new one:
//   it = myvector.begin();

//   ft::vector<int> anothervector (2,400);
//   myvector.insert (it+2,anothervector.begin(),anothervector.end());

//   int myarray [] = { 501,502,503 };
//   myvector.insert (myvector.begin(), myarray, myarray+3);

//   std::cout << "myvector contains:";
//   for (it=myvector.begin(); it<myvector.end(); it++)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }

/* ============================== TODO: erase ============================== */
// int main ()
// {
//   ft::vector<int> myvector;

//   // set some values (from 1 to 10)
//   for (int i=1; i<=10; i++) myvector.push_back(i);

//   // erase the 6th element
//   myvector.erase (myvector.begin()+5);

//   // erase the first 3 elements:
//   myvector.erase (myvector.begin(),myvector.begin()+3);

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); ++i)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

//   return 0;
// }
/* ============================== emplace ============================== */
int main ()
{
        ft::vector<int> myvector = {10,20,30};

  auto it = myvector.emplace ( myvector.begin()+1, 100 );
  myvector.emplace ( it, 200 );
  myvector.emplace ( myvector.end(), 300 );

  std::cout << "myvector contains:";
  for (auto& x: myvector)
    std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}