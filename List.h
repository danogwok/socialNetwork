//List.h

#ifndef LIST_H
#define LIST_H
using namespace std;

template <typename T>
class List{
  
  void insert(int pos, const T& item);

  void remove(int pos);

  void set(int pos, const T& item);

  T const & get(int pos) const;

};

#endif
