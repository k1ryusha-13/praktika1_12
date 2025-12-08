#include <iostream>
#include <cstddef>

namespace top{

  struct p_t {
    int x, y;
  };

  struct IDraw {
    virtual p_t begin() const = 0;
    virtual p_t next(p_t) const = 0;
    virtual ~IDraw() = default;
  };

  bool operator == (p_t a, p_t b){
    return a.x == b.x && a.y == b.y;
  }

  bool operator != (p_t a, p_t b){
    return !(a == b);
  }

  struct Dot:IDraw{
    p_t begin() const override;
    p_t next(p_t) const override;
    p_t d;
    Dot(int x, int y);
    explicit Dot(p_t dd);
  };
  struct frame_t {
  p_t left_bot;
  p_t right_top;
  };
  void make_f(IDraw** b, size_t k){}
  void extend(p_t** pts, size_t s, p_t p)
  {
    p_t * res = new p_t[s + 1];
    for (size_t i = 0; i < s; ++i){
      res[i] = (*pts)[i];
    }
    res[s] = p;
    delete [] *pts;
    *pts = res;
  }
  size_t get_points(const IDraw & d, p_t ** pts, size_t & s)
  {
    p_t p = d.begin();
    extend(pts, s, p);
    size_t delta = 1;

    while (d.next(p) != d.begin()){
      p = d.next(p);
      extend(pts, s + delta, p);
      ++delta;
    }
    return delta;
  }
  frame_t build_frame(const p_t * ps, size_t s){}
  char * build_canvas(frame_t f){}
  void paint_canvas(char * cnv, frame_t fr, const p_t * ps, size_t k, char f){}
  void print_canvas(const char * cnv, frame_t fr){}
}


int main()
{
  using namespace top;
  int err = 0;
  IDraw* f[3] = {};
  p_t * p = nullptr;
  size_t s = 0;
  char * cnv = nullptr;
  p_t ** kp = nullptr;
  try{
    make_f (f, 3);
    for(size_t i = 0; i < 3; ++i){
      get_points(f[i], kp, s);
    }
    frame_t fr = build_frame(p, s);
    cnv = build_canvas(fr);
    paint_canvas(cnv, fr, p, s, '#');
    print_canvas(cnv, fr);
  } catch(...){
    err = 1;
    delete f[0];
    delete f[1];
    delete f[2];
    delete[] p;
    delete[] cnv;
    return err;
  }
}

top::Dot::Dot(int x, int y):
IDraw(), o{x, y} {}

top::p_t top::Dot::begin() const{
  return o;
}

top::p_t top::Dot::next(p_t) const {
  return begin();
}