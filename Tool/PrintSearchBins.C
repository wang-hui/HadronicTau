#include <sstream>
#include <iostream>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <string>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <string>

#include "SusyAnaTools/Tools/searchBins.h"

using namespace std;
void printSearchBins(){

   print_searchBins();

}

void printlatexCom(){
  vector<double> prediction = {21.10, 6.15, 1.33, 0.22, 4.18, 4.60, 1.71, 0.25, 1.38, 2.51, 0.79, 19.81, 6.67, 2.30, 0.71, 4.53, 2.55, 1.64, 0.21, 0.92, 0.09, 9.50, 2.41, 0.50, 3.43, 1.38, 1.17, 0.12, 0.36, 7.54, 1.63, 1.01, 3.24, 0.83, 0.63, 0.21, 0.05};

  vector<double> statUp= {2.39, 1.27, 0.65, 0.56, 1.12, 1.21, 0.77, 0.57, 0.81, 1.06, 0.74, 2.45, 1.49, 0.89, 0.68, 1.23, 0.98, 0.86, 0.58, 0.74, 0.55, 1.53, 0.91, 0.66, 1.02, 0.69, 0.76, 0.56, 0.59, 1.37, 0.81, 0.69, 1.10, 0.64, 0.66, 0.58, 0.55};

  vector<double> statDown= {2.33, 1.14, 0.34, 0.10, 0.97, 1.07, 0.54, 0.15, 0.59, 0.90, 0.49, 2.38, 1.39, 0.70, 0.39, 1.10, 0.80, 0.66, 0.17, 0.49, 0.05, 1.42, 0.73, 0.36, 0.85, 0.41, 0.52, 0.12, 0.21, 1.26, 0.59, 0.41, 0.95, 0.32, 0.37, 0.17, 0.05};

  vector<double> sysUp= {1.382, 0.464, 0.176, 0.034, 0.318, 0.744, 0.198, 0.041, 0.221, 0.445, 0.120, 1.305, 0.484, 0.208, 0.099, 0.747, 0.233, 0.199, 0.034, 0.132, 0.024, 0.936, 0.426, 0.082, 0.388, 0.135, 0.148, 0.020, 0.074, 1.128, 0.271, 0.131, 0.310, 0.097, 0.178, 0.033, 0.006};

  vector<double> sysDown= {1.381, 0.463, 0.177, 0.036, 0.321, 0.742, 0.198, 0.040, 0.221, 0.446, 0.120, 1.304, 0.490, 0.209, 0.100, 0.746, 0.231, 0.203, 0.034, 0.132, 0.024, 0.936, 0.426, 0.082, 0.388, 0.135, 0.148, 0.020, 0.074, 1.128, 0.271, 0.131, 0.312, 0.097, 0.178, 0.033, 0.006};

  print_searchBinsPred_latex(prediction, statUp, statDown, sysUp, sysDown, "& $\\tauh$ Prediction \\\\");
}

void printlatexComInv(){
  vector<double> prediction = {15.60, 5.15, 2.44, 0.56, 4.85, 2.40, 0.68, 0.12, 1.87, 0.79, 0.96, 10.89, 3.68, 1.86, 0.76, 2.01, 1.41, 0.76, 0.37, 0.72, 0.03, 5.38, 1.64, 1.19, 1.93, 0.61, 0.61, 0.29, 0.73, 4.67, 3.18, 1.18, 1.24, 0.97, 0.58, 0.91, 0.51};

    vector<double> statUp= {1.72, 1.10, 0.86, 0.63, 1.00, 0.80, 0.59, 0.56, 0.87, 0.64, 0.78, 1.53, 0.89, 0.80, 0.63, 0.74, 0.68, 0.72, 0.59, 0.63, 0.55, 1.07, 0.81, 0.74, 0.92, 0.60, 0.68, 0.58, 0.74, 1.08, 1.08, 0.72, 0.68, 0.67, 0.63, 0.77, 0.71};

    vector<double> statDown= {1.63, 0.96, 0.66, 0.31, 0.83, 0.58, 0.22, 0.10, 0.67, 0.33, 0.55, 1.42, 0.70, 0.58, 0.30, 0.50, 0.40, 0.46, 0.20, 0.30, 0.03, 0.91, 0.60, 0.49, 0.74, 0.23, 0.41, 0.17, 0.49, 0.93, 0.93, 0.46, 0.40, 0.38, 0.31, 0.53, 0.45};

  vector<double> sysUp= {1.794, 0.440, 0.412, 0.093, 0.675, 0.540, 0.135, 0.039, 0.244, 0.163, 0.225, 1.040, 0.320, 0.307, 0.099, 0.282, 0.209, 0.175, 0.108, 0.096, 0.009, 0.946, 0.324, 0.155, 0.200, 0.112, 0.076, 0.034, 0.100, 0.811, 0.648, 0.200, 0.116, 0.154, 0.077, 0.239, 0.069};

  vector<double> sysDown= {1.793, 0.439, 0.413, 0.098, 0.678, 0.539, 0.135, 0.039, 0.243, 0.163, 0.225, 1.040, 0.322, 0.307, 0.101, 0.281, 0.208, 0.175, 0.108, 0.096, 0.009, 0.946, 0.323, 0.154, 0.200, 0.112, 0.076, 0.034, 0.099, 0.811, 0.648, 0.199, 0.117, 0.154, 0.077, 0.239, 0.069};

  print_searchBinsPred_latex(prediction, statUp, statDown, sysUp, sysDown, "& $\\tauh$ Prediction \\\\");
}
int main(){
   printSearchBins();
   printlatexCom();
   return 0;
}

