#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <TString.h>
#include <TH1D.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TPaveStats.h>
#include <TColor.h>
#include <TLatex.h>
#include <TLegend.h>
#include <TMath.h>

#include <boost/algorithm/string.hpp>

class ExcelSheet {
public:
    ExcelSheet(TString filename) {
//        std::cout << "Loading file: " << filename << std::endl;
        ifstream f(filename);
  
        string line;
        while(getline(f, line)) {
            vector<string> tmpSplit;
            boost::split(tmpSplit, line, [](char c){return c == ',';});
            Row.push_back(tmpSplit);
            
            if(Column.size() == 0) {
                Column.resize(tmpSplit.size());
            }
            else if(Column.size() < tmpSplit.size()) {
                exit(1);
            }
            for(int i = 0; i < tmpSplit.size(); i++) {
                Column[i].push_back(tmpSplit.at(i));
            }
            if(Column.size() > tmpSplit.size()) {
                for(int i = tmpSplit.size(); i < Column.size(); i++) {
                    Column[i].push_back("");
                }
            }
        }
        std::cout << "Loaded csv file!" << std::endl;
        f.close();
  }

  vector<vector<string> > Column;
  vector<vector<string> > Row;
    
};

template <typename T>
vector<T> change_type(vector<string> oldVec, T dummy) {
  vector<T> newVec;
  for(auto token : oldVec) {
    stringstream convert(token);
    T tmp;
    convert >> tmp;
    newVec.push_back(tmp);
  }
  return newVec;
}

template <typename T>
vector<T> change_type_nofirst(vector<string> oldVec, T dummy) {
  vector<T> newVec;
  for(auto iter = ++oldVec.begin(); iter != oldVec.end(); iter++) {
    stringstream convert(*iter);
    T tmp;
    convert >> tmp;
    newVec.push_back(tmp);
  }
  return newVec;
}

class PlotterLines {
public:
    // This is the really important part of the code! it uses the above functions
    // and takes the values out of the .csv files and returns in to the program
    // calling it in the form of a vector.
    PlotterLines(ExcelSheet sheet, int startRow, int endRow, int startCol, int col_num) : size(endRow + 1 - startRow) {
    double dummy;
    for(int i = 0; i < col_num; i++) {
      lines[i] = change_type(vector<string>(sheet.Column[startCol+i].begin()+startRow, sheet.Column[startCol+i].begin()+endRow+1), dummy);
    }
    voltages = change_type(vector<string>(sheet.Column[0].begin()+startRow, sheet.Column[0].begin()+endRow+1), dummy);
  }

  int size;
  vector<double> lines[10];
  vector<double> voltages;
};


