#include<iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <algorithm>


// calculated the std deviation of an array
double std_dev(double* v, int size)
{
  double ret=0.0, sum=0.0, mean=0.0 ;
  // TODO
  int i;
  for (i = 0; i < size; i++) {
    sum += v[i];
  }
  mean = sum / size;

  for (i = 0; i < size; i++) {
    ret += pow(mean - v[i], 2);
  }
    
  ret = sqrt(ret / size);

  return ret;
}


// calculate the std deviation for a vector
double std_dev_vec(const std::vector<double>& v)
{
  const auto mean = std::accumulate(v.begin(), v.end(), 0.0, [=](double a, double b) {return a + b / v.size(); });
  return sqrt(std::accumulate(v.begin(), v.end(), 0.0, [=](double a, double b) {return a + std::pow(mean - b, 2); })/v.size());
}

double std_for_each(const std::vector<double>& v) {
  double ret = 0.0, sum = 0.0, mean = 0.0, size = v.size();

  sum = std::accumulate(v.begin(), v.end(), 0.0);
  mean = sum / size;

  double square(double mean, double a) {
    return pow(mean - a, 2);
  }

  vector w = v;
  
  std::for_each(w.begin(), w.end(), square(mean));

  ret = std::accumulate(w.begin(), w.end(), 0.0);

  ret = sqrt(ret / size);

  return ret;
}

int quadratic_solver(double a, double b, double c , double* x1, double* x2) {
  double delta = b * b - 4 * a * c;
  if (delta >= 0) {

    *x1 = (-b + sqrt(delta)) / (2 * a);
    *x2 = (-b - sqrt(delta)) / (2 * a);
    return 2;
  }
  else {
    return 0;
  }
}

int main() {
  //double solution1 = 0.0;
  //double solution2 = 0.0;
  //auto nsol = quadratic_solver(1, 4.5, 3, &solution1, &solution2);
  //if (nsol == 2)
  //  std::cout << solution1 << ", " << solution2 << "\n";
  //else
  //  std::cout << "no real solutions\n";
  //return 0;

  
  double x[10];
  for (int i = 0; i < 10; ++i)
    x[i] = 1.0 + 2.3 * i;

  std::vector<double> y(2);
  y[0] = 0;
  y[1] = 10;

  std::cout << std_for_each(y);
  return 0;
}
//function for quadratic 

