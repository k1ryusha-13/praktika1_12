#include "dot.hpp"
top::Dot::Dot(p_t dd):
  IDraw(),
  d{dd}
{}
top::Dot::Dot(int x, int y):
  IDraw(), 
  d{x, y}
{}
top::p_t top::Dot::begin() const{
  return d;
}

top::p_t top::Dot::next(p_t prev) const {
  if (prev != begin()){

  }
  return begin();
}