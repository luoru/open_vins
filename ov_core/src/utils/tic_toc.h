//
// Created by Zhongfei Luo on 2022/5/28.
//

#ifndef OPEN_VINS_TIC_TOC_H
#define OPEN_VINS_TIC_TOC_H

#include <chrono>
#include <cstdlib>
#include <ctime>

class TicToc {
 public:
  TicToc() { tic(); }

  void tic() { start = std::chrono::system_clock::now(); }

  double toc() {
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    return elapsed_seconds.count() * 1000;
  }

 private:
  std::chrono::time_point<std::chrono::system_clock> start, end;
};

#endif  // OPEN_VINS_TIC_TOC_H
