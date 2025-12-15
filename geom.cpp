#include "geom.hpp"
#include <stdexcept>
bool top::operator == (p_t a, p_t b){
    return a.x == b.x && a.y == b.y;
  }
bool top::operator != (p_t a, p_t b){
    return !(a == b);
  }
size_t top::rows(f_t fr){
    return (fr.bb.y - fr.aa.y + 1);
  }
size_t top::cols(f_t fr){
    return (fr.bb.x - fr.aa.x + 1);
  }
top::f_t frame(const top::p_t * pts, size_t s)
  {
    if (!s){
      throw std::logic_error("bad size");
    }
    int minx = pts[0].x, maxx = minx;
    int miny = pts[0].y, maxy = miny;
    for (size_t i = 1; i < s; ++i){
      minx = (pts[i].x < minx)? pts[i].x : minx;
      maxx = (pts[i].x > maxx)? pts[i].x : maxx;
      miny = (pts[i].y < miny)? pts[i].y : miny;
      maxy = (pts[i].y > maxy)? pts[i].y : maxy;
    }
    top::p_t aa{minx, miny};
    top::p_t bb{miny, maxy};
  }
  size_t rows(top::f_t fr){
    return (fr.bb.y - fr.aa.y + 1);
  }
  size_t cols(top::f_t fr){
    return (fr.bb.x - fr.aa.x + 1);
  }