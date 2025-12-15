#include <iostream>
#include "geom.hpp"
#include "idraw.hpp"
#include "dot.hpp"
#include "canvas.hpp"


int main()
{
  using namespace top;
  int err = 0;
  IDraw* shp[3] = {};
  p_t * pts = nullptr;
  size_t s = 0;
  char * cnv = nullptr;
  p_t ** kp = nullptr;
  try{
    shp[0] = new Dot({0, 0});
    shp[1] = new Dot({2, 3});
    shp[2] = new Dot({-5, -2});
    for(size_t i = 0; i < 3; ++i){
      points(shp[i], &pts, s);
    }
    f_t fr = frame(pts, s);
    char * cnv = build_canvas(fr, '.');
    for (size_t i = 0; i < s; ++i) {
      paint_canvas(pts[i], cnv, fr, '#');
    }

    paint_canvas(cnv, fr, pts, s, '#');
    flush(std::cout, cnv, fr);
  } catch(...){
    err = 1;
    delete shp[0];
    delete shp[1];
    delete shp[2];
    delete[] pts;
    delete[] cnv;
    return err;
  }
}

